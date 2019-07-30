#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _user{
    struct _user *next;
    char name[101];
}user;

int main() {
    int N;
    user members[201];
    for(int i=0; i<201; ++i){
        members[i].next = NULL;
    }

    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        int age;
        char name[101];
        scanf("%d%s", &age, name);
        user *temp = malloc(sizeof(user));
        strcpy(temp->name, name);
        temp->next = NULL;

        user *ptr = &(members[age]);
        while(ptr->next != NULL){
            ptr = ptr -> next;
        }
        ptr -> next = temp;
    }

    for(int i=1; i<=200; ++i){
        user *temp = members[i].next;
        while(temp != NULL){
            printf("%d %s\n", i, (*temp).name);
            temp = temp->next;
        }
    }

    return 0;
}
