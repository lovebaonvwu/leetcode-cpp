class Solution {
 public:
  int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int n = plants.size();

    int i = 0, j = n - 1;
    int a = capacityA;
    int b = capacityB;
    vector<int>& p = plants;

    int ans = 0;
    while (i < j) {
      if (p[i] > a) {
        ++ans;
        a = capacityA;
      }

      a -= p[i++];

      if (p[j] > b) {
        ++ans;
        b = capacityB;
      }

      b -= p[j--];
    }

    if (i == j && a < p[i] && b < p[i]) {
      ++ans;
    }

    return ans;
  }
};
// Runtime: 235 ms, faster than 13.94%
// Memory Usage: 78.3 MB, less than 64.97%
// 2021.12.15 at 奥盛大厦

class Solution {
 public:
  int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int n = plants.size();

    int i = 0, j = n - 1;
    int a = capacityA;
    int b = capacityB;
    vector<int>& p = plants;

    int ans = 0;
    while (i < j) {
      ans += (a < p[i]) + (b < p[j]);
      a = a < p[i] ? capacityA : a;
      b = b < p[j] ? capacityB : b;
      a -= p[i++];
      b -= p[j--];
    }

    return ans + (i == j && max(a, b) < p[i]);
  }
};
// Runtime: 218 ms, faster than 18.98%
// Memory Usage: 78.3 MB, less than 21.29%
// 2021.12.15 at 奥盛大厦