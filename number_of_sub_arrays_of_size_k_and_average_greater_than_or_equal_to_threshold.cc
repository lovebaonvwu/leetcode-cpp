class Solution {
 public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    size_t n = arr.size();

    vector<int> presum(n + 1);

    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + arr[i - 1];
    }

    int ans = 0;

    for (int i = k; i < presum.size(); ++i) {
      int sum = presum[i] - presum[i - k];

      if (static_cast<double>(sum) / k >= threshold) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 89.68%
// Memory Usage: 18.6 MB, less than 100.00%

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    size_t n = arr.size();

    int sum = 0;
    sum = accumulate(arr.begin(), arr.begin() + k, 0);

    int ans = 0;

    int l = 0;
    int r = l + k;
    while (r < n) {
      if (static_cast<double>(sum) / k >= threshold) {
        ++ans;
      }

      sum -= arr[l++];
      sum += arr[r++];
    }

    if (static_cast<double>(sum) / k >= threshold) {
      ++ans;
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 89.34%
// Memory Usage: 16.3 MB, less than 100.00%

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    size_t n = arr.size();

    int target = k * threshold;

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      sum += arr[i];

      if (i >= k) {
        sum -= arr[i - k];
      }

      if (i >= k - 1 && sum >= target) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 89.34%
// Memory Usage: 16.3 MB, less than 100.00%

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int window = 0;
    int l = 0;
    int r = 0;

    for (; r < k; ++r) {
      window += arr[r];
    }

    int target = k * threshold;

    int ans = 0;

    if (window >= target) {
      ++ans;
    }

    while (r < arr.size()) {
      window -= arr[l++];
      window += arr[r++];

      if (window >= target) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 70.27%
// Memory Usage: 16.4 MB, less than 100.00%