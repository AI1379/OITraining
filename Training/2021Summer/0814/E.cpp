#include <bits/stdc++.h>
using namespace std;
const int mp[] = {2, 0, 1};
void output(int out) {
  if (out == 0)
    cout << 'R' << endl;
  else if (out == 1)
    cout << 'S' << endl;
  else if (out == 2)
    cout << 'P' << endl;
}
int input() {
  char in;
  cin >> in;
  if (in == 'R')
    return 0;
  else if (in == 'S')
    return 1;
  else if (in == 'P')
    return 2;
}
int last;
int generate(int in) {
  last = in;
  if (in == 0) return rand() % 3;
  return mp[in];
}
int main() {
  int n;
  cin >> n;
  int in = 0;
  srand(time(NULL));
  for (int i = 1; i <= n; i++) {
    output(generate(in));
    in = input();
  }
  return 0;
}