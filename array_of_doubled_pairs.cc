class Solution {
 public:
  bool canReorderDoubled(vector<int>& A) {
    map<int, int> mp;

    for (auto n : A) {
      ++mp[n];
    }

    for (auto m : mp) {
      while (m.second-- > 0) {
        if (m.first < 0) {
          if (mp[m.first / 2]-- < 1) {
            return false;
          }
        } else {
          if (mp[m.first * 2]-- < 1) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
// Runtime: 216 ms, faster than 13.30%
// Memory Usage: 12.4 MB, less than 100.00%

class Solution {
 public:
  bool canReorderDoubled(vector<int>& A) {
    unordered_map<int, int> mp;

    for (auto n : A) {
      ++mp[n];
    }

    vector<int> keys;

    for (auto it : mp) {
      keys.push_back(it.first);
    }

    sort(keys.begin(), keys.end(),
         [](int a, int b) { return abs(a) < abs(b); });

    for (auto n : keys) {
      if (mp[n] > mp[2 * n]) {
        return false;
      }

      mp[2 * n] -= mp[n];
    }

    return true;
  }
};
// Runtime: 100 ms, faster than 70.59%
// Memory Usage: 12.7 MB, less than 100.00%

class Solution {
 public:
  bool canReorderDoubled(vector<int>& A) {
    map<int, int> mp;

    for (auto n : A) {
      ++mp[n];
    }

    for (auto it : mp) {
      if (it.second < 1) {
        continue;
      }

      if (it.first < 0) {
        if (it.second > mp[it.first / 2]) {
          return false;
        }

        mp[it.first / 2] -= it.second;
      } else {
        if (it.second > mp[it.first * 2]) {
          return false;
        }

        mp[it.first * 2] -= it.second;
      }
    }

    return true;
  }
};
// Runtime: 132 ms, faster than 49.36%
// Memory Usage: 12.3 MB, less than 100.00%