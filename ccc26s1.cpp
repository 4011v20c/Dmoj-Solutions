#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long f(long long x, long long D, long long K) {
    return abs(x) + abs(D - x * K);
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);

    long long a, b,k, t;

    cin >> a >> b>> k >> t;

    long long D = abs(a - b);

    long long q = D / k;

    long long M =min(f(q, D, k), f(q + 1, D, k));

    if (t == 1) {
        cout << M << "\n";
    } else {
        bool b= false;

        for (long long x = q - 5; x <= q + 5; ++x) {
            if (f(x, D, k) == M + 1) {
                b = true;
                break;
            }
        }

        if (b){
            cout <<M + 1 << "\n";
        } else {
            cout << M + 2 << "\n";
        }
    }

    return 0;
}