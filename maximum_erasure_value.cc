class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int ans = 0;

    unordered_set<int> st;

    for (int i = 0, j = 0, sum = 0; i < nums.size(); ++i) {
      sum += nums[i];

      if (!st.count(nums[i])) {
        st.insert(nums[i]);
      } else {
        while (nums[j] != nums[i]) {
          sum -= nums[j];
          st.erase(nums[j++]);
        }

        sum -= nums[j++];
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// Runtime: 608 ms, faster than 28.57%
// Memory Usage: 114.7 MB, less than 14.29%

class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int n = nums.size();

    vector<int> presum(n);

    presum[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + nums[i];
    }

    int cnt[10001];
    memset(cnt, -1, sizeof(cnt));

    int ans = 0;

    for (int i = 0, j = -1, sum = 0; i < nums.size(); ++i) {
      j = max(j, cnt[nums[i]]);

      sum = presum[i] - (j > -1 ? presum[j] : 0);

      ans = max(ans, sum);

      cnt[nums[i]] = i;
    }

    return ans;
  }
};
// Runtime: 288 ms, faster than 57.14%
// Memory Usage: 93.5 MB, less than 35.71%