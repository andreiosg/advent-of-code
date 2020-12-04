/*
 *
 * Kompleksnost O(n^2 * m)
 *  n - broj parova {tocka, vektor}
 *  m - broj sekundi potrebnih za formiranje slova
 *
 */
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int manDist(pair<int, int> t1, pair<int, int> t2) { // 2D manhattan distance
  return abs(t2.first - t1.first) + abs(t2.second - t1.second);
}

bool isWord(vector<pair<int, int>> vPos) { // provjera ako je rijec formirana
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

bool isLetter(vector<pair<int, int>> vPos, int x,
              int y) { // provjera ako se nalazi dio slova na koordinati
  bool flag = false;
  for (auto i : vPos) {
    if (i.first == x && i.second == y)
      flag = true;
  }

  return flag;
}

int main() {
  // ios_base::sync_with_stdio(false); //:)
  // cin.tie(NULL);

  vector<pair<int, int>> vPos;
  vector<pair<int, int>> vVec;

  // unos
  string line;
  while (getline(cin, line)) {
    stringstream l(line);

    pair<int, int> x;
    char c;

    while (l.get() != '<')
      ;
    l >> x.first >> c >> x.second;
    vPos.push_back(x);

    while (l.get() != '<')
      ;
    l >> x.first >> c >> x.second;
    vVec.push_back(x);
  }

  // napredak, dobivanje rijeci
  while (!isWord(vPos)) {
    for (int i = 0; i < vPos.size(); ++i) {
      vPos[i].first += vVec[i].first;
      vPos[i].second += vVec[i].second;
    }
  }

  // granice rijeci
  int xMin = INT_MAX;
  int xMax = INT_MIN;

  int yMin = INT_MAX;
  int yMax = INT_MIN;
  for (auto i : vPos) {
    if (i.first > xMax)
      xMax = i.first;
    if (i.first < xMin)
      xMin = i.first;

    if (i.second > yMax)
      yMax = i.second;
    if (i.second < yMin)
      yMin = i.second;
  }

  // ispis rijeci
  for (int i = yMin; i <= yMax; ++i) {
    for (int j = xMin; j <= xMax; ++j) {
      if (isLetter(vPos, j, i))
        cout << '#';
      else
        cout << '.';
    }
    cout << '\n';
  }

  return 0;
}
