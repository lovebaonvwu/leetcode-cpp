class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    int n = spaces.size();

    string app = string(n, ' ');
    s = app + s;

    for (int i = 0, j = i + n, k = 0; j < s.size();) {
      if (i < spaces[k]) {
        swap(s[i++], s[j++]);
        continue;
      }

      if (++k == n) {
        break;
      }

      spaces[k] += k;
      ++i;
    }

    return s;
  }
};
// Runtime: 160 ms, faster than 62.50%
// Memory Usage: 79 MB, less than 100.00%
// 2021.12.20 at 奥盛大厦

class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    string ans(s.size() + spaces.size(), ' ');

    for (int i = 0, k = 0; i < s.size(); ++i) {
      if (k < spaces.size() && i == spaces[k]) {
        ++k;
      }

      ans[i + k] = s[i];
    }

    return ans;
  }
};
// Runtime: 152 ms, faster than 100.00%
// Memory Usage: 77.8 MB, less than 100.00%
// 2021.12.20 at 奥盛大厦