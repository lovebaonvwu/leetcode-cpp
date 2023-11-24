class Solution {
 public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;

    int n = nums1.size();

    for (int i = 0; i < n; ++i) {
      int lo = 0;
      int hi = nums2.size() - 1;

      while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (nums2[mid] < nums1[i]) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      if (hi < 0) {
        continue;
      }

      if (lo > nums2.size() - 1 && nums2[lo - 1] < nums1[i]) {
        continue;
      }

      ans = max(ans, hi - i);
    }

    return ans;
  }
};
// Runtime: 208 ms, faster than 38.83%
// Memory Usage: 98.5 MB, less than 10.26%

class Solution {
 public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;

    int n = nums1.size();

    for (int i = 0; i < n; ++i) {
      int lo = 0;
      int hi = nums2.size() - 1;

      while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (nums2[mid] < nums1[i]) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      if (hi < 0) {
        continue;
      }

      ans = max(ans, hi - i);
    }

    return ans;
  }
};
// Runtime: 180 ms, faster than 54.52%
// Memory Usage: 98.5 MB, less than 51.42%

class Solution {
 public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0, i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] > nums2[j]) {
        ++i;
      } else {
        ans = max(ans, j++ - i);
      }
    }

    return ans;
  }
};
// Runtime: 180 ms, faster than 54.52%
// Memory Usage: 98.5 MB, less than 51.42%