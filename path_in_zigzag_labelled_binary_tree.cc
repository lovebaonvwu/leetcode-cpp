class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    int N = 0;
    while (label > 2 * pow(2, N) - 1) {
      ++N;
    }

    vector<int> ans;
    for (int lvl = N + 1; lvl >= 1; --lvl) {
      ans.push_back(label);

      int i = lvl & 1 ? (label - pow(2, lvl - 1))
                      : (2 * pow(2, lvl - 1) - 1 - label);
      i /= 2;

      label =
          (lvl - 1) & 1 ? (pow(2, lvl - 2) + i) : (2 * pow(2, lvl - 2) - 1 - i);
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 100.00%

class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    int lvl = log2(label);

    vector<int> ans;
    ans.push_back(label);

    while (lvl != 0) {
      int left = pow(2, lvl) - 1;
      int right = pow(2, lvl - 1);

      label = left + (right - label / 2);

      ans.push_back(label);

      --lvl;
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 100.00%