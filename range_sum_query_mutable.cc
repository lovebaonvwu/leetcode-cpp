class SegmentTree {
 public:
  SegmentTree(const vector<int>& nums_, int a, int b)
      : start(a), end(b), val(0), left(nullptr), right(nullptr), nums(nums_) {
    if (start == end) {
      val = nums[start];
      return;
    }

    int mid = (a + b) / 2;

    left = new SegmentTree(nums, a, mid);
    right = new SegmentTree(nums, mid + 1, b);

    val = left->val + right->val;
  }

  void updateNode(int index, int n) {
    if (index < start || index > end) {
      return;
    }

    if (start == end) {
      val = n;
      return;
    }

    left->updateNode(index, n);
    right->updateNode(index, n);

    val = left->val + right->val;
  }

  int queryRange(int a, int b) {
    if (a > end || b < start) {
      return 0;
    }

    if (start >= a && end <= b) {
      return val;
    }

    return left->queryRange(a, b) + right->queryRange(a, b);
  }

 private:
  SegmentTree* left;
  SegmentTree* right;
  int start;
  int end;
  int val;

  const vector<int>& nums;
};

class NumArray {
  SegmentTree* tree;

 public:
  NumArray(vector<int>& nums) {
    tree = new SegmentTree(nums, 0, nums.size() - 1);
  }

  void update(int index, int val) { tree->updateNode(index, val); }

  int sumRange(int left, int right) { return tree->queryRange(left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// Runtime: 528 ms, faster than 20.15%
// Memory Usage: 192 MB, less than 5.12%