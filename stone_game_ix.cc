class Solution {
 public:
  bool stoneGameIX(vector<int>& stones) {
    vector<int> cnt(3);
    for (auto n : stones) {
      ++cnt[n % 3];
    }

    auto tmp = cnt;
    if (tmp[1] > 0) {
      --tmp[1];
      if (!win(tmp, 1, 1)) {
        return true;
      }
    }

    tmp = cnt;
    if (tmp[2] > 0) {
      --tmp[2];
      if (!win(tmp, 2, 1)) {
        return true;
      }
    }

    return false;
  }

  bool win(vector<int>& cnt, int sum, int turn) {
    if (cnt[0] + cnt[1] + cnt[2] == 0) {
      if (turn) {
        return true;
      } else {
        return false;
      }
    }

    if (cnt[0] > 0) {
      --cnt[0];
      return !win(cnt, sum, 1 - turn);
    } else if (sum % 3 == 1) {
      if (cnt[1] > 0) {
        --cnt[1];
        return !win(cnt, sum + 1, 1 - turn);
      } else {
        return false;
      }
    } else {
      if (cnt[2] > 0) {
        --cnt[2];
        return !win(cnt, sum + 2, 1 - turn);
      } else {
        return false;
      }
    }
  }
};
// Runtime: 200 ms, faster than 65.22%
// Memory Usage: 135.2 MB, less than 7.06%
// 2022.1.22 at 茗筑美嘉