#include <bits/stdc++.h>

#define MAX 50
#define TIME_RANGE 1000000000

using namespace std;

void printField(pair<string, string> field[MAX]) {
  for (int i = 0; i < MAX; ++i) {
    cout << field[i].first << endl;
  }
  cout << endl;
}

void drawAcre(pair<string, string> field[MAX], int len, int row, int col) {
  int moves[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                     {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

  int nOpen = 0;
  int nTrees = 0;
  int nLumbery = 0;
  for (int i = 0; i < 8; ++i) {
    int posC = col + moves[i][0];
    int posR = row + moves[i][1];
    if (posC < 0 || posC >= len || posR < 0 || posR >= MAX)
      continue;

    if (field[posR].first[posC] == '.')
      ++nOpen;
    if (field[posR].first[posC] == '|')
      ++nTrees;
    if (field[posR].first[posC] == '#')
      ++nLumbery;
  }

  switch (field[row].first[col]) {
  case '.':
    if (nTrees >= 3)
      field[row].second[col] = '|';
    break;

  case '|':
    if (nLumbery >= 3)
      field[row].second[col] = '#';
    break;

  case '#':
    if (nTrees < 1 || nLumbery < 1)
      field[row].second[col] = '.';
    break;
  }
}

int calcValue(pair<string, string> field[MAX]) {
  int nTrees = 0;
  int nLumbery = 0;
  int len = field[0].first.length();
  for (int i = 0; i < MAX; ++i) {
    for (int j = 0; j < len; ++j) {
      switch (field[i].first[j]) {
      case '|':
        ++nTrees;
        break;

      case '#':
        ++nLumbery;
        break;
      }
    }
  }

  return nTrees * nLumbery;
}

void iterateRepeated(vector<int> repeated, long long range) {
  int idx = 0;
  for (long long k = 0; k < range; ++k) {
    idx = (idx + 1) % repeated.size();
  }
  cout << repeated[idx] << endl;
  return;
}

void drawField(pair<string, string> field[MAX]) {
  vector<int> repeated;
  int value;
  int first;
  bool flag = true;
  int idx = 1;
  for (long long t = 0; t < TIME_RANGE; ++t) {
    int len = field[0].first.length();
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < len; ++j) {
        drawAcre(field, len, i, j);
      }
    }

    for (int i = 0; i < MAX; ++i) {
      field[i].first = field[i].second;
    }
    if (flag) {
      value = calcValue(field);
      if (t == 5000) { // nakon ~5000 se pocnu ponavljat, malo magic number
        first = value;
        repeated.push_back(value);
      } else if (t > 5000) {
        if (value == first) {
          flag = false;
          cout << repeated[(TIME_RANGE - t - 1) % repeated.size()] << endl;
          return;
        } else {
          repeated.push_back(value);
        }
      }
    } else {
      idx = (idx + 1) % repeated.size();
    }
  }
  cout << repeated[idx] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pair<string, string> field[MAX]; // par jer se promjene dogadaju istovremeno,
                                   // imamo staro i novo polje
  for (int i = 0; i < MAX; ++i) {
    cin >> field[i].first;
    field[i].second = field[i].first;
  }

  drawField(field);

  return 0;
}
