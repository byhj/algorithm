//To multiply x and y, recursively add x y times.

#include<stdio.h>
/* function to multiply two numbers x and y*/
int multiply(int x, int y)
{
   /* 0  multiplied with anything gives 0 */
   if(y == 0)
     return 0;
 
   /* Add x one by one */
   if(y > 0 )
     return (x + multiply(x, y-1));
  
  /* the case where y is negative */
   if(y < 0 )
     return -multiply(x, -y);
}
 
int main()
{
  printf("\n %d", multiply(5, -11));
  getchar();
  return 0;
}
Run on IDE
Time Complexity: O(y) where y is the second argument to function multiply(). 
