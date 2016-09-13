#include "stdio.h"

int main(void) {

    int c = 1, n, i, a, b;
    char j1[11], j2[11];
    scanf("%d", &n);
    while (n != 0) {
    	printf("Teste %d\n", c);
    	
    	scanf("%s\n%s", &j1, &j2);
    		
    	for (i = 0; i < n; i++) {
    		scanf("%d %d", &a, &b);
    		if ((a + b) % 2 == 0) {
    			printf("%s\n", j1);
    		}
    		else {
    			printf("%s\n", j2);
    		}
    	}
    	
    	printf("\n");
    	scanf("%d", &n);	
    	c++;
    }
    
    return 0;
}
