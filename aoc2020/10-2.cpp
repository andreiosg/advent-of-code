#include <bits/stdc++.h>
#include <climits>

/*
 *
 * Kompleksnost O(n^2 * m)
 *  n - broj parova {tocka, vektor}
 *  m - broj sekundi potrebnih za formiranje slova
 *
 */

using namespace std;

int manDist(pair<int, int> t1, pair<int, int> t2) {
  return abs(t2.first - t1.first) + abs(t2.second - t1.second);
}

bool isWord(vector<pair<int, int>> vPos) {
  for (int i = 0; i < vPos.size(); ++i) {
    bool flag = false;
    for (int j = 0; j < vPos.size(); ++j) {
      if (j == i)
        continue;
      if (manDist(vPos[i], vPos[j]) <= 2)
        flag = true;
    }
    if (!flag)
      return false; // nijedan znak u okolici (<= 2 predstavlja znak u jednoj
                    // od 8 okolnih kucica)
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false); //:)
  cin.tie(NULL);

  vector<pair<int, int>> vPos;
  vector<pair<int, int>> vVec;

  string line;
  while (getline(cin, line)) {
    stringstream l(line);

    char c;
    pair<int, int> x;

    while (l.get() != '<')
      ;
    l >> x.first >> c >> x.second;
    vPos.push_back(x);

    while (l.get() != '<')
      ;
    l >> x.first >> c >> x.second;
    vVec.push_back(x);
  }

  int time = 0;
  while (!isWord(vPos)) {
    ++time;
    for (int i = 0; i < vPos.size(); ++i) {
      vPos[i].first += vVec[i].first;
      vPos[i].second += vVec[i].second;
    }
  }

  cout << time << endl;

  return 0;
}
