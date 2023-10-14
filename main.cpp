// Wayne Pinnock, CS 211, Spring Semester 2023
#include <iostream>
#include <cmath>
using namespace std;

//Backtrack method:
bool okay(int q[], int c) {
  static int helperArray[8][5] = {  // Generate Helper array, -1 is the guard
  {-1},              // 0
  {0, -1},           // 1
  {0, -1},           // 2
  {0, 1, 2, -1},     // 3
  {0, 1, 3, -1},     // 4
  {1, 4, -1},        // 5
  {2, 3, 4, -1},     // 6
  {3, 4, 5, 6, -1},  // 7
  };

  // check if the number in position c has already been used
  for(int i = 0; i < c; i++) {
    if(q[i] == q[c]) {
      return false;
    }
  }
  // check if the number is consecutive to adjacent elements to its left
  for(int i = 0; helperArray[c][i] != -1; i++) {
    if(abs(q[c] - q[helperArray[c][i]]) == 1) {
      return false;
    }
  }

  return true;
}

void print(int q[]) {
  static int sol = 1;
  cout << "Solution#:" << sol++ << endl;
  cout << " " << q[1] << q[4] << endl;
  cout << q[0] << q[2] << q[5] << q[7] << endl;
  cout << " " << q[3] << q[6] << endl;
  cout << endl;
}

int main() {
  int q[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  int c = 0;
  q[c] = 1;  // place number 1 at position 0
  c++;  // move to the next position c
  while(c >= 0) {  // end loop if you have no square to backtrack
    if(c > 7) {  // if you have passed the last position, print and backtrack
      print(q);  // print this solution
      c--;  // backtrack to look for next solution
    } else {  // else move num ot 0, which is one num smaller than 1
      q[c] = 0;
    }
    while(c >= 0) {
      q[c]++;  // move to the next num
      if(q[c] > 8) {  // if no num can be placed at current c
        c--;  // backtrack to previous position
      } else if(okay(q, c) == true) {  // else if number is ok break and go to next position c
        c++;
        break;
      }
    }
  }

  return 0;
}
