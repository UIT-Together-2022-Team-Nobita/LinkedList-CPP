#include<iostream>
#include<iomanip>
#include<fstream>
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
void Outp(LIST);
void InterchangeSort(LIST&);

int main()
{
	cout << "Project 01." << endl;
	LIST lst;
	Init(lst);
	int n;
	cout << "\nEnter n which indicate the list's size:	";
	cin >> n;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "Enter x" << i <<" value:	";
		cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(lst, p);
	}
	if (IsEmpty(lst) == true)
	{
		cout << "\nEmpty list!";
		return 1206;
	}
	cout << "\nList before sorts:	";
	Outp(lst);
	InterchangeSort(lst);
	cout << "\nList after sorts:	";
	Outp(lst);
	cout << endl;
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

void InterchangeSort(LIST& l)
{
	for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}

void Outp(LIST l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << setw(5) << p->info ;
		p = p->pNext;
	}
	cout << ".";
}