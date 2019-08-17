class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    stack<int> stk;
    queue<int> q;
    vector<int> ans;

    for (auto& a : A) {
      if (a < 0) {
        stk.push(-a);
      } else {
        q.push(a);
      }
    }

    while (!stk.empty() && !q.empty()) {
      if (stk.top() < q.front()) {
        ans.push_back(pow(stk.top(), 2));
        stk.pop();
      } else {
        ans.push_back(pow(q.front(), 2));
        q.pop();
      }
    }

    while (!stk.empty()) {
      ans.push_back(pow(stk.top(), 2));
      stk.pop();
    }

    while (!q.empty()) {
      ans.push_back(pow(q.front(), 2));
      q.pop();
    }

    return ans;
  }
};  // 100ms

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    if (A.size() == 0) {
      return {};
    }

    vector<int> ans;

    int idx = 0;

    while (idx < A.size() && A[idx] < 0) {
      ++idx;
    }

    int i = idx - 1;
    int j = idx;

    while (i >= 0 && j < A.size()) {
      if (-A[i] < A[j]) {
        ans.push_back(A[i] * A[i]);
        --i;
      } else {
        ans.push_back(A[j] * A[j]);
        ++j;
      }
    }

    while (i >= 0) {
      ans.push_back(A[i] * A[i]);
      --i;
    }

    while (j < A.size()) {
      ans.push_back(A[j] * A[j]);
      ++j;
    }

    return ans;
  }
};  // 100ms