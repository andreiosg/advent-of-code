/*
 *
 * Kompleksnost: O(n * m * log(n * m))
 *  n - broj ulaznih frekvencijskih promjena
 *  m - iteracija u kojoj je uocena dvostruka frekvencija; m E [1, e], e < +inf
 *
 */
#include <bits/stdc++.h>

using namespace std;

int calibrate(vector<int> v) {
  set<int> s;

  int sum = 0;
  s.insert(sum);

  while (true) {
    for (const auto &i : v) {
      sum += i;
      if (s.find(sum) != s.end())
        return sum; // dvostruka freq?
      else
        s.insert(sum); // zapamti freq
    }
  }
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

  int freq = calibrate(v);
  cout << freq << endl;

  return 0;
}
