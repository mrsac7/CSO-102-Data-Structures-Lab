#include<stdio.h>
#include<math.h>
int main(){
	int amp,star,k;
	int i,j;
	scanf("%d%d",&amp,&star);
	for (int i=0;i<star;i++){
		k=(amp+10)+(amp*sin(6.28*i/(star-1)));
		for (int j=1;j<k;j++)
			printf(" ");
			printf("*\n");
	}
}