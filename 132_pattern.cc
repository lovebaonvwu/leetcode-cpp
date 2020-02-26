class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    stack<int> stk;
    int ak = INT_MIN;

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < ak) {
        return true;
      }

      while (!stk.empty() && nums[i] > stk.top()) {
        ak = stk.top();
        stk.pop();
      }

      stk.push(nums[i]);
    }

    return false;
  }
};
// Runtime: 24 ms, faster than 83.01%
// Memory Usage: 10.6 MB, less than 50.00%

class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    vector<int> mini = nums;

    size_t n = nums.size();
    for (int i = 1; i < n; ++i) {
      mini[i] = min(mini[i], mini[i - 1]);
    }

    set<int> st;
    for (int i = n - 1; i > 0; --i) {
      auto ak = st.upper_bound(mini[i - 1]);
      if (ak != st.end() && *ak < nums[i]) {
        return true;
      }

      st.insert(nums[i]);
    }

    return false;
  }
};
// Runtime: 40 ms, faster than 38.10%
// Memory Usage: 12.4 MB, less than 25.00%