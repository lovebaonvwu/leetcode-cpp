class Solution {
 public:
  int minMaxDifference(int num) {
    vector<int> digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
    }

    reverse(digits.begin(), digits.end());

    vector<int> maxd = digits;
    int target = -1;
    int maxint = 0;
    for (int i = 0; i < maxd.size(); ++i) {
      if (maxd[i] != 9 && target == -1) {
        target = maxd[i];
      }

      if (maxd[i] == target) {
        maxd[i] = 9;
      }

      maxint = maxint * 10 + maxd[i];
    }

    vector<int> mind = digits;
    target = -1;
    int minint = 0;
    for (int i = 0; i < mind.size(); ++i) {
      if (mind[i] != 0 && target == -1) {
        target = mind[i];
      }

      if (mind[i] == target) {
        mind[i] = 0;
      }

      minint = minint * 10 + mind[i];
    }

    return maxint - minint;
  }
};
// Runtime 4 ms
// Memory 6.1 MB