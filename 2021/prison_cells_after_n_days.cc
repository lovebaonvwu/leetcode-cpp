class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<int> tmp(cells.size(), 0);
    vector<int> initial;

    for (int cycle = 0; N-- > 0; cells = tmp, ++cycle) {
      for (int i = 1; i < cells.size() - 1; ++i) {
        tmp[i] = cells[i - 1] == cells[i + 1];
      }

      if (cycle == 0) {
        initial = tmp;
      } else if (initial == tmp) {
        N %= cycle;
      }
    }

    return cells;
  }
};
// Runtime: 4 ms, faster than 89.32%
// Memory Usage: 8.4 MB, less than 64.29%

class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    while (N-- > 0) {
      vector<int> tmp = cells;

      tmp[0] = 0;
      tmp[tmp.size() - 1] = 0;

      for (int i = 1; i < tmp.size() - 1; ++i) {
        if (cells[i - 1] == cells[i + 1]) {
          tmp[i] = 1;
        } else {
          tmp[i] = 0;
        }
      }

      cells = tmp;
    }

    return cells;
  }
};
// Time Limit Exceeded