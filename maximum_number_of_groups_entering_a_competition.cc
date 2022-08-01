class Solution {
 public:
  int maximumGroups(vector<int>& grades) {
    int total = 0;
    int cnt = 1;

    int ans = 0;
    while (total <= grades.size()) {
      total += cnt++;
      ans++;
    }

    return ans -= total > grades.size();
  }
};
// Runtime: 102 ms, faster than 100.00%
// Memory Usage: 56.6 MB, less than 100.00%
// 2022.8.1 at 奥盛大厦