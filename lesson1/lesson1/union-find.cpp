#include <iostream>
#include <fstream>
#include "UF.h"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc == 1)
	{
		cout << "missing parameters" << endl;
		return -1; 
	}
	ifstream f(argv[1]);

	int N = 0;
	string tmp;
	f >> N;
	cout << N << endl;
	
	UF *uf = new UF(N);

	while (!f.eof())
	{
		int p;
		f >> p;
		int q;
		f >> q;
		if (uf->_connected(p,q))
			continue;
		uf->_union_Node(p, q);
		cout << p << " " << q << endl;
	}
	cout << uf->_getCount() << "components11" << endl;


	system("pause");
	return 0;
}