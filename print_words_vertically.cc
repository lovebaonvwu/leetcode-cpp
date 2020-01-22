class Solution {
 public:
  vector<string> printVertically(string s) {
    istringstream iss(s);

    vector<string> words;

    int len = 0;
    while (iss) {
      string val;
      iss >> val;
      len = max(len, (int)val.size());

      if (val.size() > 0) {
        words.push_back(val);
      }
    }

    vector<string> ans;

    for (int i = 0; i < len; ++i) {
      string a;
      for (auto& word : words) {
        if (i < word.size()) {
          a.append(1, word[i]);
        } else {
          a.append(1, ' ');
        }
      }
      int j = a.size() - 1;

      while (a[j] == ' ')
        --j;

      ans.push_back(a.substr(0, j + 1));
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.4 MB, less than 100.00%

class Solution {
 public:
  vector<string> printVertically(string s) {
    istringstream iss(s);

    vector<string> words;

    int len = 0;
    string val;
    while (iss >> val) {
      len = max(len, (int)val.size());
      words.push_back(val);
    }

    vector<string> ans;

    for (int i = 0; i < len; ++i) {
      string a;
      for (auto& word : words) {
        if (i < word.size()) {
          a.append(1, word[i]);
        } else {
          a.append(1, ' ');
        }
      }
      int j = a.size() - 1;

      while (a[j] == ' ')
        --j;

      ans.push_back(a.substr(0, j + 1));
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 58.62%
// Memory Usage: 8.6 MB, less than 100.00%