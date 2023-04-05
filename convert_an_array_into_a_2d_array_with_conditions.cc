class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    int cnt[201] = {0};

    int k = 0;
    for (auto n : nums) {
      ++cnt[n];
      if (cnt[n] == 1) {
        ++k;
      }
    }

    vector<vector<int>> ans;
    while (k > 0) {
      vector<int> p;
      for (int i = 0; i < 201; ++i) {
        if (cnt[i] > 0) {
          p.push_back(i);
          --cnt[i];
          if (cnt[i] == 0) {
            --k;
          }
        }
      }
      ans.push_back(p);
    }

    return ans;
  }
};
// Runtime 19 ms
// Memory 29.6 MB
