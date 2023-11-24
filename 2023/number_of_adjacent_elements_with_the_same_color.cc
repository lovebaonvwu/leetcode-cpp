class Solution {
 public:
  vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    int c[100003] = {0};
    vector<int> ans;

    int cnt = 0;
    for (auto& q : queries) {
      int i = q[0] + 1, color = q[1];

      if (c[i] > 0) {
        cnt -= c[i] == c[i + 1];
        cnt -= c[i] == c[i - 1];
      }

      c[i] = color;
      cnt += c[i] == c[i + 1];
      cnt += c[i] == c[i - 1];

      ans.push_back(cnt);
    }

    return ans;
  }
};
// Runtime 551 ms
// Memory 174.8 MB