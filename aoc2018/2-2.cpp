/*
 *
 * Kompleksnost: O(n^2)
 *  n - broj stringova
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ERR "none found";

string construct(string a, string b) {
  string res;
  for (int i = 0; i < a.length() && i < b.length(); ++i) {
    if (a[i] == b[i])
      res.push_back(a[i]);
  }
  return res;
}

string findCommon(vector<string> ids) {
  for (auto i : ids) {
    for (auto j : ids) {
      int nDiff = 0;
      if (i == j)
        continue;
      for (int idx = 0; idx < i.length() && idx < j.length();
           ++idx) { // za svaki char u stringu
        if (i[idx] != j[idx])
          ++nDiff;
      }
      if (nDiff == 1)
        return construct(i, j); // pronadeni su trazeni stringovi
    }
  }

  return ERR;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<string> ids;
  string id;
  while (cin >> id)
    ids.push_back(id);

  string common = findCommon(ids);
  cout << common << endl;

  return 0;
}
