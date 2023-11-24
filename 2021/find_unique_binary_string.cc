class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    string ans;

    for (int i = 0; i < nums.size(); ++i) {
      ans += nums[i][i] == '0' ? '1' : '0';
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 10 MB, less than 98.90%
// 2021.8.24 at 奥盛大厦