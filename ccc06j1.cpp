#include <iostream>
using namespace std;

int main() {
  int menu[4][4] = {
    {461, 431, 420, 0},
    {100, 57, 70, 0},
    {130, 160, 118, 0},
    {167, 266, 75, 0}
  };

  int bchoice, schoice, dchoice, dechoice;
  cin >> bchoice;
  bchoice = menu[0][bchoice - 1];
  cin >> schoice;
  schoice = menu[1][schoice - 1];
  cin >> dchoice;
  dchoice = menu[2][dchoice - 1];
  cin >> dechoice;
  dechoice = menu[3][dechoice - 1];

  int calories = bchoice + schoice + dchoice + dechoice;
  cout << "Your total Calorie count is " << calories << "." << endl;

  return 0;
}