class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    int n = nums.size();
    long long ans = 0;
    for (int i = 0, j = 0, cnt = 0; j < n; ++j) {
      ++mp[nums[j]];

      cnt += mp[nums[j]] - 1;

      while (i < j && cnt >= k) {
        ans += n - j;
        --mp[nums[i]];
        cnt -= mp[nums[i]];
        ++i;
      }
    }

    return ans;
  }
};
// Runtime 210 ms
// Memory 75.2 MB

class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    int n = nums.size();
    long long ans = 0;
    for (int i = 0, j = 0, cnt = 0; j < n; ++j) {
      ++mp[nums[j]];

      cnt += mp[nums[j]] - 1;

      while (i < j && cnt >= k) {
        ans += n - j;
        cnt -= mp[nums[i]] - 1;
        --mp[nums[i]];
        ++i;
      }
    }

    return ans;
  }
};
// Runtime 225 ms
// Memory 75.3 MB