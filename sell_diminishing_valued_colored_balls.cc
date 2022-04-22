class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    priority_queue<int> pq(inventory.begin(), inventory.end());

    long long ans = 0;
    while (orders-- > 0) {
      int value = pq.top();
      pq.pop();

      ans = (ans + value) % ((int)1e9 + 7);
      pq.push(--value);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    constexpr int kMod = 1e9 + 7;
    long ans = 0;
    long cur = inventory[0];
    const int n = inventory.size();
    int c = 0;

    sort(rbegin(inventory), rend(inventory));

    while (orders) {
      while (c < n && inventory[c] == cur)
        ++c;

      int next = c == n ? 0 : inventory[c];

      int count = min(static_cast<long>(orders), (cur - next) * c);

      int t = cur - next;
      int r = 0;

      if (orders < (cur - next) * c) {
        t = orders / c;
        r = orders % c;
      }

      long next_p = cur - t;

      ans = (ans + ((cur + next_p + 1) * t / 2 * c + next_p * r)) % kMod;

      orders -= count;
      cur = next;
    }

    return ans;
  }
};
// Runtime: 218 ms, faster than 53.60%
// Memory Usage: 65 MB, less than 25.53%
// 2022.4.22 at 奥盛大厦