#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<string>& codes, int l, int r)
{
	int i = l, j = r;
	string x = codes[(l + r) / 2];

	while (i <= j)
	{
		while (codes[i] < x)
			i++;

		while (codes[j] > x)
			j--;

		if (i <= j) {
			swap(codes[i], codes[j]);
			i++;
			j--;
		}
	}

	if (l < j) quickSort(codes, l, j);

	if (i < r) quickSort(codes, i, r);
}

int main()
{
	vector<string> codes;

	int n;
	cin >> n;

	codes.resize(n);
	for (auto& x : codes)
	{
		cin.ignore();
		cin >> x;
	}

	quickSort(codes, 0, n - 1);

	int count = 1;
	for (int i = 0; i < n - 1; i++)
		if (codes[i] != codes[i + 1])
			count++;

	cout << count;
}

