//khai báo thư viện
#include<stdio.h>
#include<stdlib.h>
//=========================================
//khai báo struct và constant
typedef int iTemType;
struct TNode{
	iTemType info;
	TNode *left;
	TNode *right;
};
struct BTree{
	TNode *root;
};
//=========================================
//khai báo hàm con
void iNitBTree(BTree &bt);
TNode* creatTNode(iTemType x);
int insertBTree(TNode* &root, TNode *p);
void createBTree_FromArray(int n, int arr[], BTree &t);
//duyệt nút
void traverseNLR(TNode *root);
void traverseLNR(TNode *root);
void traverseLRN(TNode *root);
void traverseNRL(TNode *root);
void traverseRNL(TNode *root);
void traverseRLN(TNode *root);
void connectBTree(TNode *root1, TNode *root2);
//=========================================
//---------------- MAIN -------------------
int main()
{
	BTree bt, bt1;
	TNode *p = new TNode;
	int n1 = 5, a[5] = {8,2,10,3,1};
	int n2 = 3, b[3] = {5,9,4};
	iNitBTree(bt);
	iNitBTree(bt1);
	createBTree_FromArray(n1, a, bt);
	createBTree_FromArray(n2, b, bt1);
	printf("\n======== Tree 1 ==========\n");
	printf("\nLeft Node Right: ");
	traverseLNR(bt.root);
	printf("\nLeft Right Node: ");
	traverseLRN(bt.root);
	printf("\nNode Left Right: ");
	traverseNLR(bt.root);
	printf("\nRight Left Node: ");
	traverseRLN(bt.root);
	printf("\nRight Node Left: ");
	traverseRNL(bt.root);
	printf("\nNode Right Left: ");
	traverseNRL(bt.root);
	printf("\n======== Tree 2 ==========\n");
	printf("\nLeft Node Right: ");
	traverseLNR(bt1.root);
	printf("\nLeft Right Node: ");
	traverseLRN(bt1.root);
	printf("\nNode Left Right: ");
	traverseNLR(bt1.root);
	printf("\nRight Left Node: ");
	traverseRLN(bt1.root);
	printf("\nRight Node Left: ");
	traverseRNL(bt1.root);
	printf("\nNode Right Left: ");
	traverseNRL(bt1.root);
	printf("\n======== xu ly ==========\n");
	connectBTree(bt.root,bt1.root);
	printf("\nLeft Node Right: ");
	traverseLNR(bt.root);
	printf("\nLeft Right Node: ");
	traverseLRN(bt.root);
	printf("\nNode Left Right: ");
	traverseNLR(bt.root);
	printf("\nRight Left Node: ");
	traverseRLN(bt.root);
	printf("\nRight Node Left: ");
	traverseRNL(bt.root);
	printf("\nNode Right Left: ");
	traverseNRL(bt.root);
	return 0;
}
//=========================================
//thân hàm con
void connectBTree(TNode *root1, TNode *root2)
{
	if(root1 == NULL || root2 == NULL)
		return;
	while(root1->left != NULL)
		root1 = root1->left;
	root1->left = root2;
}
void iNitBTree(BTree &bt)
{
	bt.root = NULL;
}
TNode* creatTNode(iTemType x)
{
	TNode *t = new TNode;
	if (t == NULL)
		return NULL;
	t->info = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}
int insertBTree(TNode* &root, TNode *p)
{
	if (!p)
		return 0;
	if (!root)
	{
		root = p;
		return 1;
	}
	if (p->info == root->info)
		return 0;// đã tồn tại
	if (p->info < root->info)
		insertBTree(root->left, p);
	else
		insertBTree(root->right, p);
	return 1;
}
void createBTree_FromArray(int n, int arr[], BTree &t)
{
	for (int i = 0; i < n; i++)
	{
		TNode *p = creatTNode(arr[i]);
		insertBTree(t.root, p);
	}
}
//duyệt nút
void traverseNLR(TNode *root)
{
	if (root == NULL)
		return;
	printf("%d ",root->info);
	traverseNLR(root->left);
	traverseNLR(root->right);
}
void traverseLNR(TNode *root)
{
	if (root == NULL)
		return;
	traverseLNR(root->left);
	printf("%d ", root->info);
	traverseLNR(root->right);
}
void traverseLRN(TNode *root)
{
	if (root == NULL)
		return;
	traverseLRN(root->left);
	traverseLRN(root->right);
	printf("%d ", root->info);
}
void traverseNRL(TNode *root)
{
	if (root == NULL)
		return;
	printf("%d ", root->info);
	traverseNRL(root->right);
	traverseNRL(root->left);
}
void traverseRNL(TNode *root)
{
	if (root == NULL)
		return;
	traverseRNL(root->right);
	printf("%d ", root->info);
	traverseRNL(root->left);
}
void traverseRLN(TNode *root)
{
	if (root == NULL)
		return;
	traverseRNL(root->right);
	traverseRNL(root->left);
	printf("%d ", root->info);
}
