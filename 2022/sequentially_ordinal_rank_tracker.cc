class SORTracker {
  vector<pair<int, string>> record;
  int i = 0;

 public:
  SORTracker() {}

  void add(string name, int score) {
    record.push_back({score, name});
    sort(record.begin(), record.end(), [](auto& a, auto& b) {
      if (a.first == b.first) {
        return a.second < b.second;
      } else {
        return a.first > b.first;
      }
    });
  }

  string get() { return record[i++].second; }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
// Time Limit Exceeded

class SORTracker {
  set<pair<int, string>> st;
  set<pair<int, string>>::iterator it;

 public:
  SORTracker() { it = st.end(); }

  void add(string name, int score) {
    auto curIt = st.insert({-score, name}).first;

    if (it == st.end() || *curIt < *it) {
      --it;
    }
  }

  string get() { return (*it++).second; }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
// Runtime: 471 ms, faster than 47.34%
// Memory Usage: 149.1 MB, less than 74.08%
// 2022.1.14 at 奥盛大厦