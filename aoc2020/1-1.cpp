/*
 *
 * Kompleksnost: O(n)
 *
 */
#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> v) {
  int s = 0;
  for (const auto &i : v) {
    s += i;
  }

  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> v;
  int num;
  char sign;
  while (cin >> sign >> num) {
    switch (sign) {
    case '+':
      v.push_back(num);
      break;

    case '-':
      v.push_back(-1 * num);
      break;
    }
  }

  int s = sum(v);
  cout << s << endl;

  return 0;
}
