class Solution {
 public:
  string compressedString(string word) {
    string ans = "";
    word += '*';
    int n = word.size();
    char prev = word[0];
    for (int i = 1, cnt = 1; i < n; ++i) {
      if (word[i] == prev && cnt < 9) {
        ++cnt;
      } else {
        ans += to_string(cnt);
        ans += prev;
        cnt = 1;
        prev = word[i];
      }
    }

    return ans;
  }
};
// 83 ms
// 32.08 MB