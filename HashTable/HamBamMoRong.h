/*=========================================================================
		Title:		CODE HÀM BĂM TRỰC TIẾP
		Code By:	Nguyễn Đức Phát
		FB:			fb.com/Phat.Lino.2K2
		Git:		https://github.com/phatlino
*///=======================================================================
//khai báo thư viện
#include<stdio.h>
#include<stdlib.h>
#include<crtdbg.h>
//===========================================
//khai báo struct và constant, Biến public
int size = 7;
int soLuongPT = 0;
int* arr;
//===========================================
//khai báo hàm con
void iNitHashTableOpen();
int hashTable(int key);
void insertNodeLinear(int key);
void insertNodeQuadratic(int key);
void display();
int keyIsEmpty(int k);
void createHashTableOpenRandom();
void createHashTableOpenArrayReady();
void createHashTableOpenKeyBoard();
void createHashTableOpenArrayReady_Quadratic();
int findIndexKey(int key);
int deleteByKey(int key);

//===========================================
//===========================================
//thân hàm con
void iNitHashTableOpen()
{
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = -1;
}
int hashTable(int key)
{
	return key % size;
}

void insertNodeQuadratic(int key)
{
	int index = hashTable(key);
	int solandungdo = 1;
	if (soLuongPT > size * 0.6)
	{
		int k = size;
		//cấp phát lại
		size *= 2;
		arr = (int*)realloc(arr, size * sizeof(int));
		//khởi tạo cho các phẩn tử mới cấp phát
		for (int j = k; j < size; j++)
			arr[j] = -1;
		//kiểm tra vị trí giá trị
		for (int i = 0; i < k; i++)
		{
			if (i != hashTable(arr[i]))
			{
				index = hashTable(arr[i]);
				solandungdo = 1;
				while (arr[index] != -1)
				{
					index = (index + solandungdo * solandungdo) % size;
					solandungdo++;
				}
				arr[index] = arr[i];
				arr[i] = -1;
			}
		}
	}
	solandungdo = 1;
	while (arr[index] != -1)
	{
		index = (index + solandungdo * solandungdo) % size;
		solandungdo++;
	}
	arr[index] = key;
	soLuongPT++;
}

void insertNodeLinear(int key)
{
	int index = hashTable(key);
	int solandungdo = 1;
	solandungdo = 1;
	while (arr[index] != -1)
	{
		index = (index + solandungdo) % size;
		solandungdo++;
	}
	arr[index] = key;
	soLuongPT++;
	//kiểm tra xem có cần phải resize max
	if (soLuongPT > size * 0.6)
	{
		int k = size;
		//cấp phát lại
		size *= 2;
		arr = (int*)realloc(arr, size * sizeof(int));
		//khởi tạo cho các phẩn tử mới cấp phát
		for (int j = k; j < size; j++)
			arr[j] = -1;
		//kiểm tra vị trí giá trị
		for (int i = 0; i < k; i++)
		{
			if (i != hashTable(arr[i]))
			{
				index = hashTable(arr[i]);
				solandungdo = 1;
				while (arr[index] != -1)
				{
					index = (index + solandungdo) % size;
					solandungdo++;
				}
				arr[index] = arr[i];
				arr[i] = -1;
			}
		}
	}
}
void display()
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != -1)
		{
			printf("%02d | %5d ", i, arr[i]);
			printf("\n");
		}
	}
}
int deleteByKey(int key)
{
	int index = hashTable(key), solandungdo = 1;
	while (arr[index] != key && arr[index] != -1)
		index = (solandungdo++ + index) % size;
	if (arr[index] != -1)
	{
		arr[index] = -2;
		soLuongPT--;
	}
	else
	{
		printf("Khong co phan tu %d!", key);
		return 0;
	}
}
int keyIsEmpty(int k)
{
	int index = hashTable(k);
	return arr[index] == -1 ? 1 : 0;
}

void createHashTableOpenArrayReady()
{
	//int x[10] = { 4, 2, 12, 6, 25, 7, 8, 11, 23, 33 };
	int x[5] = { 1, 2, 3, 4, 2 };
	for (int i = 0; i < 5; i++)
	{
		insertNodeLinear(x[i]);
	}
}
void createHashTableOpenKeyBoard()
{
	int x, i = 1;
	do {
		printf("\nNhap gia tri muon them vao (so thu %d): ", i++);
		scanf("%d", &x);
		if (x != -1)
			insertNodeLinear(x);
	} while (x != -1);
}
void createHashTableOpenRandom()
{
	int x;
	for (int i = 0; i < size; i++)
	{
		x = 1 + rand() % 49;
		insertNodeLinear(x);
	}
}

int findIndexKey(int key)
{
	if (keyIsEmpty(key))
		return -1;//không tồn tại key
	int index = hashTable(key);
	int solandungdo = 0;
	while (arr[index] != key)//khác thì tìm
	{
		index = (index + solandungdo) % size;
		solandungdo++;
	}
	if (arr[index] == -1)
		return -1;//tìm bị false
	return index;//thành cong
}
void createHashTableOpenArrayReady_Quadratic()
{
	int x[10] = { 4, 2, 12, 6, 25, 7, 8, 11, 23, 33 };

	for (int i = 0; i < 10; i++)
	{
		insertNodeQuadratic(x[i]);
	}
}
//===========================================
