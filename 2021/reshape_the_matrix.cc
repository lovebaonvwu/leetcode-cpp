class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.size() && (nums.size() * nums[0].size() != r * c))
      return nums;

    vector<vector<int>> ans(r, vector<int>(c));

    int m = 0;
    int n = 0;

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        ans[i][j] = getNum(nums, m, n);
      }
    }

    return ans;
  }

  int getNum(vector<vector<int>>& nums, int& i, int& j) {
    int temp = nums[i][j];
    ++j;
    if (!(j < nums[i].size())) {
      ++i;
      j = 0;
    }

    return temp;
  }
};  // 32ms

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.size() && (nums.size() * nums[0].size() != r * c))
      return nums;

    vector<vector<int>> ans(r, vector<int>(c));

    int col = nums[0].size();

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int index = i * c + j;
        ans[i][j] = nums[index / col][index % col];
      }
    }

    return ans;
  }
};  // 36ms