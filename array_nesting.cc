class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    unordered_set<int> st;

    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int cnt = 0;
      int prev = i;
      while (st.empty() || !st.count(nums[prev])) {
        st.insert(nums[prev]);
        prev = nums[prev];
        ++cnt;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 20.78%
// Memory Usage: 12.7 MB, less than 27.27%

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      int cnt = 0;
      for (int j = i; nums[j] >= 0; ++cnt) {
        int prev = j;

        j = nums[j];
        nums[prev] = -1;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 80.16%
// Memory Usage: 7.7 MB, less than 100.00%