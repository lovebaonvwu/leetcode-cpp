class Solution {
 public:
  int minimumTime(vector<int>& jobs, vector<int>& workers) {
    int n = jobs.size();

    sort(begin(jobs), end(jobs));
    sort(begin(workers), end(workers));

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, (jobs[i] / workers[i] + ((jobs[i] % workers[i]) > 0)));
    }

    return ans;
  }
};
// 120 ms
// 86.23 MB