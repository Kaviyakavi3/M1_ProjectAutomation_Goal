#include<stdio.h>
#include<string.h>
int main()
{
	char str1[]="1234";
	char str2[4];
	printf("Enter password:");
	scanf("%s",&str2);
	if(strcmp(str1,str2)==0)
	{
		printf("correct password");
	}
	else
	{
		printf("wrong password");
	}
	return 0;
}
