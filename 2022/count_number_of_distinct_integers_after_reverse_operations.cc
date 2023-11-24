class Solution {
 public:
  int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> st(begin(nums), end(nums));

    for (auto n : nums) {
      int x = 0;
      while (n > 0) {
        x = x * 10 + n % 10;
        n /= 10;
      }

      st.insert(x);
    }

    return st.size();
  }
};
// Runtime: 318 ms, faster than 92.31%
// Memory Usage: 97.1 MB, less than 84.62%
// 2022.10.17 at 奥盛大厦