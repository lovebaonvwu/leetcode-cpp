class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();

        vector<int> time;
        for (int i = 0; i < n; ++i) {
            time.push_back((health[i] + power - 1) / power);
        }

        vector<int> enemy(n);
        iota(begin(enemy), end(enemy), 0);

        sort(begin(enemy), end(enemy), [&](int i, int j) {
            return damage[i] * time[j] > damage[j] * time[i];
        });

        long long ans = 0;
        long long cur = 0;

        for (int i = 0; i < n; ++i) {
            cur += time[enemy[i]];
            ans += damage[enemy[i]] * cur;
        }

        return ans;
    }
};
// 223 ms
// 145.76 MB
