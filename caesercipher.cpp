#include<stdio.h>
#include<string.h>
void nhapVaoChuoi(int &n,char *str);
void cipherCaeser(char *str, int key, char mode);
void cuaQuyDat(char *str, int key);
void theoCT(char *str, int key, char mode);
int timViTriChar(char c);
int main()
{
	char chuoi[35], mode='e';
	int key=0;
	
	nhapVaoChuoi(key,chuoi);
	printf("\nchuoi ban dau !\n");
	puts(chuoi);
	//cuaQuyDat(chuoi,key);
	//cipherCaeser(chuoi,key,mode);
	theoCT(chuoi,key,mode);
	if(mode == 'e')
		printf("\n[!] da ma hoa !\n");
	else if(mode == 'd')
		printf("\n[!] da giai ma! \n");
	puts(chuoi);
	return 0;
}

void cuaQuyDat(char *str, int key)
{
	int len = strlen(str);
	int tmp = 0;
	for(int i=0; i<len; i++)
	{
		if(str[i] - key < 97)
		{
			tmp = str[i] - 97;
			str[i] = 123 - (key - tmp);
		}
		else
			str[i] -= key;
	}
}
void nhapVaoChuoi(int &n,char *str)
{
	printf("Nhap vao chuoi can ma hoa: ");
	gets(str);
	fflush(stdin);
	printf("Nhap vao key Cipher Caeser: ");
	scanf("%d",&n);
}
void cipherCaeser(char *str, int key, char mode)
{
	//mode d -> decryption, e -> encryption
	char symbol[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int _len_symbol=strlen(symbol), _len_str = strlen(str), num=0, dem=0;
	strupr(str);
	printf("\n%s\n",str);
	//check mode
	if(mode == 'e')
		for(int i=0;i<_len_str;i++)
		{
			if(str[i] >='A' && str[i]<='Z')
			{
				str[i]+=key;
				if(str[i] <'A' || str[i] >'Z')
				{
					num=str[i]-'Z'-1;
					str[i]=symbol[num];
				}
			}
		}
	else
		if(mode == 'd')
		{
			for(int i=0;i<_len_str;i++)
			{
				if(str[i] >='a' && str[i]<='z' || str[i] >='A' && str[i]<='Z')
				{
					str[i] -= key;
					if(str[i] <'A' || str[i] > 'Z')
					{
						num= 25 - ('A' - str[i])+ 1;
						str[i]=symbol[num];
					}
				}
			}
		}
		else
			return;
}
int timViTriChar(char c)
{
	if(c<='a' && c >='z')
		c-=32;
	char symbol[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0;i<26;i++)
	{
		if(symbol[i]==c)
			return i;
	}
}
void theoCT(char *str, int key, char mode)
{
	//mode d -> decryption, e -> encryption
	char symbol[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int _len_symbol=strlen(symbol), _len_str = strlen(str), num=0, dem=0;
	strupr(str);
	//check mode
	if(mode == 'e')
		for(int i=0;i<_len_str;i++)
		{
			num=(timViTriChar(str[i]) + key)%26;
			str[i]=symbol[num];
		}
	else
		if(mode == 'd')
		{
			for(int i=0;i<_len_str;i++)
			{
				num=(timViTriChar(str[i]) - key)%26;
				str[i]=symbol[num];
			}
		}
		else
			return;
}