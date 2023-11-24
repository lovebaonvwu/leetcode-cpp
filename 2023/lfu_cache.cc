class LFUCache {
  int capacity;
  int minf;
  unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
  unordered_map<int, list<pair<int, int>>> freq;

  void insert(int key, int f, int value) {
    freq[f].push_back({key, value});
    cache[key] = {f, --freq[f].end()};
  }

 public:
  LFUCache(int capacity) : capacity(capacity), minf(0) {}

  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
      return -1;
    }

    const int f = it->second.first;
    const auto iter = it->second.second;
    auto [_, value] = *iter;
    freq[f].erase(iter);
    if (freq[f].empty() && minf == f) {
      ++minf;
    }

    insert(key, f + 1, value);

    return value;
  }

  void put(int key, int value) {
    if (capacity <= 0) {
      return;
    }

    auto it = cache.find(key);
    if (it != cache.end()) {
      it->second.second->second = value;
      get(key);
      return;
    }

    if (cache.size() == capacity) {
      int key = freq[minf].front().first;
      freq[minf].pop_front();
      cache.erase(key);
    }

    insert(key, 1, value);

    minf = 1;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// Runtime 523 ms
// Memory 179.7 MB
// 2023.1.29 at 奥盛大厦