class Solution {
 public:
  int countPairs(vector<vector<int>>& coordinates, int k) {
    int ans = 0;
    int n = coordinates.size();
    for (int i = 0; i < n; ++i) {
      int& ix = coordinates[i][0];
      int& iy = coordinates[i][1];
      for (int j = i + 1; j < n; ++j) {
        int& jx = coordinates[j][0];
        int& jy = coordinates[j][1];
        if ((ix ^ jx) + (iy ^ jy) == k) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int countPairs(vector<vector<int>>& coordinates, int k) {
    int ans = 0;
    int n = coordinates.size();
    for (int i = 0; i <= k; ++i) {
      unordered_map<long long, int> mp;
      for (auto& c : coordinates) {
        long long x0 = c[0];
        long long y0 = c[1];
        long long x1 = i ^ x0;
        long long y1 = (k - i) ^ y0;

        if (mp.find(x1 * 1000000 + y1) != mp.end()) {
          ans += mp[x1 * 1000000 + y1];
        }

        ++mp[x0 * 1000000 + y0];
      }
    }

    return ans;
  }
};
// 1422ms
// 478.71MB