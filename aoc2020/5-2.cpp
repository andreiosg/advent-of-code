/*
 *
 * Kompleksnost: skalirana s obzirom na 5-1; odnosno O(n)
 *
 */
#include <bits/stdc++.h>

constexpr int UPPER_LOWER_DIST = 32;

using namespace std;

int reactionNum() {
  stack<char> s;  // stack rezultata reakcija
  vector<char> a; // input chars
  char c;

  while (cin >> c)
    a.push_back(c);

  int min = numeric_limits<int>::max();
  for (char excl = 'a'; excl <= 'z';
       ++excl) {       // excludamo svaki od char iz abecede (u/l case)
    for (auto i : a) { // za svaki element inputa
      if (i == excl || i == excl - UPPER_LOWER_DIST)
        continue;

      if (!s.empty() && (i == s.top() + UPPER_LOWER_DIST ||
                         i == s.top() - UPPER_LOWER_DIST)) {
        s.pop();
      } else {
        s.push(i);
      }
    }

    min = (s.size() < min) ? s.size() : min;
    while (!s.empty())
      s.pop();
  }

  return min;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = reactionNum();
  cout << n << endl;

  return 0;
}
