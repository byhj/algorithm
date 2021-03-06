/*
Insertion Sort

Algorithm
// Sort an arr[] of size n
insertionSort(arr, n)
Loop from i = 1 to n-1.
……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]


Time Complexity: O(n*n)
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
Algorithmic Paradigm: Incremental Approach
Sorting In Place: Yes
Stable: Yes
Online: Yes
Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
What is Binary Insertion Sort?
We can use binary search to reduce the number of comparisons in normal insertion sort. Binary Insertion Sort find use binary search to find the proper location to insert the selected item at each iteration. In normal insertion, sort it takes O(i) (at ith iteration) in worst case. we can reduce it to O(logi) by using binary search. The algorithm as a whole still has a running worst case running time of O(n2) because of the series of swaps required for each insertion. Refer this for implementation.

*/
#include <vector>
#include <iostream>

using namespace std;

void insertionSort(vector<int> &vec) {
     int n = vec.size();
     for (int i = 1; i < n; ++i) {
         int key = vec[i];
         int j = i-1;
         //find the index to insert, vec [0...i-1];
         while (j >= 0 && vec[j] > key) {
                vec[j+1] = vec[j];
                --j;
         }
         vec[j+1] = key;
     }
}


int main()
{
    vector<int> vec = {12, 11, 13, 5, 6};
    insertionSort(vec);
    for (auto val : vec) {
    	cout << val << " ";
	}
    return 0;
}
