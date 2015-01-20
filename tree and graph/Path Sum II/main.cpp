#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > pathSum(TreeNode *root, int sum);
void pathSum(TreeNode* root, int sum, int cur, vector<int>& tmp, vector<vector<int> >& result);

int main()
{
	TreeNode* root=new TreeNode(0);
	root->left=new TreeNode(1);
	root->right=new TreeNode(1);
	vector<vector<int> > result=pathSum(root, 1);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

vector<vector<int> > pathSum(TreeNode *root, int sum)
{
        int cur=0;
        vector<int> tmp;
        vector<vector<int> > result;
        pathSum(root, sum, cur, tmp, result);
        return result;
}

void pathSum(TreeNode* root, int sum, int cur, vector<int>& tmp, vector<vector<int> >& result)
{
        if(root==nullptr)
            return;
        if(root->left==nullptr && root->right==nullptr && cur+root->val==sum)
        {
            tmp.push_back(root->val);
            result.push_back(tmp);
            tmp.pop_back();  /* because we are trying to find multiple possible result, so must pop_back here!!
				For tree questions, if needs to return all paths, must pop_back afterwords
				eg: (1)Word ladder || (2)Path Sum || */
        }
        else
        {
            tmp.push_back(root->val);
            cur+=root->val;
            pathSum(root->left, sum, cur, tmp, result);
            pathSum(root->right, sum, cur, tmp, result);
            tmp.pop_back();
        }
}
