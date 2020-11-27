struct patient {
    int date;
    char month[25];
    int year;
    char name[255];
    patient *next, *prev;
}*head, *tail;
