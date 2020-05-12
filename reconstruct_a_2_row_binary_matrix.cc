class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int upper,
                                        int lower,
                                        vector<int>& colsum) {
    vector<vector<int>> ans(2, vector<int>(colsum.size()));

    int uppersum = 0;
    int lowersum = 0;
    for (int i = 0; i < colsum.size(); ++i) {
      if (colsum[i] == 2) {
        ans[0][i] = 1;
        ans[1][i] = 1;

        ++uppersum;
        ++lowersum;
      }

      if (uppersum > upper || lowersum > lower) {
        return vector<vector<int>>();
      }
    }

    for (int i = 0; i < colsum.size(); ++i) {
      if (colsum[i] == 1) {
        if (uppersum < upper) {
          ans[0][i] = 1;
          ++uppersum;
        } else if (lowersum < lower) {
          ans[1][i] = 1;
          ++lowersum;
        } else {
          return vector<vector<int>>();
        }
      }
    }

    return uppersum < upper || lowersum < lower ? vector<vector<int>>() : ans;
  }
};
// Runtime: 128 ms, faster than 99.75%
// Memory Usage: 62.5 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int upper,
                                        int lower,
                                        vector<int>& colsum) {
    vector<vector<int>> ans(2, vector<int>(colsum.size()));

    for (int i = 0; i < colsum.size();
         upper -= ans[0][i], lower -= ans[1][i++]) {
      ans[0][i] = colsum[i] == 2 ? 1 : (colsum[i] && upper > lower);
      ans[1][i] = colsum[i] == 2 ? 1 : (colsum[i] && !ans[0][i]);
    }

    return upper == 0 && lower == 0 ? ans : vector<vector<int>>();
  }
};
// Runtime: 164 ms, faster than 85.78%
// Memory Usage: 62.6 MB, less than 100.00%