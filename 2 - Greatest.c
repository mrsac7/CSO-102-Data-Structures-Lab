#include<stdio.h>
#include<math.h>

int main() {
	int n, a[500];
	printf("Enter size of array: ");
	scanf("%d", &n); printf("Enter numbers: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
	}
	int mx = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > mx)
			mx = a[i];
	}
	printf("Greatest Element: %d\n", mx);
}
