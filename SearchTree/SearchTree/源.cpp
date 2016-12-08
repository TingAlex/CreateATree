#include<iostream>
using namespace std;
template<class T>
class SearchTree;
template<class T>
class SearchTreeNode {
	friend class SearchTree<T>;
private:
	T value;
	SearchTreeNode<T>* left;
	SearchTreeNode<T>* right;
public:
	SearchTreeNode() {
		value = 0;
		left = right = NULL;
	}
	SearchTreeNode(T value) {
		this->value = value;
		right=left = NULL;
	}
	void setLeft(SearchTreeNode<T>* node) {
		left = node;
	}
	void setRight(SearchTreeNode<T>* node) {
		right = node;
	}
	T getValue() {
		return value;
	}
};
template<class T>
class SearchTree {
private:
	SearchTreeNode<T>* root;
public:
	SearchTree(SearchTreeNode<T>* root) {
		this->root = root;
	}
	SearchTreeNode<T>* search(SearchTreeNode<T>* root, T value) {
		if (root == NULL)
			return root;
		else {
			SearchTreeNode<T>* temp=root;
			while (temp!=NULL&&temp->value != value) {
				if (temp->value > value)
					temp = temp->left;
				else
					temp = temp->right;
			}
				return temp;
		}
	}
	void insert(SearchTreeNode<T>* root, T value) {
		if (root == NULL)
			root->value = value;
		else {
			SearchTreeNode<T>* temp = root;
			SearchTreeNode<T>* pre=temp;
			while (temp != NULL&&temp->value != value) {
				pre = temp;
				if (temp->value > value)
					temp = temp->left;
				else
					temp = temp->right;
			}
			if (temp == NULL)
			{
				temp = new SearchTreeNode<T>(value);
				if (pre->value > value)
					pre->left = temp;
				else
					pre->right = temp;
				cout << "Successful Added." << endl;
				return;
			}
			if (temp->value == value)
				cout << "Aleardy here." << endl;
		}
	}
	void dele(SearchTreeNode<T>* node) {
		SearchTreeNode<T>* temp = this->root;
		if (temp == NULL)
		{
			cout << "Make no sense." << endl;
			return;
		}
		SearchTreeNode<T>* pre = temp;
		while (temp != NULL&&temp!= node) {
			pre = temp;
			if (temp->value > node->value)
				temp = temp->left;
			else
				temp = temp->right;
		}
			if (temp == NULL)
			{
				cout << "Can't find it." << endl;
				return;
			}

				if (!node->left)
				{
					pre->right=node->right;
					delete temp;
				}
				else if (!temp->right)
				{
					pre->left = node->left;
					delete temp;
				}
				else {
					temp = node->left;
					while (temp->right != NULL)
						temp = temp->right;
					temp->right = node->right;
					pre->left = node->left;
					delete node;
				}
				//delete temp;
				
	}
	void FirstOrder(SearchTreeNode<T>* root) {
		if (root == NULL)
			return;
		Visit(root);
		FirstOrder(root->left);
		FirstOrder(root->right);
	}
	void Visit(SearchTreeNode<T>* root) {
		cout << root->value<<' ';
	}
};
int main() {
	SearchTreeNode<int> *A=new SearchTreeNode<int>(4);
	SearchTree<int> sea(A);
	cout << "Insert?" << endl;
	int i;
	cin >> i;
	while (i!=-1) {
		sea.insert(A,i);
		cout << "Insert?" << endl;
		cin >> i;
	}
	cout << "First Order show" << endl;
	sea.FirstOrder(A);
	cout << endl;
	cout << "what do you want to find?" << endl;
	cin >> i;
	while (i != -1) {
		if (sea.search(A, i) == NULL)
			cout << "can't find " << i << endl;
		else
			cout << "find it" << endl;
		cout << "what do you want to find?" << endl;
		cin >> i;
	}
	cout << "what do you want to delete?" << endl;
	cin >> i;
	while (i != -1) {
			sea.dele(sea.search(A,i));
			cout << "what do you want to delete?" << endl;
			cin >> i;
		}
	cout << "First Order show" << endl;
	sea.FirstOrder(A);
	cout << endl;
	}


