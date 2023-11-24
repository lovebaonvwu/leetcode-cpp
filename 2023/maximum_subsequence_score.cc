class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<int> ids(n);

    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(),
         [&](int i, int j) { return nums1[i] > nums1[j]; });

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    long long ans = 0;
    long long sum = 0;
    for (auto id : ids) {
      sum += nums1[id];
      pq.push({nums2[id], nums1[id]});

      if (pq.size() > k) {
        auto [_, num] = pq.top();
        sum -= num;
        pq.pop();
      }

      if (pq.size() == k) {
        auto [multiplier, num] = pq.top();
        ans = max(ans, sum * multiplier);
      }
    }

    return ans;
  }
};
// Runtime 302 ms
// Memory 88.5 MB