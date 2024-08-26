class Solution {

    bool almostEqual(int target, int num) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        reverse(begin(digits), end(digits));

        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(digits[i], digits[j]);

                int val = 0;
                for (auto d : digits) {
                    val = val * 10 + d;
                }

                if (val == target) {
                    return true;
                }
                swap(digits[i], digits[j]);
            }
        }

        return false;
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j] || 
                    almostEqual(nums[i], nums[j]) ||
                    almostEqual(nums[j], nums[i])) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
// 615 ms
// 165.2 MB