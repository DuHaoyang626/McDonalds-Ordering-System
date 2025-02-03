#include<stdio.h>
#include"testc.h"
void testb(int,int);
int main() {
    void testa();
    printf("main\n");
    testa();
    testb(1,1);
    testc();
    return 0;
}
