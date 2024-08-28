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

void leftRotateArrayByKPlace() {
  using namespace std;
  vector<int> arr = getVectorInput();
  cout << "Number of places to rotate the array:- ";
  int k;
  cin >> k;

  int rotationCount = k % arr.size();
  vector<int> temp;

  int i = 0;
  for (; i < rotationCount; i++) {
    temp.push_back(arr[i]);
  }
  for (; i < arr.size(); i++) {
    arr[i - rotationCount] = arr[i];
  }

  // INFO: first approach
  // for (int i = arr.size() - temp.size(); i < arr.size(); i++) {
  //   arr[i] = temp[i - (arr.size() - temp.size())];
  // }
  // INFO: Second approach
  // i = arr.size() - temp.size()
  // for (int tv : temp) {
  //   arr[i] = tv;
  //   i++;
  // }
  // INFO: Third approach
  for (int i = 0; i < temp.size(); i++) {
    arr[arr.size() - temp.size() + i] = temp[i];
  }

  printVector(arr);
}
