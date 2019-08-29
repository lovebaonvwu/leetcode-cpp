class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    return max(nums[0] * nums[1] * nums[2],
               nums[nums.size() - 1] * nums[nums.size() - 2] * nums[0]);
  }
};  // 60ms

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int max1 = INT_MIN, max2 = max1, max3 = max2;
    int min1 = INT_MAX, min2 = min1;

    for (const int& n : nums) {
      if (n > max1) {
        max3 = max2;
        max2 = max1;
        max1 = n;
      } else if (n > max2) {
        max3 = max2;
        max2 = n;
      } else if (n > max3) {
        max3 = n;
      }

      if (n < min1) {
        min2 = min1;
        min1 = n;
      } else if (n < min2) {
        min2 = n;
      }
    }

    return max(max1 * max2 * max3, min1 * min2 * max1);
  }
};  // 68ms