class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(rbegin(enemyEnergies), rend(enemyEnergies));

        long long ans = 0;
        int n = enemyEnergies.size();

        for (int i = 0; i < n; ++i) {
            if (currentEnergy >= enemyEnergies[n - 1]) {
                int cnt = currentEnergy / enemyEnergies[n - 1];
                ans += cnt;
                currentEnergy -= enemyEnergies[n - 1] * cnt;
            }

            if (ans > 0) {
                currentEnergy += enemyEnergies[i];
            }
        }

        return ans;
    }
};
// 153 ms
// 78.07 MB
