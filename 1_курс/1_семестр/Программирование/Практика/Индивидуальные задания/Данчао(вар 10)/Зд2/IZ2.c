#include <stdio.h>

/*Дано целое число N (> 1) и набор из N целых чисел. Вывести те элементы в
наборе, которые меньше своего правого соседа, и количество K таких элемен-
тов. Набор генерировать. Массивы не использовать.*/

int N0,K;// гло-ые пе-ые которые хранят номер пред элемента и количество эл-ов уд-им условию

int fun( int n1)
{	
	int n0 = N0; //(1) выводим значение 
	
	K++;

	N0 = n1; //сохраняем преведущие значение N

	return n0; //(1) подходящие ус-ию
}

int main()
{
	int N,N1;
	
	printf("Здраствуйте, моё имя Костя,программа принимающая от вас набор чисел и вывожу те элементы в наборе,\
которые меньше своего правого соседа, и количество K таких элемен-тов.Давайте начнём.\n");

	printf("\nВведите количество элементов(N):\n");
	scanf("%d", &N);
	
	while(N<=0)
		{
			printf("некорректное значение N, пожалуйста повторите ввод\n");
			scanf("%d",&N);
		}
		
	printf("Введите знаение N1:"); // вводим 1 значение 
	scanf("%d", &N0);

	for(int i=2;i <= N; i++)
		{
			printf("Введите знаение N%d%s",i,":");
			scanf("%d", &N1);
			
			if (N0 < N1)
				{ 
					printf("%s%d%s\n","Бинго!:",fun(N1),";");
				}
			else
				{
					N0 = N1; //сохраняем преведущие значение N		
				}	
		}

	printf("Количестов эл-ов удовлетворяяющих условию:%d\n",K);


	return 0;
}
