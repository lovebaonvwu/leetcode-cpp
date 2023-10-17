class DisjointSet {
 public:
  DisjointSet(int n) : size(n), components(n) {
    parents.resize(n);
    iota(parents.begin(), parents.end(), 0);
    ranks.resize(n);
  }

  int Find(int child) {
    if (parents[child] != child) {
      parents[child] = Find(parents[child]);
    }

    return parents[child];
  }

  bool Union(int parent, int child) {
    int parentParent = Find(parent);
    int childParent = Find(child);

    if (childParent != child || childParent == parentParent) {
      return false;
    }

    --components;
    parents[childParent] = parentParent;

    return true;
  }

  bool Unioned() { return components == 1; }

 private:
  int size;
  int components;
  vector<int> parents;
  vector<int> ranks;
};

class Solution {
 public:
  bool validateBinaryTreeNodes(int n,
                               vector<int>& leftChild,
                               vector<int>& rightChild) {
    DisjointSet ds(n);

    for (int i = 0; i < n; ++i) {
      if (leftChild[i] != -1 && !ds.Union(i, leftChild[i])) {
        return false;
      }

      if (rightChild[i] != -1 && !ds.Union(i, rightChild[i])) {
        return false;
      }
    }

    return ds.Unioned();
  }
};
// 23ms
// 32.86MB