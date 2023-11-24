class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<vector<int>> tmp(n);
    for (int i = 0; i < n; ++i) {
      tmp[i].push_back(tasks[i][0]);
      tmp[i].push_back(i);
    }
    sort(tmp.begin(), tmp.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    long long cur = 1;

    vector<int> ans;
    int i = 0;
    while (i < tmp.size() || pq.size() > 0) {
      for (; i < tmp.size(); ++i) {
        int& enqueue = tmp[i][0];
        int& idx = tmp[i][1];
        int& process = tasks[idx][1];
        if (enqueue > cur) {
          break;
        }

        pq.push({process, idx});
      }

      if (pq.empty()) {
        ++cur;
        continue;
      }

      auto next = pq.top();
      pq.pop();

      cur += next.first;
      ans.push_back(next.second);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<vector<int>> tmp(n);
    for (int i = 0; i < n; ++i) {
      tmp[i].push_back(tasks[i][0]);
      tmp[i].push_back(i);
    }
    sort(tmp.begin(), tmp.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    long long cur = tmp[0][0];

    vector<int> ans;
    int i = 0;
    while (i < tmp.size() || pq.size() > 0) {
      for (; i < tmp.size(); ++i) {
        int& enqueue = tmp[i][0];
        int& idx = tmp[i][1];
        int& process = tasks[idx][1];
        if (enqueue > cur) {
          break;
        }

        pq.push({process, idx});
      }

      if (pq.empty()) {
        ++cur;
        continue;
      }

      auto next = pq.top();
      pq.pop();

      cur += next.first;
      ans.push_back(next.second);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<vector<int>> tmp(n);
    for (int i = 0; i < n; ++i) {
      tmp[i].push_back(tasks[i][0]);
      tmp[i].push_back(i);
    }
    sort(tmp.begin(), tmp.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    long long cur = tmp[0][0];

    vector<int> ans;
    int i = 0;
    while (i < tmp.size() || pq.size() > 0) {
      for (; i < tmp.size(); ++i) {
        int& enqueue = tmp[i][0];
        int& idx = tmp[i][1];
        int& process = tasks[idx][1];
        if (enqueue > cur) {
          break;
        }

        pq.push({process, idx});
      }

      if (pq.empty()) {
        cur = tmp[i][0];
        continue;
      }

      auto next = pq.top();
      pq.pop();

      cur += next.first;
      ans.push_back(next.second);
    }

    return ans;
  }
};
// Runtime: 1461 ms, faster than 17.19%
// Memory Usage: 151.6 MB, less than 24.48%
// 2022.9.30 at 奥盛大厦