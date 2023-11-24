class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int a = 0;
    for (auto n : nums1) {
      a ^= n;
    }

    int b = 0;
    for (auto n : nums2) {
      b ^= n;
    }

    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 % 2 == 0 && n2 % 2 == 0) {
      return 0;
    } else if (n1 % 2 == 0) {
      return a;
    } else if (n2 % 2 == 0) {
      return b;
    } else {
      return a ^ b;
    }
  }
};
// Runtime: 136 ms, faster than 98.57%
// Memory Usage: 60.5 MB, less than 70.29%
// 2022.10.6 at 茗筑美嘉