class Solution {
 public:
  vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> ans;
    for (int i = 0; i < variables.size(); ++i) {
      int& a = variables[i][0];
      int& b = variables[i][1];
      int& c = variables[i][2];
      int& m = variables[i][3];

      int ab = mod_pow(a, b, 10);
      int pc = mod_pow(ab, c, m);
      if (pc == target) {
        ans.push_back(i);
      }
    }

    return ans;
  }
  int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
      if (exp & 1) {
        result = (result * base) % mod;
      }

      exp /= 2;
      base = (base * base) % mod;
    }

    return result;
  }
};
// 4ms
// 18.63MB