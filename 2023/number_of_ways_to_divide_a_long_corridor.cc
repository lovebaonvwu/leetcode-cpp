class Solution {
 public:
  int numberOfWays(string corridor) {
    vector<int> s;
    for (int i = 0; i < corridor.size(); ++i) {
      if (corridor[i] == 'S')
        s.push_back(i);
    }

    if (s.empty() || (s.size() & 1))
      return 0;

    int mod = 1e9 + 7;
    long long ans = 1;
    for (int i = 1; i < s.size() - 2; i += 2) {
      ans = ans * (s[i + 1] - s[i]) % mod;
    }

    return ans;
  }
};
// 128ms
// 55.84MB