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
vector<list<node*> > treeToList(node *root);
void print(const vector<list<node*> >& vec);

int main()
{
	node *root1=new node(8);
	root1->left=new node(4);
	root1->right=new node(12);
	root1->left->left=new node(2);
	root1->left->right=new node(6);
	root1->right->left=new node(10);
	root1->right->right=new node(14);
	root1->left->left->left=new node(1);
	root1->left->left->right=new node(3);
	root1->left->right->left=new node(5);
	root1->left->right->right=new node(7);
	root1->right->left->left=new node(9);
	root1->right->left->right=new node(11);
	root1->right->right->left=new node(13);
	root1->right->right->right=new node(15);
	vector<list<node*> > vec=treeToList(root1);
	//cout<<"haha";
	print(vec);
	system("PAUSE");
	return 0;
}

void print(const vector<list<node*> >& vec)
{
	//cout<<vec.size()<<endl;;
	for(unsigned int i=0; i<vec.size(); i++)
	{
		//cout<<"aaaaaa"<<vec[i].size()<<" ";
		for(list<node*>::const_iterator itr=vec[i].begin(); itr!=vec[i].end(); itr++)
		{
			//cout<<"haha";
			cout<<(*itr)->data<<" ";
		}
		//cout<<"haha";
		cout<<endl;
	}
}

vector<list<node*> > treeToList(node *root)
{
	vector<list<node*> > listVec;
	list<node*> li;
	li.push_back(root);
	listVec.push_back(li);
	int level=0;
	li.clear();
	while(!listVec[level].empty())
	{
		for(list<node*>::iterator itr=listVec[level].begin(); itr!=listVec[level].end(); itr++)
		{
			if((*itr)->left!=NULL)
				li.push_back((*itr)->left);
			if((*itr)->right!=NULL)
				li.push_back((*itr)->right);
		}
		listVec.push_back(li);
		level++;
		li.clear();
	}
	return listVec;
}