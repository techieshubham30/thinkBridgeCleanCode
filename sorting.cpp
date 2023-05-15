#include <bits/stdc++.h>
using namespace std;

class searchingAlgo {
private:
  vector<int> arrayElem;

public:
  searchingAlgo(vector<int> a) { arrayElem = a; }

  int linearSearch(int targetElement) {
    for (int i = 0; i < arrayElem.size(); i++) {
      if (targetElement == arrayElem[i]) {
        return i;
      }
    }

    return -1;
  }

  int binarySearch(int targetElement) {
    int left = 0;
    int right = arrayElem.size() - 1;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (arrayElem[mid] == targetElement) {
        return mid;
      } else if (arrayElem[mid] < targetElement) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }

  int jumpSearch(int targetElement) {
    int n = arrayElem.size();
    int jump = sqrt(n);
    int left = 0;
    int right = jump;
    while (right < n && arrayElem[right] <= targetElement) {
      left = right;
      right += jump;
      if (right > n - 1) {
        right = n;
      }
    }
    for (int i = left; i < right; i++) {
      if (arrayElem[i] == targetElement) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> arrayElem = {2, 4, 10, 10, 10, 18, 20};
  searchingAlgo newObj(arrayElem);
  int targetElement = 18;
  // we can use any method as per requirement
  int index = newObj.jumpSearch(targetElement);
  if (index != -1) {
    cout << "Found " << targetElement << " at index " << index << endl;
  } else {
    cout << "Could not find " << targetElement << endl;
  }
  return 0;
}
