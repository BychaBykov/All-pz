#include <iostream>
#include <fstream>
using namespace std;

void test() {
	ofstream file("graf.txt");
	int i = 0;
	int j = 0;
	int n = 32000;
	file.clear();
	file << n << ' ' << n - 1 << ' ' << 0 << endl;
	for (i; i < n - 1; i++) {
		file << i << ' ' << i + 1 << endl;
	}
	file.close();
}