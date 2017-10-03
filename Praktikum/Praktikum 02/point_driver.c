
#include "point.h"
#include <stdio.h>

void print_bool(boolean B){

    if (B) {
        printf("true");
    }
    else {
        printf("false");
    }
    }

void print_point(POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
    }


int main(){

    POINT p1;
    BacaPOINT(&p1);

    POINT p2;
    BacaPOINT(&p2);

    TulisPOINT(p2);

    EQ(p1, p2);
    printf("\nEQ test: ");
    print_bool(EQ(p1, p2));

    NEQ(p1,p2);
    printf("\nNEQ test: ");
    print_bool(NEQ(p1,p2));

    IsOrigin(p1);
    printf("\norigin test: ");
    print_bool(IsOrigin(p1));

    IsOnSbX(p1);
    printf("\nsbx test: ");
    print_bool(IsOnSbX(p1));

    IsOnSbY(p1);
    printf("\nsby test: ");
    print_bool(IsOnSbY(p1));

    int kuad = Kuadran(p1);
    printf("\n kuad test: ");
    printf("%d",kuad);


    POINT p;
    float f;
    p = NextX(p1);
    printf("\n nextX test: ");
    print_point(p);

    p = NextY(p1);
    printf("\n nextY test: ");
    print_point(p);

    p = PlusDelta(p1,10,10);
    printf("\n plus test: ");
    print_point(p);

    p = MirrorOf(p1, true);
    printf("\n mirrorof test: ");
    print_point(p);

    f = Jarak0(p1);
    printf("\n Jarak test: ");
    printf("%f",f);

    f = Panjang(p1, p2);
    printf("\n Panjang test: ");
    printf("%f",f);


    Mirror(&p1, true);
    printf("\n Mirror test: ");
    print_point(p1);

    Geser(&p1, 10, 10);
    printf("\n Geser test: ");
    print_point(p1);

    printf("\n sebelum putar test: ");
    print_point(p1);
    Putar(&p1, 90);
    printf("\n putar test: ");
    print_point(p1);

    GeserKeSbX(&p1);
    printf("\n GeserX test: ");
    print_point(p1);

    GeserKeSbY(&p1);
    printf("\n GeserY test: ");
    print_point(p1);





return 0;
}
