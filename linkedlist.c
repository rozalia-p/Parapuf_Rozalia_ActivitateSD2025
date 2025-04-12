#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head; // variabila globala

void Insert(int x) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print() {
    struct Node* temp = head;
    printf("Lista este:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL; // lista este goala la început
    int n, x;

    printf("Cate numere?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Introduceti numarul:\n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}
