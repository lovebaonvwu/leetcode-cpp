class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int n = nums.size();

    vector<int> ltor(n);
    vector<int> rtol(n);

    for (int i = 0, cnt1 = 0, cnt2 = 0; i < n; ++i) {
      if (nums[i] == 1) {
        ++cnt1;
      } else {
        ltor[i] = cnt1;
        cnt1 = 0;
      }

      if (nums[n - 1 - i] == 1) {
        ++cnt2;
      } else {
        rtol[n - 1 - i] = cnt2;
        cnt2 = 0;
      }
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        ans = max(ans, ltor[i] + rtol[i]);
      }
    }

    return ans < 0 ? n - 1 : ans;
  }
};
// Runtime: 88 ms, faster than 92.20%
// Memory Usage: 39.8 MB, less than 25.00%

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int n = nums.size();

    vector<int> ltor(n);
    vector<int> rtol(n);

    for (int i = 0, cnt = 0; i < n; ++i) {
      if (nums[i] == 1) {
        ++cnt;
      } else {
        ltor[i] = cnt;
        cnt = 0;
      }
    }

    for (int i = n - 1, cnt = 0; i >= 0; --i) {
      if (nums[i] == 1) {
        ++cnt;
      } else {
        rtol[i] = cnt;
        cnt = 0;
      }
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        ans = max(ans, ltor[i] + rtol[i]);
      }
    }

    return ans < 0 ? n - 1 : ans;
  }
};
// Runtime: 92 ms, faster than 84.79%
// Memory Usage: 39.8 MB, less than 25.00%