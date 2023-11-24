/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
 public:
  Node* flatten(Node* head) {
    Node* cur = head;

    while (cur) {
      if (cur->child) {
        Node* tmp = cur->next;
        cur->child->prev = cur;
        cur->next = flatten(cur->child);
        cur->child = nullptr;

        Node* prev;
        while (cur) {
          prev = cur;
          cur = cur->next;
        }

        if (tmp) {
          prev->next = tmp;
          tmp->prev = prev;
        }

        cur = prev;
      }

      cur = cur->next;
    }

    return head;
  }
};
// Runtime: 12 ms, faster than 14.60%
// Memory Usage: 7.3 MB, less than 67.87%

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
 public:
  Node* flatten(Node* head) {
    for (Node* cur = head; cur; cur = cur->next) {
      if (cur->child) {
        Node* next = cur->next;
        cur->child->prev = cur;
        cur->next = cur->child;
        cur->child = nullptr;

        Node* p = cur->next;
        while (p->next) {
          p = p->next;
        }

        if (next) {
          p->next = next;
          next->prev = p;
        }
      }
    }

    return head;
  }
};
// Runtime: 8 ms, faster than 55.94%
// Memory Usage: 7.5 MB, less than 37.70%

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
 public:
  Node* flatten(Node* head) {
    Node* cur = head;

    while (cur) {
      if (cur->child) {
        Node* tmp = cur->next;
        cur->child->prev = cur;
        cur->next = flatten(cur->child);
        cur->child = nullptr;

        while (cur->next) {
          cur = cur->next;
        }

        if (tmp) {
          cur->next = tmp;
          tmp->prev = cur;
        }
      }

      cur = cur->next;
    }

    return head;
  }
};
// Runtime: 16 ms, faster than 14.60%
// Memory Usage: 7.3 MB, less than 72.24%