class Solution {
 public:
  vector<int> findArray(vector<int>& pref) {
    vector<int> ans(pref.size());

    for (int i = 0, sum = 0; i < pref.size(); ++i) {
      ans[i] = sum ^ pref[i];
      sum ^= ans[i];
    }

    return ans;
  }
};
// Runtime: 276 ms, faster than 25.00%
// Memory Usage: 76 MB, less than 50.00%
// 2022.10.9 at 茗筑美嘉