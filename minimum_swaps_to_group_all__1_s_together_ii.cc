class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int ones = count(begin(nums), end(nums), 1);
    int cnt = 0, maxCnt = 0;

    vector<int> circular(2 * n);

    for (int i = 0; i < circular.size(); ++i) {
      circular[i] = nums[i % n];
    }

    for (int i = 0; i < circular.size(); ++i) {
      if (i >= ones) {
        cnt -= circular[i - ones];
      }

      cnt += circular[i];

      maxCnt = max(maxCnt, cnt);
    }

    return ones - maxCnt;
  }
};
// Runtime: 250 ms, faster than 12.50%
// Memory Usage: 87.4 MB, less than 87.50%
// 2022.1.10 at 奥盛大厦

class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int ones = count(begin(nums), end(nums), 1);
    int cnt = 0, maxCnt = 0;

    for (int i = 0, j = 0; i < n; ++i) {
      while (j - i < ones) {
        cnt += nums[j++ % n];
      }

      maxCnt = max(maxCnt, cnt);

      cnt -= nums[i];
    }

    return ones - maxCnt;
  }
};
// Runtime: 140 ms, faster than 12.50%
// Memory Usage: 80.4 MB, less than 100.00%
// 2022.1.10 at 奥盛大厦