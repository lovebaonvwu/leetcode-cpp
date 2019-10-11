class MyHashSet {
  vector<bool> v;

 public:
  /** Initialize your data structure here. */
  MyHashSet() { v.resize(1024); }

  void add(int key) {
    while (key >= v.size()) {
      v.resize(v.size() * 2);
    }

    v[key] = true;
  }

  void remove(int key) {
    if (key < v.size()) {
      v[key] = false;
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return key < v.size() && v[key]; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// 92ms

class MyHashSet {
  int arr[1000001];

 public:
  /** Initialize your data structure here. */
  MyHashSet() { memset(arr, -1, sizeof(arr)); }

  void add(int key) { arr[key] = key; }

  void remove(int key) { arr[key] = -1; }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return arr[key] < 0 ? false : true; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// 100ms