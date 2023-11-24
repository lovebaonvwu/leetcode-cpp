class Solution {
 public:
  vector<int> separateDigits(vector<int>& nums) {
    vector<int> ans;

    for (auto n : nums) {
      int i = ans.size();
      while (n > 0) {
        ans.push_back(n % 10);
        n /= 10;
      }

      reverse(ans.begin() + i, ans.end());
    }

    return ans;
  }
};
// Runtime 4 ms
// Memory 10.1 MB
// 2023.2.19 at 奥盛大厦