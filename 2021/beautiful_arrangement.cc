class Solution {
  int ans = 0;

 public:
  int countArrangement(int N) {
    unordered_set<int> st;

    dfs(N, st);

    return ans;
  }

  void dfs(int N, unordered_set<int>& st) {
    if (st.size() == N) {
      ++ans;
      return;
    }

    for (int i = 1; i <= N; ++i) {
      if (st.count(i) == 0 &&
          (i % (st.size() + 1) == 0 || (st.size() + 1) % i == 0)) {
        st.insert(i);

        dfs(N, st);

        st.erase(i);
      }
    }
  }
};
// Runtime: 1708 ms, faster than 5.30%
// Memory Usage: 57.2 MB, less than 13.85%

class Solution {
 public:
  int countArrangement(int N) {
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
      arr[i] = i + 1;
    }

    return dfs(N, arr);
  }

  int dfs(int N, vector<int>& arr) {
    if (N == 0) {
      return 1;
    }

    int cnt = 0;

    for (int i = 0; i < N; ++i) {
      if (arr[i] % N == 0 || N % arr[i] == 0) {
        swap(arr[i], arr[N - 1]);

        cnt += dfs(N - 1, arr);

        swap(arr[i], arr[N - 1]);
      }
    }

    return cnt;
  }
};
// Runtime: 12 ms, faster than 90.15%
// Memory Usage: 6.4 MB, less than 65.37%