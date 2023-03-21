#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct node
{
	int info;
	struct node* pNext;
};
typedef struct node NODE;
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Init(LIST&);
bool IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
bool Inp(LIST&, string);
void InterchangeSort(LIST&);
int NodeCount(LIST);
void Outp(LIST);
bool Outp(LIST, string);

int main()
{
	cout << "Project 03." << endl;
	LIST l;
	string filename = "intdata01";
	string filenameinp = filename + ".inp";
	if (Inp(l, filenameinp) == true)
	{
		InterchangeSort(l);
		string filenameoutp = filename + ".outp";
		Outp(l, filenameoutp);
		cout << "\n" << filenameinp;
		cout << "\n" << filenameoutp << endl;
	}
	else 
		cout << "\nCan't open the file " << filename << "\n";
	return 1206;
}

void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
bool IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return true;
	return false;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

bool Inp(LIST& l, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	int n;
	int x{};
	fi >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return true;
}
void InterchangeSort(LIST& l)
{
	for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}
int NodeCount(LIST l)
{
	int counter = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		counter++;
		p = p->pNext;
	}
	return counter;
}
void Outp(LIST l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << setw(5) << p->info;
		p = p->pNext;
	}
	cout << ".";
}
bool Outp(LIST l, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << NodeCount(l) << endl;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		fo << setw(5) << p->info;
		p = p->pNext;
	}
	return true;
}