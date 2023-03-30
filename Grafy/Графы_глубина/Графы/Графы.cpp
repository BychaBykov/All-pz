#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

struct Graf {
	vector<vector<int>> graf;
};

void input(Graf& graf, int& v);
int DFS(Graf graf, int v);

int main()
{
	Graf graf;
	int v;
	input(graf,v);
	
}


void input(Graf& graf, int& v) {
	ifstream file("graf.txt");
	int n, m;
	file >> n >> m >> v;
	graf.graf.resize(n, vector<int>(n));
	int a, b;
	for (int i = 0; i < m; i++) {
		file >> a >> b;
		graf.graf[a][b] = 1;
	}
	file.close();
}

int DFS(Graf graf, int v) {
	int i = v;

}