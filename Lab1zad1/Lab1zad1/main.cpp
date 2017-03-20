//
// Wariacje n elementowe w zbiorze k elementowym bez powtórzeñ
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

Node * createTree(int *tab, int tabSize, int value, Node * parent) {
	Node *thisNode = new Node(parent, tabSize, value);

	for (int i = 0; i < tabSize; i++) {
		int *childTab = new int[tabSize - 1];
		for (int j = 0; j < i; j++)
			childTab[j] = tab[j];

		for (int j = i + 1; j < tabSize; j++)
			childTab[j - 1] = tab[j];

		thisNode->children[i] = createTree(childTab, tabSize - 1, tab[i], thisNode);
		delete[] childTab;
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
	const int k = 4;
	const int n = 2;
	int tab[k];

	for (int i = 0; i < k; i++)
		tab[i] = i;

	Node * root = createTree(tab, k, -1, nullptr);

	printTree(root, n);
	return 0;
}