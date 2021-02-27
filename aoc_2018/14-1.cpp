#include <bits/stdc++.h>

using namespace std;

#define NUM 10

int main() {
  vector<int> v;
  v.push_back(3);
  v.push_back(7);

  int idx1 = 0;
  int idx2 = 1;
  ;

  int target;
  cin >> target;

  while (v.size() < target + NUM) {
    int tmp = v[idx1] + v[idx2];
    if (tmp <= 9) {
      v.push_back(tmp);
    } else {
      int second = tmp % 10;
      tmp /= 10;
      int first = tmp;
      v.push_back(first);
      v.push_back(second);
    }
    idx1 = (idx1 + 1 + v[idx1]) % v.size();
    idx2 = (idx2 + 1 + v[idx2]) % v.size();
  }

  for (int i = target; i < target + NUM; ++i) {
    cout << v[i];
  }
  cout << endl;

  return 0;
}
