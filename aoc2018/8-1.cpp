#include <cstdio>

int sumMetadata() {
  int nodes;
  int metadata;

  int sum = 0;
  int operand;
  scanf("%d %d", &nodes, &metadata);

  while (nodes-- > 0) {
    sum += sumMetadata();
  }

  while (metadata-- > 0) {
    scanf("%d", &operand);
    sum += operand;
  }

  return sum;
}

int main() {
  printf("%d\n", sumMetadata());

  return 0;
}
