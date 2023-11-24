class Solution {
 public:
  bool equalFrequency(string word) {
    int cnt[26] = {0};
    for (auto c : word) {
      ++cnt[c - 'a'];
    }

    map<int, int> mp;

    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0) {
        ++mp[cnt[i]];
      }
    }

    if (mp.size() == 1) {
      if (mp.begin()->first == 1) {
        return true;
      }

      if (mp.begin()->second == 1) {
        return true;
      }
    } else if (mp.size() == 2) {
      if (mp.begin()->first == 1 && mp.begin()->second == 1) {
        return true;
      }

      if (mp.begin()->first + 1 == next(mp.begin())->first &&
          next(mp.begin())->second == 1) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 3 ms, faster than 58.68%
// Memory Usage: 6.3 MB, less than 53.77%
// 2022.10.7 at 茗筑美嘉