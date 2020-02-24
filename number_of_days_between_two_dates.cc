class Solution {
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool isLeapYear(int y) { return y % 4 == 0 && y % 100 != 0 || y % 400 == 0; }

  int countDays(string date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));

    int cnt = 0;

    for (int i = 1971; i < y; ++i) {
      cnt += isLeapYear(i) ? 366 : 365;
    }

    return cnt + d + (isLeapYear(y) && m > 2) +
           accumulate(begin(days), begin(days) + m - 1, 0);
  }

 public:
  int daysBetweenDates(string date1, string date2) {
    int d1 = countDays(date1);
    int d2 = countDays(date2);

    return d1 < d2 ? d2 - d1 : d1 - d2;
  }
};
// Runtime: 4 ms, faster than 50.00%
// Memory Usage: 8.4 MB, less than 100.00%

class Solution {
  int days[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

  int countDays(string date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));

    int cnt = 0;

    for (int i = 1971; i < y; ++i) {
      if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
        cnt += 366;
      } else {
        cnt += 365;
      }
    }

    for (int i = 1; i <= m; ++i) {
      cnt += days[i - 1];
      if (i - 1 == 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) {
        cnt += 1;
      }
    }

    for (int i = 1; i <= d; ++i) {
      ++cnt;
    }

    return cnt;
  }

 public:
  int daysBetweenDates(string date1, string date2) {
    int d1 = countDays(date1);
    int d2 = countDays(date2);

    return d1 < d2 ? d2 - d1 : d1 - d2;
  }
};
// Runtime: 4 ms, faster than 50.00%
// Memory Usage: 8.3 MB, less than 100.00%