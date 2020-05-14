class Solution {
 public:
  string largestMultipleOfThree(vector<int>& digits) {
    vector<int> cnt(10);

    int sum = 0;
    for (auto d : digits) {
      sum += d;
      ++cnt[d];
    }

    vector<int> mod1 = {1, 4, 7, 2, 5, 8};
    vector<int> mod2 = {2, 5, 8, 1, 4, 7};

    while (sum % 3) {
      for (auto d : sum % 3 == 1 ? mod1 : mod2) {
        if (cnt[d]) {
          --cnt[d];
          sum -= d;
          break;
        }
      }
    }

    string ans;
    for (int i = 9; i >= 0; --i) {
      ans += string(cnt[i], i + '0');
    }

    return ans.size() && ans[0] == '0' ? "0" : ans;
  }
};
// Runtime: 24 ms, faster than 52.67%
// Memory Usage: 13.2 MB, less than 100.00%