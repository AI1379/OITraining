#include <bits/stdc++.h>
using namespace std;
#define ll long long
namespace Game {
static ll n;
enum PigType { kUnknown = 0, kMaybeZP, kMaybeFP, kMP, kZP, kFP };
struct Card;
struct Pig {
  ll max_power, power;
  ll pos;
  ll p_num, k_num, d_num;
  vector<shared_ptr<Card>> cards;
  Pig() : max_power(4), power(4) {}
  virtual PigType type() = 0;
  bool dead() { return power <= 0; }
  void attack() {}
};
struct MP : public Pig {
  PigType type() override { return kMP; }
};
struct ZP : public Pig {
  PigType type() override { return kZP; }
};
struct FP : public Pig {
  PigType type() override { return kFP; }
};
struct Card {
  virtual char type() = 0;
  virtual void use(shared_ptr<Pig>) = 0;
};
struct PCard : public Card {
  char type() override { return 'P'; }
  void use(shared_ptr<Pig> obj) override {
    if (obj->power < obj->max_power)
      ++obj->power;
  }
};
struct KCard : public Card {
  char type() override { return 'K'; }
  void use(shared_ptr<Pig> obj) override {}
};
struct DCard : public Card {
  char type() override { return 'D'; }
  void use(shared_ptr<Pig> obj) override {}
};
struct FCard : public Card {
  char type() override { return 'F'; }
  void use(shared_ptr<Pig> obj) override {}
};
struct NCard : public Card {
  char type() override { return 'N'; }
  void use(shared_ptr<Pig> obj) override {}
};
struct WCard : public Card {
  char type() override { return 'W'; }
  void use(shared_ptr<Pig> obj) override {}
};
struct JCard : public Card {
  char type() override { return 'J'; }
  void use(shared_ptr<Pig> obj) override {}
};
struct ZCard : public Card {
  char type() override { return 'Z'; }
  void use(shared_ptr<Pig> obj) override {}
};
ll dis(const Pig &a, const Pig &b) { return (b.pos - a.pos + n) % n; }
queue<shared_ptr<Card>> cards;
shared_ptr<Card> getCard() {
  static shared_ptr<Card> ptr = nullptr;
  if (cards.empty())
    return ptr;
  ptr = cards.front();
  cards.pop();
  return ptr;
}
} // namespace Game
namespace Play {
void init() {}
void run() {}
} // namespace Play
int main() {
  Play::init();
  Play::run();
  return 0;
}