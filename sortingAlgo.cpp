#include <bits/stdc++.h>
using namespace std;

class sortingAlgo {
private:
  vector<int> arrElem;

public:
  sortingAlgo(vector<int> a) { arrElem = a; }

  // insertion sort overloaded function
  void sort() {
    for (int i = 0; i < arrElem.size() - 1; i++) {
      int j = i;
      while (j > 0 && arrElem[j - 1] > arrElem[j]) {
        swap(arrElem[j - 1], arrElem[j]);
        j--;
      }
    }
  }
  // bubble sort overloaded function
  void sort(char c) {
    for (int i = arrElem.size() - 1; i >= 1; i--) {
      for (int j = 0; j < i; j++) {
        if (arrElem[j] > arrElem[j + 1])
          swap(arrElem[j], arrElem[j + 1]);
      }
    }
  }
  // selection sort overloaded function
  void sort(bool b) {
    int minIndex;
    for (int i = 0; i < arrElem.size() - 1; i++) {
      minIndex = i;
      for (int j = i; j < arrElem.size(); j++) {
        if (arrElem[j] < arrElem[minIndex]) {
          minIndex = j;
        }
      }
      swap(arrElem[i], arrElem[minIndex]);
    }
  }

  // quick sort overloaded function
  void sort(int left, int right) {
    if (left < right) {
      // Selecting the pivot element
      int pivot = arrElem[(left + right) / 2];
      // Partitioning the array around the pivot
      int i = left;
      int j = right;
      while (i <= j) {
        while (arrElem[i] < pivot)
          i++;
        while (arrElem[j] > pivot)
          j--;
        if (i <= j) {
          swap(arrElem[i], arrElem[j]);
          i++;
          j--;
        }
      }

      sort(left, j);
      sort(i, right);
    }
  }

  void printSortedArr() {
    for (int i = 0; i < arrElem.size(); i++) {
      cout << arrElem[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  vector<int> arrayElements = {14, 30, 10, 12, 16};
  sortingAlgo newObj(arrayElements);

  // appy any method on created object, for instance:
  newObj.sort();
  newObj.sort('b');
  newObj.sort(true);
  newObj.sort(0, arrayElements.size() - 1);

  newObj.printSortedArr();
  return 0;
}