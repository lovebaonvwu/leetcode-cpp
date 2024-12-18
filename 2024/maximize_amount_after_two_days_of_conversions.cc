class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string, double>>> g1;
        for (int i = 0; i < pairs1.size(); ++i) {
            auto from = pairs1[i][0];
            auto to = pairs1[i][1];
            auto rate = rates1[i];
            g1[from].push_back({to, rate});
            g1[to].push_back({from, 1.0 / rate});
        }
        unordered_map<string, vector<pair<string, double>>> g2;
        for (int i = 0; i < pairs2.size(); ++i) {
            auto from = pairs2[i][0];
            auto to = pairs2[i][1];
            auto rate = rates2[i];
            g2[from].push_back({to, rate});
            g2[to].push_back({from, 1.0 / rate});
        }

        unordered_map<string, double> maxOnDay1;
        maxOnDay1[initialCurrency] = 1;
        queue<pair<string, double>> q;
        q.push({initialCurrency, 1});

        while (!q.empty()) {
            auto [cur, value] = q.front();
            q.pop();

            for (auto& [next, rate] : g1[cur]) {
                if (value * rate > maxOnDay1[next]) {
                    maxOnDay1[next] = value * rate;
                    q.push({next, value * rate});
                }
            }
        }

        unordered_map<string, double> maxOnDay2;
        for (auto& [node, value] : maxOnDay1) {
            q.push({node, value});
        }

        while (!q.empty()) {
            auto [cur, value] = q.front();
            q.pop();

            for (auto& [next, rate] : g2[cur]) {
                if (value * rate > maxOnDay2[next]) {
                    maxOnDay2[next] = value * rate;
                    q.push({next, value * rate});
                }
            }
        }

        return max(maxOnDay2[initialCurrency], 1.0);
    }
};
// 7 ms
// 82.21 MB
