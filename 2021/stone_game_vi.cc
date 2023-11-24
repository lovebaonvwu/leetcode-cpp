class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    vector<pair<int, int>> stones;

    for (int i = 0; i < aliceValues.size(); ++i) {
      stones.push_back({aliceValues[i] + bobValues[i], i});
    }

    sort(stones.rbegin(), stones.rend());

    int a = 0;
    int b = 0;

    for (int i = 0; i < stones.size(); ++i) {
      if (i % 2 == 0) {
        a += aliceValues[stones[i].second];
      } else {
        b += bobValues[stones[i].second];
      }
    }

    return a == b ? 0 : a > b ? 1 : -1;
  }
};
// Runtime: 876 ms, faster than 36.61%
// Memory Usage: 114.2 MB, less than 60.68%

class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    vector<vector<int>> stone(201);

    for (int i = 0; i < aliceValues.size(); ++i) {
      stone[aliceValues[i] + bobValues[i]].push_back(i);
    }

    int a = 0;
    int b = 0;

    for (int i = 200, t = 0; i >= 0; --i) {
      for (auto& idx : stone[i]) {
        if (t % 2 == 0) {
          a += aliceValues[idx];
        } else {
          b += bobValues[idx];
        }
        ++t;
      }
    }

    return a == b ? 0 : a > b ? 1 : -1;
  }
};
// Runtime: 308 ms, faster than 98.64%
// Memory Usage: 112.1 MB, less than 64.49%