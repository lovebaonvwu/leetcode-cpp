class Solution {
 public:
  int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.rbegin(), tasks.rend());
    int ans = 0;
    for (int i = 0; i < processorTime.size(); ++i) {
      for (int j = 0; j < 4; ++j) {
        ans = max(ans, processorTime[i] + tasks[4 * i + j]);
      }
    }

    return ans;
  }
};
// 190ms
// 98.17MB