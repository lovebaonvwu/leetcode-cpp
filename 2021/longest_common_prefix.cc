class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int strs_size = strs.size();

    if (!strs_size) {
      return "";
    }

    string ans = "";

    int min_string_len = strs[0].length();

    for (string& s : strs) {
      int len = s.length();
      min_string_len = len < min_string_len ? len : min_string_len;
    }

    for (int i = 0; i < min_string_len; ++i) {
      for (int j = 1; j < strs_size; j++) {
        if (strs[j][i] != strs[0][i]) {
          return ans;
        }
      }

      ans += strs[0][i];
    }

    return ans;
  }
};  // 8ms

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size() || !strs[0].length()) {
      return "";
    }

    string ans = "";
    bool stop = false;
    char c;

    for (int i = 0; i < strs[0].length(); ++i) {
      c = strs[0][i];

      for (string s : strs) {
        if (s[i] != c) {
          stop = true;
        }
      }

      if (stop) {
        break;
      }

      ans.push_back(c);
    }

    return ans;
  }
};  // 12ms

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size() || !strs[0].length()) {
      return "";
    }

    string ans = "";
    char c;

    int min_string_len = strs[0].length();

    for (string& s : strs) {
      int len = s.length();
      min_string_len = len < min_string_len ? len : min_string_len;
    }

    for (int i = 0; i < min_string_len; ++i) {
      c = strs[0][i];

      for (string s : strs) {
        if (s[i] != c) {
          return ans;
        }
      }

      ans.push_back(c);
    }

    return ans;
  }
};  // 16ms