class Solution {
 public:
  bool detectCapitalUse(string word) {
    int cnt = 0;

    for (char& c : word) {
      if (isupper(c)) {
        ++cnt;
      }
    }

    return cnt == 0 || cnt == word.size() || cnt == 1 && isupper(word.front());
  }
};  // 4ms

class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (word.size() < 2) {
      return true;
    }

    bool first_upper = isupper(word[0]) ? true : false;
    bool second_upper = isupper(word[1]) ? true : false;

    if (!first_upper && second_upper) {
      return false;
    }

    for (int i = 2; i < word.size(); ++i) {
      if (islower(word[i]) && first_upper && second_upper) {
        return false;
      } else if (isupper(word[i]) && !second_upper) {
        return false;
      }
    }

    return true;
  }
};  // 4ms