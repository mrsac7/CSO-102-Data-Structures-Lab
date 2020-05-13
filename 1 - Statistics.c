#include<stdio.h>
#include<math.h>

int main()
{
	int n,A[500];
	float mean=0.0;
	printf("Enter size of array: ");
	scanf("%d",&n);

	/*ARRAY INITIALISATION & MEAN CALCULATION
		Mean = (Sum of all ele)/(Total no.) */
	printf("\nEnter elements: ");
	for (int i=0;i<n;i++){
		scanf("%d",&A[i]);
		mean+=A[i];
	}
	mean/=n; //mean value
	printf("\nMean: %0.2f",mean);


	//BUBBLE SORT
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (A[j+1]<A[j]){
				int temp=A[j];
				A[j]=A[j+1]; A[j+1]=temp;
			}
		}
	}
	

	/*MEDIAN CALCULATION
		1. If n is odd => Median = Middle element
		2. If n is even => Median = Avg of (n/2)th and ((n+1)/2)th elements */

	float median;
	if ((n-1)%2==1) median= float (A[(n-1)/2]+A[n/2])/2;
	else median= A[(n-1)/2];
	printf("\nMedian: %0.2f",median);


	//MODE CALCULATION
	/*  1. Count Max frequency
		2. No. of unique elements */

	int mfreq=0,count=1,ele=0;
	for (int i=0;i<n;i++){
		if (i==n-1){
			if (A[i]==A[i-1] and mfreq<count) mfreq=count;
		}
		else{

		if (count==1) ele++;
		if (A[i]==A[i+1]) count++;
		else{
			if (mfreq<count) mfreq=count;
			count=1;
		}
		}
	}
	if (A[n-1]!=A[n-2]) ele++;

	/*  3. No Mode Conditions
			3.1) If Maximum frequency is n
			3.2) If frequency of all element is same */

	if (n==1 or mfreq==n or mfreq==1) printf("\nMode: None");
	else{
		count=1;
		int B[500];int m=0; //B stores modes
		for (int i=0;i<n;i++){
			if (i==n-1 and A[i]==A[i-1] and mfreq==count) {B[m]=A[i];m++;}
			else{
			if (A[i]==A[i+1]) count++;
			else{
				if (count==mfreq) {
					B[m]=A[i];
					m++;
					count=1;
				}
			}}
		}
		if (ele==m) printf("\nMode: None");

	// 4. All modes Calculation
		else{
			printf("\nMode: ");
			for (int i=0;i<m;i++) printf("%d ",B[i]);
		}
	}

	/* VARIANCE & STD. DEVIATION CALCULATION
		Var(x)= Sum((x-mean)*(x-mean))/n
		Std. Dev= sqrt(Var(x)) */
	float v=0,sd=0;
	for (int i=0;i<n;i++){
		v+= pow((A[i]-mean),2);
	}
	v/=n;
	sd= pow(v,0.5);
	printf("\nVariance: %0.2f\nStandard Deviation: %0.2f\n",v,sd);
}