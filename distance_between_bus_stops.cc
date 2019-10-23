class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance,
                              int start,
                              int destination) {
    int ccw = 0;
    int cw = 0;

    if (start > destination) {
      swap(start, destination);
    }

    for (int i = 0; i < distance.size(); ++i) {
      if (i >= start && i < destination) {
        cw += distance[i];
      } else {
        ccw += distance[i];
      }
    }

    return min(cw, ccw);
  }
};
// Runtime: 8 ms, faster than 47.97%
// Memory Usage: 9.2 MB, less than 100.00%

class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance,
                              int start,
                              int destination) {
    int sum = 0;
    int cw = 0;

    if (start > destination) {
      int tmp = start;
      start = destination;
      destination = tmp;
    }

    for (int i = 0; i < distance.size(); ++i) {
      sum += distance[i];

      if (i >= start && i < destination) {
        cw += distance[i];
      }
    }

    return min(cw, sum - cw);
  }
};
// Runtime: 8 ms, faster than 47.97%
// Memory Usage: 9.1 MB, less than 100.00%