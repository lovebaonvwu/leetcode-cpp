class Solution {
 public:
  long long numberOfSubarrays(vector<int>& nums) {
    unordered_map<int, long long> cnt;
    long long ans = 0;

    nums.push_back(1e9 + 7);

    int n = nums.size();

    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && nums[i] > nums[stk.top()]) {
        int prevSmaller = nums[stk.top()];
        stk.pop();
        ans += (1 + cnt[prevSmaller]) * cnt[prevSmaller] / 2;
        cnt[prevSmaller] = 0;
      }

      stk.push(i);
      ++cnt[nums[i]];
    }

    return ans;
  }
};