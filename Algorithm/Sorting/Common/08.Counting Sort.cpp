/*
Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence.

For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.

  Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.
Auxiliary Space: O(n+k)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int> &vec) {
	
	int n = vec.size();
    vector<int> countVec(n);
    for (int i = 0; i < n; ++i) {
        ++countVec[vec[i]];
    }
    for (int i = 1; i < n; ++i) {
        countVec[i] += countVec[i-1];
    }
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[countVec[vec[i]]-1] = vec[i];
        --countVec[vec[i]];
    }
    vec = result;
}

int main()
{
	vector<int> vec = {1, 4, 5, 0, 2, 2, 2, 6};
    countSort(vec);
    for (auto val : vec) {
    	cout << val << " ";
	}
    return 0;
 } 
