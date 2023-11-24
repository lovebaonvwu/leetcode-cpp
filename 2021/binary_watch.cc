class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    unordered_map<int, vector<int>> hours;

    for (int i = 0; i <= 11; ++i) {
      int cntOfOne = 0;

      int n = i;
      while (n > 0) {
        cntOfOne += n & 1;
        n >>= 1;
      }

      hours[cntOfOne].push_back(i);
    }

    unordered_map<int, vector<int>> mins;

    for (int i = 0; i <= 59; ++i) {
      int cntOfOne = 0;

      int n = i;
      while (n > 0) {
        cntOfOne += n & 1;
        n >>= 1;
      }

      mins[cntOfOne].push_back(i);
    }

    vector<string> ans;

    for (int i = 0; i <= turnedOn; ++i) {
      auto& hour = hours[i];
      auto& min = mins[turnedOn - i];

      for (auto h : hour) {
        for (auto m : min) {
          string t = to_string(h);
          t += ':';

          if (m <= 9) {
            t += '0';
          }
          t += to_string(m);

          ans.push_back(t);
        }
      }
    }

    return ans;
  }
};
// Runtime: 3 ms, faster than 24.30%
// Memory Usage: 6.6 MB, less than 31.89%
// 2021.11.27 at 茗筑美嘉