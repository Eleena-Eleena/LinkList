#include <stdio.h>
#include <locale.h>
#include <malloc.h>


typedef struct s_list {
	int field;
	struct s_list* next;
} list;

list* Element(list* p, int n) {

	if (p->field == n) {
		return p;
	}
	return Element(p->next,n);
}

int lenth(list* p, int count) {
	count++;
	if (p->next == (list*)-1)
		return count;
	return lenth(p->next, count);
}

int Lenth(list* p) {
	int count = 0;
	if (p->field != 0)
		return 0;
	return lenth(p, count);
}

list* list1(int i,int t) {
	list* p = (list*)malloc(sizeof(list));
	p->field = i;
	if (i == t) {
		p->next = (list*) - 1;
		return p;
	}
	p->next = list1(++i,t);
	return p;
}

list* CrateList(int t) {
	int i = 0;
	return  list1(0,t-1);
}

list* AddElement(list* p,int n){
	if (n == 0) {
		list* p1 = Element(p, n);
		list* p3 = (list*)malloc(sizeof(list));
		p3->field = n;
		p3->next = p1;
		p = p3;
		return p;
	}
	else if (n == Lenth(p)) {
		list* p1 = Element(p, n-1);
		list* p3 = (list*)malloc(sizeof(list));
		p3->field = n;
		p3->next = (list*)-1;
		p1->next = p3;
		return p;
	}
	else {
		list* p1 = Element(p, n - 1);
		list* p2 = p1->next;
		list* p3 = (list*)malloc(sizeof(list));
		p3->field = n;
		p1->next = p3;
		p3->next = p2;
		return p;
	}
}

void Show(list* p) {
	printf("%d ",p->field);
	if (p->next == (list*)-1) {
		return;
	}
	Show(p->next);
}

void Replace(list* p,int a,int c) {
	list* p1 = Element(p, a);
	list* p2 = Element(p, c);
	int field = p1->field;
	p1->field = p2->field;
	p2->field = field;
}

void update(list* p, int count) {
	p->field = count;
	if (p->next == (list*)-1) {
		return;
	}
	update(p->next, ++count);
}

void Update(list* p) {
	int count = 0;
	p->field = count;
	if (p->next == (list*)-1) {
		return;
	}
	update(p->next, ++count);
}
list* DeleteElement(list* p, int d) {
	if (d == 0) {
		list* p1 = Element(p, d);
		list* p2 = p1->next;
		p = p2;
		free(p1);
		return p;
	}
	else if (d == Lenth(p)-1) {
		list* p1 = Element(p, d - 1);
		list* p2 = p1->next;
		p1->next = (list*)-1;
		free(p2);
		return p;
	}
	else {
		list* p1 = Element(p, d-1);
		list* p2 = p1->next;
		list* p3 = p2->next;
		p1->next = p3;
		free(p2);
		return p;
	}
}
int CheckIn(int l) {
	int m = 0;
	int i = scanf("%d", &m);
	if (i == 0 ||m == EOF || m < 0 || m > l) {
		printf("\nНеверно набрано число \n");
		while ((m = getchar()) != EOF && m != '\n');
		return -1;
	}
	return m;
}

int CheckIn1() {
	int m = 0;
	int i = scanf("%d", &m);
	if (i == 0 || m == EOF || m < 0) {
		printf("\nНеверно набрано число \n");
		while ((m = getchar()) != EOF && m != '\n');
		return -1;
	}
	return m;
}

void DeleteList(list* p) {
	Update(p);
	int l = Lenth(p) - 1;
	for (int i = l; i > 0; i--)
	{
		list* p1 = Element(p, i);
		free(p1);
	}
}

void main()
{
	system("chcp 1251>nul");

	int t,n,a,c,d = 0;
lab0:	printf("\nВведите размер массива = ");
	t = CheckIn1();
	if (t == -1)
		goto lab0;
	list* p = CrateList(t);
	Show(p);


lab1:	printf("\nВведите номер для добавления = ");
	n = CheckIn(Lenth(p));
	if (n == -1)
		goto lab1;
	p = AddElement(p,n);
	Show(p);


lab2:	printf("\nПервый номер для перемещения = ");
	a = CheckIn(Lenth(p));
	if (a == -1)
		goto lab2;
lab3:	printf("Второй номер для перемещения = ");
	c = CheckIn(Lenth(p));
	if (c == -1)
		goto lab3;
	Update(p);
	Replace(p,a,c);
	Show(p);

lab4:	printf("\nУдалить номер элемента = ");
	int l = Lenth(p) - 1;
	d = CheckIn(l);
	if (d == -1)
		goto lab4;
	Update(p);
	printf("\nДо удаления: ");
	Show(p);
	printf("\n");
	p = DeleteElement(p, d);
	printf("\nПосле удаления: ");
	Show(p);

	DeleteList(p);
	printf("\nЛист удален.");

}