class Solution {
 public:
  int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));

    vector<int> diff;
    diff.push_back(nums2[0] - nums1[0]);
    diff.push_back(nums2[0] - nums1[1]);
    diff.push_back(nums2[0] - nums1[2]);

    int ans = INT_MAX;
    int n = nums2.size();
    for (auto d : diff) {
      int cnt = 0;
      int i = 0;
      for (; i < n && cnt <= 2;) {
        if (nums2[i] - nums1[i + cnt] != d) {
          ++cnt;
          continue;
        }
        ++i;
      }

      if (i == n) {
        ans = min(ans, d);
      }
    }

    return ans;
  }
};
// 4 ms
// 32.59 MB