#include "input.h"
#include "output.h"
#include <iostream>
#include <vector>

void leftRotateArrayByOnePlace() {
  std::vector<int> arr = getVectorInput();

  int first = arr[0];
  int n = arr.size();

  for (int i = 1; i < n; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = first;

  std::cout << "The shifted array is:- " << std::endl;

  printVector(arr);
}
