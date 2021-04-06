class Solution {
 public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> mp;

    for (auto& k : knowledge) {
      mp[k[0]] = k[1];
    }

    string ans, key;
    bool openBracket = false;

    for (auto c : s) {
      if (isalpha(c)) {
        if (openBracket) {
          key += c;
        } else {
          ans += c;
        }
      } else if (c == '(') {
        openBracket = true;
      } else {
        openBracket = false;

        if (mp.find(key) != mp.end()) {
          ans += mp[key];
        } else {
          ans += '?';
        }

        key = "";
      }
    }

    return ans;
  }
};
// Runtime: 344 ms, faster than 77.59%
// Memory Usage: 117.3 MB, less than 57.02%

class Solution {
 public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> mp;

    for (auto& k : knowledge) {
      mp[k[0]] = k[1];
    }

    vector<string> tmp(1);

    for (auto c : s) {
      if (c == '(') {
        tmp.push_back("");
      } else if (c == ')') {
        string stringToAppend;

        if (mp.find(tmp.back()) != mp.end()) {
          stringToAppend = mp[tmp.back()];

        } else {
          stringToAppend = '?';
        }
        tmp.pop_back();
        tmp.back() += stringToAppend;
      } else {
        tmp.back() += c;
      }
    }

    return tmp.front();
  }
};
// Runtime: 320 ms, faster than 94.13%
// Memory Usage: 117.5 MB, less than 43.05%