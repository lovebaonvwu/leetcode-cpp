class Solution {
 public:
  string decodeCiphertext(string encodedText, int rows) {
    int cols = encodedText.size() / rows;

    string ans;

    for (int j = 0; j < cols; ++j) {
      for (int i = 0, k = j; i < rows && k < cols; ++i, ++k) {
        ans += encodedText[i * cols + k];
      }
    }

    while (ans.back() == ' ') {
      ans.pop_back();
    }

    return ans;
  }
};
// Runtime: 108 ms, faster than 89.72%
// Memory Usage: 39 MB, less than 78.89%
// 2021.11.24 at 奥盛大厦

class Solution {
 public:
  string decodeCiphertext(string encodedText, int rows) {
    int n = encodedText.size();
    int cols = n / rows;

    string ans;

    for (int j = 0; j < cols; ++j) {
      for (int i = j; i < n; i += cols + 1) {
        ans += encodedText[i];
      }
    }

    while (ans.back() == ' ') {
      ans.pop_back();
    }

    return ans;
  }
};
// Runtime: 138 ms, faster than 36.63%
// Memory Usage: 43.4 MB, less than 54.38%
// 2021.11.24 at 奥盛大厦