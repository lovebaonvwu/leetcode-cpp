class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    long y = 0;
    int z = x;

    while (z) {
      y = y * 10 + z % 10;
      z /= 10;
    }

    return x == y;
  }
};  // 20ms

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    vector<int> nums;

    while (x) {
      nums.push_back(x % 10);

      x /= 10;
    }

    int i = 0, j = nums.size() - 1;

    while (i < j) {
      if (nums[i++] != nums[j--]) {
        return false;
      }
    }

    return true;
  }
};  // 36ms