//
// Generator liczb losowych dla funkcji kwadratowej
//

#include <iostream>

using namespace std;


class Generator {
public:
	Generator(int a, int b, int c, int m, int firstX) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->m = m;
		this->firstX = firstX;
		countTab = new int[m];
		for (int i = 0; i < m; i++)
			countTab[i] = 0;
	}

	void generateRandom(int amount) {
		int temp;

		for (int i = 0; i < amount; i++) {
			temp = (a * firstX * firstX + b * firstX + c) % m;
			firstX = temp;
			countTab[firstX]++;
		}
	}

	void coutCountTab() {
		for (int i = 0; i < m; i++)
			cout << countTab[i] << " ";
	}

	int a, b, c, m, firstX;
	int *countTab;
};


int main() {
	const int max = 100, amount = 1000;
	Generator generator(140, 1, 1, max, 1);
	generator.generateRandom(amount);
	generator.coutCountTab();

	return 0;
}