class Cashier {
  int n;
  int cnt;
  int dis;
  unordered_map<int, int> pro;

 public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
      : n(n), cnt(n), dis(discount) {
    for (int i = 0; i < products.size(); ++i) {
      pro[products[i]] = prices[i];
    }
  }

  double getBill(vector<int> product, vector<int> amount) {
    double bill = 0;

    for (int i = 0; i < product.size(); ++i) {
      bill += pro[product[i]] * amount[i];
    }

    if (--cnt == 0) {
      bill *= ((100 - dis) / 100.0);
      cnt = n;
    }

    return bill;
  }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
// Runtime: 340 ms, faster than 25.35%
// Memory Usage: 120.4 MB, less than 97.18%
// 2021.11.26 at 奥盛大厦