#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class BST {
	public: struct TreeNode {
		int key; //ключ узла дерева
		string val = ""; //значение узла2
		TreeNode *left, *right; //левый и правый подузел
	};
		
	public: int treeSize(TreeNode *Tree) {
		if (Tree->left == NULL && Tree->right == NULL)
			return 1;

		int left, right;

		if (Tree->left != NULL)
			left = treeSize(Tree->left);
		else
			left = 0;
		if (Tree->right != NULL)
			right = treeSize(Tree->right); 
		else 
			right = 0;
			
		return left+right+1;
	}

	public: void showAll(TreeNode *&Tree) { //показывает все узлы
		if (Tree != NULL) { //если дерево не пустое
			showAll(Tree->left); //рекурсивно вызывает левое поддерево
			cout << "Номер узла: " << Tree->key << ". Значение: " << Tree->val; //получает значение текущего узла
			if (Tree->left != NULL) //если левое поддерево не пустое
				cout << ". Левый узел: " << Tree->left->key; //то выводит номер левого подузла
			if (Tree->right != NULL) //аналогично для правого
				cout << ". Правый узел: " << Tree->right->key;
			cout << endl;
			showAll(Tree->right); //рекурсивно вызывает правое поддерево
		}
	}
		
	public: void showNode(int key, TreeNode *&Tree) { //показывает узел
		if (Tree != NULL) { //если дерево не пустое
			showNode(key, Tree->left); //рекурсивно вызывает левое поддерево
			if (key == Tree->key) {
				cout << "Номер узла: " << Tree->key << ". Значение: " << Tree->val; //получает значение текущего узла
				if (Tree->left != NULL) //если левое поддерево не пустое
					cout << ". Левый узел: " << Tree->left->key; //то выводит номер левого подузла
				if (Tree->right != NULL) //аналогично для правого
					cout << ". Правый узел: " << Tree->right->key;
				cout << endl;
			}
			showNode(key, Tree->right); //рекурсивно вызывает правое поддерево
		}
	}

	public: void addTreeNode(int key, string val, TreeNode *&Tree) { //добавление нового узла
		if (NULL == Tree) { //если дерево пустое
			Tree = new TreeNode; //выделяется память
			Tree->key = key; //добавляется ключ
			Tree->val = val; //значение
			Tree->left = Tree->right = NULL; //левый и правый узел
		}

		if (key < Tree->key) { //если указанное значение ключа меньше чем значение узла
			if (Tree->left != NULL) { //если левый узел не пустой
				addTreeNode(key, val, Tree->left); //рекурсивно вызывается добавление левого узла
			} else { //иначе
				Tree->left = new TreeNode; //выделяется память
				Tree->left->left = Tree->left->right = NULL; //добавляется левый и правый подузел
				Tree->left->key = key; //ключ
				Tree->left->val = val; //и значение узла
			}
		}

		if (key > Tree->key) { //аналагично для правого подузла
			if (Tree->right != NULL) {
				addTreeNode(key, val, Tree->right);
			} else {
				Tree->right = new TreeNode;
				Tree->right->left = Tree->right->right = NULL;
				Tree->right->key = key;
				Tree->right->val = val;
			}
		}
				
		if (key == Tree->key) {
			Tree->val = val;
		}
	}

	public: void clear(TreeNode *&Tree) { //очистка дерева
		if (Tree != NULL) { //если дерево не пустое
			clear(Tree->left); //рекурсивный вызывает левое поддерево
			clear(Tree->right); //...правое...
			delete Tree; //очищает память
			Tree = NULL; //очищает дерево
		}
	}
	
	public: TreeNode* minNode(TreeNode *&Tree) {
		if (Tree->left == NULL)
			return Tree;
		return minNode(Tree->left);
	}
	
	public: TreeNode* deleteNode(TreeNode *&Tree, int key) { //показывает узел
		if (Tree != NULL) { //если дерево не пустое
			if (key < Tree->key) {
				Tree->left = deleteNode(Tree->left, key);
			} else if (key > Tree-> key) {
				Tree->right = deleteNode(Tree->right, key);
			} else if ((Tree->left != NULL) && (Tree->right != NULL)) {
				Tree->key = minNode(Tree->right)->key;
				Tree->right = deleteNode(Tree->right, Tree->key);
			} else {
				if (Tree->left != NULL)
					Tree = Tree->left;
				else
					Tree = Tree->right;
			}
		}
		return Tree;
	}
		
	public: void treeMenu(TreeNode *&Tree) {
		while(true) {
			int command, key;
			string val;
			cout << "Команды:\n0 - выйти из программы,\n1 - показать все узлы дерева,\n2 - очистить дерево,\n3 - добавить узел,\n4 - показать определенный узел;\n5 - размер дерева;\n6 - удалить узел;\n7 - перейти к итератеру.\n:> ";
			cin >> command;
			switch (command) {
				case 0:
					exit(1);
					break;
			
				case 1:
					showAll(Tree);
					break;

				case 2:
					clear(Tree);
					break;
					
				case 3:
					cout << "Введите значение ключа: ";
					cin >> key;
					cout << "Введите значение узла: ";
					cin >> val;
					addTreeNode(key, val, Tree);
					cout << "Узел " << key << " успешно добавлен.\n";
					break;  
					
				case 4:
					cout << "Введите значение ключа: ";
					cin >> key;
					showNode(key, Tree);
					break;
					
				case 5:
					cout << "Разамер дерева: " << treeSize(Tree) << "\n";
					break;
					
				case 6:
					cout << "Введите значение ключа: ";
					cin >> key;
					Tree = deleteNode(Tree, key);
					break;
										
				case 7:
					iteratorMenu(Tree);
					break;
			}
		}
	}
	
	public: void iteratorMenu(TreeNode *&Tree) {
		string command, help, currentVal = Tree->val;
		int currentKey = Tree->key;
		TreeNode* currentLeft = Tree->left;
		TreeNode* currentRight = Tree->right;
		
		help = "root - установка на корень.\ninfo - информация об узле.\nmenu - вернуться в главное меню.\nhelp - показать эту справку.\n";
		cout << help;
		
		while (true) {
			cout << "<" << currentKey << ">: ";
			cin >> command;
			
			if (command == "root") {
				currentKey = Tree->key;
				currentVal = Tree->val;
				currentLeft = Tree->left;
				currentRight = Tree->right;
			}
			
			if (command == "info") {
				showNode(currentKey, Tree);
			}
			
			if (command == "help")
				cout << help;
					
			if (command == "menu")
				treeMenu(Tree);
		}
	}
};

int main() {
	BST binaryTree;
	BST::TreeNode *BSTree = NULL; //выделение памяти для дерева
	srand(time(0)); //рандом, зависящий от времени

	for (int i = 0; i < 10; i++) { //цикл от 0 до 100
		binaryTree.addTreeNode(1 + rand() % 100, "val_" + to_string(i), BSTree); //добавление узла в дерево
	}

	binaryTree.treeMenu(BSTree);
		
	return 0;
}