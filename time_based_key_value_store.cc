class TimeMap {
  unordered_map<string, map<int, string>> mp;

 public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].insert({timestamp, value});
  }

  string get(string key, int timestamp) {
    if (mp.find(key) == mp.end()) {
      return "";
    }

    auto it = mp[key].upper_bound(timestamp);

    if (it == mp[key].begin()) {
      return "";
    }

    return (--it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// 400ms

class TimeMap {
  unordered_map<string, priority_queue<pair<int, string>>> mp;

 public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    auto m = mp.find(key);
    if (m != mp.end()) {
      m->second.push({timestamp, value});
    } else {
      priority_queue<pair<int, string>> pq;
      pq.push({timestamp, value});

      mp[key] = pq;
    }
  }

  string get(string key, int timestamp) {
    auto m = mp.find(key);

    if (m == mp.end()) {
      return "";
    }

    stack<pair<int, string>> stk;
    while (!m->second.empty() && timestamp < m->second.top().first) {
      stk.push(m->second.top());
      m->second.pop();
    }

    string ans;

    if (m->second.empty()) {
      ans = "";
    } else {
      ans = m->second.top().second;
    }

    while (!stk.empty()) {
      m->second.push(stk.top());

      stk.pop();
    }

    return ans;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// 444ms