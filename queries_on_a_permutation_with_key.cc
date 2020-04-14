class Solution {
 public:
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> idx(m);
    for (int i = 0; i < idx.size(); ++i) {
      idx[i] = i;
    }

    vector<int> ans;
    for (auto q : queries) {
      ans.push_back(idx[q - 1]);

      for (int i = 0; i < idx.size(); ++i) {
        if (idx[i] < idx[q - 1]) {
          ++idx[i];
        }
      }
      idx[q - 1] = 0;
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 81.14%
// Memory Usage: 8.5 MB, less than 100.00%