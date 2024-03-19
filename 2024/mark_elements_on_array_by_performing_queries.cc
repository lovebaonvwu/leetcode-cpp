class Solution {
 public:
  vector<long long> unmarkedSumArray(vector<int>& nums,
                                     vector<vector<int>>& queries) {
    int n = nums.size();
    int m = queries.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < n; ++i) {
      pq.push({nums[i], i});
    }

    long long sum = accumulate(begin(nums), end(nums), 0LL);

    vector<long long> ans(m);
    for (int i = 0, j = 0; i < m; ++i) {
      int idx = queries[i][0];
      int cnt = queries[i][1];

      if (nums[idx] > 0) {
        sum -= nums[idx];
        nums[idx] = 0;
      }

      while (!pq.empty() && cnt > 0) {
        auto [num, idx] = pq.top();
        pq.pop();

        if (nums[idx] > 0) {
          sum -= nums[idx];
          nums[idx] = 0;
          --cnt;
        }
      }

      ans[i] = sum;
    }

    return ans;
  }
};
// 256 ms
// 139.75 MB