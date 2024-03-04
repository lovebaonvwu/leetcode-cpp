class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    using ll = long long;
    priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());

    int ans = 0;
    while (pq.size() > 1) {
      if (pq.top() >= k) {
        break;
      }

      ll x = pq.top();
      pq.pop();
      ll y = pq.top();
      pq.pop();

      pq.push(min(x, y) * 2 + max(x, y));
      ++ans;
    }

    return ans;
  }
};
// 231 ms
// 90.37 MB