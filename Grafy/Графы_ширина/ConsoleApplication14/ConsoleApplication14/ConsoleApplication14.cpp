#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "testcrator.cpp"
using namespace std;

struct Graf {
	vector<vector<bool>> graf; 
};

void input(Graf& graf, vector<bool>& marks, int& v);
int BFS(Graf& graf, vector<bool> marks, int v);
void result(int res);



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


void result(int res) {
	if (res == 1)
		cout << "EXIST!";
	else
		cout << "NOT EXIST";
}

int BFS(Graf& graf, vector<bool> marks, int v) {
	int a, prev = v;
	Graf markO;
	markO.graf.resize(graf.graf.size(), vector<bool>(graf.graf.size()));
	queue <int> q;
	if (marks[v])
		return 1;
	marks[v] = true;
	for (int i = 0; i < graf.graf.size(); i++)
		if ((graf.graf[v][i]) && (i != prev)){
			markO.graf[v][i] = true;
			q.push(i);
			}
	while (!q.empty())
	{
		a = q.front();
		if (marks[a])
			return 1;
		q.pop();
		marks[a] = true;
		for (int i = 0; i < graf.graf.size(); i++)
			if (graf.graf[a][i] && !markO.graf[i][a]){
				q.push(i);
				markO.graf[a][i] = true;
				}
	}
}

int main()
{
	Graf graf;
	vector<bool> marks;
	int v;
	input(graf, marks, v);
	result(BFS(graf, marks, v));
	return 0;
}
