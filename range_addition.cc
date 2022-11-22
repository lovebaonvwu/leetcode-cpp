class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ans(length);

    for (auto& update : updates) {
      int& start = update[0];
      int& end = update[1];
      int& val = update[2];
      ans[start] += val;
      if (end < length - 1) {
        ans[end + 1] -= val;
      }
    }

    for (int i = 0, cur = 0; i < length; ++i) {
      cur += ans[i];
      ans[i] = cur;
    }

    return ans;
  }
};
// Runtime 65 ms
// Memory 16.5 MB
// 2022.11.22 at 茗筑美嘉