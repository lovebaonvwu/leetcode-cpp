class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0, j = 0, cnt = 0; j < n; ++j) {
      if (nums[j] & 1) {
        --k;

        if (k <= 0) {
          cnt = 1;

          while (!(nums[i++] & 1)) {
            ++cnt;
          }

          ans += cnt;
        }
      } else if (k <= 0) {
        ans += cnt;
      }
    }

    return ans;
  }
};
// Runtime: 356 ms, faster than 49.68%
// Memory Usage: 67.9 MB, less than 65.03%

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    deque<int> dq{-1};

    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] & 1) {
        dq.push_back(i);
      }

      if (dq.size() > k + 1) {
        dq.pop_front();
      }

      if (dq.size() == k + 1) {
        ans += dq[1] - dq[0];
      }
    }

    return ans;
  }
};
// Runtime: 508 ms, faster than 24.17%
// Memory Usage: 69.8 MB, less than 44.34%

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int ans = 0;

    for (int i = 0, j = 0, cnt = 0; j < nums.size(); ++j) {
      if (nums[j] & 1) {
        --k;
        cnt = 0;
      }

      while (k == 0) {
        k += nums[i++] & 1;
        ++cnt;
      }

      ans += cnt;
    }

    return ans;
  }
};
// Runtime: 296 ms, faster than 82.09%
// Memory Usage: 67.8 MB, less than 74.38%