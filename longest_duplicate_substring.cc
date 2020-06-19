class Solution {
 public:
  string longestDupSubstring(string S) {
    int n = S.size();

    string ans;
    for (int i = n - 1; n >= 1; --i) {
      unordered_set<string> st;
      for (int j = 0; j + i <= n; ++j) {
        string sub = S.substr(j, i);
        if (st.count(sub) > 0) {
          return sub;
        } else {
          st.insert(sub);
        }
      }
    }

    return "";
  }
};
// Time Limit Exceeded

class Solution {
 public:
  string longestDupSubstring(string S) {
    int n = S.size();

    string ans;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
      int mid = (i + j) / 2;
      unordered_set<string> st;

      bool dup = false;
      for (int j = 0; j + mid <= n; ++j) {
        string sub = S.substr(j, mid);
        if (st.count(sub) > 0) {
          ans = sub;
          i = mid + 1;

          dup = true;

          break;
        } else {
          st.insert(sub);
        }
      }

      if (!dup) {
        j = mid - 1;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  vector<int> power;
  const int prime = 19260817;

  string dupString(string& s, int len) {
    if (len == 0)
      return "";

    long long hash = 0;

    for (int i = 0; i < len; ++i) {
      hash = ((hash * 26) % prime + (s[i] - 'a')) % prime;
    }

    unordered_map<int, vector<int>> mp;
    mp[hash] = vector<int>(1, 0);

    for (int i = len; i < s.size(); ++i) {
      hash -= (power[len - 1] * (s[i - len] - 'a')) % prime;
      hash += prime;
      hash %= prime;

      hash = (hash * 26 + (s[i] - 'a')) % prime;

      if (mp.find(hash) == mp.end()) {
        mp[hash] = vector<int>(1, i - len + 1);
      } else {
        for (auto idx : mp[hash]) {
          if (strcmp((s.substr(idx, len)).data(),
                     s.substr(i - len + 1, len).data()) == 0) {
            return s.substr(idx, len);
          }
        }
        mp[hash].push_back(i - len + 1);
      }
    }

    return "";
  }

 public:
  string longestDupSubstring(string S) {
    int n = S.length();

    string ans;

    power = vector<int>(n, 1);

    for (int i = 1; i < n; ++i) {
      power[i] = (power[i - 1] * 26) % prime;
    }

    int i = 0;
    int j = n;

    while (i <= j) {
      int mid = i + (j - i) / 2;

      string t = dupString(S, mid);
      // string t = validate(mid, S);

      if (t.length() == 0) {
        j = mid - 1;
      } else {
        ans = t;
        i = mid + 1;
      }
    }

    return ans;
  }
};
// Runtime: 2704 ms, faster than 34.41%
// Memory Usage: 438.5 MB, less than 16.14%