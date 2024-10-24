#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long SUM(int N, int mod){
    vector<bool> isPrime(N + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<long> dp(N + 1, 0);
    dp[0] = 1;
    for (int prime = 0; prime < primes.size(); prime++) {
        for (int i = primes[prime]; i <= N; i++) {
            dp[i] += dp[i - primes[prime]] % mod;
        }
    }
    return dp[N];
}
int main()
{
    int N;
    cin>>N;
    long next = N + 1;
    while (true) {
        if (next <= 1) return 2;
        if (next == 2) return 2;
        if (next % 2 == 0) {
            next++;
        }
        bool isPrime = true;
        for (int i = 3; i <= sqrt(next); i += 2) {
            if (next % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) break;;
        next++;
    }
    cout<<SUM(N, next)%next<<endl;
    return 0;
}