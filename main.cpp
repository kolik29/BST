#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class TreeNode {
	public: int key; //ключ узла дерева
	public: TreeNode *left, *right; //левый, правый и родительский подузлы
	public: string val; //значение элемента
	public: TreeNode* ins();
	static TreeNode* tree;
	
	public: TreeNode* search(int k, TreeNode *&node = tree) { //поиск элемента
		if ((node == NULL) || (k == node->key))
			return node;
		
		if (k < node->key)
			return search(k, node->left);
		else
			return search(k, node->right);
	}
	
	public: TreeNode* ins(int k, string val, TreeNode *&node = tree) { //вставка элемента
		if (node == NULL) {
			node->key = k;
			node->val = val;
			return node;
		} else if (k < node->key)
			node->left = ins(k, val, node->left);
		else if (k > node->key)
			node->right = ins(k, val, node->right);
		return NULL;
	}
	
	public: TreeNode* del(int k, TreeNode *&node = tree) { //удаление элемента
		if (node == NULL)
			return node;
		
		if (k < node->key) {
			node->left = del(k, node->left);
		} else if (k > node->key) {
			node->right = del(k, node->right);
		} else if ((node->left != NULL) && (node->right != NULL)) {
			node->key = begin(node->right)->key;
			node->right = del(node->key, node->right);
		} else {
			if (node->left != NULL)
				node = node->left;
			else
				node = node->right;
		}
		return node;
	}
	
	public: TreeNode* begin(TreeNode *&node = tree) { //наименьший элемент
		if (node->left == NULL)
			return node;
		
		return begin(node->right);
	}
	
	public: TreeNode* end(TreeNode *&node = tree) { //наибольший элемент
		if (node->right == NULL)
			return node;
		
		return end(node->right);
	}
	
	public: void traversal(TreeNode *&node = tree) { //обход дерева L->R->t
		if (node != NULL) {
			traversal(node->left);
			traversal(node->right);
			cout << node->key << "\t";
		}
	}
	
	public: int count(TreeNode *&node = tree) { //количество узлов в дереве
		if ((node->left == NULL) && (node->right == NULL))
			return 1;
		
		int left, right;
		
		if (node->left != NULL)
			left = count(node->left);
		else
			left = 0;
		
		if (node->right != NULL)
			right = count(node->right);
		else
			right = 0;
		
		return right + left + 1;
	}
	
	public: void clear() { //очистка дерева
		delete tree;
		tree = NULL;
	}
	
	public: bool empty() { //проверка на пустоту
		if (tree == NULL)
			return true;
		else
			return false;
	}	
};

int main() {
    TreeNode* treeNodes;
	
	for (int i = 0; i < 100; i++) {
		treeNodes->ins(i, "sdfsd");
	}
}