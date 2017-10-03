#include <stdio.h>
#include "arraypos.h"

void print_bool(boolean B){

    if (B) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    }

int main(void){

    TabInt T1,T2,TT;

    BacaIsi(&T1);
    TulisIsiTab(T1);

    printf("\nNeff : %d",NbElmt(T1));
    printf("\nFirst Idx : %d",GetFirstIdx(T1));
    printf("\nLast Idx : %d",GetLastIdx(T1));

    printf("\n test is valid \n");
    print_bool(IsIdxValid(T1, 50));
    printf("\ntest is eff \n");
    print_bool(IsIdxEff(T1, 50));
    printf("\ntest is empty \n");
    print_bool(IsEmpty(T1));

    printf("\ntest is full \n");
    print_bool(IsFull(T1));
    printf("\n");

    BacaIsi(&T2);
    TulisIsiTab(T2);
    printf("\n");
    TT = PlusMinusTab(T1,T2,true);
    TulisIsiTab(TT);
    printf("\n");
    TT = PlusMinusTab(T1,T2,false);
    TulisIsiTab(TT);
    printf("\n");

    printf("\ntest is eq \n");
    print_bool(IsEQ(T1,T2));

    printf("\ntest sort asc \n");
    Sort(&T1, true);
    TulisIsiTab(T1);

    printf("\ntest sort des \n");
    Sort(&T2, false);
    TulisIsiTab(T2);

    printf("\ntest is search \n");
    print_bool(SearchB(T1,100));
    printf("%d\n",Search1(T1,3));



    int max,min;
    MaxMin(T1,&max, &min);
    printf("\ntest maxmin %d %d \n",max,min);

    printf("\ntest sum \n");
    printf("%d\n",SumTab(T1));



return 0;
}
