class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    vector<int> presum(arr.size() + 1);

    for (int i = 1; i < presum.size(); ++i) {
      presum[i] = presum[i - 1] + arr[i - 1];
    }

    int ans = 0;

    for (int i = 0; i < presum.size(); ++i) {
      for (int j = i; j < presum.size(); ++j) {
        if ((j - i) & 1) {
          ans += presum[j] - presum[i];
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.8 MB, less than 5.07%