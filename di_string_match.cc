class Solution {
 public:
  vector<int> diStringMatch(string S) {
    vector<int> ans;

    int l = 0;
    int r = S.size();

    for (const auto& ch : S) {
      ch == 'I' ? ans.push_back(l++) : ans.push_back(r--);
    }

    ans.push_back(l);

    return ans;
  }
};
// Runtime: 36 ms, faster than 96.84%
// Memory Usage: 10.6 MB, less than 7.14%