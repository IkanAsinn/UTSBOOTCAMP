#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../model/model.h"

patient* createNewPatient(int date, char* month, int year, char* name) {
    patient* newPatient = (patient*)malloc(sizeof(patient));
    newPatient->date = date;
    strcpy(newPatient->month, month);
    newPatient->year = year;
    strcpy(newPatient->name, name);
    newPatient->next = newPatient->prev = NULL;
    return newPatient;
}

int getIndexMonth(char* month) {
    char getMonth[12][255] = {{"january"},{"february"},{"march"},{"april"},{"may"},{"june"},{"july"},{"august"},{"september"},{"october"},{"november"},{"desember"}};
    for (int i = 0; i < 12; i++){
        if (strcmp(getMonth[i], month) == 0){
            return i;
        }
    }
}

void pushPatient(int date, char* month, int year, char* name) {
    patient* newPatient = createNewPatient(date, month, year, name);
    if (!head)
        head = tail = newPatient;

    else
    {
        patient* curr = head;
        while(curr && curr->year > year)
            curr = curr->next;
        
        if (curr == head)
        {
            head->prev = newPatient;
            newPatient->next = head;
            head = newPatient;
        }
        else if (curr == tail)
        {
            tail->next = newPatient;
            newPatient->prev = tail;
            tail = newPatient;
        }
        else
        {
            curr->prev->next = newPatient;
            newPatient->prev = curr->prev;
            curr->prev = newPatient;
            newPatient->next = curr;
        }
        
    }
    
}

void popTail() {
    if (head == tail)
    {
        free(head);
        head = NULL;
    }
    else
    {
        patient* temp = tail->prev;
        tail = NULL;
        free(tail);
        tail = temp;
        tail->next = NULL;
    }
    
}

void popData(int index) {
    patient* curr = head;
    while(index > 0)
    {
        popTail();
        index--;
    }
    
}

void printData() {
    if (!head)
        return;
    else
    {
        patient* curr = head;
        while(curr)
        {
            printf ("%d %s %d - %s\n", curr->date, curr->month, curr->year, curr->name);
            curr = curr->next;
        }
    }
    
}
