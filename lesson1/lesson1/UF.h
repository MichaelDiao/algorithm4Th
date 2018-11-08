#pragma once
class UF
{
public:
	UF(int N);
	void _union_Node(int p, int q);
	int _find(int p);
	bool _connected(int p, int q);
	int _getCount();
	~UF();
private:
	int *id;
	int count;


};

