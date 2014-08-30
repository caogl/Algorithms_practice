#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbers(TreeNode *root);
void sumNumbers(TreeNode *root, string& tmp, vector<string>& result);

int main()
{
	TreeNode* head=new TreeNode(1);
	head->left=new TreeNode(2);
	head->right=new TreeNode(3);
	cout<<"The sum of the path number is: "<<sumNumbers(head)<<endl;
	
	return 0;
}

int sumNumbers(TreeNode *root)
{
        string tmp;
        vector<string> result;
        sumNumbers(root, tmp, result);
        int sum=0;
        for(int i=0; i<result.size(); i++)
            sum+=atoi(result[i].c_str());
        return sum;
}
    
void sumNumbers(TreeNode *root, string& tmp, vector<string>& result)
{
        if(root==nullptr)
            return;
        if(root->left==nullptr && root->right==nullptr)
        {
            ostringstream ss;
            ss<<root->val;
            tmp+=ss.str();
            result.push_back(tmp);
        }
        else
        {
            ostringstream ss;
            ss<<root->val;
            tmp+=ss.str();
            string tmp1(tmp), tmp2(tmp);
            sumNumbers(root->left, tmp1, result);
            sumNumbers(root->right, tmp2, result);
        }
}
