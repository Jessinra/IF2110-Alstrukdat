
#include "prioqueue.h"
#include <stdio.h>


int main (void){

	Queue Antri;
	infotype element;

	CreateEmpty(&Antri,5);
	PrintQueue(Antri);

	element.prio = 3;
	element.info = 5;
	Add(&Antri, element);
	PrintQueue(Antri);

	element.prio = 6;
	element.info = 2;
	Add(&Antri, element);
	PrintQueue(Antri);

	element.prio = 2;
	element.info = 1;
	Add(&Antri, element);
	PrintQueue(Antri);

	element.prio = 1;
	element.info = 5;
	Add(&Antri, element);
	PrintQueue(Antri);

	element.prio = 2;
	element.info = 5;
	Add(&Antri, element);
	PrintQueue(Antri);

	Del(&Antri, &element);
    PrintQueue(Antri);
    Del(&Antri, &element);
    PrintQueue(Antri);
    Del(&Antri, &element);
    PrintQueue(Antri);
    Del(&Antri, &element);
    PrintQueue(Antri);


	element.prio = 4;
	element.info = 5;
	Add(&Antri, element);
	PrintQueue(Antri);



    element.prio = 1;
	element.info = 55;
	Add(&Antri, element);
	PrintQueue(Antri);

return 0;
}
