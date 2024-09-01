class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        vector<int> nums;
        while (num1 > 0 && num2 > 0 && num3 > 0) {
            nums.push_back(min({num1 % 10, num2 % 10, num3 % 10}));
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }

        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans = ans * 10 + nums[i];
        }

        return ans;
    }
};
// 5 ms
// 8.45 MB
