
/*
typedef struct _treeNode
{
    int val;
    struct _treeNode *left;
    struct _treeNode *right;
    _treeNode(int v) : val(v), left(NULL), right(NULL) {}
}TreeNode;
*/

struct TreeNode* SingleRotateleft(struct TreeNode *tr);
struct TreeNode* SingleRotateright(struct TreeNode *tr);
struct TreeNode* DoubleRotateleft(struct TreeNode *tr);
struct TreeNode* DoubleRotateright(struct TreeNode *tr);
TreeNode* insertNode(struct TreeNode *tree, int num);
int height(struct TreeNode *tree);

struct TreeNode* sortedArrayToBST(int num[], int n)
{
    struct TreeNode *root;
    for(int i = 0; i < n; i++)
	root = insertNode(root, num[i]);

    return root;
}




struct TreeNode* insertNode(struct TreeNode *tree, int num)
{
    if(tree == NULL)
    {
    	tree = (TreeNode*)malloc(sizeof(TreeNode));
	if(tree == NULL) 
	    return NULL;

	tree->val = num;
	tree->left = NULL;
	tree->right = NULL;
    }
    else if(num < tree->val)
    {
	tree->left = insertNode(tree->left, num);
	if(height(tree->left) - height(tree->right) == 2)
	{
	    if(num < tree->left->val)
		tree = SingleRotateleft(tree);
	    else
		tree = DoubleRotateleft(tree);
	}
    }
    else if(num > tree->val)
    {
	tree->right = insertNode(tree->right, num);
	if(height(tree->right) - height(tree->left) == 2)
	{
	    if(num > tree->right->val)
		tree = SingleRotateright(tree);
	    else
		tree = DoubleRotateright(tree);
	}
    }

    return tree;
}

int height(struct TreeNode *tree)
{
    if(tree == NULL) return 0;
    else
    {
	int h1, h2;
	h1 = height(tree->left);
	h2 = height(tree->right);
	return h1 > h2 ? h1 + 1 : h2 + 1;
    }
}

struct TreeNode* SingleRotateleft(struct TreeNode *tr)
{
    TreeNode *ptr;

    ptr = tr->left;
    tr->left = ptr->right;
    ptr->right = tr;

    return ptr;
}
struct TreeNode* SingleRotateright(struct TreeNode *tr)
{
    TreeNode *ptr;

    ptr = tr->right;
    tr->right = ptr->left;
    ptr->left =tr;

    return ptr;
}
struct TreeNode* DoubleRotateleft(struct TreeNode *tr)
{
    TreeNode *k1, *k2;

    k1 = tr->left;
    k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;
    tr->left = k2->right;
    k2->right = tr;

    return k2;
}
struct TreeNode* DoubleRotateright(struct TreeNode *tr)
{
    TreeNode *k1, *k2;

    k1 = tr->right;
    k2 = k1->left;

    k1->left = k2->right;
    k2->right = k1;
    tr->right = k2->left;
    k2->left = tr;

    return k2;
}
