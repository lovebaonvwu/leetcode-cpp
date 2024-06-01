class Solution {
 public:
  int duplicateNumbersXOR(vector<int>& nums) {
    vector<int> seen(51);
    int ans = 0;
    for (auto n : nums) {
      if (seen[n]) {
        ans ^= n;
      } else {
        ++seen[n];
      }
    }

    return ans;
  }
};
// 11 ms
// 26.24 MB