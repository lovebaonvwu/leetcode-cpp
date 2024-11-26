class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        int n = s.size();

        function<long long(char, char)> next = [&](char cur, char target) -> long long {
            long long ret = 0;

            long long total = accumulate(begin(nextCost), end(nextCost), 0LL);

            if (cur > target) {
                long long sum = 0;
                for (int i = target; i < cur; ++i) {
                    sum += nextCost[i - 'a'];
                }

                ret = total - sum;
            } else if (cur < target) {
                long long sum = 0;
                for (int i = cur; i < target; ++i) {
                    sum += nextCost[i - 'a'];
                }

                ret = sum;
            } 

            return ret;
        };

        function<long long(char, char)> prev = [&](char cur, char target) -> long long {
            long long ret = 0;

            long long total = accumulate(begin(previousCost), end(previousCost), 0LL);

            if (cur < target) {
                long long sum = 0;
                for (int i = cur + 1; i <= target; ++i) {
                    sum += previousCost[i - 'a'];
                }

                ret = total - sum;
            } else if (cur > target) {
                long long sum = 0;
                for (int i = cur; i > target; --i) {
                    sum += previousCost[i - 'a'];
                }

                ret = sum;
            } 

            return ret;
        };

        for (int i = 0; i < n; ++i) {
            ans += min(next(s[i], t[i]), prev(s[i], t[i]));
        }

        return ans;
    }
};
// 177 ms
// 53.31 MB

