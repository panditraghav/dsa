#ifndef SORT
#define SORT
#include "input.h"
#include <iostream>
#include <vector>

/*
███    ███ ███████ ██████   ██████  ███████     ███████  ██████  ██████ ████████
████  ████ ██      ██   ██ ██       ██          ██      ██    ██ ██   ██    ██
██ ████ ██ █████   ██████  ██   ███ █████       ███████ ██    ██ ██████     ██
██  ██  ██ ██      ██   ██ ██    ██ ██               ██ ██    ██ ██   ██    ██
██      ██ ███████ ██   ██  ██████  ███████     ███████  ██████  ██   ██    ██
*/
/*
 * - The Merge function merges the array in a sorted order using two pointers
 * one pointer for first array and other for second, we compare the elements
 * of both pointers and push the smaller element to the temporary array and
 * increment the pointer whose element is pushed until any one array has been
 * traversed
 * - After that we traverse both array to push any remaining elements
 * - At the end we copy the temporary sorted array to our main array
 */
void merge(std::vector<int> &arr, int low, int mid, int high) {
  std::vector<int> temp;
  int i = low;
  int j = mid + 1;
  while (i < mid + 1 && j < high + 1) {
    if (arr[i] < arr[j]) {
      temp.push_back(arr[i]);
      i++;
    } else {
      temp.push_back(arr[j]);
      j++;
    }
  }

  while (i < mid + 1) {
    temp.push_back(arr[i]);
    i++;
  }
  while (j < high + 1) {
    temp.push_back(arr[j]);
    j++;
  }

  for (int i = 0; i < temp.size(); i++) {
    arr[i + low] = temp[i];
  }
}
/*
 * - Merge sort's time complexity is same as quick sort which is O(nlogn)
 *   but it requires temporary array
 * - In Merge sort we divide the array into half recursively until we have
 *   only one element left then we merge the two divided arrays using the
 *   merge function
 * */
void mergeSort(std::vector<int> &arr, int low, int high) {
  if (low == high)
    return;

  int mid = (low + high) / 2;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

void testMergeSort() {
  std::cout << "--------------------Testing merge sort----------------"
            << std::endl;
  std::vector<int> arr = getVectorInput();

  mergeSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array is: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

/*
 ██████  ██    ██ ██  ██████ ██   ██     ███████  ██████  ██████  ████████
██    ██ ██    ██ ██ ██      ██  ██      ██      ██    ██ ██   ██    ██
██    ██ ██    ██ ██ ██      █████       ███████ ██    ██ ██████     ██
██ ▄▄ ██ ██    ██ ██ ██      ██  ██           ██ ██    ██ ██   ██    ██
 ██████   ██████  ██  ██████ ██   ██     ███████  ██████  ██   ██    ██
    ▀▀
*/
/*
 * - Quick sort's time complexity is same as merge sort which is O(nlogn), but
 * it is better in space complexity as it doesn't require temporary array
 * - In Quick sort the intuition is to put the pivot element at it's right
 * position
 * - We take first element as pivot and take two pointers i=low; j=high
 * - We increment i until we find element greater then pivot and decrement j
 *   until we find element smaller then pivot
 * - After that we swap the elements at index i and j, by doing so the larger
 *   element goes at right side of the pivot and smaller on the left side
 * - We repeat this process of finding larger and smaller element and swappign
 * them until j < i when this condition happens then all the right side elements
 * are greater then pivot and left side element are smaller then pivot
 * - Then we swap pivot element with element at index j as that is the smaller
 * element so it goes to the left, hence we have put one elment to it's right
 * place
 * - After that we apply the algorithm recursively to the left and right side of
 * the sorted element until low == high then it is the only element
 */
void quickSort(std::vector<int> &arr, int low, int high) {
  if (low >= high)
    return;
  int pivot = low;
  int i = low;
  int j = high;

  while (i < j) {
    while (arr[i] <= arr[pivot] && i < high)
      i++;
    while (arr[j] >= arr[pivot] && j > low)
      j--;

    if (i < j) {
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }

  int temp = arr[j];
  arr[j] = arr[pivot];
  arr[pivot] = temp;

  quickSort(arr, low, j - 1);
  quickSort(arr, j + 1, high);
}

void testQuickSort() {
  std::cout << "--------------------Testing quick sort----------------"
            << std::endl;
  std::vector<int> arr = getVectorInput();

  quickSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array is: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

#endif
