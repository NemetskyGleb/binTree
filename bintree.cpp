#include "bintree.h"
#include <ctime>
void SBTree::Add(int k, Node* p) {
	Node* q = new Node(k);
	if(k < p->key)
		if(p->left == NULL) {
			p->left = q;
			q->parent = p;
		}
	else Add(k, p->left);
	else if (p->right == NULL) {
			p->right = q;
			q->parent = p;
		}
	else Add(k, p->right);

}
void SBTree::Del(Node* p) {
	Node* q = p->parent;
	//удаляем лист
	if (p->left == NULL && p->right == NULL) {
		if(q->left == p)
			q->left = NULL;
		else q->right = NULL;
		delete p;
		return;
	}
	// у p - нет правой ветки
	if (p->left != NULL && p->right == NULL) {
		if(q->left == p) 
			q->left = p->left;
		else q->right = p->left;
		p->left->parent = q;
		delete p;
		return;
	}
	// у p - нет левой ветки
	if (p->left == NULL && p->right != NULL) {
		if(q->left == p) 
			q->left = p->right;
		else q->right = p->left;
		p->right->parent = q;
		delete p;
		return;
	}
	// удлаяемый узле имеет 2 поддерева
	Node* t = p->left;
	if (t->right == NULL) {
		if (q->left == p)
			q->left = t;
		else q->right = t;
		t->parent = q;
		t->right = p->right;
		p->right->parent = t;
	}
	else {
		while (t->right != NULL) 
			t = t->right;
		t->parent->right = t->left;
		if (t->left != NULL)
			t->left->parent = t->parent;
		t->right = p->right;
		p->right->parent = t;
		t->left = p->left;
		p->left->parent = t;
		t->parent = q;
		if (q->left == p)
			q->left = t;
		else
			q->right = t;
	}
	delete p;
	return;
}
SBTree::SBTree(int n) {
	srand(std::time(0));
	if (n == 0)
		root = nullptr;
	else {
		root = new Node(rand() % 100);
			for (int i= 1; i < n; i++) {
				Add(rand() % 100, root);			}
	}
}
void SBTree::PrintTree(int k, Node* p) {
	using namespace std;
	if (p == NULL)
		return;
	PrintTree(k + 5, p->right);
	for (int i = 0; i < k; i++)
		cout << ' ';
	cout << p->key << endl;
	PrintTree(k + 5, p->left);
}
void SBTree::Copy(Node *q, Node *p, int k) {
     //копирует дерево с корнем q,
     //p - предок корня нового дерева
     //если k=0 - копируем левого потомка
     //если k=1 - копируем правого потомка
if(q == NULL) return;
 Node* t = new Node(q->key);
 if (k == 0) p->left = t;
 else p->right = t;
 t->parent = p;
 Copy(q->left, t, 0);
 Copy(q->right, t, 1);
}
void SBTree::Clear() {
	if (root == nullptr) return;
	Node* t = root;
	while (t->left) {
		Del(t->left);
	}
	while(t->right) {
		Del(t->right);
	}
}

SBTree::~SBTree() {
	Clear();
	if (root == nullptr) delete root;
}

SBTree::SBTree(int *a, int n) {
	if (n == 0)
		root = nullptr;
	else {
		root = new Node(a[0]);
		for (int i= 1; i < n; i++)
			Add(a[i], root);
	}
}
SBTree::SBTree(const SBTree& tree) {
	if (tree.root == nullptr)
	{
		root = nullptr;
	}
	else
	{
		root = new Node(tree.root->key);
		Copy(tree.root->left, root, 0);
		Copy(tree.root->right, root, 1);
	}
}
void SBTree::TreeTravelsalLRC(Node* p) {
	if (p == nullptr) return;
	if(p->left) TreeTravelsalLRC(p->left);
	if(p->right) TreeTravelsalLRC(p->right);
	std::cout << p->key << " ";
}

void SBTree::TreeTravelsalLCR(Node* p) {
	if (p)
	{
		TreeTravelsalLCR(p->left);
		std::cout << p->key << " ";
		TreeTravelsalLCR(p->right);
	}
}

void SBTree::TreeTravelsalRLC(Node* p) {
	if (p) {
	if(p->right) TreeTravelsalRLC(p->right);
	if(p->left) TreeTravelsalRLC(p->left);
	std::cout << p->key << " ";
	}
}

void SBTree::Del() {
	if (root->left == NULL && root->right == NULL) {
		delete root;
		root = NULL;
		return;
	}
	// у root - нет правой ветки
	if (root->left != NULL && root->right == NULL) {
		Node* p = root->left;
		p->parent = nullptr;
		delete root;
		root = p;
		return;
	}
	// у p - нет левой ветки
	if (root->left == NULL && root->right != NULL) {
		Node* p = root->right;
		p->parent = nullptr;
		delete root;
		root = p;
		return;
	}
	Node* t = root->left;
	if (t->right == NULL) {
		t->parent = nullptr;
		t->right = root->right;
		root->right->parent = t;
	}
	else {
		while (t->right != NULL) 
			t = t->right;
		t->parent->right = t->left;
		if (t->left != NULL)
			t->left->parent = t->parent;
		t->right = root->right;
		root->right->parent = t;
		t->left = root->left;
		root->left->parent = t;
		t->parent = nullptr;
	}
	delete root;
	root = t;
	return;
}
int SBTree::FindHeight(Node* p) {
	if (p)
	{
		int l = FindHeight(p->left);
		int r = FindHeight(p->right);
		if (l > r)
		{
			return l + 1;
		}
		else
		{
			return r + 1;
		}
	}
	return 0;
}
SBTree& SBTree::operator=(const SBTree& t) {
	if (this != &t)
	{
		Clear();
		root = new Node(t.root->key);
		Copy(t.root->left, root, 0);
		Copy(t.root->right, root, 1);
	}
	return *this;
}
Node* SBTree::FindMin(Node* p) {
	if (p == nullptr) return nullptr;
	Node* min = p;
	if(p->left)
		return FindMin(p->left);
	return min;
}
Node* SBTree::FindMax(Node* p) {
	if (p == nullptr) return nullptr;
	Node* max = p;
	if(p->right)
		return FindMax(p->right);
	return max;
}
Node* SBTree::FindKey(int k, Node* p) {
	if (p == nullptr) return nullptr;

	if (p->key == k) return p;

	if(FindKey(k, p->left)) 
		return FindKey(k, p->left);
	else 
		return FindKey(k, p->right);
}
