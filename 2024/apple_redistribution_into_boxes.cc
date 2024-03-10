class Solution {
 public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    sort(rbegin(capacity), rend(capacity));
    int total = accumulate(begin(apple), end(apple), 0);

    int i = 0;
    for (; i < capacity.size() && total > 0; ++i) {
      total -= capacity[i];
    }

    return i;
  }
};
// 3 ms
// 33.24 MB