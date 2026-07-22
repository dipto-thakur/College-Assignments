#include <iostream>
using namespace std;

// A perfect number equals the sum of its proper divisors
// (divisors excluding the number itself). 28 is a classic example:
// 1 + 2 + 4 + 7 + 14 = 28
bool isPerfect(int num) {
    if (num <= 0) return false;

    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPerfect(num)) {
        cout << num << " is a perfect number." << endl;
    } else {
        cout << num << " is not a perfect number." << endl;
    }

    return 0;
}
