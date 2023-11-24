class Solution {
 public:
  int numDifferentIntegers(string word) {
    for (auto& c : word) {
      if (isalpha(c)) {
        c = ' ';
      }
    }

    stringstream ss(word);

    string s;

    unordered_set<string> st;

    while (ss >> s) {
      int i = 0;
      while (s[i] == '0') {
        ++i;
      }

      string t = s.substr(i);

      st.insert(t);
    }

    return st.size();
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 92.30%
// 2021.8.12 at 奥盛大厦

class Solution {
 public:
  int numDifferentIntegers(string word) {
    unordered_set<string> st{""};

    for (int i = 0, j = 0; j <= word.size(); ++j) {
      if (j < word.size() && isdigit(word[j])) {
        if (i < j && word[i] == '0') {
          ++i;
        }
      } else {
        st.insert(word.substr(i, j - i));
        i = j + 1;
      }
    }

    return st.size() - 1;
  }
};
// Runtime: 4 ms, faster than 65.35%
// Memory Usage: 6.7 MB, less than 11.55%
// 2021.8.12 at 奥盛大厦