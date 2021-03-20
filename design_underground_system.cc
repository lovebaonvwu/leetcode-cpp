class UndergroundSystem {
  unordered_map<string, pair<int, int>> out;
  unordered_map<int, pair<string, int>> custom;

 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    custom[id].first = stationName;
    custom[id].second = t;
  }

  void checkOut(int id, string stationName, int t) {
    string key = stationName + '-' + custom[id].first;
    out[key].first += t - custom[id].second;
    out[key].second += 1;
  }

  double getAverageTime(string startStation, string endStation) {
    double time = 0.0;

    string key = endStation + '-' + startStation;
    if (out.find(key) != out.end()) {
      time = out[key].first / (out[key].second + 0.0);
    }

    return time;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// Runtime: 128 ms, faster than 96.34%
// Memory Usage: 59 MB, less than 56.43%