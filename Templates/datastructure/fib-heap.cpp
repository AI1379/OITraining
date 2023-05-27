#include <bits/stdc++.h>
using namespace std;
#define ll long long
class FibonacciHeap {
public:
  using ValueType = ll;

private:
  struct FibHeapNode {
    ValueType value;
    bool marked;
    size_t degree;
    FibHeapNode *parent, *child;
    FibHeapNode *next, *prev;
  };

public:
  using Iterator = FibHeapNode *;
  using ConstIterator = const Iterator;
  ConstIterator push(const ValueType &x) {
    FibHeapNode *node = new FibHeapNode();
    node->value = x;
    if (!top_node_) {
      top_node_ = node->next = node->prev = node;
    } else {
      node->next = top_node_->next;
      top_node_->next->prev = node;
      top_node_->next = node;
      node->prev = top_node_;
      if (top_node_->value > node->value)
        top_node_ = node;
    }
    ++size_;
    return node;
  }
  ValueType pop() {
    auto res = top_node_->value;
    if (top_node_) {
      auto cur = top_node_->child;
      while (cur->parent) {
        cur->parent = nullptr;
        cur = cur->next;
      }
      mergeList(cur, top_node_);
      removeListNode(top_node_);
      if (size_ == 1) {
        delete top_node_;
        top_node_ = nullptr;
      } else {
        delete top_node_;
        top_node_ = top_node_->next;
        consolidate();
      }
      --size_;
    }
    return res;
  }
  ValueType remove(Iterator iter) {}
  const ValueType &top() { return top_node_->value; }
  void decreaseValue(Iterator p, ValueType val) {}
  void join(const FibonacciHeap &other) {}
  size_t size() { return size_; }
  bool empty() { return size_ == 0; }

private:
  FibHeapNode *top_node_ = nullptr;
  size_t size_;
  void mergeList(FibHeapNode *lhs, FibHeapNode *rhs) {
    auto x = lhs->next, y = rhs->prev;
    lhs->next = rhs;
    rhs->prev = lhs;
    x->prev = y;
    y->next = x;
  }
  void removeListNode(FibHeapNode *p) {
    p->next->prev = p->prev;
    p->prev->next = p->next;
    p->next = p->prev = p;
  }
  void link(FibHeapNode *lhs, FibHeapNode *rhs) {
    removeListNode(lhs);
    mergeList(rhs->child, lhs);
    lhs->parent = rhs;
    ++(rhs->degree);
    lhs->marked = false;
  }
  void consolidate() {
    std::vector<FibHeapNode *> deg;
    deg.resize(size_);
    size_t d;
    FibHeapNode *x, *y;
    for (auto cur = top_node_->next; cur != top_node_; cur = cur->next) {
      x = cur;
      d = cur->degree;
      while (deg[d]) {
        y = deg[d];
        if (x->value > y->value)
          swap(x, y);
        link(y, x);
        deg[d] = nullptr;
        ++d;
      }
      deg[d] = x;
    }
    top_node_ = nullptr;
    for (auto ptr : deg) {
      if (ptr) {
        if (top_node_ == nullptr) {
          top_node_ = ptr;
        } else {
          mergeList(top_node_, ptr);
          if (ptr->value < top_node_->value) {
            top_node_ = ptr;
          }
        }
      }
    }
  }
  void cut(Iterator iter) {}
  void cascadingCut(Iterator it) {}
};
int main() {}