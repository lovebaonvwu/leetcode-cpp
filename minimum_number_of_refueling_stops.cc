class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    stations.push_back({target, 0});

    int howFarWeCanGo = startFuel;
    int nextStationId = 0;
    int distanceToNextStation = stations[nextStationId][0];
    int stops = 0;

    priority_queue<int> pq;

    while (true) {
      if (howFarWeCanGo >= distanceToNextStation) {
        howFarWeCanGo -= distanceToNextStation;

        pq.push(stations[nextStationId][1]);

        ++nextStationId;

        if (nextStationId == stations.size()) {
          return stops;
        }

        distanceToNextStation =
            stations[nextStationId][0] - stations[nextStationId - 1][0];

      } else {
        if (pq.empty()) {
          return -1;
        }

        howFarWeCanGo += pq.top();
        pq.pop();

        ++stops;
      }
    }

    return stops;
  }
};
// Runtime: 24 ms, faster than 86.55%
// Memory Usage: 16.3 MB, less than 53.82%