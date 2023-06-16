/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph
{
private:
    vector<vector<int> > G;
    map <string, int> mapping;
	vector<string> names;
public:
    void nhap(int v, int e)
    {
		names.resize(v);
		for (int i = 0; i < v; i++)
		{
			string s;
			cin >> s;
			names[i] = s;
			mapping[s] = i;
		}
        G = vector<vector<int>>(v, vector<int>(v, 0));
        for (int i = 0; i < e; i++)
        {
            string x, y;
            cin >> x >> y;
            G[mapping[x]][mapping[y]] = 1;
        }
    }
    void myProcess(int n)
    {
		for (int i = 0; i < n; i++)
		{
			int c;
			cin >> c;
			if (c == 1)
			{
				string x, y;
				cin >> x >> y;
				if (G[mapping[x]][mapping[y]])
					cout << "TRUE\n";
				else
					cout << "FALSE\n";
			}
			else
			{
				string k;
				cin >> k;
				int count = 0;
				for (int j = 0; j < mapping.size(); j++)
					if (G[mapping[k]][j])
					{
						cout << names[j] << " ";
						count++;

					}
				if (count == 0) cout << "NONE";
				cout << endl;
			}
		}
    }
};

int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

