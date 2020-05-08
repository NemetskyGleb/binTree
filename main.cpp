#include <iostream>
#include "bintree.h"
#include <vector>
#include <ctime>
int main() {
	using namespace std;
	int a[5] = {5, 4, 3, 10, 1} ; // массив ключей
	SBTree b(a, 5);
	cout << "SBTree b :" << endl;
	b.PrintTree(1, b.Root());
	cout << endl;
	SBTree c(b); // конструктор копирования
	cout << "SBTree c :" << endl;
	c.PrintTree(1, c.Root());
	cout << endl;
	SBTree d(5);
	cout << "SBTree d :" << endl;
	d.PrintTree(1, d.Root());
	cout << endl;
	d = c; // оператор копирования
	cout << "SBTree d :" << endl;
	d.PrintTree(1, d.Root());
	cout << endl;
	d.Add(12, d.Root());
	cout << "Adding 12 to d" << endl;
	cout << "SBTree d :" << endl;
	d.PrintTree(1, d.Root());
	cout << endl;
	cout << "Height of d = "<< d.FindHeight(d.Root()) << endl; // высота
	Node* max = d.FindMax(d.Root());
	cout << "Max of d = " << max->getkey() << endl;
	Node* min = d.FindMin(d.Root());
	cout << "Min of d = " << min->getkey() << endl;
	Node* fkey = d.FindKey(12, d.Root());
	cout << "Find key = 12 in d:" << endl;
	fkey->getkey() == 12 ? cout << "True.\n" : cout << "False\n";
	cout << "LCR traversal: " << endl;
	d.TreeTravelsalLCR(d.Root());
	cout << endl;
	cout << "LRC traversal: " << endl;
	d.TreeTravelsalLRC(d.Root());
	cout << endl;
	cout << "RLC traversal: " << endl;
	d.TreeTravelsalRLC(d.Root());
	cout << endl;
	cout << "SBTree b :" << endl;
	b.PrintTree(1, b.Root());
	b.Del();
	cout << "SBTree b after Del root :" << endl;
	b.PrintTree(1, b.Root());
	cin.get();
	return 0;
}