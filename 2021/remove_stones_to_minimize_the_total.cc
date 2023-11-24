class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;

    for (auto p : piles) {
      pq.push(p);
    }

    while (k-- > 0) {
      int n = pq.top();
      pq.pop();

      pq.push((n + 1) / 2);
    }

    int ans = 0;
    while (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }

    return ans;
  }
};
// Runtime: 772 ms, faster than 34.77%
// Memory Usage: 105 MB, less than 65.40%
// 2021.9.8 at 奥盛大厦

class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq(piles.begin(), piles.end());
    int ans = accumulate(piles.begin(), piles.end(), 0);

    while (k-- > 0) {
      int n = pq.top();
      pq.pop();

      pq.push(n - n / 2);

      ans -= n / 2;
    }

    return ans;
  }
};
// Runtime: 392 ms, faster than 91.96%
// Memory Usage: 98.9 MB, less than 81.42%
// 2021.9.8 at 奥盛大厦