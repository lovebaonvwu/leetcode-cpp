class Solution {
 public:
  double average(vector<int>& salary) {
    sort(salary.begin(), salary.end());

    double sum = 0;
    for (int i = 1; i < salary.size() - 1; ++i) {
      sum += salary[i];
    }

    return sum / (salary.size() - 2);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.3 MB, less than 33.33%

class Solution {
 public:
  double average(vector<int>& salary) {
    int m = INT_MAX;
    int n = INT_MIN;

    double sum = 0;

    for (int s : salary) {
      m = min(m, s);
      n = max(n, s);
      sum += s;
    }

    return (sum - m - n) / (salary.size() - 2);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.4 MB, less than 33.33%