/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
 public:
  void printLinkedListInReverse(ImmutableListNode* head) {
    if (head->getNext() != nullptr) {
      printLinkedListInReverse(head->getNext());
    }

    head->printValue();

    return;
  }
};
// Runtime 6 ms
// Memory 6.7 MB
// 2022.11.23 at 茗筑美嘉