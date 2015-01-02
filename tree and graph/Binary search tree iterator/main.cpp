// idea: Inorder traversal using stack

#include<stack>
#include<iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
	BSTIterator(TreeNode *root)
    	{
        	current=root;
    	}

    	/** @return whether we have a next smallest number */
    	bool hasNext() 
    	{
        	return (current!=nullptr || !stack1.empty());
    	}

    	/** @return the next smallest number */
    	int next() 
    	{
        	while(current!=nullptr)
		{
			stack1.push(current);
			current=current->left;
		}
		current=stack1.top()->right;
		int result=stack1.top()->val;
		stack1.pop();
		return result;
    	}
private:
	TreeNode* current;
	stack<TreeNode*> stack1; 
};

int main()
{
	TreeNode* root=new TreeNode(8);
	root->left=new TreeNode(4);
	root->right=new TreeNode(12);
	root->left->left=new TreeNode(2);
	root->left->right=new TreeNode(6);
	root->left->right->left=new TreeNode(5);
	BSTIterator itr(root);
	while(itr.hasNext())
		cout<<itr.next()<<" ";
	cout<<endl;
	return 0;
}
