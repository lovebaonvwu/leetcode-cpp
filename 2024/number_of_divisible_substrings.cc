class Solution {
 public:
  int countDivisibleSubstrings(string word) {
    int v[26] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5,
                 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9};
    int n = word.size();
    vector<int> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + v[word[i - 1] - 'a'];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if ((presum[j + 1] - presum[i]) % (j - i + 1) == 0) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// 65 ms
// 9.12 MB