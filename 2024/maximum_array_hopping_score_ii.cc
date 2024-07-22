class Solution {
 public:
  long long maxScore(vector<int>& nums) {
    stack<int> stk;
    int n = nums.size();
    stk.push(n - 1);
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] > nums[stk.top()]) {
        stk.push(i);
      }
    }

    long long ans = 0;
    int prev = 0;
    while (!stk.empty()) {
      int next = stk.top();
      stk.pop();
      ans += 1LL * nums[next] * (next - prev);
      prev = next;
    }

    return ans;
  }
};
// 139 ms
// 121.23 MB
