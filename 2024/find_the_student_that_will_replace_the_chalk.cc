class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = accumulate(begin(chalk), end(chalk), 0LL);
        k -= total * (k / total);

        int n = chalk.size();
        int ans = 0;
        while (ans < n && k >= chalk[ans]) {
            k -= chalk[ans++];
        }

        return ans;
    }
};
// 97 ms
// 76.88 MB
