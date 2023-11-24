/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
  unordered_map<Node*, Node*> visited;

 public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    }

    if (visited.find(node) != visited.end()) {
      return visited[node];
    }

    Node* copy = new Node(node->val, {});

    visited[node] = copy;

    for (auto n : node->neighbors) {
      copy->neighbors.push_back(cloneGraph(n));
    }

    return copy;
  }
};
// Runtime: 12 ms, faster than 63.72%
// Memory Usage: 9.2 MB, less than 98.34%

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
  unordered_map<Node*, Node*> visited;

 public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    }

    queue<Node*> q;
    q.push(node);

    Node* copy = new Node(node->val, {});

    visited[node] = copy;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (auto neighbor : cur->neighbors) {
        if (visited.find(neighbor) == visited.end()) {
          visited[neighbor] = new Node(neighbor->val, {});
          q.push(neighbor);
        }

        visited[cur]->neighbors.push_back(visited[neighbor]);
      }
    }

    return copy;
  }
};
// Runtime: 12 ms, faster than 63.72%
// Memory Usage: 8.7 MB, less than 98.34%