class Solution {
 public:
  string largestMerge(string word1, string word2) {
    string ans;

    int i = 0, j = 0;
    for (; i < word1.size() && j < word2.size();) {
      if (word1[i] > word2[j]) {
        ans += word1[i++];
      } else if (word1[i] < word2[j]) {
        ans += word2[j++];
      } else {
        string w1 = word1.substr(i, word1.size() - i + 1);
        string w2 = word2.substr(j, word2.size() - j + 1);

        if (w1 < w2) {
          ans += word2[j++];
        } else {
          ans += word1[i++];
        }
      }
    }

    while (i < word1.size()) {
      ans += word1[i++];
    }

    while (j < word2.size()) {
      ans += word2[j++];
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 73.78%
// Memory Usage: 163.8 MB, less than 54.16%

class Solution {
 public:
  string largestMerge(string word1, string word2) {
    if (word1.empty() || word2.empty()) {
      return word1 + word2;
    }

    if (word1 > word2) {
      return word1[0] + largestMerge(word1.substr(1), word2);
    } else {
      return word2[0] + largestMerge(word1, word2.substr(1));
    }
  }
};
// Runtime: 424 ms, faster than 14.20%
// Memory Usage: 419.6 MB, less than 8.42%