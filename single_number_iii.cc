class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int aXorB = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    int lastBit = aXorB & -aXorB;

    vector<int> ans{0, 0};

    for (auto& n : nums) {
      if (n & lastBit) {
        ans[0] ^= n;
      } else {
        ans[1] ^= n;
      }
    }

    return ans;
  }
};