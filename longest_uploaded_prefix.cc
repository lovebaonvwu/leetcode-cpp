class LUPrefix {
  set<int> st;
  int t = 0;

 public:
  LUPrefix(int n) {}

  void upload(int video) { st.insert(video); }

  int longest() {
    while (st.count(t + 1)) {
      ++t;
    }

    return t;
  }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
// 2022.10.8 at 茗筑美嘉