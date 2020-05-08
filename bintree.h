#ifndef BIN_TREE_H_ 
#define BIN_TREE_H_
#include <iostream>

class Node {
private:
	int key;
	Node* left, *right, *parent;
public:
	friend class SBTree;
	Node(int k = 0, Node* L = NULL, Node* R = NULL,Node *P = NULL) : key(k), left(L), right(R), parent(P) {}
	int getkey() { return key; }
};
class SBTree {
private:
	Node* root;
	void Copy(Node* q, Node* p, int k); // копирует дерево с корнем
										// p - предок корня нового дерева
										// если k = 0 - копируем левого потомка
										// если k = 1 - копируем правого потомка
public:
	SBTree() { root = NULL; }	
	SBTree(int n); // создание случайного дерева содержащего n узлов
	SBTree(int *a, int n); // a - массив ключей, n - кол-во ключей
	SBTree(const SBTree& );
	SBTree& operator=(const SBTree& );
	~SBTree();
	void Add(int k, Node* p); // добавление узла с ключом k после узла p
	void Del(Node* p); // удаление узла p
	void Del(); // удаление корня
	void TreeTravelsalLCR(Node* p); // обход дерева лево-корень-правл
	void TreeTravelsalLRC(Node* p); // обход дерева лево-право-корень
	void TreeTravelsalRLC(Node* p); // ...
	
	Node* FindKey(int k, Node* p); // поиск ключа
	Node* FindMax(Node* p);
	Node* FindMin(Node* p);
	int FindHeight(Node* p); // высота
	void PrintTree(int k, Node* p);
	void Clear();
	Node* Root() { return root; }
};
#endif