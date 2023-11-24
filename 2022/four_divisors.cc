class Solution {
 public:
  int sumFourDivisors(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    for (auto& [n, cnt] : mp) {
      int sum = 0, k = 0;
      for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
          ++k;
          sum += i;
        }
      }

      ans += k == 4 ? sum * cnt : 0;
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int sumFourDivisors(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    for (auto& [n, cnt] : mp) {
      int sum = 0, k = 0;
      for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
          if (i * i == n) {
            k += 1;
            sum += i;
          } else {
            k += 2;
            sum += i;
            sum += n / i;
          }
        }
      }

      ans += k == 4 ? sum * cnt : 0;
    }

    return ans;
  }
};
// Runtime 64 ms
// Memory 15 MB
// 2022.11.18 at 奥盛大厦