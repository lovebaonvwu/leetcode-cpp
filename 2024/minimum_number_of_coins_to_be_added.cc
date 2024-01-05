class Solution {
 public:
  int minimumAddedCoins(vector<int>& coins, int target) {
    int ans = 0;
    int sum = 0;
    sort(begin(coins), end(coins));
    for (int i = 0; i < coins.size() && sum < target;) {
      if (sum + 1 < coins[i]) {
        sum += sum + 1;
        ++ans;
      } else {
        sum += coins[i];
        ++i;
      }
    }

    while (sum < target) {
      sum += sum + 1;
      ++ans;
    }

    return ans;
  }
};
// 108ms
// 76.99MB