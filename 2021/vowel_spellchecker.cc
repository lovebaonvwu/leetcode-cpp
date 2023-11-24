class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> st(wordlist.begin(), wordlist.end());

    unordered_map<string, int> mp_cap;
    unordered_map<string, int> mp_err;
    for (int i = wordlist.size() - 1; i >= 0; --i) {
      string s_cap = "";
      string s_err = "";

      for (auto c : wordlist[i]) {
        s_cap += tolower(c);

        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
            c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u') {
          s_err += '*';
        } else {
          s_err += tolower(c);
        }
      }

      mp_cap[s_cap] = i;
      mp_err[s_err] = i;
    }

    vector<string> ans;

    for (auto& q : queries) {
      if (st.count(q)) {
        ans.push_back(q);
      } else {
        string s_cap = "";
        string s_err = "";

        for (auto c : q) {
          s_cap += tolower(c);

          if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
              c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u') {
            s_err += '*';
          } else {
            s_err += tolower(c);
          }
        }

        if (mp_cap.find(s_cap) != mp_cap.end()) {
          ans.push_back(wordlist[mp_cap[s_cap]]);
        } else if (mp_err.find(s_err) != mp_err.end()) {
          ans.push_back(wordlist[mp_err[s_err]]);
        } else {
          ans.push_back("");
        }
      }
    }

    return ans;
  }
};
// Runtime: 68 ms, faster than 97.48%
// Memory Usage: 29.5 MB, less than 100.00%

class Solution {
  void tolower_string(string& ori, string& s_cap, string& s_err) {
    for (int i = 0; i < ori.size(); ++i) {
      s_cap[i] = tolower(ori[i]);
      s_err[i] = tolower(ori[i]);

      if (s_err[i] == 'a' || s_err[i] == 'e' || s_err[i] == 'i' ||
          s_err[i] == 'o' || s_err[i] == 'u') {
        s_err[i] = '*';
      }
    }
  }

 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> st(wordlist.begin(), wordlist.end());

    unordered_map<string, int> mp_cap;
    unordered_map<string, int> mp_err;
    for (int i = wordlist.size() - 1; i >= 0; --i) {
      string s_cap = wordlist[i];
      string s_err = wordlist[i];

      tolower_string(wordlist[i], s_cap, s_err);

      mp_cap[s_cap] = i;
      mp_err[s_err] = i;
    }

    vector<string> ans;

    for (auto& q : queries) {
      if (st.count(q)) {
        ans.push_back(q);
      } else {
        string s_cap = q;
        string s_err = q;

        tolower_string(q, s_cap, s_err);

        if (mp_cap.find(s_cap) != mp_cap.end()) {
          ans.push_back(wordlist[mp_cap[s_cap]]);
        } else if (mp_err.find(s_err) != mp_err.end()) {
          ans.push_back(wordlist[mp_err[s_err]]);
        } else {
          ans.push_back("");
        }
      }
    }

    return ans;
  }
};
// Runtime: 80 ms, faster than 82.07%
// Memory Usage: 29.4 MB, less than 100.00%

class Solution {
  void tolower_string(string& ori, string& s_cap, string& s_err) {
    for (auto c : ori) {
      s_cap += tolower(c);

      if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
          c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u') {
        s_err += '*';
      } else {
        s_err += tolower(c);
      }
    }
  }

 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> st(wordlist.begin(), wordlist.end());

    unordered_map<string, int> mp_cap;
    unordered_map<string, int> mp_err;
    for (int i = wordlist.size() - 1; i >= 0; --i) {
      string s_cap = "";
      string s_err = "";

      tolower_string(wordlist[i], s_cap, s_err);

      mp_cap[s_cap] = i;
      mp_err[s_err] = i;
    }

    vector<string> ans;

    for (auto& q : queries) {
      if (st.count(q)) {
        ans.push_back(q);
      } else {
        string s_cap = "";
        string s_err = "";

        tolower_string(q, s_cap, s_err);

        if (mp_cap.find(s_cap) != mp_cap.end()) {
          ans.push_back(wordlist[mp_cap[s_cap]]);
        } else if (mp_err.find(s_err) != mp_err.end()) {
          ans.push_back(wordlist[mp_err[s_err]]);
        } else {
          ans.push_back("");
        }
      }
    }

    return ans;
  }
};
// Runtime: 84 ms, faster than 70.31%
// Memory Usage: 29.3 MB, less than 100.00%