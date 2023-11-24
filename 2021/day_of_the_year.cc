class Solution {
 public:
  int dayOfYear(string date) {
    int month[12]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

    int y, m, d;

    y = stoi(date.substr(0, 4));
    m = stoi(date.substr(5, 2));
    d = stoi(date.substr(8, 2));

    bool is_leap_year = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      if (i == 2 && is_leap_year) {
        ++ans;
      }

      ans += month[i];
    }

    ans += d;

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.1 MB, less than 100.00%