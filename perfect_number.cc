class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num < 2) {
      return false;
    }

    int sum = 1;

    for (int i = 2; i <= sqrt(num); ++i) {
      if (num % i == 0) {
        sum += i + (i == num / i ? 0 : num / i);
      }
    }

    return num == sum;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.4 MB, less than 100.00%

class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num < 1) {
      return false;
    }

    int sum = 0;

    for (int i = 1; i < num; ++i) {
      if (num % i == 0) {
        sum += i;
      }
    }

    return num == sum;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num < 1) {
      return false;
    }

    vector<int> divisors;

    for (int i = 1; i < num; ++i) {
      if (num % i == 0) {
        divisors.push_back(i);
      }
    }

    return num == accumulate(divisors.begin(), divisors.end(), 0);
  }
};
// Time Limit Exceeded