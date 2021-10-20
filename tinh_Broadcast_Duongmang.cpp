//thong tin phan mem
/*
	Author: Nguyễn Đức Phát 
	Chương trình hỗ trợ tìm đường mạng của IPv4, tính broadcasr của IPv4 
	Môn: Mạng Máy tính
*/
//thư viện
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//khai báo struct và constant
#define SIZE 32

//khai báo hàm con
void kiemTraLopCuaIP(int byte1, int byte2, int byte3, int byte4);
void nhapVaoIPv4(int &byte1, int &byte2, int &byte3, int &byte4, int &subnet);
void tinhToanDiaChiMang(int byte1, int byte2, int byte3, int byte4, int subnet, int bin[]);
void chuyenSangNhiPhan_DuaVaoMang(int byte,int n, int bin[]);
void xuatBinary(int bin[]);
int chuyenBinarySangDecimal(int bin[], int n);
//main
void main()
{
	printf("\t\t...:::Author: Nguyen Duc Phat :::...\n\t\t*************************************\n\n");
	int byte1, byte2, byte3, byte4, subnet, bin[SIZE];
	nhapVaoIPv4(byte1, byte2, byte3, byte4, subnet);
	printf("\n\n================ Dap An ================\n");
	tinhToanDiaChiMang(byte1, byte2, byte3, byte4, subnet, bin);
	//pause
	printf("\n");
	system("pause");
}
//thân hàm con
void kiemTraLopCuaIP(int byte1, int byte2, int byte3, int byte4)
{
	if (byte1 >= 0 && byte1 <= 127)
		printf("\nLop: A");
	else if ((byte1 >= 128 && byte2 >= 0) && (byte1 <= 192 && byte2 <= 255))
		printf("\nLop: B");
	else if ((byte1 >= 192 && byte2 >= 0) && (byte1 <= 223 && byte2 <= 255 && byte3 <= 255))
		printf("\nLop: C");
	else if (byte1 >= 224 && byte1 <= 240)
		printf("\nLop: D");
	else if (byte1 >= 241 && byte1 <= 255)
		printf("\nLop: E");
	else
		printf("\nLop: khong xac dinh !");
}
void nhapVaoIPv4(int &byte1, int &byte2, int &byte3, int &byte4, int &subnet)
{
	printf("Nhap vao IPv4: ");
	scanf("%d%*c%d%*c%d%*c%d%*c%d", &byte1, &byte2, &byte3, &byte4, &subnet);
	printf("\nThong Tin IPv4 nhan duoc !\nIPv4: %d.%d.%d.%d\nSubnet: %d", byte1, byte2, byte3, byte4, subnet);
	kiemTraLopCuaIP(byte1, byte2, byte3, byte4);
}
void chuyenSangNhiPhan_DuaVaoMang(int byte,int n, int bin[])
{
	int dem = 0;
	//chuyen sang nhi phan
	while (byte>0)//byte1
	{
		bin[n--] = byte % 2;
		byte /= 2;
	}
}
void tinhToanDiaChiMang(int byte1, int byte2, int byte3, int byte4, int subnet, int bin[])
{
	//khởi tạo mảng
	for (int i = 0; i < SIZE; i++)
		bin[i] = 0;
	//chuyển các byte sang nhị phân
	chuyenSangNhiPhan_DuaVaoMang(byte1, 7, bin);
	chuyenSangNhiPhan_DuaVaoMang(byte2, 15, bin);
	chuyenSangNhiPhan_DuaVaoMang(byte3, 23, bin);
	chuyenSangNhiPhan_DuaVaoMang(byte4, 31, bin);
	//tìm netword_id thông qua subnet
	int k = 0;
	for (; k < subnet; k++);
	//tính toán địa chỉ mang
	for (int i = 31; i >= k; i--)
		bin[i] = 0;
	int kq[4];//lưu kết quả
	kq[0] = chuyenBinarySangDecimal(bin, 7);
	kq[1] = chuyenBinarySangDecimal(bin, 15);
	kq[2] = chuyenBinarySangDecimal(bin, 23);
	kq[3] = chuyenBinarySangDecimal(bin, 31);
	printf("\n[>] IPv4 nam tren duong mang: ");
	for (int j = 0; j < 4; j++)
	{
		if (j == 1 || j == 2 || j == 3)
			printf(".");
		printf("%d",kq[j]);
	}
	printf("\nDang Nhi Phan cua duong mang: ");
	xuatBinary(bin);
	//tính toán broad cast
	for (int i = 31; i >= k; i--)
		bin[i] = 1;
	kq[0] = chuyenBinarySangDecimal(bin, 7);
	kq[1] = chuyenBinarySangDecimal(bin, 15);
	kq[2] = chuyenBinarySangDecimal(bin, 23);
	kq[3] = chuyenBinarySangDecimal(bin, 31);
	printf("\n[>] IPv4 co Broadcast la: ");
	for (int j = 0; j < 4; j++)
	{
		if (j == 1 || j == 2 || j == 3)
			printf(".");
		printf("%d", kq[j]);
	}
	printf("\nDang Nhi Phan cua BroadCast: ");
	xuatBinary(bin);
}
int chuyenBinarySangDecimal(int bin[], int n)
{
	int tong = 0;
	for (int i = n, dem = 0; dem != 8; i--, dem++)
	{
		if (bin[i] == 1)
			tong += (int)pow(2.0, dem);
			
	}
	return tong;
}
void xuatBinary(int bin[])
{
	//printf("\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d", bin[i]);
		if (i == 7 || i == 15 || i == 23)
			printf(".");
	}	
	printf("\n");
}
