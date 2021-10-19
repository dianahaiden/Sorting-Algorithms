#ifndef SORT_H
#define SORT_H

#include "Sort.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Sort::Sort(string fileName) {
  comparisons = 0;
  list = new int[10000];
  
  ifstream inFile(fileName);
  int count = 0;
  int number;

  while (count < 10000 && inFile >> number) {
    list[count++] = number;
  }
  inFile.close();
  
}

Sort::~Sort() {
  delete []list;
}

void Sort::insertionSort() {
  int swap;
  int j;

  for (int i = 1; i < 10000; i++) {
    swap = list[i];
    j = i - 1;

    while (j >= 0 && list[j] > swap) {
      list[j + 1] = list[j];
      j = j -1;
      comparisons++;
    }
    list[j + 1] = swap;
    comparisons++;
  }
  print();

  cout << "#insertion sort comparisons: " << comparisons << endl;
}

void Sort::selectionSort() {
  int min, j;

  for (int i = 0; i < 10000 - 1; i++) {
    min = i;
    for (j = i + 1; j < 10000; j++) {
      if (list[j] < list[min]) {
	min = j;
      }
      comparisons++;

      // swapping the min value with i value
      int temp = list[i];
      list[i] = list[min];
      list[min] = temp;
    }
  }

  print();
  cout << "#selection sort comparisons: " << comparisons << endl;

    
}

void Sort::mergeSort(int beg, int end) {
  if (beg >= end){
        return;
    }
    int middle = beg + (end - beg) / 2;
    mergeSort(beg, middle);
    mergeSort(middle + 1, end);
    mergeArrays(beg, middle, end);

  /* if (beg >= end) {
    return;
  }
  int middle = beg + (end - beg) / 2;
  mergeSort(beg, middle);
  mergeSort(middle + 1, end);
  mergeArrays(beg, middle, end);
  */
}

// This method creates two smaller arrays and merges them together
void Sort::mergeArrays(int beg, int middle, int end) {

  int size1 = middle - beg + 1;
  int size2 = end - middle;

  int *begArr = new int[size1];
  int *endArr = new int[size2];

  for (int i  = 0; i < size1; i++) {
    begArr[i] = list[beg + i];
  }
  for (int i = 0; i < size2; i++) {
    endArr[i] = list[middle + 1 + i];
  }

  int begIndex = 0;
  int endIndex = 0;
  int mergedIndex = beg;

  while (begIndex < size1 && endIndex < size2) {
    if (begArr[begIndex] <= endArr[endIndex]) {
      list[mergedIndex] = begArr[begIndex];
      begIndex++;
      comparisons++;
    } else {
      list[mergedIndex] = endArr[endIndex];
      endIndex++;
      comparisons++;
    }
    mergedIndex++;
  }
  
  while (begIndex < size1) {
    list[mergedIndex] = begArr[begIndex];
    mergedIndex++;
    begIndex++;
  }

  while (endIndex < size2) {
    list[mergedIndex] = endArr[endIndex];
    mergedIndex++;
    endIndex++;
  }
  
  delete []begArr;
  delete []endArr;

}

void Sort::heapSort() {
  for (int i = 10000 / 2 - 1; i >= 0; i--) {
    heapSortHelp(10000, i);
  }
  int size = 10000;
 
  for (int i = size - 1; i > 0; i--) {
 
    int temp = list[0];
    list[0] = list[i];
    list[i] = temp;
 
    heapSortHelp(i, 0);
  }
  
  print();
  cout << "#heapsort comparisons: " << comparisons << endl;
}

//This method makes a subtree
void Sort::heapSortHelp(int size, int root) {
  int biggest = root; 
  int left = 2 * root + 1; 
  int right = 2 * root + 2; 
 
  comparisons++;
  if (left < size && list[left] > list[biggest]) {
    biggest = left;
  }
 
  comparisons++;
  if (right < size && list[right] > list[biggest]) {
    biggest = right;
  }
    
  if (biggest != root) {
    int temp = list[root];
    list[root] = list[biggest];
    list[biggest] = temp;
    heapSortHelp(size, biggest);

  }
}

void Sort::quickSort(int beg, int end) {
  if (beg < end) {
      int pivot = quickSortHelp(beg, end);
 
      quickSort(beg, pivot - 1);
      quickSort(pivot + 1, end);
  }

 
}

// Places the pivot value into the right place and places all smaller values t othe left
int Sort::quickSortHelp(int beg, int end) {
  int pivot = list[end]; 
  int i = (beg - 1); 
 
  for (int j = beg; j <= end - 1; j++)
    {
      comparisons++;
      if (list[j] < pivot) { // checks if value is < pivot
	  i++;
	  
	  int temp = list[i];
	  list[i] = list[j];
	  list[j] = temp;
      }
    }

  int temp = list[i + 1];
  list[i + 1] = list[end];
  list[end] = temp;
  return (i + 1);
}

void Sort::print() {
  for (int i = 0; i < 10000; i++) {
    cout << list[i] << " ";
  }
  cout << endl;
}

long Sort::getComparisons() {
  return comparisons;
}


#endif
