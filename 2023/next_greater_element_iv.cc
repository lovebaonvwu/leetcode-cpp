class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size();
    stack<int> s1, s2, tmp;

    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
      while (!s2.empty() && nums[i] > nums[s2.top()]) {
        ans[s2.top()] = nums[i];
        s2.pop();
      }

      while (!s1.empty() && nums[i] > nums[s1.top()]) {
        tmp.push(s1.top());
        s1.pop();
      }

      while (!tmp.empty()) {
        s2.push(tmp.top());
        tmp.pop();
      }

      s1.push(i);
    }

    return ans;
  }
};
// Runtime 195 ms
// Memory 89.4 MB