
#include <fstream>
#include <string>

using namespace std;

class Sort
{
 public:
  Sort(); // constructor
  Sort(string fileName);
  ~Sort(); // destructor
  void insertionSort();
  void selectionSort();
  void mergeSort(int, int);
  void heapSort();
  void quickSort(int, int);
  void print();
  long getComparisons();
  
 private:
  long comparisons;
  int *list;
  void mergeArrays(int, int, int);
  int quickSortHelp(int, int);
  void heapSortHelp(int, int);
};


