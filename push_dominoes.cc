class Solution {
 public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();

    vector<int> leftRGap(n, n), rightLGap(n, n);

    for (int i = 0, leftRPos = -1; i < n; ++i) {
      if (dominoes[i] == 'R') {
        leftRPos = i;
      } else if (dominoes[i] == 'L') {
        leftRPos = -1;
      }

      if (leftRPos >= 0) {
        leftRGap[i] = (i - leftRPos);
      }
    }

    for (int i = n - 1, rightLPos = -1; i >= 0; --i) {
      if (dominoes[i] == 'L') {
        rightLPos = i;
      } else if (dominoes[i] == 'R') {
        rightLPos = -1;
      }

      if (rightLPos >= 0) {
        rightLGap[i] = (rightLPos - i);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == '.' && leftRGap[i] != rightLGap[i]) {
        dominoes[i] = leftRGap[i] > rightLGap[i] ? 'L' : 'R';
      }
    }

    return dominoes;
  }
};
// Runtime: 44 ms, faster than 18.64%
// Memory Usage: 20.4 MB, less than 5.12%
// 2021.7.21 at 奥盛大厦