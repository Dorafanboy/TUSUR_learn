#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

/** ���� ����� ����� N � ����� �� N ������������ �����: A1, A2, . . ., AN.
�������: A1^1,(A2)^2, . . .,(AN-1)^(N-1),(AN)^N */

    int main()

    {

    srand(time(NULL));

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

        printf("���� ����� ����� N � ����� �� N ������������ �����: A1, A2, . . ., AN. \n");

        printf("�������: A1^1,(A2)^2, . . .,(AN-1)^(N-1),(AN)^N \n");

            int N, Nt, Nm, i;

	    printf("������� N: ");

	    scanf("%d",&N);

	int Mod(int,int); ///���������� ������� Mod

	for (i=1; i <= N; i++){

            Nt = rand();

              if (Nt<10000){Nt=1;}			///��������� ��������� �����

                else{if(Nt<25000){Nt=2;}else{Nt=3;}}

                printf("A%d=%d",i,Nt);

            Nm=Mod(Nt,i);

        printf("\tA%d^%d=%d \n",i,i,Nm);

	}

	system("pause");

    return(0);

}

    int Mod(Nt, i){///������� Mod

    int Nm=Nt;

    for(i;i>1;i--){Nm=Nm*Nt;}

    return(Nm);

}
