class Solution {
 public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long ans = 0;
    sort(rbegin(happiness), rend(happiness));

    for (int i = 0; i < happiness.size() && k > 0; ++i) {
      ans += max(happiness[i] - i, 0);
      --k;
    }

    return ans;
  }
};
// 233 ms
// 108.78 MB