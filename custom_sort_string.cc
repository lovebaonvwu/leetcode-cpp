class Solution {
 public:
  string customSortString(string S, string T) {
    int mp[26];
    memset(mp, -1, sizeof(mp));

    for (int i = 0; i < S.size(); ++i) {
      mp[S[i] - 'a'] = i;
    }

    vector<string> cnt(26, "");

    string t{""};
    for (char ch : T) {
      if (mp[ch - 'a'] < 0) {
        t += ch;
      } else {
        cnt[mp[ch - 'a']].append(1, ch);
      }
    }

    string ans;
    for (int i = 0; i < cnt.size(); ++i) {
      if (!cnt[i].empty()) {
        ans.append(cnt[i]);
      }
    }

    return ans.append(t);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.8 MB, less than 100.00%

class Solution {
 public:
  string customSortString(string S, string T) {
    int mp[26];
    memset(mp, -1, sizeof(mp));

    for (int i = 0; i < S.size(); ++i) {
      mp[S[i] - 'a'] = i;
    }

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    string t{""};
    for (char ch : T) {
      if (mp[ch - 'a'] < 0) {
        t += ch;
      } else {
        ++cnt[mp[ch - 'a']];
      }
    }

    string ans;
    for (auto ch : S) {
      int n = cnt[mp[ch - 'a']];
      if (n > 0) {
        ans.append(n, ch);
      }
    }

    return ans.append(t);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.4 MB, less than 100.00%

class Solution {
 public:
  string customSortString(string S, string T) {
    int mp[26];
    memset(mp, -1, sizeof(mp));

    for (int i = 0; i < S.size(); ++i) {
      mp[S[i] - 'a'] = i;
    }

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    string t{""};
    for (char ch : T) {
      if (mp[ch - 'a'] < 0) {
        t += ch;
      } else {
        ++cnt[mp[ch - 'a']];
      }
    }

    string ans;
    for (int i = 0; i < S.size(); ++i) {
      if (cnt[i] > 0) {
        ans.append(cnt[i], S[i]);
      }
    }

    return ans.append(t);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.6 MB, less than 100.00%