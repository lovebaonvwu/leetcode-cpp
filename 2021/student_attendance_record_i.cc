class Solution {
 public:
  bool checkRecord(string s) {
    int cnt_a = 0;
    int cnt_l = 0;

    for (auto& c : s) {
      if (c == 'A') {
        ++cnt_a;
      }

      if (c == 'L') {
        ++cnt_l;
      } else {
        cnt_l = 0;
      }

      if (cnt_a > 1 || cnt_l > 2) {
        return false;
      }
    }

    return true;
  }
};