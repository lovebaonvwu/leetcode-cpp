class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;

    for (int i = 0; i < heights.size(); ++i) {
      int low = i;

      while (low - 1 >= 0) {
        if (heights[low - 1] < heights[i]) {
          break;
        }

        --low;
      }

      int high = i;

      while (high + 1 < heights.size()) {
        if (heights[high + 1] < heights[i]) {
          break;
        }

        ++high;
      }

      ans = max(ans, (high - low + 1) * heights[i]);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    stack<pair<int, int>> stk;
    vector<int> low(n);

    for (int i = 0; i < n; ++i) {
      if (stk.empty()) {
        low[i] = 0;
        stk.push({heights[i], i});
      } else {
        if (heights[i] > stk.top().first) {
          low[i] = i;
          stk.push({heights[i], i});
        } else {
          while (!stk.empty() && stk.top().first >= heights[i]) {
            stk.pop();
          }

          low[i] = stk.empty() ? 0 : stk.top().second + 1;
          stk.push({heights[i], i});
        }
      }
    }

    while (!stk.empty()) {
      stk.pop();
    }

    vector<int> high(n);

    for (int i = n - 1; i >= 0; --i) {
      if (stk.empty()) {
        high[i] = n - 1;
        stk.push({heights[i], i});
      } else {
        if (heights[i] > stk.top().first) {
          high[i] = i;
          stk.push({heights[i], i});
        } else {
          while (!stk.empty() && stk.top().first >= heights[i]) {
            stk.pop();
          }

          high[i] = stk.empty() ? n - 1 : stk.top().second - 1;
          stk.push({heights[i], i});
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, (high[i] - low[i] + 1) * heights[i]);
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 63.35%
// Memory Usage: 15.1 MB, less than 20.07%

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);

    int n = heights.size();

    stack<int> stk;

    int ans = 0;

    for (int i = 0; i < n;) {
      if (stk.empty() || heights[i] >= heights[stk.top()]) {
        stk.push(i++);
      } else {
        auto idx = stk.top();
        stk.pop();

        ans = max(ans, heights[idx] * (stk.empty() ? i : i - stk.top() - 1));
      }
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 63.35%
// Memory Usage: 14.6 MB, less than 43.39%