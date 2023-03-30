#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Graf {
	vector<vector<int>> graf;
};

void input(Graf& graf, vector<bool>& marks, int& v);
int DFS(Graf graf,vector<bool> marks, int v, int prev);
void result(int res);

int main()
{
	Graf graf;
	vector<bool> marks;
	int v;
	input(graf,marks,v);
	result(DFS(graf, marks, v, v));
	return 0;
}


void input(Graf& graf, vector<bool>& marks, int& v) {
	ifstream file("graf.txt");
	int n, m;
	file >> n >> m >> v;
	graf.graf.resize(n, vector<int>(n));
	int a, b;
	for (int i = 0; i < m; i++) {
		file >> a >> b;
		graf.graf[a][b] = 1;
		graf.graf[b][a] = 1;
	}
	marks.resize(n);
	file.close();
}

int DFS(Graf graf, vector<bool> marks, int v,int prev) {
	if (marks[v])
		return 1;
	marks[v] = true;
	for (int i = 0; i < graf.graf.size(); i++) {
		if ((graf.graf[v][i] == 1) && (i != prev)) {
			int res = DFS(graf, marks, i, v);
			if (res != -1)
				return res;
		}
	}
	return -1;
}

void result(int res) {
	if (res == 1)
		cout << "EXIST!";
	else
		cout << "NOT EXIST";
}