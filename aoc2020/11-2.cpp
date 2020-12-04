#include <bits/stdc++.h>

#define X_MAX 300
#define Y_MAX 300

using namespace std;

struct Result {
  int max;
  int size;
};

void calcSum(int cells[Y_MAX + 2][X_MAX + 2], int key) {
  int sum = 0;
  for (int i = 1; i <= Y_MAX; ++i) {
    for (int j = 1; j <= X_MAX; ++j) {
      cells[i][j] = j + 10;
      cells[i][j] *= i;
      cells[i][j] += key;
      cells[i][j] *= j + 10;
      cells[i][j] /= 100;
      cells[i][j] %= 10;
      cells[i][j] -= 5;
      sum += cells[i][j];
      cells[i][j] = sum;
    }
  }
}

struct Result partialSum(int cells[Y_MAX + 2][X_MAX + 2], int x, int y) {
  struct Result r;
  int sum;
  r.max = numeric_limits<int>::min();
  for (int j = 1; y + (j - 1) <= Y_MAX && x + (j - 1) <= X_MAX; ++j) {
    sum = 0;
    for (int i = 0; i < j; ++i) {
      sum += cells[y + i][x + (j - 1)] - cells[y + i][x - 1];
    }

    if (r.max < sum) {
      r.max = sum;
      r.size = j;
    }
  }

  return r;
}

void findMax(int cells[Y_MAX + 2][X_MAX + 2]) {
  int x, y;
  int max = numeric_limits<int>::min();
  int size;
  struct Result r;
  for (int i = 1; i <= Y_MAX - 2; ++i) {
    for (int j = 1; j <= X_MAX - 2; ++j) {
      r = partialSum(cells, j, i);
      if (r.max > max) {
        max = r.max;
        x = j;
        y = i;
        size = r.size;
      }
    }
  }

  cout << x << ',' << y << ',' << size << endl;
}

void printMax(int key) {
  int cells[Y_MAX + 2][X_MAX + 2] = {0};

  calcSum(cells, key);

  findMax(cells);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int key;
  cin >> key;

  printMax(key);

  return 0;
}
