class Solution {
 public:
  int minNumberOperations(vector<int>& target) {
    int ans = target[0];
    for (int i = 1; i < target.size(); ++i) {
      ans += max(target[i] - target[i - 1], 0);
    }

    return ans;
  }
};
// 86ms
// 73.46MB