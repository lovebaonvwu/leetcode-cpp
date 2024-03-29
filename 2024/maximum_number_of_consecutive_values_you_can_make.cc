class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    sort(begin(coins), end(coins));

    int max_val = 1;
    for (int i = 0; i < coins.size() && coins[i] <= max_val; ++i)
      max_val += coins[i];

    return max_val;
  }
};
// 102ms
// 66.91MB

class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    sort(begin(coins), end(coins));

    int sum = 0;
    for (auto c : coins) {
      if (c <= sum + 1)
        sum += c;
      else
        break;
    }

    return sum + 1;
  }
};
// 96ms
// 67.16MB