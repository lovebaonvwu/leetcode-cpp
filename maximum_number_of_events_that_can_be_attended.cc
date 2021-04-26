class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    int ans = 0;
    char attended[100001] = {0};

    for (auto& e : events) {
      for (int i = e[0]; i <= e[1]; ++i) {
        if (!attended[i]) {
          attended[i] = 1;
          ++ans;
          break;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    int min_d = INT_MAX;
    int max_d = INT_MIN;

    for (auto& e : events) {
      min_d = min(min_d, e[0]);
      max_d = max(max_d, e[1]);
    }

    vector<int> days(max_d - min_d + 1);

    iota(days.begin(), days.end(), min_d);

    set<int> st(days.begin(), days.end());

    int ans = 0;
    for (auto& e : events) {
      auto it = st.lower_bound(e[0]);

      if (it != st.end() && *it <= e[1]) {
        st.erase(it);
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 456 ms, faster than 26.44%
// Memory Usage: 113.8 MB, less than 18.01%