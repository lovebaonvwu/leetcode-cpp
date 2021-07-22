class Solution {
 public:
  int addRungs(vector<int>& rungs, int dist) {
    int ans = 0;

    rungs.insert(rungs.begin(), 0);

    for (int i = rungs.size() - 2; i >= 0; --i) {
      int gap = rungs[i + 1] - rungs[i];

      while (gap > dist) {
        gap -= dist;
        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded
// 2021.7.22 at 奥盛大厦

class Solution {
 public:
  int addRungs(vector<int>& rungs, int dist) {
    int ans = 0;

    rungs.insert(rungs.begin(), 0);

    for (int i = rungs.size() - 2; i >= 0; --i) {
      int gap = rungs[i + 1] - rungs[i] - 1;

      while (gap >= dist) {
        ans += gap / dist;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 108 ms, faster than 61.82%
// Memory Usage: 54.2 MB, less than 29.37%
// 2021.7.22 at 奥盛大厦

class Solution {
 public:
  int addRungs(vector<int>& rungs, int dist) {
    int ans = 0;

    rungs.insert(rungs.begin(), 0);

    for (int i = rungs.size() - 2; i >= 0; --i) {
      ans += (rungs[i + 1] - rungs[i] - 1) / dist;
    }

    return ans;
  }
};
// Runtime: 96 ms, faster than 90.43%
// Memory Usage: 54.2 MB, less than 29.37%
// 2021.7.22 at 奥盛大厦