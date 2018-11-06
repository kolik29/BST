#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class BST {
	public: struct TreeNode {
		int key; //ключ узла дерева
		TreeNode *left, *right; //левый, правый и родительский подузлы
	};
	
	public: TreeNode* search(TreeNode *&node, int k) { //поиск элемента
		if ((node == NULL) || (k == node->key))
			return node;
		
		if (k < node->key)
			return search(node->left, k);
		else
			return search(node->right, k);
	}
	
	public: TreeNode* ins(TreeNode *&node, int k) { //вставка элемента
		if (node == NULL) {
			node->key = k;
			return node;
		} else if (k < node->key)
			node->left = ins(node->left, k);
		else if (k > node->key)
			node->right = ins(node->right, k);
	}
	
	public: TreeNode* del(TreeNode *&node, int k) { //удаление элемента
		if (node == NULL)
			return node;
		
		if (k < node->key) {
			node->left = del(node->left, k);
		} else if (k > node->key) {
			node->right = del(node->right, k);
		} else if ((node->left != NULL) && (node->right != NULL)) {
			node->key = min(node->right)->key;
			node->right = del(node->right, node->key);
		} else {
			if (node->left != NULL)
				node = node->left;
			else
				node = node->right;
		}
		return node;
	}
	
	public: TreeNode* min(TreeNode *&node) { //наименьший элемент
		if (node->left == NULL)
			return node;
		
		return min(node->right);
	}
	
	public: TreeNode* max(TreeNode *&node) { //наибольший элемент
		if (node->right == NULL)
			return node;
		
		return max(node->right);
	}
	
	public: void traversal(TreeNode *&node) { //обход дерева L->R->t
		if (node != NULL) {
			traversal(node->left);
			traversal(node->right);
			cout << node->key << "\t";
		}
	}
	
	public: int count(TreeNode *&node) { //количество узлов в дереве
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
	
	public: void clear(TreeNode *&node) { //очистка дерева
		if (node != NULL) {
			clear(node->left);
			clear(node->right);
			delete node;
			node = NULL;
		}
	}
	
	public: bool empty(TreeNode *&node) { //проверка на пустоту
		if (node == NULL)
			return true;
		else
			return false;
	}
};

int main() {
    
}