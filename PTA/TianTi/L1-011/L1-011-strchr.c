#include<stdio.h>
#include<string.h>
int main(){
	char a[100000],b[100000];
	gets(a);
	gets(b);
	for(int i=0;i<strlen(a);i++)
	{
		if(strchr(b,a[i]))
			continue;
		else 
			printf("%c",a[i]);
	}
	return 0;
}