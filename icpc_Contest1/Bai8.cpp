#include <bits/stdc++.h>
using namespace std;

const long long MAX_VAL = 1e6;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;
        vector<long long> A(N);
        vector<long long> freq(MAX_VAL + 1, 0);
        
        for (long long i = 0; i < N; ++i) {
            cin >> A[i];
            freq[A[i]]++;
        }

        long long max_gcd = 0;

        for (long long i = 1; i <= MAX_VAL; ++i) {
            long long count = 0;
            for (long long j = i; j <= MAX_VAL; j += i) {
                count += freq[j];
            }
            if (count > 1) {
                max_gcd = i;
            }
        }

        cout << max_gcd << endl;
    }
    
    return 0;
}


