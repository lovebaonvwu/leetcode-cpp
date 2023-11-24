class Allocator {
  vector<int> mem;

 public:
  Allocator(int n) { mem.resize(n); }

  int allocate(int size, int mID) {
    int i = 0;
    while (i < mem.size()) {
      while (i < mem.size() && mem[i] != 0) {
        ++i;
      }

      if (i + size - 1 >= mem.size()) {
        return -1;
      }

      bool valid = true;
      for (int j = 0; j < size; ++j) {
        if (mem[i + j] != 0) {
          i = i + j + 1;
          valid = false;
          break;
        }
      }

      if (valid) {
        for (int j = 0; j < size; ++j) {
          mem[i + j] = mID;
        }
        return i;
      }
    }

    return -1;
  }

  int free(int mID) {
    int freed = 0;
    for (int i = 0; i < mem.size(); ++i) {
      if (mem[i] == mID) {
        ++freed;
        mem[i] = 0;
      }
    }

    return freed;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
//
// Runtime 348 ms
// Memory 30.6 MB
// 2023.1.5 at 奥盛大厦