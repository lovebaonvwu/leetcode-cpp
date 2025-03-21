using State = tuple<int, int, int, bool, bool>;

class Solution {
    vector<int> digits;
    map<State, int> cached;
public:
    int beautifulNumbers(int l, int r) {
        return count(r) - count(l - 1);
    }

    int count(int n) {
        digits.clear();
        cached.clear();

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(begin(digits), end(digits));

        return dfs(0, 0, 1, true, true);
    }

    int dfs(int pos, int sum, int prod, bool isTight, bool isLeadingZero) {
        if (pos == digits.size()) {
            return (sum > 0 && (prod % sum == 0));
        }

        State key = {pos, sum, prod, isTight, isLeadingZero};
        if (cached.find(key) != cached.end()) {
            return cached[key];
        }

        int limit = isTight ? digits[pos] : 9;
        int ret = 0;
        for (int d = 0; d <= limit; ++d) {
            ret += dfs(
                        pos + 1, 
                        sum + d, 
                        (isLeadingZero && d == 0) ? 1 : prod * d,
                        isTight && (d == limit),
                        isLeadingZero && (d == 0));
        }

        return cached[key] = ret;
    }
};
// Time: O(9*81*30xx*2*2)
// Space: O(9*81*30xx*2*2)
