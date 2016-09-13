#include "stdio.h"

int main(void) {

    int n, i, m = 0, am = 0, ln, an;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
    	scanf("%d", &an);
    	if (an == ln) {
    		am++;
    	}
    	else {
    		ln = an;
    		am = 1;
    	}
      if (am > m) {
        m = am;
      }
    }
    printf("%d\n", m);
    
    return 0;
}
