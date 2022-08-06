class Solution {
 public:
  string bestHand(vector<int>& ranks, vector<char>& suits) {
    int suit[5] = {0};
    int rank[14] = {0};

    for (int i = 0; i < ranks.size(); ++i) {
      ++suit[suits[i] - 'a'];
      ++rank[ranks[i]];
    }

    for (auto s : suit) {
      if (s == 5) {
        return "Flush";
      }
    }

    int cnt = 0;
    for (auto r : rank) {
      cnt = max(cnt, r);
    }

    if (cnt >= 3) {
      return "Three of a Kind";
    } else if (cnt == 2) {
      return "Pair";
    }

    return "High Card";
  }
};
// Runtime: 3 ms, faster than 61.50%
// Memory Usage: 10.2 MB, less than 48.53%
// 2022.8.6 at 茗筑美嘉