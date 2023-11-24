class Solution {
 public:
  string capitalizeTitle(string title) {
    for (int i = 0, j = 0; i < title.size(); ++i, ++j) {
      while (j < title.size() && title[j] != ' ') {
        ++j;
      }

      if (j - i <= 2) {
        while (i < j) {
          title[i] = tolower(title[i]);
          ++i;
        }
      } else {
        title[i] = toupper(title[i]);
        ++i;
        while (i < j) {
          title[i] = tolower(title[i]);
          ++i;
        }
      }
    }

    return title;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 80.08%
// 2022.1.15 at 茗筑美嘉

class Solution {
 public:
  string capitalizeTitle(string title) {
    for (int i = 0, j = 0; j <= title.size(); ++j) {
      if (j == title.size() || title[j] == ' ') {
        if (j - i > 2) {
          title[i] = toupper(title[i]);
        }
        i = j + 1;
      } else {
        title[j] = tolower(title[j]);
      }
    }

    return title;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 80.08%
// 2022.1.15 at 茗筑美嘉