#include<stdio.h>
int main(){
	char str[500];
	printf("Enter string: ");
	scanf("%s",&str);
	int n=0;
	while (str[n]!='\0') n++;
	
	for (int i=0;i<n/2;i++){
		char temp = str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=temp;

	}
printf("Reversed String: %s",str);

}