
#include <cstddef>
#include <list>
#include <memory>
#include <random>
#include <tuple>
#include <utility>

template <typename Key, typename Comp = std::less<Key>,
          typename Alloc = std::allocator<Key>>
class PersistentBST {
public:
  using KeyType = Key;
  using AllocatorType = Alloc;
  PersistentBST() : alloc_(std::allocator<Node>()) {}
  explicit PersistentBST(const Alloc alloc) : alloc_(alloc) {}
  void insert(const Key &key) { auto tmp = split(current_, key); }

private:
  struct Node;
  using NodePtr = std::shared_ptr<Node>;
  struct Node {
    NodePtr lson, rson;
    std::size_t size, prior, count;
    KeyType key;
  };
  std::list<NodePtr, AllocatorType> roots_;
  typename std::list<NodePtr, AllocatorType>::iterator current_;
  AllocatorType alloc_;
  void pushup(NodePtr p) { p->size = p->lson->size + p->rson->size + p.count; }
  std::tuple<NodePtr, NodePtr, NodePtr> split(NodePtr ptr, const Key &value) {
    if (ptr == nullptr)
      return {nullptr, nullptr};
    std::tuple<NodePtr, NodePtr, NodePtr> tmp;
    auto new_node = std::allocate_shared<Node>(alloc_, &ptr);
    if (Comp{}(new_node->data, value)) {
      tmp = split(new_node->rson, value);
      new_node->rson = std::get<0>(tmp);
      pushup(new_node);
      return {new_node, std::get<1>(tmp), std::get<2>(tmp)};
    } else if (new_node->data == value) {
      auto res = {new_node->lson, new_node, new_node->rson};
      new_node->lson = new_node->rson = nullptr;
      return res;
    } else {
      tmp = split(new_node->lson, value);
      new_node->lson = tmp.second;
      pushup(new_node);
      return {tmp.first, new_node};
    }
  }
  NodePtr merge(NodePtr u, NodePtr v) {
    if (u == nullptr && v == nullptr)
      return nullptr;
    if (u == nullptr)
      return v;
    if (v == nullptr)
      return u;
    if (u->prior <= v->prior) {
      u->rson = merge(u->rson, v);
      pushup(u);
      return u;
    } else {
      v->lson = merge(u, v->lson);
      pushup(v);
      return v;
    }
  }
  auto random() {
    static std::random_device rd;
    static std::mt19937_64 mt(rd());
    static std::uniform_int_distribution<std::size_t> dist;
    return dist(mt);
  }
};
