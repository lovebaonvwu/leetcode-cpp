class Solution {
 public:
  void reverseString(vector<char>& s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
      char tmp = s[l];
      s[l] = s[r];
      s[r] = tmp;

      ++l;
      --r;
    }
  }
};

class Solution {
 public:
  void reverseString(vector<char>& s) {
    size_t n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      swap(s[i], s[n - i - 1]);
    }
  }
};
// Runtime: 48 ms
// Memory Usage : 23.3 MB
// Your runtime beats 82.38 % of cpp submissions