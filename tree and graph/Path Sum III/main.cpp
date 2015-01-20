#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node(int data1)
	{
		data=data1;
		left=NULL;
		right=NULL;
	}
};

vector<vector<int> > findPathSum(node* root, int target);
void findPathSum(node* root, int target, vector<int>& tmp, vector<vector<int> >& result);

int main()
{
	node *root1=new node(8);
	root1->left=new node(4);
	root1->right=new node(2);
	root1->left->left=new node(2);
	root1->left->right=new node(6);
	root1->right->left=new node(5);
	root1->right->right=new node(14);
	root1->left->left->left=new node(1);
	root1->left->left->right=new node(3);
	root1->left->right->left=new node(4);
	root1->left->right->right=new node(7);
	root1->right->left->left=new node(9);
	root1->right->left->right=new node(11);
	root1->right->right->left=new node(13);
	root1->right->right->right=new node(15);
	/* answer:
		8 4 2 
		4 6 4 
		5 9 
		14 
	*/
	vector<vector<int> > result=findPathSum(root1, 14);
	for(unsigned int i=0; i<result.size(); i++)
	{
		for(unsigned int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

vector<vector<int> > findPathSum(node* root, int target)
{
	vector<vector<int> > result;
	vector<int> tmp;
	findPathSum(root, target, tmp, result);
	return result;
}

void findPathSum(node* root, int target, vector<int>& tmp, vector<vector<int> >& result)
{
	if(root==NULL)
		return;
	tmp.push_back(root->data);
	int sum=0;
	for(int i=tmp.size()-1; i>=0; i--)
	{
		sum+=tmp[i];
		if(sum==target)
		{
			vector<int> resultElem;
			for(int j=i; j<tmp.size(); j++)
			{
				resultElem.push_back(tmp[j]);
			}
			result.push_back(resultElem);
		}
	}

	findPathSum(root->left, target, tmp, result);
	findPathSum(root->right, target, tmp, result);
	tmp.pop_back();
}
