#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void function(int M)

{

	int i, j, sum, arr[M][M];

	  printf("������ M x M:\n");

          for (i=0; i<M; i++)

        {

            for(j=0; j<M; j++)

    {

            arr[i][j] = rand()%20-10;

            printf("%3d ",arr[i][j]);

    }

	printf("\n");

        }

    sum=0;

    for(j=1; j<M-1; j++)

    {

            for(i=0; i<M; i++)

    {

    sum+=arr[i][j];

        }

    j++;

    }

  printf("\n\n����� �����: %d \n\n", sum);

    if (sum > 0)

{

    printf("\n ��������������� ������ M x M:");

    for(i=0; i<M; i++)

        {

        for(j=0; j<M; j++)

        arr[i][j]*=arr[i][j];

        i++;

        }

}

    if (sum < 0)

        {

        printf("\n ��������������� ������ M x M:");

        for(j=0; j<M; j++)

            {

                i = M - j - 1;

                arr[i][j] +=2;

            }

        }

    printf("\n");

    for (i=0; i<M; i++)

        {

            for(j=0; j<M; j++)

        {

    printf("%3d ",arr[i][j]);

}

    printf("\n");}}

int main()

{

  int M;

    setlocale (LC_CTYPE, "RUS");

    printf("������� ������ ������� M x M \n");

    printf("���������� ����� � �������� M:");

    scanf("%d", &M);

        while(M<1)

        if(M<1)

{
            printf("������! ������� ����� ������!\n");

            printf("���������� ����� � �������� M:");

            scanf("%d", &M);}

            printf("\n");

            function(M);

return 0;

}
