class Solution {
 public:
  int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    return nums2[0] - nums1[0];
  }
};
// 12 ms
// 34.28 MB

class Solution {
 public:
  int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    int n1 = *min_element(begin(nums1), end(nums1));
    int n2 = *min_element(begin(nums2), end(nums2));

    return n2 - n1;
  }
};
// 12 ms
// 34.00 MB