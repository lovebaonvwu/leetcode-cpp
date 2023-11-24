class Solution {
 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int diff{0}, maxDiff{0}, ans{0};

    set<int> st(nums1.begin(), nums1.end());

    for (int i = 0; i < nums1.size(); ++i) {
      diff = abs(nums1[i] - nums2[i]);

      ans = ans % 1000000007 + diff;

      if (diff > maxDiff) {
        auto it = st.lower_bound(nums2[i]);

        if (it != st.end()) {
          maxDiff = max(maxDiff, diff - abs(*it - nums2[i]));
        }

        if (it != st.begin()) {
          maxDiff = max(maxDiff, diff - abs(*prev(it) - nums2[i]));
        }
      }
    }

    return (ans - maxDiff) % 1000000007;
  }
};
// Runtime: 228 ms, faster than 77.33%
// Memory Usage: 111.2 MB, less than 33.86%