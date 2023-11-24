class Solution {
 public:
  int minProductSum(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.rbegin(), nums2.rend());

    int ans = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      ans += nums1[i] * nums2[i];
    }

    return ans;
  }
};
// Runtime 272 ms
// Memory 105.5 MB
// 2022.11.22 at 茗筑美嘉