class ATM {
  vector<long> cnt;
  int note[5] = {20, 50, 100, 200, 500};

 public:
  ATM() { cnt.resize(5); }

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < banknotesCount.size(); ++i) {
      cnt[i] += banknotesCount[i];
    }
  }

  vector<int> withdraw(int amount) {
    vector<int> ans(5);

    for (int i = 4; i >= 0; --i) {
      ans[i] = min(cnt[i], static_cast<long>(amount) / note[i]);

      amount -= ans[i] * note[i];
    }

    if (amount > 0) {
      return {-1};
    }

    for (int i = 0; i < 5; ++i) {
      cnt[i] -= ans[i];
    }

    return ans;
  }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
// Runtime: 763 ms, faster than 10.88%
// Memory Usage: 108.1 MB, less than 59.93%
// 2022.4.23 at 茗筑美嘉