class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> right(n);
        right[n - 1] = s[n - 1] == '1';
        
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '1') {
                right[i] += right[i + 1] + 1;
            }
        }

        int ans = 0;
        for (int k = 1; k <= 200; ++k) {
            int j = 0;
            int zeros = 0;
            for (int i = 0; i < n; ++i) {
                while (j < n && zeros < k) {
                    zeros += s[j++] == '0';
                }

                if (zeros < k) {
                    break;
                }

                int ones = j - i - zeros;

                if (j < n && ones + right[j] >= zeros * zeros) {
                    if (zeros * zeros - ones >= 0) {
                        ans += right[j] - (zeros * zeros - ones) + 1;
                    } else {
                        ans += right[j] + 1;
                    }
                } else if (ones >= zeros * zeros) {
                    ++ans;
                }

                zeros -= s[i] == '0';
            }
        }

        for (int i = 0; i < n; ++i) {
            ans += right[i];
        }

        return ans;
    }
};
// 556 ms
// 16.58 MB