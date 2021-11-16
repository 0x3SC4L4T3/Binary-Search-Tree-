#include "BinarySearchTree.cpp"

static int copied = 0;

void readFile(BinarySearchTree<Pokemon<int>, int> &BST) {
	ifstream infile;
	string tempUS, tempJP;
	int tempID;
	infile.open("pokemon.txt");

	if (!infile.is_open()) {
		cerr << "Unable to open file 'pokemon.txt'\n";
	}
	else {
		while (infile >> tempUS >> tempID >> tempJP)
		{
			Pokemon<int> P(tempID, tempUS, tempJP);
			BST.add(P);
		}
	}
	cout << "File read to Binary Search Tree\n\n";
}


void menu(BinarySearchTree<Pokemon<int>, int>& BST) {
	int ID;
	int input = -1;
	while (true) {
		cout << "1. Insert a Pokemon\n2. Search a Pokemon\n3. Remove a Pokemon\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Make a copy\n8. Exit\n";
		cout << "Enter your option: ";
		cin >> input;
		if (input == 8) {
			break;
		}
		else if (input == 1) {
			Pokemon<int>P;
			cin >> P;
			BST.add(P);
		}
		else if (input == 2) {
			cout << "Enter ID: ";
			cin >> ID;
			BST.search(ID);
		}
		else if (input == 3) {
			cout << "Enter ID: ";
			cin >> ID;
			BST.remove(ID);
		}
		else if (input == 4) {
			BST.visitInOrder(display);
		}
		else if (input == 5) {
			BST.visitPreOrder(display);
		}
		else if (input == 6) {
			BST.visitPostOrder(display);
		}
		else if (input == 7) {
			if (copied == 1) {
				cout << "Sorry, only 1 copy is allowed\n";
			}
			else {
				BinarySearchTree<Pokemon<int>, int> BSTCOPY(BST);
				BST.visitInOrder(display);
				copied = 1;
				cout << "Copied and printed successfully\n\n";
			}
		}
	}

}

int main() {

	BinarySearchTree<Pokemon<int>, int> BST;
	readFile(BST);
	menu(BST);
	return 0;
}