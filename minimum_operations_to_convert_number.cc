class Solution {
  static int Add(int a, int b) { return a + b; }

  static int Sub(int a, int b) { return a - b; }

  static int Xor(int a, int b) { return a ^ b; }

  using func = int(int, int);

  func* op[3] = {Add, Sub, Xor};

 public:
  int minimumOperations(vector<int>& nums, int start, int goal) {
    int ans = 0;

    queue<int> q;
    q.push(start);

    unordered_set<int> visited;
    visited.insert(start);

    while (!q.empty()) {
      ++ans;

      int cnt = q.size();

      while (cnt-- > 0) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < nums.size(); ++j) {
            int dx = (*op[i])(x, nums[j]);

            if (dx == goal) {
              return ans;
            }

            if (visited.find(dx) != visited.end()) {
              continue;
            }

            if (dx < 0 || dx > 1000) {
              continue;
            }

            q.push(dx);
            visited.insert(dx);
          }
        }
      }
    }

    return -1;
  }
};
// Runtime: 396 ms, faster than 45.84%
// Memory Usage: 10.6 MB, less than 61.22%
// 2021.12.5 at 茗筑美嘉