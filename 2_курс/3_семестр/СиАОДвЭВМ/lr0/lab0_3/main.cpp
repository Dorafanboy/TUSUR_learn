#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    int x, multiplication = 1;
    std::ifstream fin("inputDATA.txt"); //������� ���� ��� ������

    if (!fin.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else
    {
        while(!fin.eof())
        {
            fin >> x;
            std::cout << x << " ";
            multiplication *= x;
        }
        fin.close(); // ��������� ����
        std::cout << std::endl << multiplication << std::endl;
    }
    std::ofstream fout("outputDATA.txt"); //������� ���� ��� ������ ����������
    if (!fout.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else
    {
         fout << multiplication;
         fout.close(); // ��������� ����
    }

    system("pause");

    return 0;
}
