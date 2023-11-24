class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> stk;

    for (int a : asteroids) {
      if (a > 0 || stk.empty() || stk.top() < 0) {
        stk.push(a);
        continue;
      }

      while (a < 0 && !stk.empty() && stk.top() > 0) {
        int b = stk.top();

        stk.pop();

        if (a + b > 0) {
          stk.push(b);
          break;
        } else if (a + b == 0) {
          break;
        } else if (stk.empty() || stk.top() < 0) {
          stk.push(a);
        }
      }
    }

    vector<int> ans(stk.size());

    for (int i = stk.size() - 1; i >= 0; --i) {
      ans[i] = stk.top();

      stk.pop();
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 95.41%
// Memory Usage: 18.3 MB, less than 95.21%

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;

    for (int i = 0; i < asteroids.size(); ++i) {
      if (asteroids[i] > 0 || ans.empty() || ans.back() < 0) {
        ans.push_back(asteroids[i]);
        continue;
      }

      if (ans.back() + asteroids[i] <= 0) {
        if (ans.back() + asteroids[i] < 0)
          --i;
        ans.pop_back();
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 56.43%
// Memory Usage: 17.8 MB, less than 95.21%