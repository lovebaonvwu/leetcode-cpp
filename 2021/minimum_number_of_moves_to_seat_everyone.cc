class Solution {
 public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int ans = 0;

    for (int i = 0; i < seats.size(); ++i) {
      ans += abs(seats[i] - students[i]);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 92.31%
// Memory Usage: 18.1 MB, less than 23.08%
// 2021.10.17 at 茗筑美嘉