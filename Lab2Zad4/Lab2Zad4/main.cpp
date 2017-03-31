//
// Generator liczb losowych metodą przesuwania bitów i xorowania, dla liczb rzeczywistych z przedziału (a,b)
//

#include <iostream>

using namespace std;

unsigned int generateOneNumber(int p, int q, int x);


int main() {
	const int max = 150, amount = 200;
	int a = 2, b = 1;
	int random = 4294967279;


	for (int i = 0; i < amount; i++) {
		random = generateOneNumber(10, 3, random);

		printf("%f\n", ((double)abs(random%max) / max)*(b - a) + a);
	}

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