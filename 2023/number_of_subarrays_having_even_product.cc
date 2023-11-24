class Solution {
 public:
  long long evenProduct(vector<int>& nums) {
    long long ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      long long product = 1;
      for (int j = i; j < nums.size(); ++j) {
        product *= nums[j];
        ans += product % 2 == 0;
        product = product % 2 == 0 ? 2 : 1;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded
// 2023.2.6 at 奥盛大厦

class Solution {
 public:
  long long evenProduct(vector<int>& nums) {
    long long ans = 0;
    for (int i = 0, cnt = 0; i < nums.size(); ++i) {
      if (nums[i] % 2 == 0) {
        cnt = i + 1;
      }

      ans += cnt;
    }

    return ans;
  }
};
// Runtime 124 ms
// Memory 66.8 MB
// 2023.2.6 at 奥盛大厦

class Solution {
 public:
  long long evenProduct(vector<int>& nums) {
    long long n = nums.size();
    long long ans = (1 + n) * n / 2;
    long long conseq1 = 0;

    for (int i = 0, cnt = 0; i < nums.size(); ++i) {
      cnt = nums[i] & 1 ? cnt + 1 : 0;
      conseq1 += cnt;
    }

    return ans - conseq1;
  }
};
// Runtime 126 ms
// Memory 66.9 MB
// 2023.2.6 at 奥盛大厦