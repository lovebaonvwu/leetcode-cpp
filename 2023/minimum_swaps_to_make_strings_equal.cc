class Solution {
 public:
  int minimumSwap(string s1, string s2) {
    int n = s1.size();
    int xy_cnt = 0, yx_cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s1[i] == 'x' && s2[i] == 'y') {
        ++xy_cnt;
      } else if (s1[i] == 'y' && s2[i] == 'x') {
        ++yx_cnt;
      }
    }

    if (xy_cnt % 2 != yx_cnt % 2) {
      return -1;
    }

    return xy_cnt / 2 + yx_cnt / 2 + (xy_cnt % 2) * 2;
  }
};
// -ms
// 6.26mb