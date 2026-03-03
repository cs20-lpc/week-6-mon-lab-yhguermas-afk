#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Time Complexity Analysis:
 * Tower of Hanoi:
 *   T(n) = 2T(n-1) + 1
 *   → O(2^n)
 *   Number of moves = 2^n - 1
*******************************************************************************/

void towerHanoi(int numDisks, string source, string buffer,
                string target, int& numMoves)
{
    // Base case
    if (numDisks == 1) {
        cout << "Moving disc 1 from " << source
             << " to " << target << endl;
        numMoves++;
        return;
    }

    // Move n-1 disks to buffer
    towerHanoi(numDisks - 1, source, target, buffer, numMoves);

    // Move largest disk
    cout << "Moving disc " << numDisks
         << " from " << source
         << " to " << target << endl;
    numMoves++;

    // Move n-1 disks to target
    towerHanoi(numDisks - 1, buffer, source, target, numMoves);
}

/*******************************************************************************
 * MAIN (unchanged)
*******************************************************************************/

int main() {
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    return 0;
}
