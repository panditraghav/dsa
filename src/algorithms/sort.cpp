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
  std::vector<int> arr = inputVector();

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
  std::vector<int> arr = inputVector();

  quickSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array is: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

#endif
