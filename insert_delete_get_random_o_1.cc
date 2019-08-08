class RandomizedSet {
 private:
  unordered_map<int, int> mp;
  vector<int> arr;

 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (mp.find(val) != mp.end()) {
      return false;
    }

    arr.push_back(val);
    mp[val] = arr.size() - 1;

    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (mp.find(val) == mp.end()) {
      return false;
    }

    int index = mp[val];
    int tail = arr[arr.size() - 1];

    mp[tail] = index;
    arr[index] = tail;

    mp.erase(val);
    arr.pop_back();

    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return arr[rand() % arr.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// 56ms