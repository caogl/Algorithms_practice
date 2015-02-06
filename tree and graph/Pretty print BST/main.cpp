// facebook interview question
// reference: (1) http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=86176&extra=page%3D2%26filter%3Dsortid%26sortid%3D311%26searchoption%255B3046%255D%255Bvalue%255D%255B2%255D%3D2%26searchoption%255B3046%255D%255Btype%255D%3Dcheckbox&page=2
//            (2) http://www.fgdsb.com/2015/01/25/pretty-print-bst/
/*
            4                     
      1           5         
         2           6   
           3   
           
—> needs to calculate:
(1) the left node to the border
(2) the distance between each node
From the figure, we see that the tree can be constructed like:
oooooooxooooooo        
oooxoooooooxooo
oxoooxoooxoooxo
xoxoxoxoxoxoxox

level	(1)	(2)
1	7		->2^3-1
2	3	7	—>2^2-1
3	1	3	->2^1-1
4	0	1	->2^0-1

FB的题，本质上就是level order遍历。这里不需要画斜线，只用空格表示还是比较简单的。
因为是二叉树，每一层最大节点数都是可以计算的，也就是每一个节点离previous节点的距离（空格数）也可以计算到。
那么每层遍历的时候针对每个节点（包括空节点）输空格即可。
下面的代码适用于任意二叉树。*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max_height(TreeNode* node); 
void pretty_print_bst(TreeNode* root, int space_size = 3);

int main()
{
	TreeNode* root=new TreeNode(4);
	root->left=new TreeNode(1);
	root->left->right=new TreeNode(2);
	root->left->right->right=new TreeNode(3);
	root->right=new TreeNode(5);
	root->right->right=new TreeNode(6);
	pretty_print_bst(root, 3);
}

int max_height(TreeNode* node) 
{
    if(!node) return 0;
    return 1 + max(max_height(node->left), max_height(node->right));
}

void pretty_print_bst(TreeNode* root, int space_size) 
{
	deque<TreeNode*> q = { root };
	int height = max_height(root);
	int cur_level_nodes = 1, next_level_nodes = 0, level = 1;
	int padding = space_size * (pow(2, height - level) - 1);
	cout << setw(padding / 2) << "";
	while (level <= height)
	{
		cout << setw(space_size);
		if (q.front())
		{
			cout << q.front()->val;
			q.push_back(q.front()->left);
			q.push_back(q.front()->right);
		}
		else
		{
			cout << " ";
			q.push_back(nullptr);
			q.push_back(nullptr);
		}
		next_level_nodes += 2;
		cout << setw(padding) << "";
		q.pop_front();
		// go to next level
		if (--cur_level_nodes == 0)
		{
			cur_level_nodes = next_level_nodes;
			next_level_nodes = 0;
			++level;
			padding = space_size * (pow(2, height - level) - 1);
			cout << endl << setw(padding / 2) << "";
		}
	}
}
