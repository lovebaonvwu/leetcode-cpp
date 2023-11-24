class FreqStack {
  priority_queue<vector<int>> pq;
  unordered_map<int, int> mp;
  int id = 0;

 public:
  FreqStack() {}

  void push(int x) {
    ++mp[x];
    pq.push({mp[x], id++, x});
  }

  int pop() {
    auto p = pq.top();
    pq.pop();

    --mp[p[2]];

    return p[2];
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
// Runtime: 304 ms, faster than 38.63%
// Memory Usage: 87.4 MB, less than 36.72%

class FreqStack {
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> mp;
  int max_freq = 0;

 public:
  FreqStack() {}

  void push(int x) {
    ++freq[x];
    max_freq = max(max_freq, freq[x]);

    mp[freq[x]].push(x);
  }

  int pop() {
    int ret = mp[max_freq].top();
    mp[max_freq].pop();

    --freq[ret];

    if (mp[max_freq].empty()) {
      --max_freq;
    }

    return ret;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
// Runtime: 172 ms, faster than 85.51%
// Memory Usage: 86.5 MB, less than 52.92%