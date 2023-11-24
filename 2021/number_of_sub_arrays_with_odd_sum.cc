class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    vector<int> presum(arr.size() + 1);

    int n = presum.size();

    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + arr[i - 1];
    }

    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((presum[j] - presum[i]) & 1) {
          ans = (ans + 1) % (static_cast<int>(1e9) + 7);
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    vector<int> presum(arr.size() + 1);

    int n = presum.size();

    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + arr[i - 1];
    }

    int ans = 0;

    for (int i = 0, even_prefix = 0, odd_prefix = 0; i < n; ++i) {
      if (presum[i] & 1) {
        ans = (ans + even_prefix) % (static_cast<int>(1e9) + 7);
        ++odd_prefix;
      } else {
        ans = (ans + odd_prefix) % (static_cast<int>(1e9) + 7);
        ++even_prefix;
      }
    }

    return ans;
  }
};
// Runtime: 352 ms, faster than 74.21%
// Memory Usage: 113.3 MB, less than 13.98%

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    int presum = 0;
    int even_presum_cnt = 1;
    int odd_presum_cnt = 0;

    int ans = 0;

    for (auto n : arr) {
      presum += n;

      if (presum & 1) {
        ans = (ans + even_presum_cnt) % (static_cast<int>(1e9) + 7);
        ++odd_presum_cnt;
      } else {
        ans = (ans + odd_presum_cnt) % (static_cast<int>(1e9) + 7);
        ++even_presum_cnt;
      }
    }

    return ans;
  }
};
// Runtime: 352 ms, faster than 74.21%
// Memory Usage: 108.2 MB, less than 60.27%

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    int presum = 0;
    int even_presum_cnt = 1;
    int odd_presum_cnt = 0;

    int ans = 0;

    for (auto n : arr) {
      presum += n;

      if (presum & 1) {
        ans = ans + even_presum_cnt;
        ++odd_presum_cnt;
      } else {
        ans = ans + odd_presum_cnt;
        ++even_presum_cnt;
      }

      ans %= static_cast<int>(1e9) + 7;
    }

    return ans;
  }
};
// Runtime: 400 ms, faster than 56.81%
// Memory Usage: 108.1 MB, less than 82.27%