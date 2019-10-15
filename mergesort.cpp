// Inspired by Programming Foundations: Algorithms - Implement the merge sort on LinkedinLearning
#include <iostream>
#include <vector>

using namespace std;
   
vector<int> items = {6, 20, 8, 19, 56, 23, 87, 41, 49, 53};

void mergeSort(vector<int>& dataSet)
{
  if (dataSet.size() > 1)
  {
    auto mid = dataSet.begin() + dataSet.size() / 2;
    vector<int> leftVec(dataSet.begin(), mid);
    vector<int> rightVec(mid, dataSet.end());

    // recursively break down the vectors
    mergeSort(leftVec);
    mergeSort(rightVec);

    // perform merging
    int i = 0; // index into the left vector
    int j = 0; // index into right vector
    int k = 0; // index into merged vector

    // while both vectors have content
    int leftVecSize = leftVec.size();
    int rightVecSize = rightVec.size();
    while (i < leftVecSize && j < rightVecSize)
    {
      if (leftVec[i] < rightVec[j])
      {
        dataSet[k] = leftVec[i];
        i++;
      }
      else
      {
        dataSet[k] = rightVec[j];
        j++;
      }
      k++;
    }

    // if left vector still has values, add them
    while (i < leftVecSize)
    {
      dataSet[k] = leftVec[i];
      i++;
      k++;
    }

    // if right vector still has values, add them
    while (j < rightVecSize)
    {
      dataSet[k] = rightVec[j];
      j++;
      k++;
    }
  }
}

int main() 
{
  for (auto x : items)
    cout << x << " ";
  mergeSort(items);
  for (auto x : items)
    cout << x << " ";
}
