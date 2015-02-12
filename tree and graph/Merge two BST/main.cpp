// Google interview questions
// reference: http://www.fgdsb.com/2015/01/18/merge-BST/

/* You are given two balanced binary search trees. Write a function that merges the two given balanced BSTs
   into a balanced binary search tree. Your merge function should take O(M+N) time and O(1) space.
   
   Solution: divide into 3 sub-problems
             (1) BST to sorted doubly linked list in place
             (2) Merge two double linked list in place
             (3) Sorted doubly linked list to BST in place
*/

#include<iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* flattenBST(TreeNode* root); // the return node will be the leftmost node of original tree
TreeNode* merge(TreeNode* root1, TreeNode* root2); // merge two flattened TreeNode
TreeNode* listToBST(TreeNode* head);
TreeNode* listToBST(TreeNode* begin, TreeNode* end);
TreeNode* middle(TreeNode* begin, TreeNode* end); // get the middle node
TreeNode* mergeBST(TreeNode* root1, TreeNode* root2); // merge two BST
void inorderTraversal(TreeNode* root);

int main()
{
	TreeNode* root1=new TreeNode(9);
	root1->left=new TreeNode(5);
	root1->left->left=new TreeNode(2);
	root1->left->right=new TreeNode(7);
	root1->right=new TreeNode(13);
	root1->right->left=new TreeNode(11);
	root1->right->right=new TreeNode(17);

        TreeNode* root2=new TreeNode(8);
        root2->left=new TreeNode(4);
        root2->left->left=new TreeNode(3);
        root2->left->right=new TreeNode(6);
        root2->right=new TreeNode(12);
        root2->right->left=new TreeNode(10);
        root2->right->right=new TreeNode(14);

	TreeNode* root=mergeBST(root1, root2);
	inorderTraversal(root);
	return 0;	
}

void inorderTraversal(TreeNode* root)
{
	if(root==nullptr)
		return;
	inorderTraversal(root->left);
	cout<<root->val<<" ";
	inorderTraversal(root->right);
}

TreeNode* mergeBST(TreeNode* root1, TreeNode* root2)
{
	if(!root1)	return root2;
	if(!root2)	return root1;

        TreeNode* root11=flattenBST(root1);
        TreeNode* root22=flattenBST(root2);
	return listToBST(merge(root11, root22));
}

TreeNode* middle(TreeNode* begin, TreeNode* end)
{
	TreeNode* fast=begin;
	TreeNode* slow=begin;
	while(fast!=end && fast->right!=end)
	{
		fast=fast->right->right;
		slow=slow->right;
	}	
	return slow;
}

TreeNode* listToBST(TreeNode* begin, TreeNode* end)
{
	if(begin==end) // nothing to adjust
	{
		begin->left=nullptr;
		begin->right=nullptr;
		return begin;
	}
	if(begin->right==end)
	{
		begin->right=nullptr;
		begin->left=nullptr;
		end->right=nullptr;
		return end;
	}

        TreeNode* mid=middle(begin, end);
	mid->left=listToBST(begin, mid->left);
	mid->right=listToBST(mid->right, end);
	return mid;
}

TreeNode* listToBST(TreeNode* head)
{
	if(!head)	return head;
	TreeNode* end=head;
	while(end && end->right)
		end=end->right;
	listToBST(head, end); 
}

TreeNode* merge(TreeNode* root1, TreeNode* root2)
{
	if(!root1)	return root2;
	if(!root2)	return root1;

	TreeNode* sudoHead=new TreeNode(-1);
	TreeNode* head=sudoHead;
	while(root1 && root2)
	{
		if(root1->val<root2->val)
		{
			head->right=root1;
			root1=root1->right;
			head->right->left=head;
			head=head->right;
		}
		else
		{
			head->right=root2;
			root2=root2->right;
			head->right->left=head;
			head=head->right;
		}
	}
	head=sudoHead->right;
	delete sudoHead;
	return head;
}

TreeNode* flattenBST(TreeNode* root)
{
	if(!root) return nullptr;
   
    	TreeNode* leftTree = flattenBST(root->left);
	TreeNode* rightTree = flattenBST(root->right);

	TreeNode* head=leftTree; // the left most node of the left subtree
	while(leftTree && leftTree->right)	
		leftTree=leftTree->right; 
    	if(leftTree) leftTree->right = root;
    	root->left = leftTree;
    	root->right = rightTree;
    	return head? head:root;
}
