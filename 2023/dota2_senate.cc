class Solution {
 public:
  string predictPartyVictory(string senate) {
    queue<int> rq, dq;
    int n = senate.size();

    for (int i = 0; i < n; ++i) {
      if (senate[i] == 'R') {
        rq.push(i);
      } else {
        dq.push(i);
      }
    }

    while (!rq.empty() && !dq.empty()) {
      int r = rq.front();
      rq.pop();
      int d = dq.front();
      dq.pop();

      if (r < d) {
        rq.push(r + n);
      } else {
        dq.push(d + n);
      }
    }

    return rq.empty() ? "Dire" : "Radiant";
  }
};
// Runtime 6 ms
// Memory 8 MB