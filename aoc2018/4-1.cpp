#include <cstdio>
#include <cstdlib>
#include <cstring>
#define NUM_STRINGS 1200
#define MAX_STRING_LEN 64

#define TIME_SIZE 20

#define MAX_GUARDS 1000
#define MINUTES 60

struct Guard {
  int ID;
  int minutes[MINUTES];
};

void printStrings(char strings[NUM_STRINGS][MAX_STRING_LEN], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%s\n", strings[i]);
  }
  putchar('\n');
}

void swapStrings(char x[MAX_STRING_LEN], char y[MAX_STRING_LEN]) {
  char tmp[MAX_STRING_LEN];
  memcpy(tmp, x, MAX_STRING_LEN * sizeof(char));
  memcpy(x, y, MAX_STRING_LEN * sizeof(char));
  memcpy(y, tmp, MAX_STRING_LEN * sizeof(char));
}

int partition(char strings[NUM_STRINGS][MAX_STRING_LEN], int left, int right) {
  char pivot[MAX_STRING_LEN];
  memcpy(pivot, strings[right], MAX_STRING_LEN * sizeof(char));

  int newPivotIdx = left;
  char tmp[MAX_STRING_LEN];

  for (int i = left; i < right; ++i) {
    if (strcmp(strings[i], pivot) < 0) {
      swapStrings(strings[i], strings[newPivotIdx]);
      ++newPivotIdx;
    }
  }
  swapStrings(strings[newPivotIdx], strings[right]);

  return newPivotIdx;
}

void quicksort(char strings[NUM_STRINGS][MAX_STRING_LEN], int left, int right) {
  if (left < right) {
    int pivot = partition(strings, left, right);
    quicksort(strings, left, pivot - 1);
    quicksort(strings, pivot + 1, right);
  }
}

int findIdx(struct Guard *guards, int nGuards, int ID) {
  for (int i = 0; i < nGuards; ++i) {
    if (guards[i].ID == ID)
      return i;
  }

  return -1;
}

int strategyOne(struct Guard *guards, int nGuards) {
  int sum;
  int maxSum = 0;
  int maxIdx = 0;
  for (int i = 0; i < nGuards; ++i) {
    sum = 0;
    for (int j = 0; j < MINUTES; ++j) {
      sum += guards[i].minutes[j];
    }
    if (sum > maxSum) {
      maxSum = sum;
      maxIdx = i;
    }
  }

  int minute;
  int maxSlept = 0;
  for (int i = 0; i < MINUTES; ++i) {
    if (guards[maxIdx].minutes[i] > maxSlept) {
      maxSlept = guards[maxIdx].minutes[i];
      minute = i;
    }
  }

  return minute * guards[maxIdx].ID;
}

int strategyTwo(struct Guard *guards, int nGuards) {
  int sum;
  int maxFreq = 0;
  int maxIdx = 0;
  int maxMinute;
  for (int i = 0; i < nGuards; ++i) {
    sum = 0;
    for (int j = 0; j < MINUTES; ++j) {
      if (guards[i].minutes[j] > maxFreq) {
        maxFreq = guards[i].minutes[j];
        maxIdx = i;
        maxMinute = j;
      }
    }
  }

  return maxMinute * guards[maxIdx].ID;
}
void parseDataAndSolve(char strings[NUM_STRINGS][MAX_STRING_LEN], int nStrings,
                       struct Guard *guards, int nGuards) {
  char choice[6];

  int idx;
  int ID;
  int start;
  int end;
  for (int i = 0; i < nStrings; ++i) {
    sscanf(strings[i], "%*s %*s %s", choice);
    if (!strcmp(choice, "Guard")) {
      sscanf(strings[i], "%*s %*s %*s #%d", &ID);

      int retval = findIdx(guards, nGuards, ID);
      if (retval >= 0) {
        idx = retval;
      } else {
        idx = nGuards;
        guards[nGuards].ID = ID;
        memset(guards[nGuards].minutes, 0, MINUTES * sizeof(int));
        ++nGuards;
      }
    } else if (!strcmp(choice, "falls")) {
      sscanf(strings[i], "%*s %*d:%d", &start);
    } else if (!strcmp(choice, "wakes")) {
      sscanf(strings[i], "%*s %*d:%d", &end);
      for (int j = start; j < end; ++j) {
        ++guards[idx].minutes[j];
      }
    }
  }

  printf("%d\n", strategyOne(guards, nGuards));
}

int main() {
  char strings[NUM_STRINGS][MAX_STRING_LEN];
  int nStrings = 0;

  while (scanf("%[^\n\r] ", strings[nStrings]) != EOF) {
    ++nStrings;
  }

  quicksort(strings, 0, nStrings - 1);

  struct Guard *guards =
      (struct Guard *)malloc(MAX_GUARDS * sizeof(struct Guard));
  int nGuards = 0;
  parseDataAndSolve(strings, nStrings, guards, nGuards);
  free(guards);

  return 0;
}
