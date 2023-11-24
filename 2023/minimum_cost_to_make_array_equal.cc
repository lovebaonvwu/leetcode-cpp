class Solution {
 public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    int n = nums.size();
    vector<long long> left(n), right(n);

    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
      p.push_back({nums[i], cost[i]});
    }
    sort(p.begin(), p.end());

    long long leftsum = p[0].second;
    for (int i = 1; i < n; ++i) {
      left[i] = left[i - 1] + (p[i].first - p[i - 1].first) * leftsum;
      leftsum += p[i].second;
    }

    long long rightsum = p[n - 1].second;
    for (int i = n - 2; i >= 0; --i) {
      right[i] = right[i + 1] + (p[i + 1].first - p[i].first) * rightsum;
      rightsum += p[i].second;
    }

    long long ans = LONG_MAX;
    for (int i = 0; i < n; ++i) {
      ans = min(ans, left[i] + right[i]);
    }

    return ans;
  }
};
// Runtime 93 ms
//  Memory 44.6 MB