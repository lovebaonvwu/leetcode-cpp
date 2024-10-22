class Solution {
    vector<int> getPrimes(int n) {
        vector<int> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i <= n; ++i) {
            if (primes[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(begin(nums), end(nums));
        vector<int> primes = getPrimes(maxElement);

        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                for (int j = 0; j < primes.size(); ++j) {
                    if (nums[i] % primes[j] == 0) {
                        ++ans;
                        nums[i] = primes[j];
                        break;
                    }
                }

                if (nums[i] > nums[i + 1]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
// 1547 ms
// 315.56 MB
