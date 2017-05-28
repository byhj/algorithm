#include <iostream>
using namespace std;

int sumDig(int n)
{
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
	int t, n;
	cin >> t;
	while (t--) {
	    cin >> n;
	    cout << (n % sumDig(n) == 0) << endl;
	       
	}
	return 0;
}
