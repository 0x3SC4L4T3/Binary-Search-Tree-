#include "BinarySearchTreeInterface.h"
#include "Pokemon.h"

template <typename ItemType, typename KeyType>
class BNode {
public:
	ItemType value;
	BNode* left;
	BNode* right;
	
	BNode(ItemType _value) {
		this->value = _value;
		this->left = NULL;
		this->right = NULL;
	}

};
template <typename ItemType, typename KeyType>
class BinarySearchTree : public BinarySearchTreeInterface<ItemType, KeyType> {
private:
	BNode<ItemType, KeyType>* root;
	BNode<ItemType, KeyType>* addWrapper(BNode<ItemType, KeyType> *root, ItemType entry){
		if (root == NULL) {
			root = new BNode<ItemType, KeyType>(entry);;
			return root;
		}
		/* Otherwise, recur down the tree */
		if (entry < root->value)
			root->left = addWrapper(root->left, entry);
		else if (entry > root->value)
			root->right = addWrapper(root->right, entry);
		return root;
	}

	ItemType maxValue()
	{
		BNode<ItemType, KeyType>* current = this->root;
		while (current->right) {
			current = current->right;
		}
		return current->value;
	}

	BNode<ItemType, KeyType>* minValueNode(BNode<ItemType, KeyType>* treePtr)
	{
		BNode<ItemType, KeyType>* current = treePtr;

		/* loop down to find the leftmost leaf */
		while (current && current->left != NULL) {
			current = current->left;
		}
		return current;
	}


	BNode<ItemType, KeyType>* searchWrapper(BNode<ItemType, KeyType>* root, KeyType entry) const{
	
		if (root == NULL || root->value == entry)
			return root;

		// Key is greater than root's key
		if (root->value < entry)
			return searchWrapper(root->right, entry);

		// Key is smaller than root's key
		return searchWrapper(root->left, entry);
	}

	void deleteTree(BNode<ItemType,KeyType>* node)
	{
		if (node == NULL) return;

		/* first delete both subtrees */
		deleteTree(node->left);
		deleteTree(node->right);

		/* then delete the node */
		cout << "\nDeleting node: " << node->value;
		delete node;
	}

	void preorder(void visit(ItemType), BNode<ItemType, KeyType> *treePtr) const
	{
		if (treePtr != nullptr)
		{
			ItemType value = treePtr->value;
			visit(value);
			preorder(visit, treePtr->left);
			preorder(visit, treePtr->right);
		}
	}  

	void inorder(void visit(ItemType), BNode<ItemType, KeyType>* treePtr) const
	{
		if (treePtr != nullptr)
		{
			inorder(visit, treePtr->left);
			ItemType value = treePtr->value;
			visit(value);
			inorder(visit, treePtr->right);
		}
	}



	void postorder(void visit(ItemType), BNode<ItemType, KeyType>* treePtr) const
	{
		if (treePtr != nullptr)
		{
			postorder(visit, treePtr->left);
			postorder(visit, treePtr->right);
			ItemType value = treePtr->value;
			visit(value);

		}
	}


	BNode<ItemType, KeyType>* removeNode(BNode<ItemType, KeyType>* _root, KeyType key)
	{
		if (_root == NULL) return _root;

		// If the key to be deleted is smaller than the root's key,
		// then it lies in left subtree
		if (_root->value > key)
			_root->left = removeNode(_root->left, key);

		// If the key to be deleted is greater than the root's key,
		// then it lies in right subtree
		else if (_root->value < key)
			_root->right = removeNode(_root->right, key);

		// if key is same as root's key, then This is the node
		// to be deleted
		else
		{
			// node with only one child or no child
			if (_root->left == NULL)
			{
				BNode<ItemType, KeyType>* temp = _root->right;
				delete _root;
				return temp;
			}
			else if (root->right == NULL)
			{
				BNode<ItemType, KeyType>* temp = _root->left;
				delete _root;
				return temp;
			}

			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			BNode<ItemType, KeyType>* temp = minValueNode(_root->right);

			// Copy the inorder successor's content to this node
			_root->value = temp->value;

			// Delete the inorder successor
			//_root->right = removeNode(_root->right, temp->value);
		}
		return _root;
	}

	BNode<ItemType, KeyType> *clone(BNode<ItemType, KeyType>* ptr) const
	{
		if (ptr)
		{
			BNode<ItemType, KeyType>* newnode = new BNode<ItemType, KeyType>(ptr->value);
			newnode->left = clone(ptr->left);
			newnode->right = clone(ptr->right);
			return newnode;
		}
		return NULL;
	}

public:
	BinarySearchTree() {
		root = NULL;
	}

	BinarySearchTree(const BinarySearchTree& copy) {
		root = clone(copy.root);
	}

	void add(ItemType entry) {
		root = this->addWrapper(root, entry);
	}

	ItemType search(KeyType key) const {
		BNode<ItemType,KeyType> *getSearch = searchWrapper(root, key);
		if (getSearch == NULL) {
			std::cout << "Node not Found with the key " << key << std::endl;
			return Pokemon<int>(-1, "-1", "-1");
		}
		
		std::cout << "Node Found with the key " << key << std::endl;
		return getSearch->value;
	}

	void clear() {
		cout << "\n-----Deleting the Tree-----\n";
		deleteTree(root);
		root = NULL;
		cout << "\n-----Tree Deleted-----\n";
	}

	~BinarySearchTree() {
		cout << "\n-----Destructor Called-----\n";
		deleteTree(root);
		root = NULL;
		cout << "\n-----Tree Deleted-----\n";
	}

	void visitPreOrder(void visit(ItemType item)) const {
		cout << "\n-----Pre Order Traversal-----\n";
		preorder(visit, root);
		cout << "-----Pre Order Traversal End-----\n";
	}

	void visitInOrder(void visit(ItemType item)) const {
		cout << "\n-----In Order Traversal-----\n";
		inorder(visit, root);
		cout << "-----In Order Traversal End-----\n";
	}

	void visitPostOrder(void visit(ItemType item)) const {
		cout << "\n-----Post Order Traversal-----\n";
		postorder(visit, root);
		cout << "-----Post Order Traversal End-----\n";
	}

	void remove(KeyType key) {
		BNode<ItemType, KeyType>* getDeleted = removeNode(root, key);
		if (getDeleted == NULL) {
			std::cout << "Node not Found with the key " << key << std::endl;
		}
		std::cout << "Node Deleted with the key " << key << std::endl;
	}

};

template <typename ItemType>
void display(ItemType anItem)
{
	std::cout << anItem << "\n";
}

