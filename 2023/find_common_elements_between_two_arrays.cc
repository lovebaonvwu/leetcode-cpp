class Solution {
 public:
  vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    int n1[101]{0};
    for (auto n : nums1)
      ++n1[n];
    int n2[102]{0};
    vector<int> ans{0, 0};
    for (auto n : nums2) {
      ans[1] += n1[n] > 0;
      ++n2[n];
    }

    for (auto n : nums1) {
      ans[0] += n2[n] > 0;
    }

    return ans;
  }
};
// 32ms
// 60.88MB