class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    for (int i = 0; i < dist.size(); ++i) {
      dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] > 0);
    }

    sort(dist.begin(), dist.end());

    int ans = 0;

    for (int i = 0; i < dist.size() && i < dist[i]; ++i) {
      if (i < dist[i]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 128 ms, faster than 90.64%
// Memory Usage: 80.9 MB, less than 96.06%
// 2021.7.6 at 奥盛大厦