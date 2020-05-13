#include<stdio.h>
#include<math.h>

int main() {
	int n, a[500], s, g;
	printf("Enter size of array: ");
	scanf("%d", &n); printf("Enter numbers: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i == 0) {
			s = a[i]; g = a[i];
		}
		if (a[i] < s) {
			s = a[i];
		}
		if (a[i] > g) {
			g = a[i];
		}
	}
	if (s == g) {
		printf("No 2nd greatest element");
	} else {
		for (int i = 0; i < n; i++) {
			if (a[i] > s and a[i] < g) s = a[i];
		}
		printf("2nd greatest element: %d\n", s);
	}
}
