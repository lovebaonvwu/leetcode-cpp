class Solution {

    vector<int> buildPrimesScore(int n) {
        vector<int> primesScore(n + 1);

        for (int i = 2; i <= n; ++i) {
            if (primesScore[i] == 0) {
                for (int j = i; j <= n; j += i) {
                    ++primesScore[j];
                }
            }
        }

        return primesScore;
    }

    long long quickMul(int num, long long cnt) {
        int mod = 1e9 + 7;
        long long ret = 1;

        while (cnt-- > 0) {
            ret = (ret * num) % mod;
        }

        return ret;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int maxnum = *max_element(begin(nums), end(nums));
        vector<int> scoresMap = buildPrimesScore(maxnum);

        vector<int> scores(n);
        for (int i = 0; i < n; ++i) {
            scores[i] = scoresMap[nums[i]];
        }

        vector<int> prevLarger(n, -1);
        vector<int> nextLarger(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && scores[i] > scores[stk.top()]) {
                nextLarger[stk.top()] = i;
                stk.pop();
            }

            if (!stk.empty()) {
                prevLarger[i] = stk.top();
            }

            stk.push(i);
        }

        priority_queue<pair<int, long long>> pq;
        for (int i = 0; i < n; ++i) {
            long long count = 1LL * (i - prevLarger[i]) * (nextLarger[i] - i);
            pq.push({nums[i], count});
        }

        long long ans = 1;
        int mod = 1e9 + 7;
        while (k > 0) {
            auto [num, cnt] = pq.top();
            pq.pop();

            int opers = min(1LL * k, cnt);
            k -= opers;

            ans = (ans * quickMul(num, opers)) % mod;
        }

        return ans;
    }
};

// Time: O(n^2log(n))
// Space: O(n)

class Solution {

    vector<int> buildPrimesScore(int n) {
        vector<int> primesScore(n + 1);

        for (int i = 2; i <= n; ++i) {
            if (primesScore[i] == 0) {
                for (int j = i; j <= n; j += i) {
                    ++primesScore[j];
                }
            }
        }

        return primesScore;
    }

    long long quickMul(long long num, long long cnt) {
        long long ret = 1;

        int mod = 1e9 + 7;

        while (cnt > 0) {
            if (cnt & 1) {
                ret = (ret * num) % mod;
            }

            num = (num * num) % mod;

            cnt /= 2;
        }

        return ret;
    }
    
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int maxnum = *max_element(begin(nums), end(nums));
        vector<int> scoresMap = buildPrimesScore(maxnum);

        vector<int> scores(n);
        for (int i = 0; i < n; ++i) {
            scores[i] = scoresMap[nums[i]];
        }

        vector<int> prevLarger(n, -1);
        vector<int> nextLarger(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && scores[i] > scores[stk.top()]) {
                nextLarger[stk.top()] = i;
                stk.pop();
            }

            if (!stk.empty()) {
                prevLarger[i] = stk.top();
            }

            stk.push(i);
        }

        priority_queue<pair<int, long long>> pq;
        for (int i = 0; i < n; ++i) {
            long long count = 1LL * (i - prevLarger[i]) * (nextLarger[i] - i);
            pq.push({nums[i], count});
        }

        long long ans = 1;
        int mod = 1e9 + 7;
        while (k > 0) {
            auto [num, cnt] = pq.top();
            pq.pop();

            int opers = min(1LL * k, cnt);
            k -= opers;

            ans = (ans * quickMul(num, opers)) % mod;
        }

        return ans;
    }
}

// Time: O(nlog(n))
// Space: O(n)