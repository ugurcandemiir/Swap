#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap_simple(int *aptr,int *bptr);
void swap_xorbit(int *aptr,int *bptr);
void swap_xorword(int *aptr,int *bptr);
void flipBit(int *aptr,int i);
int getBit(int *aptr, int i);

int main(int argc, char **argv) {
    if (argc<3) {
        printf("Invoke as %s <a> <b>\n",argv[0]);
        return 1;
    }
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    printf("A=%d B=%d\n",a,b);
    swap_simple(&a,&b);
    printf("After simple swap, A=%d B=%d\n",a,b);
    swap_xorbit(&a,&b);
    printf("After xor bit swap, A=%d B=%d\n",a,b);
    swap_xorword(&a,&b);
    printf("After xor word swap, A=%d B=%d\n",a,b);
    return 0;
}

void swap_simple(int *aptr,int *bptr) {
    /* Your code goes here */
    int t = *aptr;
    *aptr = *bptr;
    *bptr = t;
}

void swap_xorbit(int *aptr,int *bptr) {
    /* Your code goes here */
    for (int i = 0  ; i < sizeof(int)* CHAR_BIT ; i++){
        if (getBit(aptr,i)!=getBit(bptr,i)) {
            flipBit(aptr,i);
            flipBit(bptr,i);
        }
    }
}

void swap_xorword(int *aptr,int *bptr) {
    /* Your code goes here */
    *aptr = *aptr ^ *bptr;
    *bptr = *aptr ^ *bptr;
    *aptr = *aptr ^ *bptr;
}
void flipBit(int *aptr,int i) { (*aptr) ^= 1<<i; } //flip the ith bit
int getBit(int *aptr, int i) {
    
    if (((*aptr) & (1<< i)) != 0 ){
        i = 1;
    }else{
        i = 0;
    }
    return i;
}
