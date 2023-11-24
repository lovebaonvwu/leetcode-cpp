class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());

    int ans = 0;
    int n = piles.size() / 3;
    for (int i = piles.size() - 1, cnt = 0; i >= 0 && cnt < n; i -= 2, ++cnt) {
      ans += piles[i - 1];
    }

    return ans;
  }
};
// Runtime: 364 ms, faster than 50.00%
// Memory Usage: 53.8 MB, less than 25.00%

class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());

    int ans = 0;
    int n = piles.size();
    for (int i = n / 3; i < n; i += 2) {
      ans += piles[i];
    }

    return ans;
  }
};
// Runtime: 356 ms, faster than 100.00%
// Memory Usage: 53.4 MB, less than 100.00%