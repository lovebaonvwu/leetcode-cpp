class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, priority_queue<int>> mp;

    for (auto n : nums) {
      int sum = 0;

      int num = n;
      while (n > 0) {
        sum += n % 10;
        n /= 10;
      }

      mp[sum].push(num);
    }

    int ans = -1;
    for (auto& [k, v] : mp) {
      if (v.size() >= 2) {
        int a = v.top();
        v.pop();
        int b = v.top();
        v.pop();

        ans = max(ans, a + b);
      }
    }

    return ans;
  }
};
// Runtime: 209 ms, faster than 100.00%
// Memory Usage: 67.9 MB, less than 100.00%
// 2022.7.18 at 奥盛大厦