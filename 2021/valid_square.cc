class Solution {
  int dis(vector<int>& a, vector<int>& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
  }

 public:
  bool validSquare(vector<int>& p1,
                   vector<int>& p2,
                   vector<int>& p3,
                   vector<int>& p4) {
    int distances[6];

    distances[0] = dis(p1, p2);
    distances[1] = dis(p1, p3);
    distances[2] = dis(p1, p4);
    distances[3] = dis(p2, p3);
    distances[4] = dis(p2, p4);
    distances[5] = dis(p3, p4);

    sort(distances, distances + 6);

    return distances[0] && distances[0] == distances[1] &&
           distances[1] == distances[2] && distances[2] == distances[3] &&
           distances[4] == distances[5] && distances[3] != distances[4];
  }
};
// Runtime: 4 ms, faster than 71.77%
// Memory Usage: 7.5 MB, less than 100.00%

class Solution {
  int dis(vector<int>& a, vector<int>& b) {
    return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
  }

 public:
  bool validSquare(vector<int>& p1,
                   vector<int>& p2,
                   vector<int>& p3,
                   vector<int>& p4) {
    int distances[6];

    distances[0] = dis(p1, p2);
    distances[1] = dis(p1, p3);
    distances[2] = dis(p1, p4);
    distances[3] = dis(p2, p3);
    distances[4] = dis(p2, p4);
    distances[5] = dis(p3, p4);

    sort(distances, distances + 6);

    return distances[0] && distances[0] == distances[1] &&
           distances[1] == distances[2] && distances[2] == distances[3] &&
           distances[4] == distances[5] && distances[3] != distances[4];
  }
};
// Runtime: 4 ms, faster than 71.77%
// Memory Usage: 7.8 MB, less than 100.00%