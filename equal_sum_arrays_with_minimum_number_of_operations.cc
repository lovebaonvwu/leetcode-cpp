class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() * 1 > nums2.size() * 6 ||
        nums1.size() * 6 < nums2.size() * 1) {
      return -1;
    }

    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    if (sum1 > sum2) {
      swap(nums1, nums2);
    }

    priority_queue<int, vector<int>, greater<int>> q1(nums1.begin(),
                                                      nums1.end());
    priority_queue<int> q2(nums2.begin(), nums2.end());

    int ans = 0, diff = abs(sum1 - sum2);

    while (diff > 0) {
      ++ans;

      if (q1.empty() || (!q2.empty() && (q2.top() - 1 > 6 - q1.top()))) {
        diff -= q2.top() - 1;
        q2.pop();
      } else {
        diff -= 6 - q1.top();
        q1.pop();
      }
    }

    return ans;
  }
};
// Runtime: 164 ms, faster than 16.67%
// Memory Usage: 117.6 MB, less than 33.33%

class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() * 1 > nums2.size() * 6 ||
        nums1.size() * 6 < nums2.size() * 1) {
      return -1;
    }

    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    if (sum1 > sum2) {
      swap(nums1, nums2);
    }

    int points[6] = {0};
    for (auto n : nums1) {
      ++points[6 - n];
    }

    for (auto n : nums2) {
      ++points[n - 1];
    }

    int diff = abs(sum1 - sum2);

    int ans = 0;
    for (int i = 5, cnt = 0; i > 0 && diff > 0; --i) {
      cnt = min(points[i], (diff + i - 1) / i);

      diff -= cnt * i;

      ans += cnt;
    }

    return ans;
  }
};
// Runtime: 104 ms, faster than 83.33%
// Memory Usage: 113.7 MB, less than 33.33%