class Solution {
 public:
  bool canConvertString(string s, string t, int k) {
    if (s.size() != t.size()) {
      return false;
    }

    unordered_set<int> st;

    for (int i = 0, move = 0; i < s.size(); ++i) {
      if (s[i] == t[i]) {
        continue;
      }

      if (s[i] < t[i]) {
        move = t[i] - s[i];
      } else if (s[i] > t[i]) {
        move = t[i] + 26 - s[i];
      }

      while (st.count(move)) {
        move += 26;
      }

      if (move > k) {
        return false;
      }
      st.insert(move);
    }

    return true;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool canConvertString(string s, string t, int k) {
    if (s.size() != t.size()) {
      return false;
    }

    unordered_map<int, int> mp;

    for (int i = 0, move = 0; i < s.size(); ++i) {
      if (s[i] == t[i]) {
        continue;
      }

      if (s[i] < t[i]) {
        move = t[i] - s[i];
      } else if (s[i] > t[i]) {
        move = t[i] + 26 - s[i];
      }

      if (mp.count(move % 26)) {
        move = mp[move % 26] + 26;
      }

      if (move > k) {
        return false;
      }

      mp[move % 26] = move;
    }

    return true;
  }
};
// Runtime: 352 ms, faster than 46.21%
// Memory Usage: 18.1 MB, less than 33.62%

class Solution {
 public:
  bool canConvertString(string s, string t, int k) {
    if (s.size() != t.size()) {
      return false;
    }

    int mul[26] = {};

    for (int i = 0, shift = 0; i < s.size(); ++i) {
      shift = t[i] - s[i] + (t[i] >= s[i] ? 0 : 26);

      if (shift != 0 && shift + mul[shift] * 26 > k) {
        return false;
      }

      ++mul[shift];
    }

    return true;
  }
};
// Runtime: 188 ms, faster than 85.61%
// Memory Usage: 17.7 MB, less than 96.89%

class Solution {
 public:
  bool canConvertString(string s, string t, int k) {
    if (s.size() != t.size()) {
      return false;
    }

    unordered_map<int, int> mp;

    for (int i = 0, move = 0; i < s.size(); ++i) {
      if (s[i] == t[i]) {
        continue;
      }

      if (s[i] < t[i]) {
        move = t[i] - s[i];
      } else if (s[i] > t[i]) {
        move = t[i] + 26 - s[i];
      }

      if (mp.count(move)) {
        move = mp[move] + 26;
      }

      if (move > k) {
        return false;
      }

      mp[move % 26] = move;
    }

    return true;
  }
};
// Runtime: 356 ms, faster than 45.07%
// Memory Usage: 18.1 MB, less than 30.46%