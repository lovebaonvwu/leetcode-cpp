class Solution {
 public:
  string triangleType(vector<int>& nums) {
    sort(begin(nums), end(nums));
    int a = nums[0];
    int b = nums[1];
    int c = nums[2];

    if (a + b <= c)
      return "none";

    if (a == b && a == c)
      return "equilateral";
    else if (a == b || a == c || b == c)
      return "isosceles";
    else
      return "scalene";
  }
};
// 3 ms
// 22.16 MB