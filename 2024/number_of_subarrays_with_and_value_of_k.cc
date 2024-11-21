class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;

        unordered_map<int, long long> cnt;
        for (auto num : nums) {
            unordered_map<int, long long> tmp;
            for (auto [x, c] : cnt) {
                tmp[x & num] += c;
            }

            ++tmp[num];

            if (tmp.find(k) != tmp.end()) {
                ans += tmp[k];
            }

            cnt = tmp;
        }

        return ans;
    }
};
// 829 ms
// 385.88 MB

