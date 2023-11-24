class ProductOfNumbers {
  vector<int> arr = {1};

 public:
  ProductOfNumbers() {}

  void add(int num) {
    if (num > 0) {
      arr.push_back(num * arr.back());
    } else {
      arr = {1};
    }
  }

  int getProduct(int k) {
    if (k >= arr.size()) {
      return 0;
    } else {
      return arr.back() / arr[arr.size() - k - 1];
    }
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// Runtime: 196 ms, faster than 80.79%
// Memory Usage: 62.5 MB, less than 100.00%

class ProductOfNumbers {
  vector<int> arr;

 public:
  ProductOfNumbers() {}

  void add(int num) { arr.push_back(num); }

  int getProduct(int k) {
    int res = 1;

    for (int i = 1; i <= k; ++i) {
      res *= arr[arr.size() - i];
    }

    return res;
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// Runtime: 1780 ms, faster than 5.15%
// Memory Usage: 62.7 MB, less than 100.00%