/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
 public:
  Node* construct(vector<vector<int>>& grid) {
    leafNodes_[0] = new Node(false, true);
    leafNodes_[1] = new Node(true, true);

    return construct(grid, 0, 0, grid.size());
  }

  Node* construct(vector<vector<int>>& g, int r, int c, int k) {
    if (k == 1) {
      return leafNodes_[g[r][c]];
    }

    k /= 2;

    Node* topLeft = construct(g, r, c, k);
    Node* topRight = construct(g, r, c + k, k);
    Node* bottomLeft = construct(g, r + k, c, k);
    Node* bottomRight = construct(g, r + k, c + k, k);

    if (topLeft == topRight && topLeft == bottomLeft &&
        topLeft == bottomRight) {
      return topLeft;
    }

    return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
  }

 private:
  array<Node*, 2> leafNodes_;
};
// Runtime 16 ms
// Memory 12.5 MB
// 2023.2.27 at 奥盛大厦