class Solution {
 public:
  int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int ans = 0;
    for (auto n1 : nums1) {
      for (auto n2 : nums2) {
        if (n1 % (n2 * k) == 0)
          ++ans;
      }
    }

    return ans;
  }
};
// 9 ms
// 41.04 MB