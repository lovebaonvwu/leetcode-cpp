class Solution {
 public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int ans = 0;
    for (int i = 0, j = n - n / 2; j < n; ++j) {
      if (nums[i] * 2 <= nums[j]) {
        ++i;
        ++ans;
      }
    }

    return ans * 2;
  }
};
// Runtime 171 ms
// Memory 60.2 MB

class Solution {
 public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int lo = 0, hi = n / 2;

    while (lo < hi) {
      int md = (lo + hi + 1) / 2;

      int i = 0;
      for (; i < md; ++i) {
        if (nums[i] * 2 > nums[n - md + i]) {
          break;
        }
      }

      if (i < md) {
        hi = md - 1;
      } else {
        lo = md;
      }
    }

    return lo * 2;
  }
};
// Runtime 195 ms
// Memory 60.1 MB