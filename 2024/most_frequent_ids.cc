class Solution {
 public:
  vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    priority_queue<pair<long long, int>> pq;

    int n = nums.size();
    unordered_map<int, long long> cnt;
    vector<long long> ans(n);
    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      int f = freq[i];

      cnt[num] += f;
      pq.push({cnt[num], num});
      while (!pq.empty() && cnt[pq.top().second] != pq.top().first)
        pq.pop();

      ans[i] = pq.top().first;
    }

    return ans;
  }
};
// 229 ms
// 152.79 MB