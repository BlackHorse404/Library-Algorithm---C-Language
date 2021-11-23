/*=========================================================================

				Title:		CODE HÀM BĂM TRỰC TIẾP
				Code By:	Nguyễn Đức Phát
				FB:			fb.com/Phat.Lino.2K2
				Git:		https://github.com/phatlino

*///=======================================================================
//khai báo thư viện
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//==============================================
//khai báo struct và constant
#define SIZE 20
#define TRUE 1
#define FALSE 0

typedef int iTemTypeHash;

typedef int iTemType;

struct HashNode{
	iTemType key;
	HashNode *next;
};

typedef HashNode* NodePtr;
NodePtr bucket[SIZE];
//==============================================
//khai báo hàm con - prototype

//khởi tạo bucket
void iNitBucket();
//hàm băm giá trị
int HashFunction(iTemType k);
//kiểm tra bucket có tồn tài giá trị nào không
int BucketIsEmpty(int vt);
//tạo HashNode hoàn chỉnh
NodePtr createHashNode(iTemType k);
//thêm một nút vào đầu bucket
void push(int vt, iTemType k);
//thêm vào bucket node k sau HashNode p
void insertAfter(NodePtr p, iTemType k);
//chèn kháo k vào vị trí vt của bucket
void place(int vt, iTemType k);
//kiểm tra bảng băm có tồn tại bucket nào không
int isEmpty();
//thêm k vào bảng băm
void insert(iTemType k);
//xóa HashNode p
void freeNode(NodePtr &p);
//xóa một nút ở đầu bucket
NodePtr pop(int vt);
//xóa một nút ngay sau p
int deleteAfter(NodePtr p);
//hủy có khóa k trong bảng băm
void remove(iTemType k);
//xóa bucket trong bảng băm
void clearBucket(int vt);
//xóa tất cả các phần tử trong bảng băm
void clear();
//duyệt các phần tử trong bucket vt
void traverseBucket(int vt);
//duyệt toàn bộ hàm băm
void traverse();
//tim kiếm phần tử trong bảng băm
NodePtr Search(iTemType k);
//==============================================
//==============================================
//thân hàm con

//khởi tạo bucket
void iNitBucket()
{
	for (int i = 0; i < SIZE; i++)
		bucket[i] = NULL;
}
//hàm băm giá trị
int hashFunction(iTemTypeHash k)
{
	return k % SIZE;
}
//tạo HashNode hoàn chỉnh
NodePtr createHashNode(iTemType k)
{
	HashNode *p = new HashNode;
	if (!p)
		return NULL;
	p->key = k;
	p->next = NULL;
	return p;
}
//kiểm tra bucket có tồn tài giá trị nào không
int bucketIsEmpty(int vt)
{
	return !bucket[vt] ? TRUE : FALSE;
}
//thêm một nút vào đầu bucket
void push(int vt, iTemType k)
{
	NodePtr p = createHashNode(k);
	if (!p)
		return;
	bucket[vt] = p;
}
//thêm vào bucket node k sau HashNode p
void insertAfter(NodePtr p, iTemType k)
{
	if (!p)
		return;
	HashNode *q = createHashNode(k);
	p->next = q;
}
//chèn kháo k vào vị trí vt của bucket
void place(int vt, iTemType k)
{
	NodePtr q = NULL, p;
	for (p = bucket[vt]; p != NULL; p = p->next)
		q = p;
	if (!q)
		push(vt, k);
	else
		insertAfter(q, k);
}
//kiểm tra bảng băm có tồn tại bucket nào không
int isEmpty()
{
	for (int i = 0; i < SIZE; i++)
		if (!bucketIsEmpty(i))
			return FALSE;
	return TRUE;
}
//thêm k vào bảng băm
void insert(iTemType k)
{
	int vt = hashFunction(k);
	place(vt, k);
}
//xóa HashNode p
void freeNode(NodePtr &p)
{
	delete p;
}
//xóa một nút ở đầu bucket
NodePtr pop(int vt)
{//null là không thể lấy ra do DS hashnode null
	if (bucketIsEmpty(vt))
		return NULL;
	NodePtr p = bucket[vt];
	bucket[vt] = p->next;
	return p;
}
//xóa một nút ngay sau p
int deleteAfter(NodePtr p)
{
	if (!p || !p->next)
		return FALSE;//khong the xoa
	NodePtr q = p->next;
	p->next = q->next;
	freeNode(p);
	return TRUE;//xoa thanh cong
}
//hủy có khóa k trong bảng băm
void remove(iTemType k)
{
	NodePtr q, p;
	int vt = hashFunction(k);
	p = bucket[vt];
	while (p && p->next)
	{
		q = p;
		p = p->next;
	}
	if (!p)
		printf("\nKhong co khoa '%d'", k);
	else if (p == bucket[vt])
		pop(vt);
	else
		deleteAfter(q);
}
//xóa bucket trong bảng băm
void clearBucket(int vt)
{
	NodePtr q = NULL, p = bucket[vt];
	while (p)
	{
		q = p;
		p = p->next;
		freeNode(q);
	}
	bucket[vt] = NULL;
}
//xóa tất cả các phần tử trong bảng băm
void clear()
{
	for (int i = 0; i < SIZE; i++)
		clearBucket(i);
}
//duyệt các phần tử trong bucket vt
void traverseBucket(int vt)
{
	NodePtr p = bucket[vt];
	while (p)
	{
		printf("[%s]->", p->key);
		p = p->next;
		if (!p)
			printf("null");
	}
}
//duyệt toàn bộ hàm băm
void traverse()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (!bucketIsEmpty(i))
		{
			printf("\n%02d | ", i);
			traverseBucket(i);
			printf("\n----\n");
		}
	}
}
//tim kiếm phần tử trong bảng băm
NodePtr findHashNode(iTemType k)
{
	int vt = hashFunction(k);
	NodePtr p = bucket[vt];
	while (k > p->key && p)
		p = p->next;
	if (!p || k != p->key)
		return NULL;
	else
		return p;
}
//==============================================