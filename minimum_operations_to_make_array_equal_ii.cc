class Solution {
 public:
  long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    long long ans = 0;
    long long inc = 0, dec = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      if (nums1[i] != nums2[i]) {
        int diff = abs(nums1[i] - nums2[i]);
        if (k == 0 || diff % k != 0) {
          return -1;
        }

        if (nums1[i] < nums2[i]) {
          inc += diff / k;
        } else {
          dec += diff / k;
        }
      }
    }

    return inc == dec ? inc : -1;
  }
};
// Runtime 145 ms
// Memory 73.1 MB
// 2023.2.21 at 奥盛大厦