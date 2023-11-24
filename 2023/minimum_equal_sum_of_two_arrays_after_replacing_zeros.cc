class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (auto n : nums1) {
      sum1 += n;
      cnt1 += n == 0;
    }

    for (auto n : nums2) {
      sum2 += n;
      cnt2 += n == 0;
    }

    if (sum1 + cnt1 > sum2 + cnt2) {
      if (cnt2 == 0) {
        return -1;
      }

      return sum1 + cnt1;
    } else if (sum1 + cnt1 < sum2 + cnt2) {
      if (cnt1 == 0) {
        return -1;
      }

      return sum2 + cnt2;
    } else {
      if (cnt1 == 0 && sum2 + cnt2 != sum1) {
        return -1;
      }
      if (cnt2 == 0 && sum1 + cnt1 != sum2) {
        return -1;
      }

      return sum1 + cnt1;
    }
  }
};
// 156ms
// 130.62MB