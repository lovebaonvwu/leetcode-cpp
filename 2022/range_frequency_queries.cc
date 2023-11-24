class RangeFreqQuery {
  vector<int> cnt[10001];

 public:
  RangeFreqQuery(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
      cnt[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int value) {
    return upper_bound(cnt[value].begin(), cnt[value].end(), right) -
           lower_bound(cnt[value].begin(), cnt[value].end(), left);
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// Runtime: 923 ms, faster than 35.27%
// Memory Usage: 238.5 MB, less than 20.95%
// 2022.4.28 at 茗筑美嘉