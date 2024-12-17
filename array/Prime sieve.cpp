#include <vector>
#include <iostream>
using namespace std;

vector<int> sieve(int n) {
    // Step 1: Create a boolean array to store prime status
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime
    
    // Step 2: Apply the Sieve of Eratosthenes
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Step 3: Collect all primes into a result vector
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {
    int n = 30;
    vector<int> primes = sieve(n);
    
    // Output the primes up to n
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}
