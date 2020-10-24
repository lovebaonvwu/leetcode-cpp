class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int P) {
    int i = 0;
    int j = tokens.size() - 1;
    int scores = 0;

    sort(tokens.begin(), tokens.end());

    int ans = 0;
    while (i <= j) {
      if (P >= tokens[i]) {
        P -= tokens[i++];
        ans = max(ans, ++scores);
      } else if (scores > 0) {
        --scores;
        P += tokens[j--];
      } else {
        break;
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 84.96%
// Memory Usage: 11.1 MB, less than 99.21%