class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto a : arr) {
            ++mp[(a % k + k) % k];
        }

        for (auto [rem, val] : mp) {
            if (rem == 0) {
                if (val % 2 != 0) {
                    return false;
                }
            } else {
                if (val != mp[k - rem]) {
                    return false;
                }
            }
        }

        return true;
    }
};
// 118 ms
// 73.65 MB
