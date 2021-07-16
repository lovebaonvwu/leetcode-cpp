class Solution {
 public:
  bool sumGame(string num) {
    int leftSum = 0, rightSum = 0, leftMarks = 0, rightMarks = 0;
    int n = num.size();

    for (int i = 0; i < n / 2; ++i) {
      if (num[i] == '?') {
        ++leftMarks;
      } else {
        leftSum += num[i] - '0';
      }

      if (num[n - 1 - i] == '?') {
        ++rightMarks;
      } else {
        rightSum += num[n - 1 - i] - '0';
      }
    }

    if ((leftMarks + rightMarks) % 2 != 0) {
      return true;
    }

    if (leftMarks == rightMarks) {
      return leftSum != rightSum;
    }

    if (leftMarks < rightMarks) {
      swap(leftMarks, rightMarks);
      swap(leftSum, rightSum);
    }

    return (rightSum - leftSum) != (leftMarks - rightMarks) / 2 * 9;
  }
};
// Runtime: 28 ms, faster than 66.92%
// Memory Usage: 11.2 MB, less than 72.95%
// 2021.7.16 at 奥盛大厦