#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

long long gcd(long long a,long long b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);

    int n;
    cin >> n;

    vector<long long> c(n);
    bool u = false;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] == -1) {
            u = true;
        }
    }

    if (u) {
        int k= 100;
        cout<< k << "\n";

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 1);

        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(indices.begin(), indices.end(), rng);

        for (int i = 0; i < k; ++i) {
            cout << 2 << " " << 2 << "\n";
            cout << indices[i*4] << " " << indices[i*4+1] << "\n";
            cout << indices[i*4+2] << " " << indices[i*4+3] << "\n";
        }
        return 0;
    }

    vector<int> evens, odds;
    for (int i = 0; i < n; ++i) {
        if (c[i] % 2 == 0) evens.push_back(i + 1);
        else odds.push_back(i + 1);
    }

    if (evens.size() >= 2) {
        cout << "YES\n";
        cout << "1 1\n";
        cout << evens[0] << "\n";
        cout << evens[1] << "\n";
        return 0;
    }

    if (evens.size() >= 1 && odds.size() >= 2) {
        cout << "YES\n";
        cout << "1 2\n";
        cout << evens[0] << "\n";
        cout << odds[0] << " " << odds[1] << "\n";
        return 0;
    }

    if (odds.size() >= 4) {
        cout << "YES\n";
        cout << "2 2\n";
        cout << odds[0] << " " << odds[1] << "\n";
        cout << odds[2] << " " << odds[3] << "\n";
        return 0;
    }

    int b1 = 0, b2 = 0;
    bool found = false;

    for (int m1 = 1; m1 < (1 << n); ++m1) {
        for (int m2 = 1; m2 < (1 << n); ++m2) {
            if ((m1 & m2) == 0) {
                long long sum1 = 0, sum2 = 0;
                for (int i = 0; i < n; ++i) {
                    if ((m1>> i) & 1) sum1 += c[i];
                    if ((m2 >> i) & 1) sum2+= c[i];
                }
                if (gcd(sum1, sum2) > 1) {
                    found = true;
                    b1 = m1;
                    b2 = m2;
                    break;
                }
            }
        }
        if (found)break;
    }

    if (found){
        cout << "YES\n";
        vector<int> A, B;
        for (int i = 0; i < n; ++i) {
            if ((b1 >> i) & 1) A.push_back(i + 1);
            if ((b2 >> i) & 1) B.push_back(i + 1);
        }
        cout << A.size() << " " << B.size() << "\n";

        for (int i = 0; i < A.size(); ++i) {
            cout << A[i] << (i + 1 == A.size()? "" :" ");
        }
        cout << "\n";

        for (int i = 0; i< B.size(); ++i) {
            cout << B[i] << (i + 1 == B.size() ? "" : " ");
        }
        cout << "\n";
    } else {
        cout <<"NO\n";
    }

    return 0;
}