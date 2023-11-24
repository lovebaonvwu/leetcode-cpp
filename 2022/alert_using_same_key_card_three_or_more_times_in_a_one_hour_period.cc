class Solution {
 public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    vector<pair<string, int>> times;
    for (int i = 0; i < keyTime.size(); ++i) {
      times.push_back({keyTime[i], i});
    }

    sort(times.begin(), times.end());

    unordered_map<string,
                  priority_queue<string, vector<string>, greater<string>>>
        mp;

    set<string> st;

    for (int i = 0; i < times.size(); ++i) {
      string& name = keyName[times[i].second];
      string& time = times[i].first;

      if (mp.find(name) == mp.end()) {
        mp[name].push(time);
        continue;
      }

      auto prevTime = mp[name].top();
      if (overOneHour(prevTime, time)) {
        mp[name].pop();
      }

      mp[name].push(time);

      if (mp[name].size() > 2) {
        st.insert(name);
      }
    }

    return vector<string>(st.begin(), st.end());
  }

 private:
  bool overOneHour(const string& a, const string& b) {
    int hh = ((a[0] - '0') * 10 + (a[1] - '0'));
    int mm = ((a[3] - '0') * 10 + (a[4] - '0'));
    int t1 = hh * 3600 + mm * 60;

    hh = ((b[0] - '0') * 10 + (b[1] - '0'));
    mm = ((b[3] - '0') * 10 + (b[4] - '0'));
    int t2 = hh * 3600 + mm * 60;

    return abs(t1 - t2) > 3600;
  }
};
// Runtime: 638 ms, faster than 18.91%
// Memory Usage: 122.2 MB, less than 25.65%
// 2022.2.11 at 奥盛大厦