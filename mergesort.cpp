#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &arr) {
   int length = arr.size();
   for (int i = 0; i < length; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void bubbleSort(vector<int> &arr){
  
  int length = arr.size();
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if(arr[i] < arr[j]) {
       int temp = arr[j];
       arr[j] = arr[i];
       arr[i] = temp;
      }
    }
  }
  
}

vector<int> merge(vector<int> &left, vector<int> &right) {
  if(left.size() != 1) {
    bubbleSort(left);
  }
  
  if (right.size() != 1)
    bubbleSort(right);
  
  vector<int> combined;
  combined.reserve(left.size() + right.size());
  combined.insert(combined.end(), left.begin(), left.end());
  combined.insert(combined.end(), right.begin(), right.end());
  
  bubbleSort(combined);
  return combined;
}


void mergeSort(vector<int> &arr) {
  if (arr.size() == 1)
    return;

  auto midpoint = arr.begin() + arr.size() / 2;

  vector<int> firstHalf(arr.size()/2, 0);
  copy(arr.begin(), midpoint, firstHalf.begin());
  cout << "First Half: "; print(firstHalf);

  vector<int> secondHalf(arr.size() - arr.size()/2, 0);
  copy(midpoint, arr.end(), secondHalf.begin());
  cout << "Second Half: "; print(secondHalf);

  mergeSort(firstHalf);
  mergeSort(secondHalf);

  arr = merge(firstHalf, secondHalf);
}

int main() {

  vector<int> arr = { 75, 43, 126, 12, 33, 4, 679, 21, 22, 34, 5, 4 };
  
  cout << "Vector before merge sort: ";
  print(arr);
  cout << endl;
  
  mergeSort(arr);
  
  cout << endl;
  cout << "Vector after merge sort: ";
  print(arr);
  
  return 0;
}
