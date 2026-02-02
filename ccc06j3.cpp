#include <bits/stdc++.h>
using namespace std;

int main() {
    string c;
    while(cin >> c) {
        if(c == "halt") {
            break;
        }
        int sec = 0;
        char prev = ' ';
        for(int i = 0; i < c.length(); i++) {
            if(c[i] >= 'a' && c[i] <= 'c') {
                int temp = (c[i] - 'a') % 3 + 1;
                sec = sec + temp;
                if(prev >= 'a' && prev <= 'c') {
                    sec = sec + 2;
                }
            }
            else if(c[i] >= 'd' && c[i] <= 'f') {
                int temp = (c[i] - 'd') % 3 + 1;
                sec = sec + temp;
                if(prev >= 'd' && prev <= 'f') {
                    sec = sec + 2;
                }
            }
            else if(c[i] >= 'g' && c[i] <= 'i') {
                int temp = (c[i] - 'g') % 3 + 1;
                sec = sec + temp;
                if(prev >= 'g' && prev <= 'i') {
                    sec = sec + 2;
                }
            }
            else if(c[i] >= 'j' && c[i] <= 'l') {
                int temp = (c[i] - 'j') % 3 + 1;
                sec = sec + temp;
                if(prev >= 'j' && prev <= 'l') {
                    sec = sec + 2;
                }
            }
            else if(c[i] >= 'm' && c[i] <= 'o') {
                int temp = (c[i] - 'm') % 3 + 1;
                sec = sec + temp;
                if(prev >= 'm' && prev <= 'o') {
                    sec = sec + 2;
                }
            }
            else if(c[i] >= 'p' && c[i] <= 's') {
                int temp = (c[i] - 'p') % 4 + 1;
                sec = sec + temp;
                if(prev >= 'p' && prev <= 's') {
                    sec = sec + 2;
                }
            }
            else if(c[i] >= 't' && c[i] <= 'v') {
                int temp = (c[i] - 't') % 3 + 1;
                sec = sec + temp;
                if(prev >= 't' && prev <= 'v') {
                    sec = sec + 2;
                }
            }
            else if(c[i] >= 'w' && c[i] <= 'z') {
                int temp = (c[i] - 'w') % 4 + 1;
                sec = sec + temp;
                if(prev >= 'w' && prev <= 'z') {
                    sec = sec + 2;
                }
            }
            prev = c[i];
        }
        cout << sec << endl;
    }

    return 0;
}
