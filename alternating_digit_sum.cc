class Solution {
 public:
  int alternateDigitSum(int n) {
    vector<int> val;

    while (n > 0) {
      val.push_back(n % 10);
      n /= 10;
    }

    reverse(val.begin(), val.end());

    int ans = 0;
    for (int i = 0; i < val.size(); ++i) {
      if (i % 2 == 0) {
        ans += val[i];
      } else {
        ans -= val[i];
      }
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 6.2 MB
// 2023.2.25 at 茗筑美嘉