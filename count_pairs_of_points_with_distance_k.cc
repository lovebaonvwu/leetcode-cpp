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
  int minLengthAfterRemovals(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (auto n : nums) {
      ++cnt[n];
    }

    priority_queue<int> pq;
    for (auto& [_, c] : cnt) {
      pq.push(c);
    }

    while (pq.size() >= 2) {
      auto i = pq.top();
      pq.pop();
      auto j = pq.top();
      pq.pop();

      i -= 1;
      j -= 1;

      if (i > 0) {
        pq.push(i);
      }

      if (j > 0) {
        pq.push(j);
      }
    }

    return pq.size() ? pq.top() : 0;
  }
};
// 250ms
// 166.60MB