class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    for (int i = 0; i < n; ++i) {
      bool find = true;

      for (int j = i, cnt = 0, g = 0, c = 0; cnt < n; ++j, ++cnt) {
        g += gas[j % n];
        c += cost[j % n];

        if (g < c) {
          find = false;
          break;
        }
      }

      if (find) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 164 ms, faster than 18.76%
// Memory Usage: 9.9 MB, less than 51.52%

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int ans = 0;
    int sum = 0;
    int psum = 0;

    for (int i = 0; i < n; ++i) {
      psum += gas[i] - cost[i];

      if (psum < 0) {
        sum += psum;
        psum = 0;
        ans = i + 1;
      }
    }

    sum += psum;

    return sum < 0 ? -1 : ans % n;
  }
};
// Runtime: 8 ms, faster than 96.30%
// Memory Usage: 9.8 MB, less than 93.88%