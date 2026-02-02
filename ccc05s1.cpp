#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string number;
    int digits = 0;
    int j = 0;
    int dashes = 0;
    for (int i = 0; i < t; i++) {
        cin >> number;
        while (digits < 10) {
            if (((digits == 3) && (dashes == 0)) || ((digits == 6) && (dashes == 1))) {
                cout << "-";
                dashes += 1;
            }
            if ((number[j] >= 48) && (number[j] <= 57)) {
                cout << number[j];
            }
            else if ((number[j] >= 65) && (number[j] <= 67)) {
                cout << "2";
            }
            else if ((number[j] >= 68) && (number[j] <= 70)) {
                cout << "3";
            }
            else if ((number[j] >= 71) && (number[j] <= 73)) {
                cout << "4";
            }
            else if ((number[j] >= 74) && (number[j] <= 76)) {
                cout << "5";
            }
            else if ((number[j] >= 77) && (number[j] <= 79)) {
                cout << "6";
            }
            else if ((number[j] >= 80) && (number[j] <= 83)) {
                cout << "7";
            }
            else if ((number[j] >= 84) && (number[j] <= 86)) {
                cout << "8";
            }
            else if ((number[j] >= 87) && (number[j] <= 90)) {
                cout << "9";
            }
            j++;
            if (number[j] != '-') {
                digits++;
            }

        }
        cout << endl;
        j = 0;
        digits = 0;
        dashes = 0;
    }
}