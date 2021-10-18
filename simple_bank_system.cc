class Bank {
  vector<long long> balance;

 public:
  Bank(vector<long long>& balance) { this->balance = balance; }

  bool transfer(int account1, int account2, long long money) {
    if (account1 < 1 || account1 > balance.size()) {
      return false;
    }

    if (account2 < 1 || account2 > balance.size()) {
      return false;
    }

    if (money > balance[account1 - 1]) {
      return false;
    }

    balance[account1 - 1] -= money;
    balance[account2 - 1] += money;

    return true;
  }

  bool deposit(int account, long long money) {
    if (account < 1 || account > balance.size()) {
      return false;
    }

    balance[account - 1] += money;

    return true;
  }

  bool withdraw(int account, long long money) {
    if (account < 1 || account > balance.size()) {
      return false;
    }

    if (money > balance[account - 1]) {
      return false;
    }

    balance[account - 1] -= money;

    return true;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// Runtime: 236 ms, faster than 68.75%
// Memory Usage: 116.8 MB, less than 75.00%
// 2021.10.18 at 奥盛大厦