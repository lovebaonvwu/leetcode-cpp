class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int t = tickets[k];

    int ans = 0;

    for (int i = 0; i < tickets.size(); ++i) {
      ans += min(t - (i > k), tickets[i]);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 59.09%
// Memory Usage: 7.7 MB, less than 50.00%
// 2021.11.15 at 奥盛大厦

class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int ans = 0;

    for (int i = 0; tickets[k] > 0; ++i) {
      if (tickets[i % tickets.size()] == 0) {
        continue;
      }

      --tickets[i % tickets.size()];

      ++ans;
    }

    return ans;
  }
};
// Runtime: 0 ms
// Memory Usage : 7.7 MB
// 2021.11.15 at 奥盛大厦