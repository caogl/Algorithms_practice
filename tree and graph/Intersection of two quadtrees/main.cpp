// reference: http://www.fgdsb.com/2015/01/25/intersection-of-two-quadtrees/
/*
Given a quadtree structure:
struct QuadNode {
    QuadNode(int num_ones = 0) : ones(num_ones) {}
    int ones{ 0 };
    QuadNode* child[4]{ nullptr };
};
Please build a quadtree to represent a 0-1 matrix, assume the matrix is a square and the dimension is power of 2.
Given two such quadtrees with same depth, please write a function to calculate how many 1s are overlapped.

四叉树多次出现在G家的onsite面经中，构建0-1矩阵和求交集则属于频率比较高也比较简单的考查方式。
注意在计算交集的时候，如果比较的两个节点有一个节点的ones等于0，则该子树可以直接砍掉，这就是四叉树的高效之处。
*/

#include<iostream>
#include<vector>
using namespace std;

// change the struct def like this is clear
struct QuadNode 
{
    int ones; // number of ones for the subtree starting with this node
    QuadNode* child[4];
    
    QuadNode(int num_ones)
    {
    	ones=num_ones;
    	for(int i=0; i<4; i++)
    		child[i]=nullptr;
    }
};

QuadNode* buildTree(vector<vector<int> >& matrix);
QuadNode* buildTree(vector<vector<int> >& matrix, int size, int row, int col);
int intersections(QuadNode* tree0, QuadNode* tree1);
int intersections(QuadNode* tree0, QuadNode* tree1, int sum);

int main()
{
	vector<int> tmp0={0, 1};
	vector<int> tmp1={1, 1};
	vector<vector<int> > matrix1={tmp0, tmp1};
        vector<int> vec0={0, 0};
        vector<int> vec1={1, 1};
        vector<vector<int> > matrix2={vec0, vec1};
	QuadNode* tree1=buildTree(matrix1);
	QuadNode* tree2=buildTree(matrix2);
	cout<<intersections(tree1, tree2)<<endl;
	return 0;
}

QuadNode* buildTree(vector<vector<int> >& matrix)
{
	int n=matrix.size();
	if(n==0)	return nullptr;
	return buildTree(matrix, n, 0, 0);
}
QuadNode* buildTree(vector<vector<int> >& matrix, int size, int row, int col)
{
	// base
	if(size==1)	return new QuadNode(matrix[row][col]);

	// recursive
	QuadNode* root=new QuadNode(0);
	size/=2;
	int sub_coords[4][2]={{row, col}, {row+size, col}, {row, col+size}, {row+size, col+size}};
	for(int i=0; i<4; i++)
	{
		root->child[i]=buildTree(matrix, size, sub_coords[i][0], sub_coords[i][1]);
		root->ones+=root->child[i]->ones;
	}
	return root;
}

int intersections(QuadNode* tree0, QuadNode* tree1)
{
	return intersections(tree0, tree1, 0);
}
int intersections(QuadNode* tree0, QuadNode* tree1, int sum)
{
	// base
	if(!tree0 || !tree1 || !tree0->ones || !tree1->ones)	return 0;
	
	// recursive
	int result=sum;
	if(!tree0->child[0] && !tree1->child[0]) // not initialized child, means singel elemnet
		result+=(tree0->ones && tree1->ones);
	else
		for(int i=0; i<4; i++)
			result+=intersections(tree0->child[i], tree1->child[i], sum);
	return result;
}



