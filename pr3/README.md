# Отчет по практической работе №3
### 1 Введение
Целью данной работы является ознакомление и получение первичных навыков взаимодействия с односвязными списками.

Шаги выполнения лабораторной работы представлены ниже:

1.Должны быть выполнены предыдущие работы

2.Прочитать про односвязные списки на СИ

3.Написать программу

4.Настроить pipeline

5.Написать отчет по работе в разметке Markdown (README.md)

6.Залить на gitlab и убедиться, что pipeline проходит успешно

7.Защитить работу у преподавателя

Требуется создать программу с функциями, которые представлены в таблице 1.

Таблица 1 - Функции
| Номер | Задание |
| ------------- | ------------- |
| 1 | Считывание количества элементов n, 0 < n <= 2147483647; |
| 2 | Создание пустого списка, считывание n элементов a, a <= 2147483647 и заносение их в список; |
| 3 | Вывод содержимого списка, используя функцию print; |
| 4 | Считывание k1, k2, k3 (k <= 2147483647) и вывод "1", если в списке существует элемент с таким значением и "0", если нет (вывод через пробел, например "1 0 1"); |
| 5 | Считывание m, m <= 2147483647 и вставка его в конец списка; |
| 6 | Вывод содержимого списка, используя функцию print; |
| 7 | Считывание t, t <= 2147483647 и вставка его в начало списка; |
| 8 | Вывод содержимого списка, используя функцию print; |
| 9 | Считывание j и x (0 < j <= 2147483647, x <= 2147483647) и вставка значения x после j-ого элемента списка; |
| 10 | Вывод содержимого списка, используя функцию print; |
| 11 | Считывание z, z <= 2147483647 и удаление первого элемента (при его наличии), хранящий значение z из списка; |
| 12 | Вывод содержимого списка, используя функцию print; |
| 13 | Очищение списка |


### 2 Ход работы
#### 2.1 Работа с кодом
Используя IDE Visual Studio и CLion напишем коды программ.

Ниже приведен фрагмент кода, отвечаюший за значение,которое хранит узел, а также ссылку на следующий элмент списка
```с
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
int value; // значение, которое хранит узел
struct node *next; // ссылка на следующий элемент списка
} node;
```
Ниже приведен фрагмент кода отвечающий за начало списка, инициализацию списка, удаление всех элементов из списка и проверки на пустоту
```с
typedef struct list {
struct node *head; // начало списка
} list;
// инициализация пустого списка
void init(list *l) {
l -> head = NULL;
return;
}
// удалить все элементы из списка
void clean(list *l) {
if (! l -> head) {
return;
}
node *current = l->head;
node *temp;
while (current) {
temp = current->next;
free(current);
current = temp;
}
l->head = NULL;
return;
}
// проверка на пустоту списка
bool is_empty(list *l) {
if(l -> head == NULL) {
return true;
}
return false;
}
```
Приведенный фрагмент кода ниже отчечает за поис элемента по значению 
```c
// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int key) {
node *current = l -> head;
if(! l -> head) {
return NULL;
}
while(current -> value != key) {
current = current -> next;
if(current == NULL) {
return NULL;
}
}
return current;
}
node* FindTail(list *l) {
if(l -> head == NULL) {
return NULL;
}
node *current = l -> head;
while(current -> next != NULL) {
current = current -> next;
}
return current;
}
```
Приведенный код ниже отвечает, за вставку значения в конец списка, вставка значения в начало списка, вставка значения после указанного узла.
```C
// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int key) {
if (! is_empty(l)) {
node *lastnode = FindTail(l);
node *current = malloc(sizeof(node));
lastnode -> next = current;
current -> next = NULL;
current -> value = key;
}
else {
node *current = malloc(sizeof(node));
current -> value = key;
current -> next = NULL;
l -> head = current;
}
return 0;
}
// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int key) {
node *current;
current = malloc(sizeof(node));
current -> value = key;
current -> next = l -> head;
l -> head = current;
return 0;
}
// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int key) {
if(n == NULL) {
return 1;
}
node *NewNode = malloc(sizeof(node));
NewNode -> value = key;
NewNode -> next = n -> next;
n -> next = NewNode;
return 0;
}
```
Приведенный фрагмент кода ниже отвечает, за удаление первого элемента из списка.
```c
// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_node(list *l, int key) {
node *current = l -> head;
node *previous = NULL;
if(l -> head == NULL) {
return 1;
}
while(current -> value != key) {
if(current -> next == NULL) {
return 1;
}
else {
previous = current;
current = current -> next;
}
}
if(current == l -> head) {
l -> head = l -> head -> next;
}
else {
previous -> next = current -> next;
}
free(current);
return 0;
}
```
Приведенный фрагмент кода ниже отвечает, за вывод всех значений из списка в прямом порядке через пробел.
```c
// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l) {
node *current = l -> head;
if (current == NULL) {
return;
}
while(current != NULL) {
printf("%d ", current-> value);
current = current -> next;
}
printf("\n");
return;
}
void checkingexist(node *n1, node *n2, node *n3) {
if(n1 == NULL) {
printf("0 ");
}
else {
printf("1 ");
}
if(n2 == NULL) {
printf("0 ");
}
else {
printf("1 ");
}
if(n3 == NULL) {
printf("0 ");
}
else {
printf("1 \n");
}
}
node *findbyindex(list *l, int index) {
if(l -> head == NULL) {
return NULL;
}
node *current = l -> head;
int i = 0;
while(i != index) {
current = current -> next;
if(current == NULL) {
return NULL;
}
i++;
}
return current;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
int i, n, k1, k2, k3, m, t, j, x, z, a;
(void) scanf("%d", &n);
list *link;
link = malloc(sizeof(list));
init(link);
for(i = 1; i <= n; i++) {
(void) scanf("%d", &a);
push_back(link, a);
}
print(link);
(void) scanf("%d %d %d", &k1, &k2, &k3);
node *finder1 = find(link, k1);
node *finder2 = find(link, k2);
node *finder3 = find(link, k3);
checkingexist(finder1, finder2, finder3);
(void)scanf("%d", &m);
push_back(link, m);
print(link);
(void)scanf("%d", &t);
push_front(link, t);
print(link);
(void) scanf("%d %d", &j, &x);
node *FindNode = findbyindex(link, j - 1);
insert_after(FindNode, x);
print(link);
(void) scanf("%d", &z);
remove_node(link, z);
print(link);
clean(link);
link -> head = NULL;
return 0;
}
```
Результат работы программы Представлен на рисунке 1.

![](https://sun9-33.userapi.com/impf/uuvM8Iqnf4pqBv8LkrweFvjEeqrwvecli-eNjw/9bvkSsdDe6M.jpg?size=678x194&quality=96&sign=06713cc24c3dd28bc408d6bf8a4fe335&type=album)

Рисунок 1 — Результат работы программы

Изначально вводится количество элементов. Далее, вводятся значения элементов и заносятся в список. С помощью функции print эти данные выводятся. Вводится три значения и выводит "1", если в списке существует элемент с таким значением и "0", если нет. Далее вводится значение, которое встанет на 0-ое место в списке, а также значения, которое встанет на последнее место в списке. Считывает j и x и вставляет значение x после j-ого элемента списка. Далее считывает z, и удаляет z-й элемент.

#### 2.2 Работа с GitLab

Внесем последние в локальный проект и перешлем его в GitLab (commit and push).
Результаты проверки представлены на рисунке 3.

Рисунок 3 — Результаты pipeline-проверки

![](https://sun9-52.userapi.com/impf/Ar78Sxhmp1m5iauJiVpWjKXCFv0KjKsNoGbA3w/p52-dNR38Jc.jpg?size=227x215&quality=96&sign=6ebc8a49778792a6be61314d982b037c&type=album)

### 3 Заключение
В ходе выполнения практической работы, были изучены основы односвязных списков, а также успешно разработаны программы, заданные вариантом.

### 4 Приложение А
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
int value; // значение, которое хранит узел
struct node *next; // ссылка на следующий элемент списка
} node;
typedef struct list {
struct node *head; // начало списка
} list;
// инициализация пустого списка
void init(list *l) {
l -> head = NULL;
return;
}
// удалить все элементы из списка
void clean(list *l) {
if (! l -> head) {
return;
}
node *current = l->head;
node *temp;
while (current) {
temp = current->next;
free(current);
current = temp;
}
l->head = NULL;
return;
}
// проверка на пустоту списка
bool is_empty(list *l) {
if(l -> head == NULL) {
return true;
}
return false;
}
// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int key) {
node *current = l -> head;
if(! l -> head) {
return NULL;
}
while(current -> value != key) {
current = current -> next;
if(current == NULL) {
return NULL;
}
}
return current;
}
node* FindTail(list *l) {
if(l -> head == NULL) {
return NULL;
}
node *current = l -> head;
while(current -> next != NULL) {
current = current -> next;
}
return current;
}
// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int key) {
if (! is_empty(l)) {
node *lastnode = FindTail(l);
node *current = malloc(sizeof(node));
lastnode -> next = current;
current -> next = NULL;
current -> value = key;
}
else {
node *current = malloc(sizeof(node));
current -> value = key;
current -> next = NULL;
l -> head = current;
}
return 0;
}
// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int key) {
node *current;
current = malloc(sizeof(node));
current -> value = key;
current -> next = l -> head;
l -> head = current;
return 0;
}
// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int key) {
if(n == NULL) {
return 1;
}
node *NewNode = malloc(sizeof(node));
NewNode -> value = key;
NewNode -> next = n -> next;
n -> next = NewNode;
return 0;
}
// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_node(list *l, int key) {
node *current = l -> head;
node *previous = NULL;
if(l -> head == NULL) {
return 1;
}
while(current -> value != key) {
if(current -> next == NULL) {
return 1;
}
else {
previous = current;
current = current -> next;
}
}
if(current == l -> head) {
l -> head = l -> head -> next;
}
else {
previous -> next = current -> next;
}
free(current);
return 0;
}
// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l) {
node *current = l -> head;
if (current == NULL) {
return;
}
while(current != NULL) {
printf("%d ", current-> value);
current = current -> next;
}
printf("\n");
return;
}
void checkingexist(node *n1, node *n2, node *n3) {
if(n1 == NULL) {
printf("0 ");
}
else {
printf("1 ");
}
if(n2 == NULL) {
printf("0 ");
}
else {
printf("1 ");
}
if(n3 == NULL) {
printf("0 ");
}
else {
printf("1 \n");
}
}
node *findbyindex(list *l, int index) {
if(l -> head == NULL) {
return NULL;
}
node *current = l -> head;
int i = 0;
while(i != index) {
current = current -> next;
if(current == NULL) {
return NULL;
}
i++;
}
return current;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
int i, n, k1, k2, k3, m, t, j, x, z, a;
(void) scanf("%d", &n);
list *link;
link = malloc(sizeof(list));
init(link);
for(i = 1; i <= n; i++) {
(void) scanf("%d", &a);
push_back(link, a);
}
print(link);
(void) scanf("%d %d %d", &k1, &k2, &k3);
node *finder1 = find(link, k1);
node *finder2 = find(link, k2);
node *finder3 = find(link, k3);
checkingexist(finder1, finder2, finder3);
(void)scanf("%d", &m);
push_back(link, m);
print(link);
(void)scanf("%d", &t);
push_front(link, t);
print(link);
(void) scanf("%d %d", &j, &x);
node *FindNode = findbyindex(link, j - 1);
insert_after(FindNode, x);
print(link);
(void) scanf("%d", &z);
remove_node(link, z);
print(link);
clean(link);
link -> head = NULL;
return 0;
}
```
