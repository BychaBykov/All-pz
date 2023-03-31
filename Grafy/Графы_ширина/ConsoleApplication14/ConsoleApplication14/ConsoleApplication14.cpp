#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS_
using namespace std;

struct Graf {
	vector<vector<int>> graf;
};

void input(Graf& graf, vector<bool>& marks, int& v);
int DFS(Graf graf, vector<bool> marks, int v, int prev);
void result(int res);



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


void result(int res) {
	if (res == 1)
		cout << "EXIST!";
	else
		cout << "NOT EXIST";
}

int BFS(Graf graf, vector<bool> marks, int v, int prev) {
	int a;
	queue <int> q;
	if (marks[v])
		return 1;
	marks[v] = true;
	for (int i = 0; i < graf.graf.size(); i++) 
		if ((graf.graf[v][i] == 1) && (i != prev))
			q.push(i);
	while (!q.empty())
	{
		a = q.front();
		if (marks[a])
			return 1;
		q.pop();
		marks[a] = true;
		for (int i = 0; i < graf.graf.size(); i++)
			if ((graf.graf[a][i] == 1) && (i != prev))
				q.push(i);
		prev = a;
	}
	
}

int main()
{
	Graf graf;
	vector<bool> marks;
	int v;
	input(graf, marks, v);
	result(BFS(graf, marks, v, v));
	return 0;
}