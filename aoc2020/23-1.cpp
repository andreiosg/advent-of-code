#include <bits/stdc++.h>

using namespace std;

struct Nanobots {
  int x, y, z;
  int r;
};

int manDist(struct Nanobots n1, struct Nanobots n2) {
  return abs(n2.x - n1.x) + abs(n2.y - n1.y) + abs(n2.z - n1.z);
}

vector<struct Nanobots> parseInput() {
  vector<struct Nanobots> v;
  char c;
  struct Nanobots n;
  while (cin >> c) {
    if (c == '<') {
      cin >> n.x >> c >> n.y >> c >> n.z;
    } else if (c == 'r') {
      cin >> c >> n.r;
      v.push_back(n);
    }
  }

  return v;
}

int findMaxRange(vector<struct Nanobots> v) {
  int idx;
  int maxR = 0;
  for (auto i = 0; i < v.size(); ++i) {
    if (v[i].r > maxR) {
      maxR = v[i].r;
      idx = i;
    }
  }

  int inRange = 0;
  for (auto j = 0; j < v.size(); ++j) {
    if (manDist(v[idx], v[j]) <= v[idx].r)
      inRange++;
  }

  return inRange;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<struct Nanobots> v = parseInput();

  int maxInRange = findMaxRange(v);

  cout << maxInRange << endl;

  return 0;
}
