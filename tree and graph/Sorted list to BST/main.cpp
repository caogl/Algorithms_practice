#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode *head);
void inorderTraversal(TreeNode* root);
TreeNode* sortedListToBST(ListNode* &head, int begin, int end);

int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=new ListNode(5);
	head->next->next->next->next->next=new ListNode(6);
	head->next->next->next->next->next->next=new ListNode(7);
	head->next->next->next->next->next->next->next=new ListNode(8);
	head->next->next->next->next->next->next->next->next=new ListNode(9);

	TreeNode* root=sortedListToBST(head);
	inorderTraversal(root);
	cout<<endl;
	return 0;
}

TreeNode* sortedListToBST(ListNode *head)
{
	ListNode* head1=head;
	int len=0;
	while(head1!=nullptr)
	{
		head1=head1->next;
		len++;
	}
	TreeNode* root=sortedListToBST(head, 0, len-1);
}

TreeNode* sortedListToBST(ListNode* &head, int begin, int end)
{
	if(begin>end)
		return nullptr;
	int mid=(begin+end)/2;
	TreeNode* leftNode=sortedListToBST(head, begin, mid-1);
	TreeNode* root=new TreeNode(head->val);
	head=head->next;
	TreeNode* rightNode=sortedListToBST(head, mid+1, end);
	root->left=leftNode;
	root->right=rightNode;
	return root;
}

void inorderTraversal(TreeNode* root)
{
	if(root==nullptr)
		return;
	inorderTraversal(root->left);
	cout<<root->val<<" ";
	inorderTraversal(root->right);
}
