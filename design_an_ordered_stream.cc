class OrderedStream {
  vector<string> container;
  int cur = 0;

 public:
  OrderedStream(int n) : container(vector<string>(n)) {}

  vector<string> insert(int id, string value) {
    container[id - 1] = value;

    vector<string> res;

    while (cur < container.size() && !container[cur].empty()) {
      res.push_back(container[cur++]);
    }

    return res;
  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
// Runtime: 96 ms, faster than 90.65%
// Memory Usage: 83.7 MB, less than 79.78%