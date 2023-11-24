class TwoSum {
  unordered_map<int, int> nums;
  unordered_set<int> sums;

 public:
  TwoSum() {}

  void add(int number) {
    for (auto& [k, _] : nums) {
      sums.insert(number + k);
    }

    ++nums[number];
  }

  bool find(int value) { return sums.find(value) != sums.end(); }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
// Time Limit Exceeded

class TwoSum {
  unordered_map<int, int> nums;

 public:
  TwoSum() {}

  void add(int number) { ++nums[number]; }

  bool find(int value) {
    for (auto& [k, cnt] : nums) {
      long long target = (long long)value - k;
      if (nums.count(target) && (target != k || cnt > 1)) {
        return true;
      }
    }

    return false;
  }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
// Runtime 170 ms
// Memory 27.9 MB
// 2023.2.2 at 聊城滦河路汉庭优佳