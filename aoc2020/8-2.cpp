#include <cstdio>

int sumMetadata() {
  int nodes;
  int metadata;

  int sum = 0;
  int tmp;
  scanf("%d %d", &nodes, &metadata);

  if (nodes > 0) {
    int val[nodes];
    tmp = nodes;
    while (tmp > 0) {
      val[nodes - tmp] = sumMetadata();
      --tmp;
    }
    while (metadata-- > 0) {
      scanf("%d", &tmp);
      --tmp;
      if (tmp < nodes) {
        sum += val[tmp];
      }
    }
  } else {
    while (metadata--) {
      scanf("%d", &tmp);
      sum += tmp;
    }
  }

  return sum;
}

int main() {
  printf("%d\n", sumMetadata());

  return 0;
}
