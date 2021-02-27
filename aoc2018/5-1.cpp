/*
 *
 * Kompleksnost: O(n)
 *
 */
#include <bits/stdc++.h>

constexpr int UPPER_LOWER_DIST = 32;

using namespace std;

int reactionNum() {
  stack<int> s;
  char c;

  while (cin >> c) {
    if (!s.empty() &&
        (c == s.top() + UPPER_LOWER_DIST || c == s.top() - UPPER_LOWER_DIST)) {
      s.pop();
    } else {
      s.push(c);
    }
  }

  return s.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = reactionNum();
  cout << n << endl;

  return 0;
}
