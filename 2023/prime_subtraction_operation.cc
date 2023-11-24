class Solution {
 public:
  bool primeSubOperation(vector<int>& nums) {
    vector<int> p;
    getPrimes(p);

    for (int i = nums.size() - 2, prev = nums.back(); i >= 0; --i) {
      if (nums[i] < prev) {
        prev = nums[i];
        continue;
      }

      bool find = false;
      for (int k = 0; k < p.size() && p[k] < nums[i]; ++k) {
        if (nums[i] - p[k] < prev) {
          find = true;
          prev = nums[i] - p[k];
          break;
        }
      }

      if (!find) {
        return false;
      }
    }

    return true;
  }

 private:
  void getPrimes(vector<int>& ret) {
    int p[1001] = {0};

    for (int i = 2; i * i <= 1000; ++i) {
      if (!p[i]) {
        for (int j = i * i; j <= 1000; j += i) {
          p[j] = 1;
        }
      }
    }

    for (int i = 2; i <= 1000; ++i) {
      if (!p[i]) {
        ret.push_back(i);
      }
    }
  }
};
// Runtime 23 ms
// Memory 25.6 MB