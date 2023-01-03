class Solution {
 public:
  int maxJump(vector<int>& stones) {
    int ans = stones[1] - stones[0];
    for (int i = 3; i < stones.size(); i += 2) {
      ans = max(ans, stones[i] - stones[i - 2]);
    }

    for (int i = 2; i < stones.size(); i += 2) {
      ans = max(ans, stones[i] - stones[i - 2]);
    }

    return ans;
  }
};
// Runtime 176 ms
// Memory 65.5 MB
// 2023.1.3 at 奥盛大厦