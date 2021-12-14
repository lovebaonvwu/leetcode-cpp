class Solution {
 public:
  int countPoints(string rings) {
    int rods[10] = {0};

    for (int i = 0; i < rings.size(); i += 2) {
      rods[rings[i + 1] - '0'] |= 1 << (rings[i] == 'G'   ? 1
                                        : rings[i] == 'B' ? 2
                                                          : 0);
    }

    int ans = 0;

    for (int i = 0; i < 10; ++i) {
      if (rods[i] == 7) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 60.67%
// 2021.12.14 at 奥盛大厦