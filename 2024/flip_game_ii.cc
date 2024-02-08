class Solution {
  bool gameover(const string& s) {
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '+' && s[i - 1] == '+')
        return false;
    }
    return true;
  }

 public:
  bool canWin(string currentState) {
    function<bool(string, bool)> dfs = [&](string s, bool myTurn) -> bool {
      if (gameover(s)) {
        return myTurn ? false : true;
      }

      for (int j = 1; j < s.size(); ++j) {
        if (s[j] == '+' && s[j - 1] == '+') {
          s[j] = '-';
          s[j - 1] = '-';

          bool ret = dfs(s, !myTurn);
          if (ret) {
            if (myTurn)
              return true;
          } else {
            if (!myTurn)
              return false;
          }

          s[j] = '+';
          s[j - 1] = '+';
        }
      }

      return myTurn ? false : true;
    };

    return dfs(currentState, true);
  }
};
// 255 ms
// 50.22 MB