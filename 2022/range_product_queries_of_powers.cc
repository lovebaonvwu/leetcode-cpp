class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> p;

    for (int i = 0; i < 32; ++i) {
      if ((n >> i) & 1) {
        p.push_back(pow(2, i));
      }
    }

    vector<int> ans;

    int mod = 1e9 + 7;
    for (auto& q : queries) {
      long long sum = 1;
      for (int i = q[0]; i <= q[1]; ++i) {
        sum = sum * p[i] % mod;
      }

      ans.push_back(sum);
    }

    return ans;
  }
};
// Runtime: 881 ms, faster than 49.01%
// Memory Usage: 143 MB, less than 67.56%
// 2022.10.20 at 奥盛大厦