#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
	int t, n;
	cin >> t;
	while (t--) {
	    cin >> n;
	    cout << (isPrime(n) ? "Yes" : "No") << endl;
	}
	return 0;
}
