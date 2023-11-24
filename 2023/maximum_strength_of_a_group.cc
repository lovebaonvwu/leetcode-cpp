class Solution {
 public:
  long long maxStrength(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums.back();
    }

    int neg_cnt = 0;
    int max_negnum = INT_MIN;
    int max_num = INT_MIN;

    long long ans = 1;

    for (auto n : nums) {
      max_num = max(max_num, n);

      if (n == 0) {
        continue;
      }

      if (n < 0) {
        ++neg_cnt;
        max_negnum = max(max_negnum, n);
      }

      ans *= n;
    }

    if (max_num == 0 && neg_cnt < 2) {
      return 0;
    }

    if (max_num < 0 && neg_cnt == 1) {
      return max_num;
    }

    if (ans > 0) {
      return ans;
    }

    return ans / max_negnum;
  }
};
// Runtime 18 ms
// Memory 46.5 MB