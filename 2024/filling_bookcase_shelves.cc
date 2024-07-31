class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int n = books.size();
    vector<vector<int>> cached(n, vector<int>(shelfWidth + 1));

    function<int(int, int, int)> dfs = [&](int i, int remain_w,
                                           int max_h) -> int {
      if (i == n - 1) {
        if (remain_w >= books[i][0]) {
          return max(books[i][1], max_h);
        } else {
          return max_h + books[i][1];
        }
      }

      if (cached[i][remain_w]) {
        return cached[i][remain_w];
      }

      int ret = max_h + dfs(i + 1, shelfWidth - books[i][0], books[i][1]);
      if (remain_w >= books[i][0]) {
        ret = min(ret,
                  dfs(i + 1, remain_w - books[i][0], max(max_h, books[i][1])));
      }

      return cached[i][remain_w] = ret;
    };

    return dfs(0, shelfWidth, 0);
  }
};
// 8 ms
// 21.04 MB
