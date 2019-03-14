#include <stdio.h>
void insert(char x, char A[], int length) {
	int j = length - 1;
	while (j >= 0 && A[j] > x) {
		A[j + 1] = A[j];
		j--;
	}
	A[j + 1] = x;
}

void pa(char a[], int length) {
	int j;
	for (j = 0; j < length; j++) printf("a[%d] is %c \n", j, a[j]);
}
int main(int argc, char * argv[]) {
	char A[20];
	int i = 0;
	
	insert('b', A, i);
	i++;

	insert('d', A, i);
	i++;

	insert('a', A, i);
	i++;
	pa(A, i);
	getchar();
	return 0;
}

