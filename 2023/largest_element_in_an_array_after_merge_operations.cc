class Solution {
 public:
  long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    stack<long long> stk;
    long long ans = 0;

    for (int i = n - 1; i >= 0; --i) {
      long long cur = nums[i];
      while (!stk.empty() && cur <= stk.top()) {
        long long prev = stk.top();
        stk.pop();

        cur += prev;
      }
      stk.push(cur);
      ans = max(ans, stk.top());
    }

    return ans;
  }
};
// 225 ms
// 106.1 MB

class Solution {
 public:
  long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    long long prev = nums.back();
    long long ans = nums.back();

    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] <= prev) {
        prev += nums[i];
      } else {
        prev = nums[i];
      }

      ans = max(ans, prev);
    }

    return ans;
  }
};
// 204ms
// 105.27mb