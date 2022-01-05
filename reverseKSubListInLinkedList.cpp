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

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    ListNode * firstTail = nullptr;
    ListNode * secondHead = nullptr;

    ListNode * previous = nullptr;
    ListNode * current = head;
    while (firstTail == nullptr) {
      if (current->value == p) {
        firstTail = previous;
      }
      previous = current;
      current = current->next;
    }
    cout << firstTail->value << " first tail reached" << endl;

    while (secondHead == nullptr) {
      if (previous->value == q) {
        secondHead = current;
      }
      previous = current;
      current = current->next;
    }
    cout << secondHead->value << " secondHead reached" << endl;

    previous = firstTail;
    current = firstTail->next;
    ListNode * next = current->next;

    ListNode * innerHead = current;
    while (previous->value != q) {
      next = current->next;

      cout << previous->value << endl;
      current->next = previous;


      previous = current;
      current = next;
    }
    ListNode * innerTail = previous;

    firstTail->next = innerTail;
    innerHead->next = secondHead;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
