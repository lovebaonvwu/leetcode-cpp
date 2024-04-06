class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    unordered_map<int, vector<int>> mp;
    long long ans = LONG_MIN;
    bool find = false;
    for (int i = 0; i < n; ++i) {
      int t1 = nums[i] + k;
      int t2 = nums[i] - k;
      if (mp.find(t1) != mp.end()) {
        find = true;
        for (auto j : mp[t1]) {
          ans = max(ans, prefix[i + 1] - prefix[j]);
        }
      }

      if (mp.find(t2) != mp.end()) {
        find = true;
        for (auto j : mp[t2]) {
          ans = max(ans, prefix[i + 1] - prefix[j]);
        }
      }

      mp[nums[i]].push_back(i);
    }

    return find ? ans : 0;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    unordered_map<int, int> mp;
    long long ans = LONG_MIN;
    for (int i = 0; i < n; ++i) {
      int t1 = nums[i] + k;
      int t2 = nums[i] - k;
      if (mp.find(t1) != mp.end()) {
        ans = max(ans, prefix[i + 1] - prefix[mp[t1]]);
      }

      if (mp.find(t2) != mp.end()) {
        ans = max(ans, prefix[i + 1] - prefix[mp[t2]]);
      }

      if (mp.find(nums[i]) == mp.end() || prefix[i] - prefix[mp[nums[i]]] < 0) {
        mp[nums[i]] = i;
      }
    }

    return ans == LONG_MIN ? 0 : ans;
  }
};
// 284 ms
// 141.12 MB