#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/*******************************************************************************
 * Time Complexity Analysis:
 * findMaxRecTail:
 *   Makes one recursive call per element → O(n)
 *
 * findMaxRecBinarySplit:
 *   Splits array into two halves recursively
 *   T(n) = 2T(n/2) + O(1)
 *   → O(n)
*******************************************************************************/

template <typename T>
T findMaxRecTail(const T arr[], const int size, int i)
{
    // Base case: last element
    if (i == size - 1)
        return arr[i];

    // Recursive call
    T maxRest = findMaxRecTail(arr, size, i + 1);

    return (arr[i] > maxRest) ? arr[i] : maxRest;
}

template <typename T>
T findMaxRecBinarySplit(const T arr[], const int left, const int right)
{
    // Base case: one element
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    T maxLeft = findMaxRecBinarySplit(arr, left, mid);
    T maxRight = findMaxRecBinarySplit(arr, mid + 1, right);

    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

/*******************************************************************************
 * MAIN (unchanged)
*******************************************************************************/

int main() {
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE, 0) << endl 
         << "From Binary split:"
         << findMaxRecBinarySplit(myArray, 0, SIZE-1)
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2, 0) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    return 0;
}