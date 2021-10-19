#include <string>
#include <iostream>
#include <fstream>

#include "Sort.h"

using namespace std;

int main(int argc, char **argv) {

  string algorithm;
  string fileName(argv[1]);
  
  // requests user to select an algorithm to sort file
  cout << "(i)insertion sort (s)selection sort (m)merge sort (h)heapsort (q)quicksort" << endl;

  cout << "Enter the algorithm: ";
  cin >> algorithm;
  
  
  // performs sorting algorithm that user selected
  if(algorithm == "i") {
    Sort insertion(fileName);
    insertion.insertionSort();

  } else if (algorithm == "s") {
    Sort selection(fileName);
    selection.selectionSort();
  } else if (algorithm == "m") {
    Sort merged(fileName);
    merged.mergeSort(0, 10000 - 1);
    merged.print();
    cout << "#merged comparisons: " << merged.getComparisons() << endl;
  } else if (algorithm == "h") {
    Sort heap(fileName);
    heap.heapSort();
  } else if (algorithm == "q") {
    Sort quick(fileName);
    quick.quickSort(0, 10000 - 1);
    quick.print();
    cout << "#quicksort comparisons: " << quick.getComparisons() << endl;
  }
  
  return 0;
}
