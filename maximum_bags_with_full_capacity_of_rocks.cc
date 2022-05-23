class Solution {
 public:
  int maximumBags(vector<int>& capacity,
                  vector<int>& rocks,
                  int additionalRocks) {
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < capacity.size(); ++i) {
      pq.push(capacity[i] - rocks[i]);
    }

    int ans = 0;
    while (!pq.empty() && additionalRocks > 0) {
      int n = pq.top();
      pq.pop();

      ans += additionalRocks >= n;
      additionalRocks -= n;
    }

    return ans;
  }
};
// Runtime: 289 ms, faster than 33.33%
// Memory Usage: 89.5 MB, less than 33.33%
// 2022.5.23 at 奥盛大厦