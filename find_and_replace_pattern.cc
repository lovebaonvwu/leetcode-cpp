class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;

    for (const string& w : words) {
      if (F(w) == F(pattern)) {
        ans.push_back(w);
      }
    }

    return ans;
  }

  string F(string s) {
    unordered_map<char, int> mp;

    for (auto& ch : s) {
      if (!mp.count(ch)) {
        mp[ch] = mp.size();
      }
    }

    for (int i = 0; i < s.size(); ++i) {
      s[i] = mp[s[i]];
    }

    return s;
  }
};  // 4ms

class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;

    for (const string& w : words) {
      if (w.size() != pattern.size()) {
        continue;
      }

      bool match = true;
      char w2p[26];
      char p2w[26];

      memset(w2p, 0, sizeof(w2p));
      memset(p2w, 0, sizeof(p2w));

      for (int i = 0; i < w.size(); ++i) {
        if ((w2p[w[i] - 'a'] && w2p[w[i] - 'a'] != pattern[i]) ||
            (p2w[pattern[i] - 'a'] && p2w[pattern[i] - 'a'] != w[i])) {
          match = false;
          break;
        }

        w2p[w[i] - 'a'] = pattern[i];
        p2w[pattern[i] - 'a'] = w[i];
      }

      if (match) {
        ans.push_back(w);
      }
    }

    return ans;
  }
};  // 4ms

class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;

    for (const string& w : words) {
      if (w.size() != pattern.size()) {
        continue;
      }

      bool match = true;
      unordered_map<char, char> w2p;
      unordered_map<char, char> p2w;

      for (int i = 0; i < w.size(); ++i) {
        if ((w2p[w[i]] && w2p[w[i]] != pattern[i]) ||
            (p2w[pattern[i]] && p2w[pattern[i]] != w[i])) {
          match = false;
          break;
        }

        w2p[w[i]] = pattern[i];
        p2w[pattern[i]] = w[i];
      }

      if (match) {
        ans.push_back(w);
      }
    }

    return ans;
  }
};  // 8ms