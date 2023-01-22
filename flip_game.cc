class Solution {
 public:
  vector<string> generatePossibleNextMoves(string currentState) {
    vector<string> ans;
    string& s = currentState;
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == '+' && s[i + 1] == '+') {
        s[i] = '-';
        s[i + 1] = '-';
        ans.push_back(currentState);
        s[i] = '+';
        s[i + 1] = '+';
      }
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 7.3 MB
// 2023.1.22 at 茗筑美嘉