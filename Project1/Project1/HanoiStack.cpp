#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct StackNode {
	int n;
	char from, tmp, to;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType *s)
{
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType *s)
{
	return 0;
}
// 삽입 함수  수정완
void push(int n, char from, char tmp, char to, LinkedStackType *s)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	temp->n = n;
	temp->from = from;
	temp->tmp = tmp;
	temp->to = to;
	temp->link = s->top;
	s->top = temp;
}

void pStack(int n, char from, char tmp, char to) {
	printf(" ____________________\n");
	printf("|Pointer|  n    = %d |\n", n);
	printf("|       |  from = %c |\n", from);
	printf("|       |  tmp  = %c |\n", tmp);
	printf("|       |  to   = %c |\n", to);
	printf(" ￣￣￣￣￣￣￣￣￣￣\n");
	printf("  ↓  \n");


}


// 수정일단 함 괜찮은지 모름
void print_stack(LinkedStackType *s)
{
	printf("                      top\n");

	for (StackNode *p = s->top; p != NULL; p = p->link)
		pStack(p->n, p->from, p->tmp, p->to);

	printf("NULL \n");
	printf("_____________________________\n");
}
// 삭제 함수  수정완
void pop(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode *temp = s->top;
		s->top = s->top->link;
		free(temp);
	}
}


void hanoi_tower(int n, char from, char tmp, char to, LinkedStackType *s)
{
	push(n, from, tmp, to, s);
	print_stack(s);
	if (n == 1) {
		pop(s);
		print_stack(s);
	}
	else {

		hanoi_tower(n - 1, from, to, tmp, s);
		hanoi_tower(n - 1, tmp, from, to, s);
		pop(s);
		print_stack(s);
	}
}



int main(void) {
	LinkedStackType stack;
	init(&stack);

	hanoi_tower(3, 'A', 'B', 'C', &stack);

	return 0;
}