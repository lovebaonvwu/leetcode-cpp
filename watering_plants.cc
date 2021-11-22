class Solution {
 public:
  int wateringPlants(vector<int>& plants, int capacity) {
    int ans = 0;

    for (int i = 0, cap = capacity, n = plants.size(); i < n;) {
      while (i < n && cap >= plants[i]) {
        cap -= plants[i];
        ++ans;
        ++i;
      }

      if (i == n) {
        break;
      }

      ans += i * 2;
      cap = capacity;
    }

    return ans;
  }
};
// Runtime: 10 ms, faster than 25.00%
// Memory Usage: 8.5 MB, less than 50.00%
// 2021.11.22 at 奥盛大厦

class Solution {
 public:
  int wateringPlants(vector<int>& plants, int capacity) {
    int ans = 0;

    int n = plants.size();

    for (int i = 0, cap = capacity; i < n; ++i) {
      if (cap < plants[i]) {
        ans += i * 2;
        cap = capacity;
      }

      cap -= plants[i];
    }

    return ans + n;
  }
};

// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 50.00%
// 2021.11.22 at 奥盛大厦