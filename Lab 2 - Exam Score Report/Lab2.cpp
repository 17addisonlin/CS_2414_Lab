// CS 2414 Lab 2 — Exam Score Report
// Do NOT change main() or any function signature.
// Implement the function bodies at the bottom of this file.
//
// Compile:  g++ -o Lab1 Lab1.cpp
// Run:      ./Lab1 < sample1.in

#include <iostream>
using namespace std;


// ----- FUNCTION SIGNATURES: provided. Do not edit. -----
// ----- pass by VALUE -----
int  larger(int a, int b);
int  smaller(int a, int b);
bool isEven(int n);
int  classify(int score, int cutoff);   // 1 ABOVE, 0 MEET, -1 BELOW

// ----- pass by REFERENCE -----
void swapInts(int& x, int& y);
void addScore(int score, int& sum, int& lo, int& hi, bool& started);
void tally(int code, int& above, int& meet, int& below);

// ----- main: provided. Do not edit. -----
int main() {
    int n, cutoff;
    cin >> n >> cutoff;

    int sum = 0;
    int lo = 0;
    int hi = 0;
    bool started = false;
    int above = 0, meet = 0, below = 0;
    int first = 0, last = 0;

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        if (i == 0) {
            first = s;
        }
        last = s;

        addScore(s, sum, lo, hi, started);

        int code = classify(s, cutoff);
        tally(code, above, meet, below);

        if (code == 1) {
            cout << "ABOVE" << endl;
        } else if (code == 0) {
            cout << "MEET" << endl;
        } else {
            cout << "BELOW" << endl;
        }
    }

    int left = first;
    int right = last;
    if (left > right) {
        swapInts(left, right);
    }

    cout << "sum = " << sum << endl;
    cout << "range = " << lo << " " << hi << endl;
    cout << "parity = " << (isEven(sum) ? "EVEN" : "ODD") << endl;
    cout << "above = " << above << " meet = " << meet << " below = " << below << endl;
    cout << "ordered_ends = " << left << " " << right << endl;
    return 0;
}

// ----- YOUR CODE BELOW -----

int larger(int a, int b) {
    int result_larger = (a > b) ? a : b;  //if a > b, return a; else return b
    return result_larger;
}

int smaller(int a, int b) {
    int result_smaller = (a < b) ? a : b;   // if a < b, return a; else return b
    return result_smaller;
}

bool isEven(int n) {
    return (n % 2 == 0);   //this uses modulus to see if even
}

int classify(int score, int cutoff) {
    // below is to check if the score is above, meet, or below
    if (score > cutoff) {
        return 1;   // ABOVE
    } else if (score == cutoff) {
        return 0;   // MEET
    } else {
        return -1;  // BELOW
    }
}

void swapInts(int& x, int& y) {
    int temp = x; // have one of the values in temp for later use
    x = y; // now use the value that is not yet affected to other value
    y = temp; // now temp comes in play, since temp has a copy of x
}

void addScore(int score, int& sum, int& lo, int& hi, bool& started) {
    sum += score; // add all the current scores
    //conitions below
    if (!started) {
        lo = hi = score;
        started = true;
    } else {
        hi = larger(hi, score);
        lo = smaller(lo, score);
    }
}

void tally(int code, int& above, int& meet, int& below) {
    // if else or switch to tally
    switch (code) { // used switch
        case 1: 
            above++;
            break;
        case 0:
            meet++;
            break;
        case -1:
            below++;
            break;
    }
}
