
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    a = a/g;
    b = b/g;
    if (a < b)
    {
        if (a != 0)
        {
            cout << a << '/' << b;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        int q = a/b;
        int r = a%b;
        cout << q ;
        if (r != 0)
        {
            cout << ' ' << r << '/' << b;
        }
    }
    cout << '\n';
}