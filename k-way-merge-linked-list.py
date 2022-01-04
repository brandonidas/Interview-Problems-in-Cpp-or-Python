from __future__ import print_function
from heapq import *


class ListNode:
  def __init__(self, value):
    self.value = value
    self.next = None
  
  # used for the min-heap
  def __lt__(self, other):
    return self.value < other.value

def merge_lists(lists):
  result_head = None
  k = len(lists)
  minhp = []

  for i in range(k):
    if lists[i]:
      heappush(minhp, lists[i])
  
  result_head,current_ptr = None, None
  while minhp:
    tmp = heappop(minhp)
    if result_head == None:
      result_head = current_ptr = tmp
    else:
      current_ptr.next = tmp
      current_ptr = current_ptr.next
    if tmp.next:
      heappush(minhp, tmp.next)

  return result_head

def main():
  l1 = ListNode(2)
  l1.next = ListNode(6)
  l1.next.next = ListNode(8)

  l2 = ListNode(3)
  l2.next = ListNode(6)
  l2.next.next = ListNode(7)

  l3 = ListNode(1)
  l3.next = ListNode(3)
  l3.next.next = ListNode(4)

  result = merge_lists([l1, l2, l3])
  # result = merge_lists([l1,l2])
  print("Here are the elements form the merged list: ", end='')
  while result != None:
    print(str(result.value) + " ", end='')
    result = result.next


main()

