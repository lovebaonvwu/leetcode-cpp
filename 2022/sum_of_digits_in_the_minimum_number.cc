class Solution {
 public:
  int sumOfDigits(vector<int>& nums) {
    int n = *min_element(nums.begin(), nums.end());

    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }

    return !(sum % 2);
  }
};
// Runtime 10 ms
// Memory 8 MB
// 2022.12.1 at 茗筑美嘉