//
// Kombinacje n elementowe
//

#include <iostream>

using namespace std;

void combinations(int tab[], int tabStart, int tabSize, int result[], int count, int comSize) {
	if (count == comSize) {
		for (int i = 0; i < comSize; i++)
			cout << result[i] << " ";

		cout << endl;
		return;
	}
	for (int i = tabStart; i < tabSize; i++) {
		result[count] = tab[i];
		combinations(tab, i + 1, tabSize, result, count + 1, comSize);
	}
}

int main() {

	int tabSize = 3;
	int n = 3;
	int *tabOfResults = new int[n];
	int tab[4] = { 1, 2, 3 };
	combinations(tab, 0, tabSize, tabOfResults, 0, n);

	delete[] tabOfResults;
	return 0;
}