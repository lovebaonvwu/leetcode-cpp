class Solution {
 public:
  bool isArmstrong(int n) {
    int t = n;
    vector<int> nums;
    while (t > 0) {
      nums.push_back(t % 10);
      t /= 10;
    }

    int sum = 0;
    for (auto n : nums) {
      sum += pow(n, nums.size());
    }

    return sum == n;
  }
};
// Runtime 0 ms
// Memory 6.3 MB
// 2022.11.29 at 茗筑美嘉