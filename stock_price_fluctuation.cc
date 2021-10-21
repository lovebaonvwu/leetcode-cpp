class StockPrice {
  map<int, int> time;
  map<int, int> p;

 public:
  StockPrice() {}

  void update(int timestamp, int price) {
    int prevPrice = -1;

    if (time.find(timestamp) != time.end()) {
      prevPrice = time[timestamp];
    }

    time[timestamp] = price;

    if (prevPrice > -1) {
      --p[prevPrice];

      if (p[prevPrice] == 0) {
        p.erase(prevPrice);
      }
    }

    ++p[price];
  }

  int current() { return time.rbegin()->second; }

  int maximum() { return p.rbegin()->first; }

  int minimum() { return p.begin()->first; }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// Runtime: 784 ms, faster than 33.41%
// Memory Usage: 165.6 MB, less than 73.93%
// 2021.10.21 at 奥盛大厦