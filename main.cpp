#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class BST {
	public: struct TreeNode {
		int key; //ключ узла дерева
		TreeNode *left, *right, *parent; //левый, правый и родительский подузлы
	};
	
	public: TreeNode* search(TreeNode *&node, int k) { //поиск
		if ((node == NULL) || (k == node->key)) {
			return node;
		}
		
		if (k < node->key) {
			return search(node->left, k);
		} else {
			return search(node->right, k);
		}
	}
	
	public: TreeNode* ins(TreeNode *&node, int k) { //вставка
		if (node == NULL) {
			node->key = k;
			return node;
		} else if (k < node->key) {
			node->left = ins(node->left, k);
		} else if (k > node->key) {
			node->right = ins(node->right, k);
		}
	}
	
	public: TreeNode* del(TreeNode *&node, int k) { //удаление
		if (node == NULL) {
			return node;
		}
		
		if (k < node->key) {
			node->left = del(node->left, k);
		} else if (k > node->key) {
			node->right = del(node->right, k);
		} else if ((node->left != NULL) && (node->right != NULL)) {
			node->key = min(node->right)->key;
			node->right = del(node->right, node->key);
		} else {
			if (node->left != NULL) {
				node = node->left;
			} else {
				node = node->right;
			}
		}
		return node;
	}
	
	public: TreeNode* min(TreeNode *&node) { //наименьшее
		if (node->left == NULL) {
			return node;
		}
		
		return min(node->right);
	}
	
	public: TreeNode* max(TreeNode *&node) { //наибольшее
		if (node->right == NULL) {
			return node;
		}
		
		return max(node->right);
	}
	
	public: int traversal(TreeNode *&node) {
		if (node != NULL) {
			traversal(node->left);
			traversal(node->right);
			cout << node->key << " ";
		}
		
		return NULL;
	}
	
	public: int count(TreeNode *&node) {
		
	}
};

int main() {
    
}