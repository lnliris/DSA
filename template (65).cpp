/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool* G[], int e);
void process(bool* G[], int v, int n);

int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool** G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được;

	//###INSERT CODE HERE -
	G = new bool* [v];
	for (int i = 0; i < v; i++)
		G[i] = new bool[v];
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			G[i][j] = 0;
	inputGraph(G, e);
	process(G, v, n);
	return 0;
}
void inputGraph(bool* G[], int e)
{
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x - 1][y - 1] = 1;
	}
}
void process(bool* G[], int v, int n)
{
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if (c == 1)
		{
			int x, y;
			cin >> x >> y;
			if (G[x - 1][y - 1])
				cout << "TRUE\n";
			else
				cout << "FALSE\n";
		}
		else
		{
			int k;
			cin >> k;
			int count = 0;
			for (int j = 0; j < v; j++)
				if (G[k - 1][j])
				{
					cout << j + 1 << " ";
					count++;
			
				}
			if (count == 0) cout << "NONE";
			cout << endl;
		}
	}
}
