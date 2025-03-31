#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;//variabila globala
void Insert(int x) {
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;

}
void Print() {
	struct Node* temp = head;
	printf("List is: ");
	while (temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
};

int main() {
	head = NULL; // lista goala
	printf("Cate numere?\n");
	int n, i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Introduceti numarul \n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
}
