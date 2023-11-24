class Solution {
 public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int g = numsDivide[0];

    for (int i = 1; i < numsDivide.size(); ++i) {
      g = gcd(g, numsDivide[i]);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (g % nums[i] == 0) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 233 ms, faster than 50.00%
// Memory Usage: 88.2 MB, less than 25.00%
// 2022.7.22 at 奥盛大厦

class Solution {
 public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int g = numsDivide[0];

    for (int i = 1; i < numsDivide.size(); ++i) {
      g = gcd(g, numsDivide[i]);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() && nums[i] <= g; ++i) {
      if (g % nums[i] == 0) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 199 ms, faster than 50.00%
// Memory Usage: 88.1 MB, less than 25.00%
// 2022.7.22 at 奥盛大厦