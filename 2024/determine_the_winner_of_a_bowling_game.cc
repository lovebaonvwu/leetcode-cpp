class Solution {
 public:
  int isWinner(vector<int>& player1, vector<int>& player2) {
    function<int(const vector<int>&)> score =
        [&](const vector<int>& player) -> int {
      int ret = 0;
      for (int i = 0; i < player.size(); ++i) {
        if (i > 1 && (player[i - 1] == 10 || player[i - 2] == 10)) {
          ret += player[i] * 2;
        } else if (i > 0 && player[i - 1] == 10) {
          ret += player[i] * 2;
        } else {
          ret += player[i];
        }
      }

      return ret;
    };

    int score1 = score(player1);
    int score2 = score(player2);

    return score1 == score2 ? 0 : (score1 > score2 ? 1 : 2);
  }
};
// 24ms
// 75.65MB