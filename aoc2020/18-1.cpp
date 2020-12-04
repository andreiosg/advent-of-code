#include <bits/stdc++.h>

#define MAX 50
#define TIME_RANGE 10

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

void drawField(pair<string, string> field[MAX]) {
  for (int t = 0; t < 10; ++t) {
    int len = field[0].first.length();
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < len; ++j) {
        drawAcre(field, len, i, j);
      }
    }

    for (int i = 0; i < MAX; ++i) {
      field[i].first = field[i].second;
    }
    // printField(field);
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
  int value = calcValue(field);
  cout << value << endl;

  return 0;
}
