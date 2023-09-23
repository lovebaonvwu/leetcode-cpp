class Solution {
 public:
  int accountBalanceAfterPurchase(int purchaseAmount) {
    int round =
        (purchaseAmount % 10) >= 5 ? (purchaseAmount + 9) : purchaseAmount;
    return 100 - (round / 10 * 10);
  }
};
// 2ms
// 6.39MB