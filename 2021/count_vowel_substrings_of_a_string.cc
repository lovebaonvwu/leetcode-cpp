class Solution {
  bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  int countVowelSubstrings(string word) {
    int ans = 0;
    unordered_set<char> st;

    for (int i = 0; i < word.size(); ++i) {
      for (int j = i; j < word.size(); ++j) {
        if (!isVowel(word[j])) {
          break;
        }

        st.insert(word[j]);

        if (st.size() == 5) {
          ++ans;
        }
      }

      st.clear();
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 54.45%
// Memory Usage: 6.9 MB, less than 55.54%
// 2021.12.9 at 奥盛大厦

class Solution {
  bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  int countVowelSubstrings(string word) {
    int ans = 0;
    unordered_set<char> st;

    for (int i = 0; i < word.size(); ++i) {
      for (int j = i; j >= 0; --j) {
        if (!isVowel(word[j])) {
          break;
        }

        st.insert(word[j]);

        if (st.size() == 5) {
          ++ans;
        }
      }

      st.clear();
    }

    return ans;
  }
};
// Runtime: 10 ms, faster than 55.91%
// Memory Usage: 7.1 MB, less than 54.98%
// 2021.12.9 at 奥盛大厦
