#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ROWS 1200
#define COLS 1200

#define MAX_COORDINATES 1000

struct Coordinates {
  int x;
  int y;
  int tmpDist;
  int numPoints;
  int isFinite;
};

int manDist(struct Coordinates a, int x, int y) {
  return abs(a.x - x) + abs(a.y - y);
}

void drawCoordinate(struct Coordinates *arr, int n, int field[ROWS][COLS],
                    int row, int col) {
  int minDist = INT_MAX;

  int idx;
  for (int i = 0; i < n; ++i) {
    arr[i].tmpDist = manDist(arr[i], col, row);
    if (arr[i].tmpDist < minDist) {
      minDist = arr[i].tmpDist;
      idx = i;
    }
  }
  field[row][col] = idx;
  ++arr[idx].numPoints;

  for (int i = 0; i < n; ++i) {
    if (i == idx)
      continue;
    if (arr[i].tmpDist == minDist) {
      --arr[idx].numPoints;
      field[row][col] = -5; // jednaka min udaljenost
      return;
    }
  }
}

int drawField(struct Coordinates *arr, int n, int field[ROWS][COLS]) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      if (field[i][j] != -2) {
        // printf(" %c ", field[i][j] + 97);
        continue;
      }
      drawCoordinate(arr, n, field, i, j);
      // printf(" %c ", field[i][j] + 97);
    }
    // putchar('\n');
  }
}

int findMax(struct Coordinates *arr, int n, int field[ROWS][COLS]) {
  int notQualified[MAX_COORDINATES];
  int nQualified = 0;
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      if (i == 0 || j == 0 || i == ROWS - 1 ||
          j == COLS - 1 && field[i][j] != -5) {
        arr[field[i][j]].isFinite = 0;
      }
    }
  }

  int max = INT_MIN;
  for (int i = 0; i < n; ++i) {
    if (max < arr[i].numPoints && arr[i].isFinite == 1) {
      max = arr[i].numPoints;
    }
  }

  return max;
}

int main() {
  struct Coordinates *arr = (struct Coordinates *)malloc(
      MAX_COORDINATES * sizeof(struct Coordinates));
  int n = 0;

  int field[ROWS][COLS];
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      field[i][j] = -2; //-2, pocetna vrijednost
    }
  }

  while (scanf("%d, %d", &arr[n].x, &arr[n].y) != EOF) {
    arr[n].numPoints = 1;
    arr[n].isFinite = 1;
    field[arr[n].y][arr[n].x] = n;
    ++n;
  }
  drawField(arr, n, field);
  /*
  for(int i = 0; i < n; ++i){
      printf("\n%c %d\n", i + 97, arr[i].numPoints);
  }
  */

  printf("%d\n", findMax(arr, n, field));

  free(arr);
  return 0;
}
