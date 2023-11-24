class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> cd;
    vector<pair<int, char>> t(26);

    int cnt = 0;
    for (auto task : tasks) {
      t[task - 'A'] = {++t[task - 'A'].first, task};
      ++cnt;
    }

    int ans = 0;

    while (cnt > 0) {
      sort(t.rbegin(), t.rend());

      char next = 'x';

      for (auto& [c, task] : t) {
        if (c > 0 && cd[task] == 0) {
          next = task;
          --c;
          break;
        }
      }

      for (auto& c : cd) {
        if (c.second > 0) {
          --c.second;
        }
      }

      if (next != 'x') {
        cd[next] = n;
        --cnt;
      }

      ++ans;
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mp;

    int max = 0;
    for (auto t : tasks) {
      ++mp[t - 'A'];

      max = ::max(mp[t - 'A'], max);
    }

    int ans = (max - 1) * (n + 1);

    for (auto m : mp) {
      if (m.second == max) {
        ++ans;
      }
    }

    return ::max(ans, static_cast<int>(tasks.size()));
  }
};
// Runtime: 152 ms, faster than 68.63%
// Memory Usage: 34.6 MB, less than 60.52%

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mp;

    int max = 0;
    int maxCount = 0;

    for (auto t : tasks) {
      ++mp[t];

      if (max == mp[t]) {
        ++maxCount;
      } else if (max < mp[t]) {
        max = mp[t];
        maxCount = 1;
      }
    }

    int emptySlots = (max - 1) * (n - (maxCount - 1));
    int t = tasks.size() - (max * maxCount);

    int idle = ::max(0, emptySlots - t);

    return tasks.size() + idle;
  }
};
// Runtime: 180 ms, faster than 54.80%
// Memory Usage: 34.7 MB, less than 35.43%