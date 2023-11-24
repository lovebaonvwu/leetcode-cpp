class SnapshotArray {
  unordered_map<int, map<int, int>> mp;
  int cur_id = 0;

 public:
  SnapshotArray(int length) {}

  void set(int index, int val) { mp[index][cur_id] = val; }

  int snap() { return cur_id++; }

  int get(int index, int snap_id) {
    auto it = mp[index].upper_bound(snap_id);

    return it == begin(mp[index]) ? 0 : prev(it)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// Runtime: 276 ms, faster than 75.07%
// Memory Usage: 79.2 MB, less than 100.00%

class SnapshotArray {
  vector<int> vec;
  vector<vector<int>> snaps;

 public:
  SnapshotArray(int length) { vec = vector<int>(length, 0); }

  void set(int index, int val) { vec[index] = val; }

  int snap() {
    snaps.push_back(vec);
    return snaps.size() - 1;
  }

  int get(int index, int snap_id) { return snaps[snap_id][index]; }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// MLE

class SnapshotArray {
  unordered_map<int, vector<int>> mp;
  vector<int> vec;
  int snap_id = -1;

 public:
  SnapshotArray(int length) { vec = vector<int>(length, 0); }

  void set(int index, int val) { vec[index] = val; }

  int snap() {
    ++snap_id;
    mp[snap_id] = vec;

    return snap_id;
  }

  int get(int index, int snap_id) { return mp[snap_id][index]; }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// MLE