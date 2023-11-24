class Solution {
  int m;
  int n;
  vector<vector<bool>> visited;

 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image,
                                int sr,
                                int sc,
                                int newColor) {
    m = image.size();
    n = image[0].size();

    visited = vector<vector<bool>>(m, vector<bool>(n));

    dfs(image, sr, sc, newColor, image[sr][sc]);

    return image;
  }

  void dfs(vector<vector<int>>& img, int r, int c, int newColor, int orgColor) {
    if (r < 0 || r > m - 1 || c < 0 || c > n - 1 || visited[r][c]) {
      return;
    }

    if (img[r][c] == orgColor) {
      img[r][c] = newColor;

      visited[r][c] = true;

      dfs(img, r, c - 1, newColor, orgColor);
      dfs(img, r, c + 1, newColor, orgColor);
      dfs(img, r - 1, c, newColor, orgColor);
      dfs(img, r + 1, c, newColor, orgColor);
    }
  }
};
// Runtime: 16 ms, faster than 81.54%
// Memory Usage: 14.4 MB, less than 25.61%

class Solution {
  int m;
  int n;
  int oldColor;
  int newColor;

 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image,
                                int sr,
                                int sc,
                                int newColor) {
    m = image.size();
    n = image[0].size();

    oldColor = image[sr][sc];
    this->newColor = newColor;

    if (oldColor != newColor) {
      dfs(image, sr, sc);
    }

    return image;
  }

  void dfs(vector<vector<int>>& img, int r, int c) {
    if (r < 0 || r > m - 1 || c < 0 || c > n - 1 || img[r][c] != oldColor) {
      return;
    }

    img[r][c] = newColor;

    dfs(img, r, c - 1);
    dfs(img, r, c + 1);
    dfs(img, r - 1, c);
    dfs(img, r + 1, c);
  }
};
// Runtime: 16 ms, faster than 81.54%
// Memory Usage: 14 MB, less than 76.52%