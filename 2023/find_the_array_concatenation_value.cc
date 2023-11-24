class Solution {
 public:
  long long findTheArrayConcVal(vector<int>& nums) {
    long long ans = 0;
    for (int i = 0, j = nums.size() - 1; i <= j; ++i, --j) {
      int a = nums[i], b = nums[j];
      int cnt = 0, t = b;
      while (t > 0) {
        t /= 10;
        ++cnt;
      }

      ans += (i < j ? (a * pow(10, cnt)) : 0) + b;
    }

    return ans;
  }
};
// Runtime 7 ms
// Memory 9.4 MB
// 2023.2.18 at 茗筑美嘉