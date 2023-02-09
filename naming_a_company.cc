class Solution {
 public:
  long long distinctNames(vector<string>& ideas) {
    unordered_set<string> names[26] = {};

    for (auto& idea : ideas) {
      names[idea[0] - 'a'].insert(idea.substr(1));
    }

    long long ans = 0LL;
    for (int i = 0; i < 26; ++i) {
      for (int j = i + 1; j < 26; ++j) {
        long long cnt1 = 0LL, cnt2 = 0LL;
        for (auto& suffix : names[i]) {
          if (!names[j].count(suffix)) {
            ++cnt1;
          }
        }
        for (auto& suffix : names[j]) {
          if (!names[i].count(suffix)) {
            ++cnt2;
          }
        }

        ans += cnt1 * cnt2;
      }
    }

    return ans * 2;
  }
};
// Runtime 674 ms
// Memory 83.4 MB
// 2023.2.8 at 聊城市东昌路怡莱酒店