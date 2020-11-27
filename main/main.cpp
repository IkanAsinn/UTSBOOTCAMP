#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../controller/controller.h"

int main() {

    int patient, cure;
    scanf ("%d %d", &patient, &cure); getchar();
    char name[255], month[25], str[255];
    int date, year;
    for (int i = 0; i < patient; i++)
    {
        scanf ("%d %s %d - %[^\n]", &date, month, &year, name); getchar();
        pushPatient(date, month, year, name);
    }

    popData(cure);
    if (patient > cure)
        printf ("Need %d more cure\n", patient - cure);
    
    printData();
    
    return 0;
}
