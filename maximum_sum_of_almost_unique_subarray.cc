class Solution {
 public:
  long long maxSum(vector<int>& nums, int m, int k) {
    long long sum = accumulate(nums.begin(), nums.begin() + k, 0LL);
    long long ans = 0;
    nums.push_back(-1);
    for (int i = k; i < nums.size(); ++i) {
      unordered_set<int> st(nums.begin() + i - k, nums.begin() + i);
      if (st.size() >= m) {
        ans = max(ans, sum);
      }

      sum += nums[i];
      sum -= nums[i - k];
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long maxSum(vector<int>& nums, int m, int k) {
    unordered_map<long long, long long> mp;
    for (int i = 0; i < k; ++i) {
      ++mp[nums[i]];
    }

    long long sum = accumulate(nums.begin(), nums.begin() + k, 0LL);
    long long ans = 0;
    nums.push_back(-1);
    for (int i = k; i < nums.size(); ++i) {
      if (mp.size() >= m) {
        ans = max(ans, sum);
      }
      sum += nums[i];
      sum -= nums[i - k];
      ++mp[nums[i]];
      --mp[nums[i - k]];
      if (mp[nums[i - k]] == 0) {
        mp.erase(nums[i - k]);
      }
    }

    return ans;
  }
};
// 123ms
// 68.12MB