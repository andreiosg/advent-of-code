/*
 *
 * Kompleksnost: O(n)
 *  n - broj stringova
 *
 */
#include <bits/stdc++.h>

using namespace std;

int calcChecksum(vector<string> ids) {
  int d = 0;
  int t = 0;
  vector<int> v;
  for (const auto &i : ids) {
    v.assign(26, 0);
    bool bd = false;
    bool bt = false;

    for (const auto &j : i)
      ++v[j - 'a'];

    for (const auto &j : v) {
      if (j == 2)
        bd = true;
      else if (j == 3)
        bt = true;
    }

    d += bd ? 1 : 0;
    t += bt ? 1 : 0;
  }

  return d * t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<string> ids;
  string id;
  while (cin >> id)
    ids.push_back(id);

  int checksum = calcChecksum(ids);
  cout << checksum;

  return 0;
}
