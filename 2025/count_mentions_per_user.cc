class Solution {
    void handleMessage(const vector<int>& offline, vector<int>& ans, int t, const string& m) {
        stringstream ss(m);
        string s;
        vector<string> ids;

        while (ss >> s) {
            ids.push_back(s);
        }

        for (auto id : ids) {
            if (id == "ALL") {
                for (int i = 0; i < ans.size(); ++i) {
                    ++ans[i];
                }
            } else if (id == "HERE") {
                for (int i = 0; i < ans.size(); ++i) {
                    if (offline[i] == 0 || offline[i] + 60 <= t) {
                        ++ans[i];
                    }
                }
            } else {
                int idx = stoi(id.substr(2));
                ++ans[idx];
            }
        }
    }

    void handleOffline(vector<int>& offline, int t, const string& m) {
        int id = stoi(m);
        offline[id] = t;
    }
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(begin(events), end(events), [&](auto& a, auto& b) {
            return stoi(a[1]) == stoi(b[1]) ? a[0] > b[0] : stoi(a[1]) < stoi(b[1]);
        });

        vector<int> ans(numberOfUsers);
        vector<int> offline(numberOfUsers);

        for (auto& e : events) {
            if (e[0] == "MESSAGE") {
                handleMessage(offline, ans, stoi(e[1]), e[2]);
            } else {
                handleOffline(offline, stoi(e[1]), e[2]);
            }
        }

        return ans;
    }
};
// 44 ms
// 55.70 MB