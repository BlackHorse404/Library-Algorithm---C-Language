/*=========================================================================

				Title:		CODE CÂY CÂN BẰNG AVL
				Code By:	Nguyễn Đức Phát
				FB:			fb.com/Phat.Lino.2K2
				Git:		https://github.com/phatlino

*///=======================================================================
//khai báo thư viện
#include<stdio.h>
#include<stdlib.h>
//========================================
//khai báo struct và constant
#define LH -1 // trái > phải
#define EH 0 // trái = phải 
#define RH 1 // phải > trái

typedef int iTemType;

struct AVLNode
{
	int balFactor;// chỉ số cân bằng
	iTemType Info;
	AVLNode *Left, *Right;
};

struct AVLTree
{
	AVLNode *Root;
};

typedef AVLNode *Tree;
//========================================
//khai báo hàm con

//khởi tạo cây AVL
void iNitAVLTree(AVLTree &avl);
//tạo một Node AVL hoàn chỉnh
AVLNode* createAVLNode(iTemType x);
//trường hợp quay Left Left
void rorateLL(Tree &T);
//trường hợp quay Left Right
void rorateLR(Tree &T);
//trường hợp quay Right Right
void rorateRR(Tree &T);
//trường hợp quay Right Left
void rorateRL(Tree &T);
//trường hợp quay Right Balance
int rorateRB(Tree &T);
//trường hợp quay Left Balance
int rorateLB(Tree &T);
//thêm NodeAVL tạo thành cây
int insertAVLNode(AVLNode* &T, AVLNode* p);
//hàm bổ trợ cho hàm xóa AVLNode
int searchStandFor(AVLNode* &p, AVLNode* &q);
//Xóa nút có Info bằng với x
int deleteAVLNode(AVLNode* &T, iTemType x);
//duyệt cây NLR
void traverseLNR(AVLNode *T);
//xuất thông tin AVLNode
void showAVLNode(AVLNode *T);
//========================================
//========================================
//thân hàm con

//khởi tạo cây AVL
void iNitAVLTree(AVLTree &avl)
{
	avl.Root = NULL;
}
//tạo một Node AVL hoàn chỉnh
AVLNode* createAVLNode(iTemType x)
{
	AVLNode *p = new AVLNode;
	if (!p)//kiểm tra khởi tạo dc p hay không
		return NULL;
	//gán giá trị khởi tạo node AVL
	p->balFactor = 0;
	p->Info = x;
	p->Left = p->Right = NULL;
	//trả về Node AVL -> P hoàn chỉnh
	return p;
}
//trường hợp quay Left Left
void rorateLL(Tree &T)
{
	AVLNode *T1 = T->Left;
	T->Left = T1->Right;
	T1->Right = T;
	switch (T1->balFactor)
	{
	case LH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = LH;
		T1->balFactor = RH;
		break;
	}
	T = T1;
}
//trường hợp quay Left Right
void rorateLR(Tree &T)
{
	AVLNode *T1 = T->Left, *T2 = T1->Right;
	T->Left = T2->Right;
	T2->Right = T;
	T1->Right = T2->Left;
	T2->Left = T1;
	switch (T2->balFactor)
	{
	case LH:
		T->balFactor = EH;
		T1->balFactor = RH;
		break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case RH:
		T->balFactor = LH;
		T1->balFactor = EH;
		break;
	}
	T2->balFactor = EH;
	T = T2;
}
//trường hợp quay Right Right
void rorateRR(Tree &T)
{
	AVLNode *T1 = T->Right;
	T->Right = T1->Left;
	T1->Left = T;
	switch (T1->balFactor)
	{
	case RH:
		T->balFactor = EH;
		T->balFactor = EH;
		break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = LH;
		break;
	}
	T = T1;
}
//trường hợp quay Right Left
void rorateRL(Tree &T)
{
	AVLNode *T1 = T->Right, *T2 = T1->Left;
	T->Right = T2->Left;
	T2->Left = T;
	T1->Left = T2->Right;
	T2->Right = T1;
	switch (T2->balFactor)
	{
	case RH:
		T->balFactor = EH;
		T1->balFactor = LH; break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = EH; break;
	case LH:
		T->balFactor = RH;
		T1->balFactor = EH; break;
	}
	T2->balFactor = EH;
	T = T2;
}
//trường hợp quay Right Balance
int rorateRB(Tree &T)
{
	//khi cây T lệch bên phải cần cân bằng lại
	AVLNode* T1 = T->Right;
	switch (T1->balFactor)
	{
	case LH:
		rorateRL(T);
		return 2;
	case EH:
		rorateRR(T);
		return 1;
	case RH:
		rorateRR(T);
		return 2;
	}
	return 0; //Trường balance bị sai
}
//trường hợp quay Left Balance
int rorateLB(Tree &T)
{
	AVLNode* T1 = T->Left;
	switch (T1->balFactor)
	{
	case LH:
		rorateLL(T);
		return 2;
	case EH:
		rorateLL(T);
		return 1;
	case RH:
		rorateLR(T);
		return 2;
	}
	return 0; //Trường balance bị sai
}
//thêm NodeAVL tạo thành cây
int insertAVLNode(AVLNode* &T, AVLNode* p)
{
	if (p == NULL)
		return -1; //Nút mới p muốn thêm không tồn tại
	if (T == NULL)
	{//Cây rỗng nên thêm nút mới vào gốc
		T = p;
		return 2; //Thực hiện thành công nút mới có giá trị x
	}
	//Cây không rỗng
	int Result;
	if (T->Info == p->Info)
		return 0; //Không thêm được vì tồn tại nút có giá trị bằng x
	if (T->Info > p->Info)
	{//Thêm nút mới vào nhánh trái
		Result = insertAVLNode(T->Left, p);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case RH:
			T->balFactor = EH;
			return 1;
		case EH:
			T->balFactor = LH;
			return 2;
		case LH:
			rorateLB(T);
			return 1;
		}
	}
	else
	{//Thêm nút mới vào nhánh phải
		Result = insertAVLNode(T->Right, p);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case LH:
			T->balFactor = EH;
			return 1;
		case EH:
			T->balFactor = RH;
			return 2;
		case RH:
			rorateRB(T);
			return 1;
		}
	}
}
//hàm bổ trợ cho hàm xóa AVLNode
int searchStandFor(AVLNode* &p, AVLNode* &q)
{
	int Result;
	if (q->Left != NULL)
	{
		Result = searchStandFor(p, q->Left);
		if (Result < 2)
			return Result;
		switch (q->balFactor)
		{
		case LH:
			q->balFactor = EH;
			return 2;
		case EH:
			q->balFactor = RH;
			return 1;
		case RH:
			return rorateRB(q);
		}
	}
	else
	{
		p->Info = q->Info;
		p = q;
		q = q->Right;
	}
	return 2;
}
//Xóa nút có Info bằng với x
int deleteAVLNode(AVLNode* &T, iTemType x)
{
	int Result;
	if (T == NULL)
		return 0; //Thực hiện không thành công
	if (T->Info > x)
	{
		Result = deleteAVLNode(T->Left, x);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case LH:
			T->balFactor = EH;
			return 2;
		case EH:
			T->balFactor = RH;
			return 1;
		case RH:
			return rorateRB(T);
		}
	}
	else if (T->Info < x)
	{
		Result = deleteAVLNode(T->Right, x);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case RH:
			T->balFactor = EH;
			return 2;
		case EH:
			T->balFactor = LH;
			return 1;
		case LH:
			return rorateLB(T);
		}
	}
	else
	{
		AVLNode* p = T;
		if (T->Left == NULL)
		{
			T = T->Right;
			Result = 2;
		}
		else
		{
			if (T->Right == NULL)
			{
				T = T->Left;
				Result = 2;
			}
			else
			{
				Result = searchStandFor(p, T->Right);
				if (Result < 2)
					return Result;
				switch (T->balFactor)
				{
				case RH:
					T->balFactor = EH;
					return 2;
				case EH:
					T->balFactor = LH;
					return 1;
				case LH:
					return rorateLB(T);
				}

			}
		}
		delete p;
		return Result;

	}
	return Result;
}
//duyệt cây NLR
void traverseLNR(AVLNode *T)
{
	if (!T)
		return;
	traverseLNR(T->Left);
	showAVLNode(T);
	traverseLNR(T->Right);
}
//xuất thông tin AVLNode
void showAVLNode(AVLNode *T)
{
	if (T)
		printf("%d ", T->Info);
}
//========================================