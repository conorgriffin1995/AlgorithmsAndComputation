#include <string>
#include <iostream>
using namespace std;

void hanoi(int n, char peg1, char peg2, char peg3);
int moves(0);

int main() {
	int pegs;
	cout << "Enter number of pegs: " << endl;
	cin >> pegs;
	hanoi(pegs, 'A', 'B', 'C');
	cout << "It took " << moves << " moves." << endl;

	system("pause");
	return 0;
}

void hanoi(int n, char peg1, char peg2, char peg3) {
	moves++;
	if (n == 1) {
		cout << "Move peg " << n << " from " << peg1 << " to " << peg3 << endl;
	}
	else {
		hanoi(n - 1, peg1, peg3, peg2);
		cout << "Move peg " << n << " from " << peg1 << " to " << peg3 << endl;
		hanoi(n - 1, peg2, peg1, peg3);
	}
}