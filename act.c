#include<stdio.h>
int sum(int n) {
	if (n < 1) return 0;
	return sum(n - 1) * (n - 1) + n;
}
		int main()
        {
            printf("%d",sum(5));
        }
