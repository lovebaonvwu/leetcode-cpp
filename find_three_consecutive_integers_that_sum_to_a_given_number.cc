class Solution {
 public:
  vector<long long> sumOfThree(long long num) {
    vector<long long> ans;

    if (num % 3 != 0) {
      return ans;
    }

    long long n = num / 3;
    ans.push_back(n - 1);
    ans.push_back(n);
    ans.push_back(n + 1);

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 25.91%
// 2022.2.22 at 奥盛大厦