
#include "jam.h"
#include "boolean.h"
#include <stdio.h>


void print_bool(boolean B){

    if (B) {
        printf("true");
    }
    else {
        printf("false");
    }
    }

void print_jam(JAM J){
       printf("%02d:%02d:%02d", Hour(J), Minute(J), Second(J));
   }
void print_long(long L){
       printf("%ld",L);
   }

int main(){

    JAM jam1, jam2;
    long N;

    BacaJAM(&jam1);
    BacaJAM(&jam2);
    TulisJAM(jam1);
    TulisJAM(jam2);

    N = JAMToDetik (jam1);
    printf("\n jam to detik test : ");
    print_long(N);

    jam1 = DetikToJAM (36000000);
    printf("\n detik to jam test : ");
    print_jam(jam1);

    JEQ (jam1, jam2);
    printf("\n JEQ test : ");
    print_bool(JEQ (jam1, jam2));

    JNEQ (jam1, jam2);
    printf("\n JNEQ test : ");
    print_bool(JNEQ (jam1, jam2));

    JLT (jam1, jam2);
    printf("\n JLT test : ");
    print_bool(JLT (jam1, jam2));

    JGT (jam1, jam2);
    printf("\n JGT test : ");
    print_bool(JGT (jam1, jam2));

    jam1 = NextDetik (jam1);
    printf("\n Next1 test : ");
    print_jam(jam1);

    jam1 = NextNDetik (jam1, 30);
    printf("\n NextN test : ");
    print_jam(jam1);

    jam1 = PrevDetik (jam1);
    printf("\n prev1 test : ");
    print_jam(jam1);

    jam1 = PrevNDetik (jam1, 30);
    printf("\n prevN test : ");
    print_jam(jam1);

    printf("\n jam 1 : ");
    print_jam(jam1);
    printf("\n jam 2 : ");
    print_jam(jam2);

    long dur = Durasi (jam1, jam2);
    printf("\n durasi test : ");
    print_long(dur);



    return 0;
}
