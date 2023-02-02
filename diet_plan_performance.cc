class Solution {
 public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < calories.size(); ++i) {
      sum += calories[i];

      if (i >= k) {
        sum -= calories[i - k];
      }

      if (i >= k - 1) {
        ans += sum < lower ? -1 : sum > upper ? 1 : 0;
      }
    }

    return ans;
  }
};
// Runtime 27 ms
// Memory 23.1 MB
// 2023.2.2 at 聊城滦河路汉庭优佳