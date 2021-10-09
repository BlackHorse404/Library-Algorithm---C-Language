
// Nguyen Van Thanh. k55cb.Dh cong nghe-DHQGHN
//Thu vien chuan :

#include<conio.h>
#include<math.h>
#include<iostream>
#include<string.h>

using namespace std;

// HAM :Cong 2 so nhi phan.( Co the cai tien bang cach nhap do dai tuy y cho mang 
// chua so nhi phan, su dung while va dieu kien dung ok).
void cong(int a[],int n, int b[],int m,int luu[],int &len)
{
	//Chu y: a[],b[] la hai mang the hien so nhi phan do dai tuong ung la n va m ; 
	//luu[] la mang ket qua co do dai tuong ung la len.

	int i=n-1,j=-1;//
	int tong,nho=0,tong2;
	int a1[100],b1[100],luu1[100];

	// Copy theo chieu nguoc lai cac mang so nhi phan ban dau sang mang moi a1,b1:

	for(i=n-1;i>=0;i--)
		a1[n-i-1]=a[i];
	for(i=m-1;i>=0;i--)
		b1[m-i-1]=b[i];

	//Them phan tu 0 vao sau mang a1 neu a1 co do dai nho hon:

	i=n-1;
	while ( i < m-1 ) 
	{
		i++;
		a1[i] = 0;
		n=m;
	}

	//Them phan tu 0 vao sau mang b1 neu b1 co do dai nho hon:

	j = m-1;
	while ( j < n-1 ) 
	{
		j++;
		b1[j]=0;
	}

	//Tien hanh cong lan luot: luu ket qua vao mang luu[]:

	for( i = 0 ; i < n ; i++)
	{
		tong =( a1[i] + b1[i] + nho );
		tong2 = tong % 2;
		nho = tong/2;
		luu1[i]= tong2;
	}
	len=n;//len: do dai mang ket qua se dc in ra.

	if (nho!=0 )
	{
		luu1[n]=1;
		len=n+1;
	}
	for(i=len-1;i>=0;i--)
		luu[len-1-i]=luu1[i];
	return ;
}
//Ham nhan hai so nhi phan:


//Ham main():

int main()
{
	int i,len,m,n,lent;
	int a[100],b[100],c[100],tich2[100];
	cout<<"so chu so cua so thu 1:";cin>>n;
	cout<<"\nso chu so cua so thu 2:";cin>>m;

	cout<<"\nNhap so thu 1:";
	for(i=0;i<n;i++) cin >> a[i];

	cout<<"\nNhap so thu 2:";
	for(i=0;i<m;i++) cin >> b[i];
	cong(a,n,b,m,c,len);
	cout<<"\ntong:";
	for(i=0;i<len;i++)cout<< c[i];

	getch();

}

//==========================
if (m < 0 && n > 0)//m âm n dương thoả n>m
		{
			m=abs(m);
			printf("Ket qua cong: -%ld\n", caculateBinaryMinus(bin1, bin2));
			printf("Ket qua tru: %ld\n", caculateBinaryAdd(bin1, bin2));
		}
		else
			if (n < m && n > 0 && m > 0)//n<m va n,m dương
			{

				printf("Ket qua cong: %ld\n", caculateBinaryAdd(bin1, bin2));
				printf("Ket qua tru: -%ld\n", caculateBinaryMinus(bin1, bin2));
			}
			else
				if (n<0 && m>0)//n dương m âm
				{
					n = abs(n);
					printf("Ket qua cong: %ld\n", caculateBinaryMinus(bin2, bin1));
					printf("Ket qua tru: -%ld\n", caculateBinaryAdd(bin1, bin2));
				}
				else// cả 2 đều âm
				{
					n = abs(n);
					m = abs(m);
					printf("Ket qua cong: -%ld\n", caculateBinaryAdd(bin1, bin2));
					if (n>m)
						printf("Ket qua tru: -%ld\n", caculateBinaryMinus(bin1, bin2));
					else
						printf("Ket qua tru: %ld\n", caculateBinaryMinus(bin2, bin1));
				}