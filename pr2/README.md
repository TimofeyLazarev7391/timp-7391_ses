## Отчет по практической работе №2
### 1 Введение
Целью данной работы является ознакомление и получение первичных навыков взаимодействия с однопроходными алгоритмами.


### 2 Задание

Задание:

1.Должна быть выполнена 1 практическая работа

2.Написать программы в соответствии с вариантом

3.Настроить pipeline

4.Составить блок-схемы программ

5.Написать отчет по работе в разметке Markdown (README.md)

6.Залить на gitlab и убедиться, что pipeline проходит успешно

7.Защитить работу у преподавателя

Требуется выполнить задание №8 и №18:
- Найти среднее арифметическое n-чисел.
- Найти сумму четных кубов n-чисел.

### 3 Ход работы
#### 3.1 Работа с кодом
Используя онлайн компилятор и CLion напишем коды программ.
Код для программы №1 выглядит следующим образом:
```с
#include <stdio.h>
int main() {
int n, x, count, i;
(void) scanf("%d", &n);
count = 0;
for (i = 1; i <= n; i++) {
(void) scanf("%d", &x);
if (x <= 0) {
count++;
}
}
printf("%d", count);
return 0;
}
```
Результат работы программы №1 представлен на рисунке 1.

<p align="center">

  <img width="450" height="250" src="https://sun9-74.userapi.com/impg/4rzV7wjcN8CO6ktY44GeZsFp94E22KOQHP15zQ/xtQqDpVK3ls.jpg?size=448x178&quality=96&sign=1a979fd264b10bbce7de772601d8ba24&type=album">
</p>
Рисунок 1 - Результат работы программы


Изначально в консоль в первую строку вводится количество чисел (в нашем случае - "3"). Далее мы вводим эти числа, и впоследствии выводится количесвто чисел, которые меньше либо равно 0.

Код для программы №2 выглядит следующим образом:
```c
#include <stdio.h>
int main(void) {
int n, x, i, sum;
sum = 0;
(void) scanf("%d", &n);
for (i = 1; i <= n; i++) {
(void) scanf("%d", &x);
sum += x - i;
}
printf("%d", sum);
return 0;
}
```

Результат работы программы №2 представлен на рисунке 2.
<p align="center">

  <img width="450" height="250" src="https://sun9-62.userapi.com/impg/irHLXGlT9gXOszeUOO6M_wXMZL2BSSo_YRzVRw/i8GxkVPtAxs.jpg?size=349x129&quality=96&sign=9252e3daa9cae6b0c62a5e88199d8acc&type=album">
</p>


Рисунок 2 — Результат работы программы №2


#### 3.2 Работа с GitLab

Внесем последние в локальный проект и перешлем его в GitLab (commit and push).
Результаты проверки представлены на рисунке 3.

<p align="center">

  <img width="460" height="400" src="https://sun9-54.userapi.com/impg/u3dwsDzXUFADtOHNlaO14xzm-3jVpDv1-w06pg/kB4BzAPQbP4.jpg?size=605x475&quality=96&sign=8f9d514e4a44706f2dc59165229c7ce1&type=album">
</p>
Рисунок 3 — Результаты pipeline-проверки


#### 3.3 Работа с блок-схемами
Создадим блок-схемы для программы №8 и №18.

<p align="center">

  <img width="290" height="" src="https://sun9-48.userapi.com/impg/Wy_C1Q2i1VwUEteQ5I_Ei1b80bIY1uFXbMBLRA/KJsewBYWZaQ.jpg?size=593x1101&quality=96&sign=a72ea8c08067bb568637e7eb536040d0&type=album">
</p>


Рисунок 4 — Блок схема для программы №8



<p align="center">

  <img width="120" height="" src="https://sun9-51.userapi.com/impg/FmeSpmvqAslrmquSZGYpBjp5wRmlZ2qATSNf1g/7pHrbJx-h74.jpg?size=121x1041&quality=96&sign=846294126bd50a685f70894252bc411d&type=album">
</p>
Рисунок 5 — Блок схема для программы №18

### 3 Заключение
В ходе выполнения практической работы, были успешно разработаны программы, заданные вариантом.
