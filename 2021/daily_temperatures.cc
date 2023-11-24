class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size(), 0);

    for (int i = T.size() - 2; i >= 0; --i) {
      int j = i + 1;

      while (j < T.size() - 1 && T[i] >= T[j]) {
        if (ans[j] == 0) {
          ans[i] == 0;
          break;
        }

        j += ans[j];
      }

      if (T[i] < T[j]) {
        ans[i] = j - i;
      }
    }

    return ans;
  }
};  // 196ms

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());

    stack<int> stk;

    for (int i = T.size() - 1; i >= 0; --i) {
      while (!stk.empty() && T[stk.top()] <= T[i]) {
        stk.pop();
      }

      ans[i] = stk.empty() ? 0 : stk.top() - i;

      stk.push(i);
    }

    return ans;
  }
};  // 196ms

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());

    stack<pair<int, int>> stk;

    for (int i = T.size() - 1; i >= 0; --i) {
      while (!stk.empty() && stk.top().first <= T[i]) {
        stk.pop();
      }

      ans[i] = stk.empty() ? 0 : stk.top().second - i;

      stk.push({T[i], i});
    }

    return ans;
  }
};  // 204ms

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size(), 0);

    for (int i = 0; i < T.size(); ++i) {
      for (int j = i + 1; j < T.size(); ++j) {
        if (T[j] > T[i]) {
          ans[i] = j - i;
          break;
        }
      }
    }

    return ans;
  }
};  // TLE