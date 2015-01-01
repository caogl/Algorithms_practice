#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

Node* newNode(int data1);

void preOrderTraversal(Node* root);
void preStack(Node* root);
/* 100 50 25 75 150 125 110 175 */

void inOrderTraversal(Node* root);
void inStack(Node* root);

void postOrderTraversal(Node* root);
void postStack(Node* root);
/* 25 75 50 110 125 175 150 100 */

int main()
{
	Node* root=newNode(100);
	root->left=newNode(50);
	root->right=newNode(150);
	root->left->left=newNode(25);
	root->left->right=newNode(75);
	root->right->left=newNode(125);
	root->right->left->left=newNode(110);
	root->right->right=newNode(175);

	preOrderTraversal(root);
	cout<<endl;
	preStack(root);
	cout<<endl;

	inOrderTraversal(root);
	cout<<endl;
	inStack(root);
	cout<<endl;

	postOrderTraversal(root);
	cout<<endl;
	postStack(root);
	cout<<endl;

	return 0;
}

Node* newNode(int data1)
{
	Node* node=new Node;
	node->data=data1;
	node->left=nullptr;
	node->right=nullptr;
	return node;
}

void preOrderTraversal(Node* root)
{
	if(root==nullptr)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void preStack(Node* root)
{
	stack<Node*> stack1;
	stack1.push(root);
	while(!stack1.empty())
	{
		cout<<stack1.top()->data<<" ";
		Node* tmp=stack1.top();
		stack1.pop();
		if(tmp->right!=nullptr)
			stack1.push(tmp->right);
		if(tmp->left!=nullptr)
			stack1.push(tmp->left);
	}
}

void inOrderTraversal(Node* root)
{
	if(root==nullptr)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

/*
   Demo:
           100
           /  \
           
        /        \
      50         150
     /  \       /   \
   25   75    125   175
              /
           110
   
      	stack elements(bottom to top)		current		pop and print
   (0)  empty  					100
   (1)  100					50
   ...
   (2)  100-50-25				nullptr		25
   (3)	100-50					nullptr		50
   (4)	100-75					75
   (5)  100-75					nullptr		75
   (6)	100					nullptr		100
   (7)	150					125
   (8)  150-125					110
   ......
*/

void inStack(Node* root)
{
	Node* current=root; // current node to explore
	stack<Node*> stack1;
	while(!stack1.empty() || current!=nullptr)
	{
		//if current node is not nullptr, go left until there are no left nodes
		if(current!=nullptr) 
		{
			stack1.push(current);
			current=current->left;
		}
		else
		{
			// if current is nullptr, means the top element is the leftmost, print, explore the right of the top as current
			cout<<stack1.top()->data<<" ";
			current=stack1.top();
			stack1.pop();
			current=current->right;
		}
	}
}

void postOrderTraversal(Node* root)
{
	if(root==nullptr)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";
}

/*
 * Using two stacks one for parent and one for child
 * Push the root node to the child stack.
   while child stack is not empty
   Pop a node from the child stack, and push it to the parent stack.
   Push its left child followed by its right child to the child stack.
   end while
   Now the parent stack would have all the nodes ready to be traversed in post-order. 
   Pop off the nodes from the parent stack one by one and you will have the post order traversal of the tree.
   Demo:
           100
          /    \
           
        /        \
      50         150
     /  \       /   \
   25   75    125   175
              /
           110

         child                  parent
   (1)     100
   (2)   150  50                  100
   (3)  175 125 50              150 100
   (4)   125  50              175 150 100
   (5)  110 50              125 175 150 100
   ......
 */

void postStack(Node* root)
{
	stack<Node*> parent;
	stack<Node*> child;
	if(root!=nullptr)
		child.push(root);
	while(!child.empty())
	{
		Node* tmp=child.top();
		parent.push(tmp);
		child.pop();
		if(tmp->left!=nullptr)
			child.push(tmp->left);
		if(tmp->right)
			child.push(tmp->right);
	}
	while(!parent.empty())
	{
		cout<<parent.top()->data<<" ";
		parent.pop();
	}
}

