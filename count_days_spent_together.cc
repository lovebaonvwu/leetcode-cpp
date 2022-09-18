class Solution {
  int getMonth(const string& s) { return stoi(s.substr(0, 2)); }

  int getDay(const string& s) { return stoi(s.substr(3)); }

  int getTotal(int days[], const string& s) {
    int m = getMonth(s);
    int d = getDay(s);
    int total = d;
    for (int i = 0; i < m - 1; ++i) {
      total += days[i];
    }

    return total;
  }

 public:
  int countDaysTogether(string arriveAlice,
                        string leaveAlice,
                        string arriveBob,
                        string leaveBob) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int aliceBegin = getTotal(days, arriveAlice);
    int aliceEnd = getTotal(days, leaveAlice);
    int bobBegin = getTotal(days, arriveBob);
    int bobEnd = getTotal(days, leaveBob);

    if (aliceBegin > bobEnd || bobBegin > aliceEnd) {
      return 0;
    }

    return min(aliceEnd, bobEnd) - max(aliceBegin, bobBegin) + 1;
  }
};
// Runtime: 7 ms, faster than 20.00%
// Memory Usage: 5.9 MB, less than 50.00%
// 2022.9.18 at 茗筑美嘉