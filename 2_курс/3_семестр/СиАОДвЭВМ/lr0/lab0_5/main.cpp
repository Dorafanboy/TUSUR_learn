#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    int toSum, start;

    std::ifstream fin("inputDATA.txt"); //������� ���� ��� ������
    std::ofstream fout("outputDATA.txt"); //������� ���� ��� ������ ����������


    if (!fin.is_open() && !fout.is_open()) // ���� ����� �� �������
        std::cout << "������� ��� �������� ����� �� ����� ���� �������!\n"; // �������� �� ����
    else
    {
        fin >> start;
        std::cout << start << std::endl;
        while(!fin.eof())
        {
            fin >> toSum;
            std::cout << toSum << " ";
            fout << start+toSum << " ";
        }
        fin.close(); // ��������� ������� ����
        fout.close(); // ��������� �������� ����
    }

    system("pause");
    return 0;
}
