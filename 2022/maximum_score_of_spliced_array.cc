class Solution {
 public:
  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    return max(sum1 + kadane(nums2, nums1), sum2 + kadane(nums1, nums2));
  }

  int kadane(vector<int>& a, vector<int>& b) {
    int cur = a[0] - b[0];
    int g = cur;

    for (int i = 1; i < a.size(); ++i) {
      cur = max(a[i] - b[i], cur + a[i] - b[i]);

      g = max(g, cur);
    }

    return g;
  }
};
// Runtime: 257 ms, faster than 31.78%
// Memory Usage: 82.6 MB, less than 84.84%
// 2022.7.13 at 奥盛大厦