/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp;

    Node* ans = nullptr;
    Node* cur = nullptr;
    Node* tmp = head;

    while (tmp) {
      Node* node = new Node(tmp->val, nullptr, nullptr);

      mp[tmp] = node;

      if (!ans) {
        ans = node;
      }

      if (!cur) {
        cur = node;
      } else {
        cur->next = node;
        cur = cur->next;
      }

      tmp = tmp->next;
    }

    cur = ans;
    tmp = head;

    while (tmp) {
      cur->random = mp[tmp->random];

      tmp = tmp->next;
      cur = cur->next;
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 73.86%
// Memory Usage: 22 MB, less than 100.00%

class Solution {
  unordered_map<Node*, Node*> mp;

 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }

    if (mp.find(head) != mp.end()) {
      return mp[head];
    }

    Node* node = new Node(head->val);
    mp[head] = node;

    node->next = copyRandomList(head->next);
    node->random = copyRandomList(head->random);

    return node;
  }
};
// Runtime: 36 ms, faster than 36.91%
// Memory Usage: 22.3 MB, less than 52.38%