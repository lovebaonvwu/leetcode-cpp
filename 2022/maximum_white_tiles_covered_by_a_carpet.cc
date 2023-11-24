class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());

    int& len = carpetLen;

    int ans = 0, cnt = 0;
    for (int i = 0, j = 0; i < tiles.size() && cnt < len;) {
      if (i == j || tiles[j][0] + len > tiles[i][1]) {
        cnt += min(len, tiles[i][1] - tiles[i][0] + 1);
        ans = max(ans, cnt);
        ++i;
      } else {
        int partial = max(0, tiles[j][0] + len - tiles[i][0]);
        ans = max(ans, cnt + partial);

        cnt -= tiles[j][1] - tiles[j][0] + 1;
        ++j;
      }
    }

    return ans;
  }
};
// Runtime: 397 ms, faster than 85.68%
// Memory Usage: 69.9 MB, less than 66.92%
// 2022.5.20 at 奥盛大厦