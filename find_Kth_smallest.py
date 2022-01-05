from heapq import *

def find_Kth_smallest(lists, k):
  minheap = []
  for i in range(len(lists)):
    # value, list_index, super_list_index
    heappush(minheap, (lists[i][0], 0, i,))

  counter = 0
  while minheap:
    value, list_index, super_list_index = heappop(minheap)
    next_list_index = list_index + 1

    if next_list_index < len(lists[super_list_index]):
      heappush(minheap, 
        (lists[super_list_index][next_list_index],
          next_list_index, 
          super_list_index))
      
    counter += 1
    if counter == k:
      return value

  return -1


def main():
  print("Kth smallest number is: " +
        str(find_Kth_smallest([[2, 6, 8], [3, 6, 7], [1, 3, 4]], 5)))
  print("Kth smallest number is: " +
        str(find_Kth_smallest([[5, 8, 9],[1, 7]],3)))


main()