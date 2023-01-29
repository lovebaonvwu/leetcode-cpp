class Solution {
  unordered_map<string, bool> memo;

  string getKey(vector<int>& piles) {
    string key;
    for (auto p : piles) {
      key += p - '0';
    }

    return key;
  }

 public:
  bool nimGame(vector<int>& piles) {
    int cnt = 0;
    for (auto p : piles) {
      cnt += p;
    }

    return ifNextPlayerWin(piles, cnt);
  }

  bool ifNextPlayerWin(vector<int>& piles, int cnt) {
    if (cnt == 0) {
      return false;
    }

    string key = getKey(piles);

    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    for (int i = 0; i < piles.size(); ++i) {
      for (int j = 1; j <= piles[i]; ++j) {
        piles[i] -= j;

        vector<int> tmp = piles;
        sort(tmp.begin(), tmp.end());
        if (!ifNextPlayerWin(tmp, cnt - j)) {
          return memo[key] = true;
        }

        piles[i] += j;
      }
    }

    return memo[key] = false;
  }
};
// Runtime 103 ms
// Memory 20.7 MB
// 2023.1.29 at 奥盛大厦