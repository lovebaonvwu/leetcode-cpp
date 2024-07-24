class Solution {
 public:
  int makePrefSumNonNegative(vector<int>& nums) {
    int ans = 0;
    long long sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto n : nums) {
      sum += n;

      if (n < 0) {
        pq.push(n);
      }

      while (!pq.empty() && sum < 0) {
        sum += -pq.top();
        pq.pop();
        ++ans;
      }
    }

    return ans;
  }
};
// 121 ms
// 95.34 MB