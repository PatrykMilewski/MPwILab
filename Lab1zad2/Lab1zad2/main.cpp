//
// Wariacje n elementowe w zbiorze k elementowym z powtórzeniami
//

#include <iostream>

using namespace std;

class Node {
public:
	Node(Node *parent, int childrenAmount, int value) {
		this->value = value;
		this->parent = parent;
		this->childrenAmount = childrenAmount;
		if (childrenAmount > 0)
			this->children = new Node *[childrenAmount];
		else
			this->children = nullptr;
	}

	~Node() {
		for (int i = 0; i < childrenAmount; i++) {
			if (children[i] != nullptr)
				children[i]->~Node();
		}
		delete[] children;
	}
	Node * parent;
	Node ** children;
	int childrenAmount;
	int value;
};

Node * createTree(int *tab, int tabSize, int value, Node * parent, int depth) {
	Node *thisNode = new Node(parent, tabSize, value);

	for (int i = 0; i < tabSize; i++) {
		if (depth - 1 != 0)
			thisNode->children[i] = createTree(tab, tabSize, tab[i], thisNode, depth - 1);
	}
	return thisNode;
}

void printTree(Node * node, int depth) {
	if (node->children == nullptr || depth == 0) {
		while (node->parent != nullptr) {
			cout << node->value << " ";
			node = node->parent;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < node->childrenAmount; i++) {
		if (node->children[i] != nullptr && depth != 0)
			printTree(node->children[i], depth - 1);
	}
}

int main() {
	const int k = 2;
	const int n = 2;
	int tab[k];

	for (int i = 0; i < k; i++)
		tab[i] = i;

	Node * root = createTree(tab, k, -1, nullptr, n + 1);

	printTree(root, n);
	return 0;
}