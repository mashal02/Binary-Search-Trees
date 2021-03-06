#include <iostream>
using namespace std;

class bstnode{
public:
	int data;
	bstnode* LeftChild;
	bstnode* RightChild;
	

	bstnode()
	{ 
		LeftChild = NULL;
		RightChild = NULL;
	}
	
};
class bst
{public:
	bstnode* root;
	bstnode* loc;
	bstnode* preloc;

	bst()
	{
		root = NULL;
		loc = NULL;
		preloc = NULL;
	}
	bool IsEmpty(); //returns true if it's empty
	void search(int value);
	void InsertWithoutDuplication(int value);
	
};
bool  bst::IsEmpty()
{
	return (root== NULL);
}

void bst::search(int value) {
	if (!IsEmpty())
	{
		loc = root;
		preloc = NULL;
		while (loc != NULL && loc->data != value)
		{
			if (loc->data > value)
			{
				preloc = loc;
				loc = loc->LeftChild;
			}
			else
			{
				preloc = loc;
				loc = loc->RightChild;
			}
		}
	}
}

void bst::InsertWithoutDuplication(int value)
{
	search(value);
	if (loc == NULL)
	{
		bstnode* newnode = new bstnode();
		newnode->data = value;
		if (preloc == NULL)
		{
			root = newnode;
		}
		else if (value > preloc->data)
		{
			preloc->RightChild = newnode;
		}
		else if (value < preloc->data)
		{
			preloc->LeftChild = newnode;
		}
		
	}
}

void preorder(bstnode* root)
{
	if (root != NULL)
	{
		cout << root->data<< "  ";
		preorder(root->LeftChild);
		preorder(root->RightChild);
	}
}

void inorder(bstnode* root)
{
	if (root != NULL)
	{
		inorder(root->LeftChild);
		cout << root->data << "  ";
		inorder(root->RightChild);
	}
}

void postorder(bstnode* root)
{
	if (root != NULL)
	{
		postorder(root->LeftChild);
		cout << root->data << "  ";
		postorder(root->RightChild);
	}
}
void printsmallest(bstnode* root)
{
	if(root!=NULL)
	{
		if (root->LeftChild != NULL)
		{
			printsmallest(root->LeftChild);
		}
		else cout << root->data;
	}

}
void printlargest(bstnode* root)
{
	if (root != NULL)
	{
		if (root->RightChild != NULL)
		{
			printlargest(root->RightChild);
		}
		else cout << root->data;
	}

}

void printleafnodes(bstnode* loc)
{
	if (loc->LeftChild == NULL && loc->RightChild == NULL)
	{
		cout << loc->data << " ";
	}
	else
	{
		if (loc->LeftChild != NULL)
			printleafnodes(loc->LeftChild);
		if (loc->RightChild != NULL)
			printleafnodes(loc->RightChild);
	}
}

int countleaves(bstnode* root)
{
	static int count = 0;
	if (root->LeftChild == NULL && root->RightChild == NULL)
	{
		count++;
		return count;
	}
	else
	{
		if (root->LeftChild != NULL)
		countleaves(root->LeftChild);
		if (root->RightChild != NULL)
			countleaves(root->RightChild);
	}

}
//Task 9
int countinternal(bstnode* root)
{
	//base case
	if (root==NULL || (root->LeftChild == NULL && root->RightChild == NULL))
	{
		return 0;
	}
	else
	{
		return 1 + countinternal(root->LeftChild) + countinternal(root->RightChild);
	}
}
//Task 10
int height(bstnode* root)
{
	if (root == NULL)
		return -1;
	else
		return  1 + max(height(root->LeftChild), height(root->RightChild));
}

//task11
int DEPTH(bstnode* root, int depth)
{
	if (root == NULL)
		return (depth - 1);

	//find the depth of each subtree

	int a = DEPTH(root->LeftChild, depth + 1);
	int b = DEPTH(root->RightChild, depth + 1);

	// Choose the larger one and add the root to it.
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	bst mytree;
	//menu
	while (1) {
		cout << "Select an option: \n1-Insert a node in the tree\t2-Print the tree inOrder\n3-Print tree in preorder\t4-Print tree in post order\n";
		cout << "5-Print the node with having largest value\n6-Print the node having smallest value\n7-Count Leaves of the tree\t8-Count internal nodes of tree\n";
		cout << "9-Print height of tree\t10-Print depth of tree" << endl;
		int select;

		{
			cin >> select;
			switch (select)
			{
			case 1: { cout << "Enter values in tree. Press -1 to quit.\n";
				int val = 0;
				while (val != -1)
				{
					cin >> val;
					mytree.InsertWithoutDuplication(val);
				}
				break; }
			case 2: {cout << "\nTree in order:\n";
				inorder(mytree.root);
				break; }
			case 3: { cout << "\nTree in preorder:\n";
				preorder(mytree.root);
				break; }
			case 4: { cout << "\nTree in postorder:\n";
				postorder(mytree.root); break; }
			case 5: { cout << "\nLargest value in tree:\t";
				printlargest(mytree.root); break; }
			case 6: { cout << "\nSmallest value in tree:\t";
				printsmallest(mytree.root); break; }

			case 7: { cout << "\nTotal Leaves in tree: "<< countleaves(mytree.root);
				break; }
			case 8: { cout << "\nTotal internal nodes in tree: "<< countinternal(mytree.root);
				 break; }
			case 9: { cout << "\nHeight of tree:\t"<< height(mytree.root);
				break; }
			}
		}
	}
}
