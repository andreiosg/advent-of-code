#include <bits/stdc++.h>

#define X_MAX 300
#define Y_MAX 300

using namespace std;

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

int partialSum(int cells[Y_MAX + 2][X_MAX + 2], int x, int y) {
  int sum = 0;
  for (int i = 0; i < 3; ++i) {
    sum += cells[y + i][x + 2] - cells[y + i][x - 1];
  }

  return sum;
}

void findMax(int cells[Y_MAX + 2][X_MAX + 2]) {
  int x, y;
  int max = numeric_limits<int>::min();
  for (int i = 1; i <= Y_MAX - 2; ++i) {
    for (int j = 1; j <= X_MAX - 2; ++j) {
      int sum = partialSum(cells, j, i);
      if (sum > max) {
        max = sum;
        x = j;
        y = i;
      }
    }
  }

  cout << x << ',' << y << endl;
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
