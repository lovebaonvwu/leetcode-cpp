class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> mp;
    long long day = 0;

    for (int i = 0; i < tasks.size(); ++i) {
      if (mp.find(tasks[i]) == mp.end()) {
        mp[tasks[i]] = day++;
        continue;
      }

      while (day - mp[tasks[i]] - 1 < space) {
        ++day;
      }

      mp[tasks[i]] = day++;
    }

    return day;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> mp;
    long long day = 0;

    for (int i = 0; i < tasks.size(); ++i) {
      if (mp.find(tasks[i]) == mp.end()) {
        mp[tasks[i]] = day++;
        continue;
      }

      long long cur_space = day - mp[tasks[i]] - 1;
      day += max(0LL, space - cur_space);

      mp[tasks[i]] = day++;
    }

    return day;
  }
};
// Runtime: 430 ms, faster than 100.00%
// Memory Usage: 102.1 MB, less than 100.00%
// 2022.8.11 at 奥盛大厦