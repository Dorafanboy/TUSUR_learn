#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

/**��� ������ ������� N.
����� ����� ��� ���������� ���������� ���������*/


    int main()

{

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

        printf("��� ������ ������� N.\n");

        printf("����� ����� ��� ���������� ���������� ���������\n");

    int N, NM=0, i;

    printf("������� N: ");

    scanf("%d",&N);

	int arr[N]; ///���� �������


	for (i=0; i <= N-1; i++)

	{

            printf("������� arr[%d]: ",i);

            scanf("%d",&arr[i]);

	}

	for (i=1; i <= N-2; i++){

						        ///����� ���������� ���������
    	    if((arr[i]>arr[i-1])&&(arr[i]>arr[i+1])){

            NM=i;
    }
}
    printf("����� ���������� ���������: %d",NM);

    system("pause");

    return(0);

}

