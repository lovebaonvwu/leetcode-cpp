class Solution {
 public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int pacman_dist = abs(target[0]) + abs(target[1]);
    for (auto& g : ghosts) {
      int ghosts_dist = abs(target[0] - g[0]) + abs(target[1] - g[1]);
      if (pacman_dist >= ghosts_dist) {
        return false;
      }
    }

    return true;
  }
};
// 0ms
// 10.66MB