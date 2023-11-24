class Solution {
 public:
  int maximumProduct(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

    while (k-- > 0) {
      auto n = pq.top();
      pq.pop();
      pq.push(n + 1);
    }

    long long ans = 1;
    int mod = 1e9 + 7;

    while (!pq.empty()) {
      ans = (ans * pq.top()) % mod;
      pq.pop();
    }

    return ans;
  }
};
// Runtime: 460 ms, faster than 30.00%
// Memory Usage: 85.8 MB, less than 10.00%
// 2022.4.11 at 奥盛大厦

class Solution {
 public:
  int maximumProduct(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end(), greater<int>());

    while (k-- > 0) {
      pop_heap(nums.begin(), nums.end(), greater<int>());
      ++nums.back();
      push_heap(nums.begin(), nums.end(), greater<int>());
    }

    return accumulate(nums.begin(), nums.end(), 1LL, [](long long res, int n) {
      return res * n % 1000000007;
    });
  }
};
// Runtime: 524 ms, faster than 30.00%
// Memory Usage: 82.1 MB, less than 20.00%
// 2022.4.11 at 奥盛大厦