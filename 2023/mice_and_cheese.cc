class Solution {
 public:
  int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int n = reward1.size();

    vector<int> index(n);
    iota(begin(index), end(index), 0);

    sort(index.begin(), index.end(), [&](int i, int j) {
      return (reward1[i] - reward2[i]) > (reward1[j] - reward2[j]);
    });

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (k > 0) {
        ans += reward1[index[i]];
        --k;
      } else {
        ans += reward2[index[i]];
      }
    }

    return ans;
  }
};
// Runtime 259 ms
// Memory 103.6 MB