#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    int x;
    double division = 1;
    std::ifstream fin("inputDATA.txt"); //������� ���� ��� ������

    if (!fin.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else
    {
        fin >> x;
        std::cout << x << " ";
        division = x;
        while(!fin.eof())
        {
            fin >> x;
            std::cout << x << " ";
            division /= x;
        }
        fin.close(); // ��������� ����
        std::cout << std::endl << division << std::endl;
    }
    std::ofstream fout("outputDATA.txt"); //������� ���� ��� ������ ����������
    if (!fout.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else
    {
         fout << division;
         fout.close(); // ��������� ����
    }

    system("pause");

    return 0;
}
