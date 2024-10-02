#include "array_easy.h"
#include "input.h"
#include "output.h"
#include <iostream>
#include <set>
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

void unionOfSortedArray::brute() {
  using namespace std;
  cout << "Enter 1st array:\n";
  vector<int> arr1 = getVectorInput();
  cout << "Enter 2nd array:\n";
  vector<int> arr2 = getVectorInput();

  set<int> unionSet;

  // set insertion takes O(logn) -> n = sizeo fo set
  // So for n1 element O(n1logn)
  for (int e : arr1) {
    unionSet.insert(e);
  }
  // So for n2 element O(n2logn)
  for (int e : arr2) {
    unionSet.insert(e);
  }

  cout << "The union is:- " << endl;

  // log(n1 + n2)
  for (int e : unionSet) {
    cout << e << " ";
  }
}

void unionOfSortedArray::optimal() {
  using namespace std;
  // cout << "Enter 1st array:\n";
  // vector<int> arr1 = getVectorInput();
  // cout << "Enter 2nd array:\n";
  // vector<int> arr2 = getVectorInput();
  vector<int> arr1 = {1, 3, 4, 5, 8, 9};
  vector<int> arr2 = {2, 4, 5, 7, 8, 12, 14, 18};

  int p1 = 0, p2 = 0;
  vector<int> un;

  while (p1 < arr1.size() && p2 < arr2.size()) {
    if (arr1[p1] < arr2[p2]) {
      if (un.size() == 0 || un.back() != arr1[p1]) {
        un.push_back(arr1[p1]);
      }
      p1++;
    } else {
      if (un.size() == 0 || un.back() != arr2[p2]) {
        un.push_back(arr2[p2]);
      }
      p2++;
    }
  }
  while (p1 < arr1.size()) {
    if (un.size() == 0 || un.back() != arr1[p1]) {
      un.push_back(arr1[p1]);
    }
    p1++;
  }
  while (p2 < arr2.size()) {
    if (un.size() == 0 || un.back() != arr2[p2]) {
      un.push_back(arr2[p2]);
    }
    p2++;
  }
  cout << "The first array:- ";
  printVector(arr1);
  cout << "The second array:- ";
  printVector(arr2);
  cout << "The union is:- ";
  printVector(un);
}

/*
 *
 * Problem Statement: Given an integer N and an array of size N-1 containing N-1
 * numbers between 1 to N. Find the number(between 1 to N), that is not present
 * in the given array.
 */
void findMissingNumber::brute() {
  using namespace std;
  cout << "Problem Statement: Given an integer N and an array of size N-1 "
          "containing N-1 numbers between 1 to N. Find the number(between 1 to "
          "N), that is not present in the given array\n";
  int n;
  cout << "Enter integer N: ";
  cin >> n;
  vector<int> arr = getVectorInput(n - 1);

  int me = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != i + 1) {
      me = i + 1;
      break;
    }
  }
  if (me) {
    cout << "Missing element is:- " << me << endl;
  } else {
    cout << "There is no missing element in this array\n";
  }
}
