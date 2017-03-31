//
// Generator liczb losowych metod¹ przesuwania bitów i xorowania
//

#include <iostream>

using namespace std;

unsigned int generateOneNumber(int p, int q, int x);


int main() {
	const int max = 150, amount = 10000000;

	int random = 4294967279;
	unsigned int *tab = new unsigned int[max];

	for (int i = 0; i < max; i++)
		tab[i] = 0;


	for (int i = 0; i < amount; i++) {
		random = generateOneNumber(10, 3, random);

		tab[abs(random % max)]++;
	}

	for (int i = 0; i < max; i++)
		printf("%d ", tab[i]);

	delete[] tab;

	return 0;
}

unsigned int generateOneNumber(int p, int q, int x) {
	int A, B, mA, mB, xor;
	for (int i = 0; i < 32; i++) {
		A = 1 << p;
		B = 1 << q;
		mA = (x&A) >> p;
		mB = (x&B) >> q;
		xor = !(mA == mB);
		x <<= 1;
		x += xor;
	}
	return x;
}