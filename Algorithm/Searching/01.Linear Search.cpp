//Time : O(n)


 //C/C++
int search(int arr[], int n, int x)
   for (int i = 0; i < n; ++i) {
       if (arr[i] == x) {
          return i;
       }
   }
   return -1;
}

//Python
if x in  arr:
    print arr.index(x)

or

def search(arr, x)
{
  for i in range(len(arr)):
      if arr[i] == x
         return i
  return -1
}


//Java
class LinearSearch
{
   static int search(int arr[], int n, int x)
   {
       for (int i = 0; i < n; ++i) {
          if (arr[i] == x)
             return i;
       }
       return -1;
   }
}
