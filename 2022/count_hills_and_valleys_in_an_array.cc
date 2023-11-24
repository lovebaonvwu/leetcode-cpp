class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    vector<int> tmp;

    for (auto n : nums) {
      if (tmp.empty() || n != tmp.back()) {
        tmp.push_back(n);
      }
    }

    int ans = 0;
    for (int i = 1; i < tmp.size() - 1; ++i) {
      if (tmp[i] > tmp[i - 1] && tmp[i] > tmp[i + 1]) {
        ++ans;
      }

      if (tmp[i] < tmp[i - 1] && tmp[i] < tmp[i + 1]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 10 ms, faster than 11.37%
// Memory Usage: 9 MB, less than 10.82%
// 2022.3.29 at 奥盛大厦