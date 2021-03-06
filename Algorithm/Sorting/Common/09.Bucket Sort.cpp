/*

Bucket sort is mainly useful when input is uniformly distributed over a range

bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.

Time Complexity: If we assume that insertion in a bucket takes O(1) time then 
steps 1 and 2 of the above algorithm clearly take O(n) time. The O(1) is easily 
possible if we use a linked list to represent a bucket (In the following code, 
C++ vector is used for simplicity). Step 4 also takes O(n) time as there will be
 n items in all buckets.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void bucketSort(vector<float> &arr)
{
	int n = arr.size();
    vector<float> bucket[n];
    for (int i = 0; i < n; ++i) {
        int index = n * arr[i];
        bucket[index].push_back(arr[i]);
    }

    //sort individual buckets
    for (int i = 0; i < n; ++i) {
        sort(bucket[i].begin(), bucket[i].end());

     //concatenate all buckets into arr[]
     int idx = 0;
     for (int i = 0; i < n; ++i) {
         for (int j = 0; j < bucket[i].size(); ++j) {
             arr[idx++] = bucket[i][j];
         }
     }
    }
}

int main()
{
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);
    for (auto val : arr) {
    	cout << val << " ";
	}
    return 0;
}

