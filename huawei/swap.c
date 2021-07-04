#include <stdio.h>
 
int* myfunc(int* p, int nSize) {
    int i, j;
    for (i = 0, j = 0; j < nSize; j++) {
        if (p[j] != 0) {
            p[i++] = p[j];
        }
    }
    while (i < nSize) {
        p[i++] = 0;
    }
    return p;
}
 
int main() {
    int p[] = { 1, 3, 0, 2, 5, 0, 0, 0, 3, 6, 1, 7 };
    int num;
    int i;
    num = sizeof(p) / sizeof(int);
    myfunc(p, num);
    for (i = 0; i < num; i++) {
        printf("%d ", p[i]);
    }
    puts("");
}
