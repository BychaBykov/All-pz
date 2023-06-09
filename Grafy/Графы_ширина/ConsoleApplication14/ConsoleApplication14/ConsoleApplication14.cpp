﻿#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <time.h>
#include "testcrator.cpp"
using namespace std;

struct Graf {
	vector<vector<bool>> graf; 
};

void input(Graf& graf, vector<bool>& marks, int& v);
bool BFS(Graf& graf, vector<bool> marks, int v);
void result(int res);



void input(Graf& graf, vector<bool>& marks, int& v) {
	//test();
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

bool BFS(Graf& graf, vector<bool> marks, int v) {
	int a;
	Graf markO;
	markO.graf.resize(graf.graf.size(), vector<bool>(graf.graf.size()));
	queue <int> q;
	marks[v] = true;
	for (int i = 0; i < graf.graf.size(); i++)
		if (graf.graf[v][i]){
			markO.graf[v][i] = true;
			q.push(i);
			}
	while (!q.empty())
	{	
		a = q.front();
		if (marks[a])
			return true;
		q.pop();
		marks[a] = true;
		for (int i = 0; i < graf.graf.size(); i++)
			if (graf.graf[a][i] && !markO.graf[i][a]){
				q.push(i);
				markO.graf[a][i] = true;
				}
	}
	return false;
}

int main()
{
	Graf graf;
	vector<bool> marks;
	int v;
	input(graf, marks, v);
	int start = clock();
	result(BFS(graf, marks, v));
	int end = clock();
	cout << endl << "Time: " << end - start;
	return 0;
}
