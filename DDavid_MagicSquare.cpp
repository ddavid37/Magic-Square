#include <iostream>
#include <array>

using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number
const string PROGRAMMERNAME = "Daniel David";
const char PROJECTNUM = '5';
const string DUEDATE = "12 / 10 / 2023";
bool isUniqe, allDiag15, allCol15, allRows15, valuesValidated;

// Function prototypes
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

//main finction
int main() {
    int arrayRow1[MAX];
    int arrayRow2[MAX];
    int arrayRow3[MAX];
    int size = MAX; 
    char userInput;
    bool repeat = false;

    do {
        fillArray(arrayRow1, arrayRow2, arrayRow3, size);
        valuesValidated = checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
            checkUnique(arrayRow1, arrayRow2, arrayRow3, size);

        showArray(arrayRow1, arrayRow2, arrayRow3, size);
        allRows15 = checkRowSum(arrayRow1, arrayRow2, arrayRow3, size);
        allCol15 = checkColSum(arrayRow1, arrayRow2, arrayRow3, size);
        allDiag15 = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);

        if (valuesValidated && isMagicSquare(arrayRow1, arrayRow2, arrayRow3, size)) {
            cout << "Amazing!!\nThis is a Lo Shu magic square!!";
        }
        else {
            cout << "This is not a Lo Shu magic square";
        }

        cout << "\n\n\nDo you want to try again? ";
        cin >> userInput;
        if (userInput == 'y' || userInput == 'Y') {
            repeat = true;
        }
        else if (userInput == 'n' || userInput == 'N') {
            repeat = false;
        }
        else {
            cout << "Make sure you enter only one of: Y/y/N/n\n\n";
        }
    } while (repeat == true);

    cout << "\n\nName: " << PROGRAMMERNAME << endl
        << "Project #: " << PROJECTNUM << endl
        << "Due Date: " << DUEDATE << endl << endl;

    system("pause");
    return 0;
}
//data collection
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int j = 0; j < COLS; j++) {
        cout << "Enter the number for row 1 and column " << j + 1 << " :";
        cin >> arrayRow1[j];
    }

    for (int j = 0; j < COLS; j++) {
        cout << "Enter the number for row 2 and column " << j + 1 << " :";
        cin >> arrayRow2[j];
    }

    for (int j = 0; j < COLS; j++) {
        cout << "Enter the number for row 3 and column " << j + 1 << " :";
        cin >> arrayRow3[j];
    }
}
//chack range
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
    size = 3;
    bool validRow1 = true, validRow2 = true, validRow3 = true;

    for (int i = 0; i < size; i++) {
        if (!(MIN <= arrayRow1[i] && arrayRow1[i] <= MAX)) {
            validRow1 = false;
        }
    }

    for (int i = 0; i < size; i++) {
        if (!(MIN <= arrayRow2[i] && arrayRow2[i] <= MAX)) {
            validRow2 = false;
        }
    }

    for (int i = 0; i < size; i++) {
        if (!(MIN <= arrayRow3[i] && arrayRow3[i] <= MAX)) {
            validRow3 = false;
        }
    }

    if (validRow1 && validRow2 && validRow3) {
        return true;
    }
    else {
        return false;
    }
}
//check uniqe of arrays
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    isUniqe = (arrayRow1[0] != arrayRow1[1]) && (arrayRow1[1] != arrayRow1[2]) && (arrayRow1[0] != arrayRow1[2]) &&
        (arrayRow2[0] != arrayRow2[1]) && (arrayRow2[1] != arrayRow2[2]) && (arrayRow2[0] != arrayRow2[2]) &&
        (arrayRow3[0] != arrayRow3[1]) && (arrayRow3[1] != arrayRow3[2]) && (arrayRow3[0] != arrayRow3[2]);

    if (isUniqe) {
        return true;
    }
    else {
        return false;
    }
}
//show array
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    size = 3;

    for (int i = 0; i < size; i++) {
        cout << arrayRow1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << arrayRow2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << arrayRow3[i] << " ";
    }
    cout << endl;
}
//func to check sum of rows
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sumRow1 = 0;
    int sumRow2 = 0;
    int sumRow3 = 0;
    allRows15 = true;

    sumRow1 = arrayRow1[0] + arrayRow1[1] + arrayRow1[2];
    sumRow2 = arrayRow2[0] + arrayRow2[1] + arrayRow2[2];
    sumRow3 = arrayRow3[0] + arrayRow3[1] + arrayRow3[2];

    if (sumRow1 != 15 || sumRow2 != 15 || sumRow3 != 15) {
        allCol15 = false;
    }
    return allRows15;
}
//func to check sum of columns
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sumCol1 = 0;
    int sumCol2 = 0;
    int sumCol3 = 0;
    allCol15 = true;

    sumCol1 = arrayRow1[0] + arrayRow2[0] + arrayRow3[0];
    sumCol2 = arrayRow1[1] + arrayRow2[1] + arrayRow3[1];
    sumCol3 = arrayRow1[2] + arrayRow2[2] + arrayRow3[2];

    if (sumCol1 != 15 || sumCol2 != 15 || sumCol3 != 15) {
        allCol15 = false;
    }
    return allCol15;
}
//func to check sum of diagonals
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sumDiag1 = 0;
    int sumDiag2 = 0;
    allDiag15 = true;

    sumDiag1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    sumDiag2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];

    if (sumDiag1 != 15 || sumDiag2 != 15) {
        allDiag15 = false;
    }
    return allDiag15;
}
//func checing if magic square
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    return valuesValidated && isUniqe && allRows15 && allCol15 && allDiag15;
}
