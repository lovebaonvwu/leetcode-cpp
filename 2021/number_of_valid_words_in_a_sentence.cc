class Solution {
 public:
  int countValidWords(string sentence) {
    int ans = 0;

    stringstream ss(sentence);
    string word;

    while (ss >> word) {
      if (word[0] == '-' || word.back() == '-') {
        continue;
      }

      bool valid = true;

      for (int i = 0, cnt = 0; i < word.size(); ++i) {
        if (isdigit(word[i])) {
          valid = false;
          break;
        }

        if ((word[i] == '!' || word[i] == '.' || word[i] == ',') &&
            i != word.size() - 1) {
          valid = false;
          break;
        }

        if (word[i] == '-' && !(isalpha(word[i - 1]) && isalpha(word[i + 1]))) {
          valid = false;
          break;
        } else if (word[i] == '-' && ++cnt > 1) {
          valid = false;
          break;
        }
      }

      if (valid) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 27.27%
// Memory Usage: 7.2 MB, less than 13.64%
// 2021.10.24 at 茗筑美嘉