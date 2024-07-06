class Solution {
 public:
  string betterCompression(string compressed) {
    compressed += 'A';
    vector<int> freq(26);

    int cnt = 0;
    char prev = compressed[0];
    for (int i = 1; i < compressed.size(); ++i) {
      if (isalpha(compressed[i])) {
        freq[prev - 'a'] += cnt;
        cnt = 0;
        prev = compressed[i];
      } else {
        cnt = cnt * 10 + (compressed[i] - '0');
      }
    }

    string ans;
    for (int i = 0; i < 26; ++i) {
      if (freq[i] > 0) {
        ans += i + 'a';
        ans += to_string(freq[i]);
      }
    }

    return ans;
  }
};
// 29 ms
// 16.72 MB