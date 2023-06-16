/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph(vector<vector<int> >& G, int v, int e)
{
	G = vector<vector<int>>(v, vector<int>(v, 0));
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x - 1][y - 1] = 1;
	}
}

void process(vector<vector<int> > G, int v, int n)
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
int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
