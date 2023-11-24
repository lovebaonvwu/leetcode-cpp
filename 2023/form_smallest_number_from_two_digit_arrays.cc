class Solution {
 public:
  int minNumber(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        if (nums1[i] == nums2[j]) {
          return nums1[i];
        }
      }
    }

    int& a = nums1[0];
    int& b = nums2[0];

    return a < b ? (a * 10 + b) : (b * 10 + a);
  }
};
// Runtime 11 ms
// Memory 21.9 MB