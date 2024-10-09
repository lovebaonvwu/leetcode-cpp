class Solution {
    vector<int> toBinaryArray(int n) {
        vector<int> ret;
        while (n > 0) {
            ret.push_back(n % 2);
            n /= 2;
        }

        reverse(begin(ret), end(ret));

        return ret;
    }
    int build(int a, int b, int c) {
        vector<int> tmpa = toBinaryArray(a);
        vector<int> tmpb = toBinaryArray(b);
        vector<int> tmpc = toBinaryArray(c);

        int ret = 0;
        for (auto n : tmpa) {
            ret = ret * 2 + n;
        }

        for (auto n : tmpb) {
            ret = ret * 2 + n;
        }

        for (auto n : tmpc) {
            ret = ret * 2 + n;
        }

        return ret;
    }
public:
    int maxGoodNumber(vector<int>& nums) {
        return max({
            build(nums[0], nums[1], nums[2]), 
            build(nums[0], nums[2], nums[1]),
            build(nums[1], nums[0], nums[2]),
            build(nums[1], nums[2], nums[0]),
            build(nums[2], nums[0], nums[1]),
            build(nums[2], nums[1], nums[0])
        });
    }
};
// 14 ms
// 27.58 MB