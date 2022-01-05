using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    ListNode * current;
    ListNode * next;
    ListNode * previous;

    previous = nullptr;
    current = head;
    next = current->next;

    while (current != nullptr) {
      next = current->next; // keep context, in order to perform next reverse part

      current->next = previous; // the reverse part
      
      previous = current; // update pointers to next nodes, respectively
      current = next;
    }
    
    return previous;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseLinkedList::reverse(head);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
