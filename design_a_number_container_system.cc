class NumberContainers {
  unordered_map<int, int> mp1;
  unordered_map<int, set<int>> mp2;

 public:
  NumberContainers() {}

  void change(int index, int number) {
    if (mp1.find(index) != mp1.end()) {
      int num = mp1[index];
      mp2[num].erase(index);
    }
    mp1[index] = number;
    mp2[number].insert(index);
  }

  int find(int number) {
    if (mp2.find(number) == mp2.end() || mp2[number].empty()) {
      return -1;
    }

    return *mp2[number].begin();
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// Runtime: 1077 ms, faster than 33.33%
// Memory Usage: 177.1 MB, less than 33.33%
// 2022.7.27 at 奥盛大厦