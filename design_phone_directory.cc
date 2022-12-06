class PhoneDirectory {
  int cnt;
  vector<int> nums;

 public:
  PhoneDirectory(int maxNumbers) {
    cnt = maxNumbers;
    nums.resize(cnt);
  }

  int get() {
    for (int i = 0; i < cnt; ++i) {
      if (nums[i] == 0) {
        nums[i] = 1;
        return i;
      }
    }

    return -1;
  }

  bool check(int number) { return nums[number] == 0; }

  void release(int number) { nums[number] = 0; }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
// Runtime 137 ms
// Memory 22.2 MB
// 2022.12.6 at 奥盛大厦

class PhoneDirectory {
  unordered_set<int> pool;

 public:
  PhoneDirectory(int maxNumbers) {
    for (int i = 0; i < maxNumbers; ++i) {
      pool.insert(i);
    }
  }

  int get() {
    if (pool.empty()) {
      return -1;
    }

    int res = *pool.begin();
    pool.erase(pool.begin());

    return res;
  }

  bool check(int number) { return pool.find(number) != pool.end(); }

  void release(int number) { pool.insert(number); }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
// Runtime 34 ms
// Memory 22.7 MB
// 2022.12.6 at 奥盛大厦