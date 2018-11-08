#include "UF.h"


UF::UF(int N)
{
	count = N;
	id = new int[N];
	for (int i = 0; i < N; ++i)
	{
		id[i] = i;
	}
}
int UF::_getCount()
{
	return count;
}

bool UF::_connected(int p, int q)
{
	return _find(p) == _find(q);
}

int UF::_find(int p)
{
	return 0;
}

void UF::_union_Node(int p, int q)
{

}




UF::~UF()
{
	delete[] id;
}
