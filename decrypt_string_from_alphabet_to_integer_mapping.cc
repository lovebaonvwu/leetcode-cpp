class Solution {
 public:
  string freqAlphabets(string s) {
    string ans{""};

    for (int i = s.size() - 1; i >= 0;) {
      if (s[i] != '#') {
        ans += ('a' + (s[i] - '0' - 1));
        --i;
      } else {
        ans += ('a' + ((s[i - 2] - '0') * 10 + s[i - 1] - '0' - 1));
        i -= 3;
      }
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 100.00%

class Solution {
 public:
  string freqAlphabets(string s) {
    unordered_map<string, char> mp{
        {"26#", 'z'}, {"25#", 'y'}, {"24#", 'x'}, {"23#", 'w'}, {"22#", 'v'},
        {"21#", 'u'}, {"20#", 't'}, {"19#", 's'}, {"18#", 'r'}, {"17#", 'q'},
        {"16#", 'p'}, {"15#", 'o'}, {"14#", 'n'}, {"13#", 'm'}, {"12#", 'l'},
        {"11#", 'k'}, {"10#", 'j'}, {"9", 'i'},   {"8", 'h'},   {"7", 'g'},
        {"6", 'f'},   {"5", 'e'},   {"4", 'd'},   {"3", 'c'},   {"2", 'b'},
        {"1", 'a'}};

    string partial{""};
    string ans{""};

    for (int i = s.size() - 1; i >= 0; --i) {
      partial = s[i] + partial;

      if (mp.find(partial) != mp.end()) {
        ans = mp[partial] + ans;

        partial = "";
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 62.98%
// Memory Usage: 9.6 MB, less than 100.00%