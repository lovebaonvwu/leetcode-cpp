class Solution {
 public:
  int minimumOperationsToMakeKPeriodic(string word, int k) {
    unordered_map<string, int> cnt;
    int n = word.size();
    int max_cnt = 0;
    for (int i = 0; i < n; i += k) {
      string s = word.substr(i, k);
      cnt[s] += 1;
      max_cnt = max(max_cnt, cnt[s]);
    }
    return n / k - max_cnt;
  }
};
// 105 ms
// 29.12 MB