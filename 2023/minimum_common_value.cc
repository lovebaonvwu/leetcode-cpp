class Solution {
 public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int ans = -1;

    for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
      if (nums1[i] == nums2[j]) {
        ans = nums1[i];
        break;
      } else if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        ++j;
      }
    }

    return ans;
  }
};
// Runtime 105 ms
// Memory 50.7 MB
