class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;

    for (int i = 0, prev = 0; i < target.size(); prev = target[i++]) {
      for (int j = 1; j < target[i] - prev; ++j) {
        ans.push_back("Push");
        ans.push_back("Pop");
      }
      ans.push_back("Push");
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8 MB, less than 100.00%