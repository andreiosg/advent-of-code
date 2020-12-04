#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int players;  // broj igraca
  int endWorth; // krajnja vrijednost
  string tmp;   // da se rijesim stringova
  cin >> players >> tmp >> tmp >> tmp >> tmp >> tmp >> endWorth;

  vector<int> v(players, 0); // vektor s rezultatima igraca

  list<int> l;
  list<int>::iterator it;

  l.push_front(0);
  it = l.begin();
  for (int i = 1; i <= endWorth; ++i) {
    int idx = i % players; // indeks za vektor rezultata igraca
    if (i % 23 != 0) {     // ako nije visekratnik 23
      ++it;
      if (it == l.end())
        it = l.begin();
      ++it;
      it = l.insert(it, i);
    } else {
      for (int j = 0; j < 7; ++j) {
        if (it == l.begin()) {
          it = l.end();
        }
        --it;
      }
      v[idx] += *it + i;
      it = l.erase(it);
    }
  }

  // pronalazak max rezultata igraca
  int max = 0;
  for (const auto &el : v)
    max = (el > max) ? el : max;

  cout << max;

  return 0;
}
