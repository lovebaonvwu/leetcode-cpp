class Solution {
 public:
  int maxScore(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());

    int ans = 0;
    long long sum = 0;
    for (auto n : nums) {
      sum += n;
      ans += sum > 0;
    }

    return ans;
  }
};
// Runtime 240 ms
// Memory 83.2 MB

class Solution {
 public:
  int maxScore(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());

    int ans = 0;
    long long sum = 0;
    for (auto n : nums) {
      sum += n;
      ans += sum > 0;

      if (sum < 0) {
        break;
      }
    }

    return ans;
  }
};
// Runtime 253 ms
// Memory 83.1 MB
