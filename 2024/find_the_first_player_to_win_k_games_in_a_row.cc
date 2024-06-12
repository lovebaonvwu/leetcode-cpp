class Solution {
 public:
  int findWinningPlayer(vector<int>& skills, int k) {
    deque<array<int, 3>> dq;
    for (int i = 0; i < skills.size(); ++i) {
      dq.push_back({skills[i], i, 0});
    }

    while (dq.size()) {
      auto A = dq.front();
      dq.pop_front();

      auto B = dq.front();
      dq.pop_front();

      if (A[0] > B[0]) {
        ++A[2];
        if (A[2] == k) {
          return A[1];
        }
        dq.push_front(A);
        dq.push_back(B);
      } else {
        ++B[2];
        if (B[2] == k) {
          return B[1];
        }
        dq.push_front(B);
        dq.push_back(A);
      }
    }

    return -1;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int findWinningPlayer(vector<int>& skills, int k) {
    int i = 0, cnt = 0;
    int n = skills.size();
    for (int j = 1; j < n; ++j) {
      if (skills[i] < skills[j]) {
        cnt = 0;
        i = j;
      }

      if (++cnt == k)
        break;
    }

    return i;
  }
};
// 162 ms
// 118.91 MB
