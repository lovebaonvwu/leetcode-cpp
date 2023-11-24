class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> pq;

    for (int i = 0; i < heights.size() - 1; ++i) {
      int t = heights[i + 1] - heights[i];

      if (t > 0) {
        pq.push(-t);

        if (pq.size() > ladders) {
          bricks += pq.top();
          pq.pop();
        }

        if (bricks < 0) {
          return i;
        }
      }
    }

    return heights.size() - 1;
  }
};
// Runtime: 284 ms, faster than 28.68%
// Memory Usage: 54 MB, less than 5.60%

class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> pq;

    for (int i = 0; i < heights.size() - 1; ++i) {
      int t = heights[i + 1] - heights[i];
      if (t > 0) {
        bricks -= t;
        pq.push(t);

        if (bricks < 0) {
          --ladders;

          bricks += pq.top();
          pq.pop();

          if (bricks < 0 || ladders < 0) {
            return i;
          }
        }
      }
    }

    return heights.size() - 1;
  }
};
// Runtime: 256 ms, faster than 40.52%
// Memory Usage: 54.4 MB, less than 5.60%