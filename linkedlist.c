#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;//variabila globala
void Insert(int x) {

}
void Print();

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
