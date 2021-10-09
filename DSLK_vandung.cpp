//===================================
//khai bao thu vien
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//===================================
//khai bao cau truc
typedef int iTemType;
struct Node{
	iTemType info;
	Node *next;
};
struct SList
{
	Node *head, *tail;
};
//===================================
//khai bao ham con
void thucThiChuongTrinh();
void menuChuongTrinh();
//DSLK
void iNitSList(SList &lst);
Node* createNode(iTemType x);
void addHeadSList(SList &lst, Node *p);
void addTailSList(SList &lst, Node *p);
void addMidSList(SList &lst, Node *p, Node *q);
void printSList(SList lst);
void createSList_FromArray(int n, int a[], SList &lst);
//trộn danh sách
void tronDanhSachTangDan(SList lst1, SList lst2, SList &lst);
void tronDanhSachGiamDan(SList lst1, SList lst2, SList &lst);
void tronDanhSachChanTangLeGiam(SList lst1, SList lst2, SList &lst);
void tronDanhSachVTChanTangVTLeGiam(SList lst1, SList lst2, SList &lst);
//tăng dần
void sortAscending(SList &lst);
void swap(int &x, int &y);
//===================================
//Main
void main()
{
	thucThiChuongTrinh();
}
//===================================
//Than ham con
void thucThiChuongTrinh()
{
	int chon = 0;
	int n1 = 5, n2 = 5, a[] = { 6, 5, 1, 7, 9 }, b[] = { 2, 3, 4, 8, 10 };
	SList lst1, lst2, lst;
	iNitSList(lst1);
	iNitSList(lst2);
	createSList_FromArray(n1, a, lst1);
	createSList_FromArray(n2, b, lst2);
	sortAscending(lst1);
	sortAscending(lst2);
	do{
		iNitSList(lst);
		menuChuongTrinh();
		printf("\nVui long chon chuc nang thuc thi: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("\nDSLK 1: ");
			printSList(lst1);
			printf("\nDSLK 2: ");
			printSList(lst2);
			tronDanhSachTangDan(lst1, lst2, lst);
			printf("\nDSLK sau khi da tron: ");
			printSList(lst);
			break;
		case 2:
			printf("\nDSLK 1: ");
			printSList(lst1);
			printf("\nDSLK 2: ");
			printSList(lst2);
			tronDanhSachGiamDan(lst1, lst2, lst);
			printf("\nDSLK sau khi da tron: ");
			printSList(lst);
			break;
		case 3:
			printf("\nDSLK 1: ");
			printSList(lst1);
			printf("\nDSLK 2: ");
			printSList(lst2);
			tronDanhSachChanTangLeGiam(lst1, lst2, lst);
			printf("\nDSLK sau khi da sap xep: ");
			printSList(lst);
			break;
		case 4:
			printf("\nDSLK 1: ");
			printSList(lst1);
			printf("\nDSLK 2: ");
			printSList(lst2);
			tronDanhSachVTChanTangVTLeGiam(lst1, lst2, lst);
			printf("\nDSLK sau khi da sap xep: ");
			printSList(lst);
			break;
		default:
			printf("\nVui long kiem tra lai chuc nang %d vua chon !\n",chon);
			break;
		}
		//pause
		printf("\nPRESS ANY KEY TO CONTINUE ====> ");
		system("pause");
		system("cls");
	} while (chon != 0);
}
void menuChuongTrinh()
{
	printf("\n=========================================================================\n");
	printf("0. Thoat chuong trinh");
	printf("\n1. Tron Danh Sach 'ls1' va 'ls2' da cho da sap xep tang ra 'ls' TANG dan!");
	printf("\n2. Tron Danh Sach 'ls1' va 'ls2' da cho da sap xep tang ra 'ls' GIAM dan!");
	printf("\n3. Tron Danh Sach 'ls1' va 'ls2' da cho da sap xep tang ra 'ls' so chan TANG dan so le GIAM dan!");
	printf("\n4. Tron Danh Sach 'ls1' va 'ls2' da cho da sap xep tang ra 'ls' vi tri chan TANG dan vi tri le GIAM dan!");
	printf("\n=========================================================================\n");

}
void iNitSList(SList &lst)
{
	lst.head = lst.tail = NULL;
}
Node* createNode(iTemType x)
{
	Node *p = new Node;
	if (!p)
		return NULL;
	p->info = x;
	p->next = NULL;
	return p;
}
void addHeadSList(SList &lst, Node *p)
{
	if (!p)
		return;
	if (lst.head == NULL)
		lst.head = lst.tail = p;
	else
	{
		p->next = lst.head;
		lst.head = p;
	}
}
void addTailSList(SList &lst, Node *p)
{
	if (!p)
		return;
	if (lst.head == NULL)
		lst.head = lst.tail = p;
	else
	{
		lst.tail->next = p;
		lst.tail = p;
	}
}
void addMidSList(SList &lst, Node *p, Node *q)
{
	if (!p || !q)
		return;
	if (!lst.head)
		lst.head = lst.tail = p;
	else
	{
		Node *go = lst.head;
		while (go->next->info != q->info)//thêm vào truoc q
			go = go->next;
		p->next = go->next;
		go->next = p;
	}
}
void createSList_FromArray(int n, int a[], SList &lst)
{
	for (int i = 0; i < n; i++)
	{
		Node *p = createNode(a[i]);
		addTailSList(lst, p);
	}
}
void printSList(SList lst)
{
	Node *p = lst.head;
	while (p)
	{
		printf("%d ", p->info);
		p = p->next;
	}
}
//trộn danh sách
void tronDanhSachTangDan(SList lst1, SList lst2, SList &lst)
{
	Node *p1 = lst1.head;
	Node *p2 = lst2.head;
	int x;
	Node *pNew;
	while (p1 && p2)
	{
		if (p1->info <= p2->info)
		{
			x = p1->info;
			pNew = createNode(x);
			addTailSList(lst, pNew);
			p1 = p1->next;
		}
		else if (p2->info < p1->info)
		{
			x = p2->info;
			pNew = createNode(x);
			addTailSList(lst, pNew);
			p2 = p2->next;
		}
	}
	while (p1)
	{
		x = p1->info;
		pNew = createNode(x);
		addTailSList(lst, pNew);
		p1 = p1->next;
	}
	while (p2)
	{
		x = p2->info;
		pNew = createNode(x);
		addTailSList(lst, pNew);
		p2 = p2->next;
	}
}
//tăng dần
void sortAscending(SList &lst)
{
	for (Node *i = lst.head; i->next != NULL; i = i->next)
	{
		for (Node *j = i->next; j != NULL; j = j->next)
		{
			if (i->info > j->info)
				swap(i->info, j->info);
		}
	}
}
void swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
//trôn giảm dần
void tronDanhSachGiamDan(SList lst1, SList lst2, SList &lst)
{
	Node *p1 = lst1.head;
	Node *p2 = lst2.head;
	int x;
	Node *pNew;
	while (p1 && p2)
	{
		if (p1->info < p2->info)
		{
			x = p1->info;
			pNew = createNode(x);
			addHeadSList(lst, pNew);
			p1 = p1->next;
		}
		else if (p2->info < p1->info)
		{
			x = p2->info;
			pNew = createNode(x);
			addHeadSList(lst, pNew);
			p2 = p2->next;
		}
	}
	while (p1)
	{
		x = p1->info;
		pNew = createNode(x);
		addHeadSList(lst, pNew);
		p1 = p1->next;
	}
	while (p2)
	{
		x = p2->info;
		pNew = createNode(x);
		addHeadSList(lst, pNew);
		p2 = p2->next;
	}
}
void tronDanhSachChanTangLeGiam(SList lst1, SList lst2, SList &lst)
{
	//trổn đưa ra DSLK lst
	Node* p1 = lst1.head;
	Node* p2 = lst2.head;
	while (p1)
	{
		Node *pNew = createNode(p1->info);
		addTailSList(lst, pNew);
		p1 = p1->next;
	}
	while (p2)
	{
		Node *pNew = createNode(p2->info);
		addTailSList(lst, pNew);
		p2 = p2->next;
	}
	//sap xep DSLK chan
	for (Node *i = lst.head; i->next != NULL; i = i->next)
	{
		for (Node *j = i->next; j != NULL; j = j->next)
		{
			if (i->info > j->info && i->info % 2 == 0 && j->info % 2 == 0)
				swap(i->info, j->info);
		}
	}
	////sap xep DSLK le
	for (Node *i = lst.head; i->next != NULL; i = i->next)
	{
		for (Node *j = i->next; j != NULL; j = j->next)
		{
			if (i->info < j->info && i->info % 2 != 0 && j->info % 2 != 0)
				swap(i->info, j->info);
		}
	}
	
}
void tronDanhSachVTChanTangVTLeGiam(SList lst1, SList lst2, SList &lst)
{
	//trổn đưa ra DSLK lst
	Node* p1 = lst1.head;
	Node* p2 = lst2.head;
	while (p1)
	{
		int x = p1->info;
		Node *pNew = createNode(x);
		addTailSList(lst, pNew);
		p1 = p1->next;
	}
	while (p2)
	{
		int x = p2->info;
		Node *pNew = createNode(x);
		addTailSList(lst, pNew);
		p2 = p2->next;
	}
	//dem vi tri
	int dem = 0;
	Node *t = lst.head;
	printf("\nDSLK vi Tri chan ban dau\n");
	while (t)
	{
		printf("%d[%d] - ", t->info, dem+=2);
		t = t->next->next;
	}
	t = lst.head->next;
	dem = 1;
	printf("\nDSLK vi Tri le ban dau\n");
	while (t)
	{
		printf("%d[%d] - ", t->info, dem+=2);
		if (t->next)
			t = t->next->next;
		else
			break;
	}

	//vi tri chẵn tăng
	for (Node *i = lst.head; i->next->next != NULL; i = i->next->next)
	{
		for (Node *j = i->next->next; j != NULL; j = j->next->next)
		{
			if (i->info > j->info)
			{ 
				swap(i->info, j->info);
			}
				
		}
	}
	//vi tri lẻ giảm
	for (Node *i = lst.head->next; i->next != NULL; i = i->next->next)
	{
		Node *j = i->next->next;
		while (j)
		{
			Node *p = j;
			if (i->info < p->info)
				swap(p->info, i->info);
			if (j->next)
				j = j->next->next;
			else
				break;
		}
	}
}
//===================================