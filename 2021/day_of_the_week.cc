class Solution {
 public:
  string dayOfTheWeek(int day, int month, int year) {
    vector<string> day_of_week{"Sunday",   "Monday", "Tuesday", "Wednesday",
                               "Thursday", "Friday", "Saturday"};

    vector<int> days_of_month{0,  31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};

    int cnt = 0;
    for (int i = 1971; i < year; ++i) {
      if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
        cnt += 366;
      } else {
        cnt += 365;
      }
    }

    for (int i = 1; i < month; ++i) {
      if (i == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
        cnt += 29;
      } else {
        cnt += days_of_month[i];
      }
    }

    cnt += (day - 1);

    cnt += 5;

    return day_of_week[cnt % 7];
  }
};
// Runtime: 4 ms, faster than 51.32%
// Memory Usage: 8.1 MB, less than 100.00%