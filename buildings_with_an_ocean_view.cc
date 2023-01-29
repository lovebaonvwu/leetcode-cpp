class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    stack<int> stk;
    vector<int> ans;
    for (int i = heights.size() - 1; i >= 0; --i) {
      while (!stk.empty() && heights[i] > heights[stk.top()]) {
        stk.pop();
      }

      if (stk.empty()) {
        ans.push_back(i);
      }

      stk.push(i);
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime 179 ms
// Memory 68.8 MB
// 2023.1.29 at 奥盛大厦

class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    int maxh = -1;
    vector<int> ans;
    for (int i = heights.size() - 1; i >= 0; --i) {
      if (heights[i] > maxh) {
        ans.push_back(i);
      }

      maxh = max(maxh, heights[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime 147 ms
// Memory 68.8 MB
// 2023.1.29 at 奥盛大厦