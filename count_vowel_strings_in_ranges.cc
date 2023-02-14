class Solution {
  bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> presum(n + 1);

    for (int i = 1; i <= n; ++i) {
      const char b = words[i - 1][0], e = words[i - 1][words[i - 1].size() - 1];
      presum[i] = (isVowel(b) && isVowel(e)) + presum[i - 1];
    }

    vector<int> ans;
    for (auto& q : queries) {
      ans.push_back(presum[q[1] + 1] - presum[q[0]]);
    }

    return ans;
  }
};
// Runtime 142 ms
// Memory 63.9 MB
// 2023.2.14 at 奥盛大厦