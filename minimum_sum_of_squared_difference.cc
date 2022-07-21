class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1,
                             vector<int>& nums2,
                             int k1,
                             int k2) {
    priority_queue<long long> pq;

    for (int i = 0; i < nums1.size(); ++i) {
      pq.push(abs(nums1[i] - nums2[i]));
    }

    while (!pq.empty() && (k1 > 0 || k2 > 0)) {
      int n = pq.top();
      pq.pop();

      if (k1 > 0) {
        --n;
        --k1;
      } else if (k2 > 0) {
        --n;
        --k2;
      }

      if (n > 0) {
        pq.push(n);
      }
    }

    long long ans = 0;
    while (!pq.empty()) {
      ans += pq.top() * pq.top();
      pq.pop();
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1,
                             vector<int>& nums2,
                             int k1,
                             int k2) {
    for (int i = 0; i < nums1.size(); ++i) {
      nums1[i] = (abs(nums1[i] - nums2[i]));
    }

    int M = *max_element(nums1.begin(), nums1.end());
    vector<int> diff(M + 1);

    for (auto n : nums1) {
      ++diff[n];
    }

    int k = k1 + k2;

    for (int i = M; i > 0 && k > 0; --i) {
      if (diff[i] > 0) {
        int minus = min(k, diff[i]);
        diff[i] -= minus;
        diff[i - 1] += minus;
        k -= minus;
      }
    }

    long long ans = 0;
    for (int i = M; i > 0; --i) {
      ans += 1LL * diff[i] * i * i;
    }

    return ans;
  }
};
// Runtime: 363 ms, faster than 59.95%
// Memory Usage: 100.1 MB, less than 87.03%
// 2022.7.21 at 奥盛大厦