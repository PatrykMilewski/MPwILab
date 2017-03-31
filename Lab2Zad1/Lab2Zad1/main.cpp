// 
// Generator liczb losowych oparty o funkcjê liniow¹
//

#include <iostream>
#include <time.h>

using namespace std;


class Generator {
public:
	Generator(int a, int c, int m, int firstX) {
		this->a = a;
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
			temp = (a * firstX + c) % m;
			firstX = temp;
			countTab[firstX]++;
		}
	}

	void coutCountTab() {
		for (int i = 0; i < m; i++)
			cout << countTab[i] << " ";
	}

	int a, c, m, firstX;
	int *countTab;
};


int main() {
	const int max = 100, amount = 10000;
	Generator generator(5821, 479, max, 1);
	generator.generateRandom(amount);
	generator.coutCountTab();

	return 0;
}