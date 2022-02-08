class Solution {
 public:
  long long smallestNumber(long long num) {
    int sign = 0;
    if (num > 0) {
      sign = 1;
    } else {
      sign = -1;
      num = -num;
    }

    vector<int> nums;

    while (num > 0) {
      nums.push_back(num % 10);

      num /= 10;
    }

    if (sign > 0) {
      sort(nums.begin(), nums.end());
      int i = 0;
      while (nums[i] == 0) {
        ++i;
      }

      swap(nums[0], nums[i]);
    } else {
      sort(nums.rbegin(), nums.rend());
    }

    long long ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      ans = ans * 10 + nums[i];
    }

    return sign * ans;
  }
};
// Runtime: 4 ms, faster than 43.62%
// Memory Usage: 6.2 MB, less than 18.30%
// 2022.2.8 at 奥盛大厦