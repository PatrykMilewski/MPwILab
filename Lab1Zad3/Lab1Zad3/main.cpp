//
// Permutacje zbioru n elementowego.
//

#include <iostream>

using namespace std;

void permutations(int tab[], int tabSize, int n) {
	if (n < tabSize - 1) {
		for (int i = n; i < tabSize; i++) {
			swap(tab[n], tab[i]);
			permutations(tab, tabSize, n + 1);
			swap(tab[n], tab[i]);
		}
	}
	else {
		for (int i = 0; i < tabSize; i++)
			cout << tab[i] << " ";
		cout << endl;
	}
}

int main() {

	const int tabSize = 4;

	int tab[tabSize] = { 1, 2, 3, 4 };
	permutations(tab, tabSize, 0);

	return 0;
}