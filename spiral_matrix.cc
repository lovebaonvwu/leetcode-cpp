
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    if (matrix.size() == 0) {
      return ans;
    }

    int rb = 0;
    int cl = 0;
    int rt = matrix.size() - 1;
    int cr = matrix[0].size() - 1;

    enum direction { right, down, left, up };

    direction d = right;

    while (rb <= rt && cl <= cr) {
      if (d == right) {
        for (int i = cl; i <= cr; ++i) {
          ans.push_back(matrix[rb][i]);
        }
        ++rb;
        d = down;
      } else if (d == down) {
        for (int i = rb; i <= rt; ++i) {
          ans.push_back(matrix[i][cr]);
        }
        --cr;
        d = left;
      } else if (d == left) {
        for (int i = cr; i >= cl; --i) {
          ans.push_back(matrix[rt][i]);
        }
        --rt;
        d = up;
      } else {
        for (int i = rt; i >= rb; --i) {
          ans.push_back(matrix[i][cl]);
        }
        ++cl;
        d = right;
      }
    }

    return ans;
  }
};