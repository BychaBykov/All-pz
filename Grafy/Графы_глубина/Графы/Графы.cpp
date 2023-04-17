#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <time.h>
#include "testcrator.cpp"

using namespace std;

struct Graf {
	vector<vector<bool> > graf;
};

void input(Graf& graf, vector<bool>& marks, int& v);
bool DFS(Graf& graf,vector<bool> marks, int v);
void result(bool res);

int main()
{
	Graf graf;
	vector<bool> marks;
	int v;
	input(graf,marks,v);
	int start = clock();
	result(DFS(graf, marks, v));
	int end = clock();
	cout << endl << "Time: " << end - start;
	return 0;
}

void input(Graf& graf, vector<bool>& marks, int& v) {
	test();
	ifstream file("graf.txt");
	int n, m;
	file >> n >> m >> v;
	graf.graf.resize(n, vector<bool>(n));
	int a, b;
	for (int i = 0; i < m; i++) {
		file >> a >> b;
		graf.graf[a][b] = true;
		graf.graf[b][a] = true;
	}
	marks.resize(n);
	file.close();
}

bool DFS(Graf& graf, vector<bool> marks, int v) {
	stack <int> q;
	Graf markO;
	markO.graf.resize(graf.graf.size(), vector<bool>(graf.graf.size()));
	q.push(v);
	int a;
	while (!q.empty()) {
		a = q.top();
		if (marks[a])
			return true;
		q.pop();
		marks[a] = true;
		for (int i = 0; i < graf.graf.size(); i++) {
			if (graf.graf[a][i] && !markO.graf[i][a]) {
				markO.graf[a][i] = true;
				q.push(i);
			}
		}
	}
	return false;
}

void result(bool res) {
	if (res)
		cout << "EXIST!";
	else
		cout << "NOT EXIST";
}