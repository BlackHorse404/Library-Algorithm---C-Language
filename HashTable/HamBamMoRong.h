/*=========================================================================

				Title:		CODE HÀM BĂM MỞ RỘNG
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

//khởi tạo các bucket
void iNitBucket();
//hàm băm giá trị
int hashFunction(iTemTypeHash k);
//tạo HashNode hoàn chỉnh
NodePtr createHashNode(iTemType k);
//kiểm tra xem bucket co rỗng (1: rỗng, 0: không rỗng)
int bucketIsEmpty(int vt);
//thêm một key tại vị trí hash(vt)
void push(int vt, iTemType k);
//thêm một key vào bảng băm method 1 (hash(k) + i) mod MAXSIZE
void insertLinearProbing_1(iTemType k);
//thêm một key vào bảng băm method 2 (hash(k) + i*i) mod MAXSIZE
void insertQuadraticProbing_2(iTemType k);
//thêm một key vào bảng băm method 3 (hash(k) + i*hash(k)) mod MAXSIZE
void insertDoubleHash_3(iTemType k);
//kiểm tra xem bảng băm có rỗng (1: rỗng , 0: không rỗng)
int isEmpty();
//giải phóng HashNode p
void freeNode(NodePtr &p);
//lấy một Hash Node tại vị trí vt
NodePtr pop(int vt);
//xóa một HashNode sau HashNode P
int deleteAfter(NodePtr p);
//Xóa node k khỏi bảng băm
void remove(iTemType k);
//xóa/dọn sạch bucket tại vị trí vt
void clearBucket(int vt);
//xóa toàn bộ bảng băm
void clear();
//duyệt bucket tại vị trí vt
void traverseBucket(int vt);
//duyệt toàn bộ bảng băm
void traverse();
//tìm kiếm một key bất kì trên bảng băm -> trả về HashNode
NodePtr findHashNode(iTemType k);
//==============================================
//==============================================
//thân hàm con

//khởi tạo các bucket
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
//kiểm tra xem bucket co rỗng (1: rỗng, 0: không rỗng)
int bucketIsEmpty(int vt)
{
	return !bucket[vt] ? TRUE : FALSE;
}
//thêm một key tại vị trí hash(vt)
void push(int vt, iTemType k)
{
	NodePtr p = createHashNode(k);
	if (!p)
		return;
	bucket[vt] = p;
}
//thêm một key vào bảng băm method 1 (hash(k) + i) mod MAXSIZE
void insertLinearProbing_1(iTemType k)
{
	//phương pháp: (hash(k) + i) % MAXSIZE 
	int vt = hashFunction(k);
	if (bucketIsEmpty(vt))
		push(vt, k);
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			vt = (vt + i) % SIZE;
			if (bucketIsEmpty(vt))
			{
				push(vt, k);
				break;
			}
		}
	}
}
//thêm một key vào bảng băm method 2 (hash(k) + i*i) mod MAXSIZE
void insertQuadraticProbing_2(iTemType k)
{
	int vt = hashFunction(k);
	if (bucketIsEmpty(vt))
		push(vt, k);
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			vt = (vt + (i*i)) % SIZE;
			if (bucketIsEmpty(vt))
			{
				push(vt, k);
				break;
			}
		}
	}
}
//thêm một key vào bảng băm method 3 (hash(k) + i*hash(k)) mod MAXSIZE
void insertDoubleHash_3(iTemType k)
{
	//phương pháp: (hash(k) + i) % MAXSIZE 
	int vt = hashFunction(k);
	if (bucketIsEmpty(vt))
		push(vt, k);
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			vt = (vt + (i*vt)) % SIZE;
			if (bucketIsEmpty(vt))
			{
				push(vt, k);
				break;
			}
		}
	}
}
//kiểm tra xem bảng băm có rỗng (1: rỗng , 0: không rỗng)
int isEmpty()
{
	for (int i = 0; i < SIZE; i++)
		if (!bucketIsEmpty(i))
			return FALSE;
	return TRUE;
}
//giải phóng HashNode p
void freeNode(NodePtr &p)
{
	delete p;
}
//lấy một Hash Node tại vị trí vt
NodePtr pop(int vt)
{//null là không thể lấy ra do DS hashnode null
	if (bucketIsEmpty(vt))
		return NULL;
	NodePtr p = bucket[vt];
	bucket[vt] = p->next;
	return p;
}
//xóa một HashNode sau HashNode P
int deleteAfter(NodePtr p)
{
	if (!p || !p->next)
		return FALSE;//khong the xoa
	NodePtr q = p->next;
	p->next = q->next;
	freeNode(p);
	return TRUE;//xoa thusername cong
}
//Xóa node k khỏi bảng băm
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
//xóa/dọn sạch bucket tại vị trí vt
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
//xóa toàn bộ bảng băm
void clear()
{
	for (int i = 0; i < SIZE; i++)
		clearBucket(i);
}
//duyệt bucket tại vị trí vt
void traverseBucket(int vt)
{
	NodePtr p = bucket[vt];
	while (p)
	{
		printf("[%d]->", p->key);
		p = p->next;
		if (!p)
			printf("null");
	}
}
//duyệt toàn bộ bảng băm
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
//tìm kiếm một key bất kì trên bảng băm -> trả về HashNode
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