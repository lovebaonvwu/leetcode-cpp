class Solution {
 public:
  int halveArray(vector<int>& nums) {
    double sum = accumulate(nums.begin(), nums.end(), 0L);

    double target = sum / 2;

    priority_queue<double> pq(nums.begin(), nums.end());

    int ans = 0;
    while (sum > target) {
      double num = pq.top() / 2;
      pq.pop();

      sum -= num;
      pq.push(num);

      ++ans;
    }

    return ans;
  }
};
// Runtime: 328 ms, faster than 72.48%
// Memory Usage: 80.8 MB, less than 92.05%
// 2022.3.22 at 奥盛大厦