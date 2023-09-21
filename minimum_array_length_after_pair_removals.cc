class Solution {
 public:
  int minLengthAfterRemovals(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (auto n : nums) {
      ++cnt[n];
    }

    priority_queue<int> pq;
    for (auto& [_, c] : cnt) {
      pq.push(c);
    }

    while (pq.size() >= 2) {
      auto i = pq.top();
      pq.pop();
      auto j = pq.top();
      pq.pop();

      i -= 1;
      j -= 1;

      if (i > 0) {
        pq.push(i);
      }

      if (j > 0) {
        pq.push(j);
      }
    }

    return pq.size() ? pq.top() : 0;
  }
};
// 250ms
// 166.60MB