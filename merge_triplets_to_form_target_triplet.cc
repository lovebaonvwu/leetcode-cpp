class Solution {
 public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> tar(3);

    for (int j = 0; j < 3; ++j) {
      for (int i = 0; i < triplets.size(); ++i) {
        if (triplets[i][j] > target[j]) {
          triplets[i][0] = 0;
          triplets[i][1] = 0;
          triplets[i][2] = 0;
        }
      }
    }

    for (int j = 0; j < 3; ++j) {
      for (int i = 0; i < triplets.size(); ++i) {
        tar[j] = max(tar[j], triplets[i][j]);
      }
    }

    return tar == target;
  }
};
// Runtime: 484 ms, faster than 68.85%
// Memory Usage: 146.5 MB, less than 41.91%

class Solution {
 public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> tar(3);

    for (auto t : triplets) {
      if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
        tar[0] = max(tar[0], t[0]);
        tar[1] = max(tar[1], t[1]);
        tar[2] = max(tar[2], t[2]);
      }
    }

    return tar == target;
  }
};
// Runtime: 532 ms, faster than 54.49%
// Memory Usage: 163.7 MB, less than 19.98%