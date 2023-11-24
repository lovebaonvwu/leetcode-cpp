class Solution {
  long long reverse(long long n, int intLength) {
    long long ret = 0;

    n = intLength & 1 ? n / 10 : n;

    while (n > 0) {
      ret = ret * 10 + n % 10;
      n /= 10;
    }

    return ret;
  }

 public:
  vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    long long start = pow(10, (intLength + 1) / 2 - 1);
    long long end = pow(10, (intLength + 1) / 2);
    long long mul = pow(10, intLength / 2);

    vector<long long> ans;
    for (auto q : queries) {
      if (start + q - 1 >= end) {
        ans.push_back(-1);
      } else {
        long long tail = reverse(start + q - 1, intLength);

        ans.push_back((start + q - 1) * mul + tail);
      }
    }

    return ans;
  }
};
// Runtime: 210 ms, faster than 69.09%
// Memory Usage: 54.1 MB, less than 39.00%
// 2022.3.30 at 奥盛大厦