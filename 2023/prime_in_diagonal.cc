class Solution {
  bool notPrime[4000001];

 public:
  int diagonalPrime(vector<vector<int>>& nums) {
    getPrime();
    int ans = 0;
    for (int i = 0, n = nums.size(); i < n; ++i) {
      ans = max(ans, notPrime[nums[i][i]] ? -1 : nums[i][i]);
      ans = max(ans, notPrime[nums[i][n - i - 1]] ? -1 : nums[i][n - i - 1]);
    }

    return ans;
  }

 private:
  void getPrime() {
    notPrime[0] = notPrime[1] = true;

    for (int i = 2; i * i < 4000001; ++i) {
      if (!notPrime[i]) {
        for (int j = i * i; j < 4000001; j += i) {
          notPrime[j] = true;
        }
      }
    }
  }
};
// Runtime 1547 ms
// Memory 40.1 MB