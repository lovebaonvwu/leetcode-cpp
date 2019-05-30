class Solution {
 public:
  int countSegments(string s) {
    int cnt = 0;
    int seg = false;

    for (char& c : s) {
      if (!isspace(c)) {
        if (!seg) {
          seg = true;
          ++cnt;
        }
      } else {
        seg = false;
      }
    }

    return cnt;
  }
};