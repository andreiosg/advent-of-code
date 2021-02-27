#include <cstdio>
#include <cstdlib>

#define ROWS 1000
#define COLS 1000
#define MAX_ELVES 1500
struct Elf {
  int ID;
  int sizeX;
  int sizeY;
  int offsetX;
  int offsetY;
};

int findSingleID(struct Elf *elves, int nElves, int fabric[ROWS][COLS]) {
  int flag;
  for (int i = 0; i < nElves; ++i) {
    flag = 1;
    for (int j = 0; j < elves[i].sizeY; ++j) {
      for (int k = 0; k < elves[i].sizeX; ++k) {
        if (fabric[elves[i].offsetY + j][elves[i].offsetX + k] != elves[i].ID)
          flag = 0;
      }
    }
    if (flag == 1)
      return elves[i].ID;
  }
}

int findMultiple(struct Elf *elves, int nElves, int fabric[ROWS][COLS]) {
  for (int i = 0; i < nElves; ++i) {
    for (int j = 0; j < elves[i].sizeY; ++j) {
      for (int k = 0; k < elves[i].sizeX; ++k) {
        if (fabric[elves[i].offsetY + j][elves[i].offsetX + k] == -1) {
          fabric[elves[i].offsetY + j][elves[i].offsetX + k] = elves[i].ID;
        } else if (fabric[elves[i].offsetY + j][elves[i].offsetX + k] != -1) {
          fabric[elves[i].offsetY + j][elves[i].offsetX + k] = 0;
        }
      }
    }
  }

  int nMultiples = 0;
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      if (fabric[i][j] == 0)
        ++nMultiples;
    }
  }

  return nMultiples;
}

int main() {
  struct Elf *elves = (struct Elf *)malloc(MAX_ELVES * sizeof(int));
  int fabric[ROWS][COLS];

  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      fabric[i][j] = -1;
    }
  }

  int nElves = 0;
  while (scanf("#%d @ %d,%d: %dx%d ", &elves[nElves].ID, &elves[nElves].offsetX,
               &elves[nElves].offsetY, &elves[nElves].sizeX,
               &elves[nElves].sizeY) != EOF) {
    ++nElves;
  }

  findMultiple(elves, nElves, fabric);
  printf("%d\n", findSingleID(elves, nElves, fabric));

  free(elves);

  return 0;
}
