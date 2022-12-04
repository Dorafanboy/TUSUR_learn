#include <stdio.h>

/*Дано целое число N (> 0). Последовательность вещественных чисел A k опреде-
ляется следующим образом: A 0 = 1, A k = (A k−1 + 1)/k, k = 1, 2, . . . . Вывести эле-
менты A 1 , A 2 , . . . , A N .*/



double f = 1; // глобальгая пе-ая, хранящия преведущие значение A 

double fun(int n, int k)
{
	double A;
	
		A = (f + 1)/k;
		f = A;
		return A;
}

int main()
{
	int N;

	printf("Здраствуйте, моё имя Эмма, программа созданая что бы содовать и выводить последовательность чисел, такую что A0 = 1,\
		 Ak = (Ak−1 + 1)/k  (k=1,2...), при этом количесвто элеентов вводите вы.Начнём");
	
	printf("Введите количество элементов\n");
	scanf("%d", &N);

	while(N<=0)
		{
			printf("некорректное значение N, пожалуйста повторите ввод\n");
			scanf("%d",&N);
		}
	
		printf("A0=1.00;\n");
		for(int i=1;i <= N-1; i++) // так как А0 уже напечатано отнимаем 1 
			{
				printf("A%d%s%2.2f%s\n",i,"=",fun(N,i),";");
			}

	return 0;
}
