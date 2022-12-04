#include "Data.h"
#include <iostream>
#include <cassert>// for assert

namespace luzinsan
{
	int Data::m_idCounter = 1;

	// ����������� �� ���������.
	Data::Data() : Data(1,1,1970) // ������������� ���������� ������������ � �����������
	{
		std::cout << "\n����� ���� ������������� ������������ � ����������� �� ������������ �� ���������. ������ ������ #" << m_id << std::endl;
	}
	//����������� � �����������
	Data::Data(int D, int M, int Y) : m_Day{ D }, m_Month{ M }, m_Year{ Y }, m_id{ m_idCounter++ }
	{
		std::cout << "\n�������� ����������� �� ���������. ������ ������ #" << m_id << std::endl;
	}
	//����������� ��������� �����������
	Data::Data(const Data& fromData) : Data(fromData.m_Day, fromData.m_Month, fromData.m_Year) // ������������� ���������� ������������ � �����������
	{
		std::cout << "\n����� ���� ������������� ������������ � ����������� �� ������������ ��������� �����������. ������ ������ #" << m_id 
			      << " �� ������� ������� #" << fromData.m_id << std::endl;
	}
	bool IsLeap(int year)
	{
		return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
	}
	void Data::SetData(int D, int M, int Y)
	{
		assert(D <= 31 && D >= 1 && M <= 12 && M >= 1 && Y >= 1 && "���� �� ���� �� �������� �������� �� ������ �� ��������� ���������� ��������");
		if (IsLeap(Y) && M == 2) // ����������� ��� � �������
				assert((D >= 1 && D <= 29) && "� ������� ����������� ���� ���� ����� ����� ���� ������ �� ������� [1;29]");
				
		switch(M)
		{
		case 2: case 4: case 6: case 9: case 11:  // ��������� ������, ���������� �� 30 ����
			assert((D >= 1 && D <= 30) && "� ���� ������ ���� ����� ���� ������ �� ������� [1;30]");
		}

		// ���������� ������ ��� ������������� ���� ��������, ��� ��� ��������� � ������ assert
		m_Day = D; m_Month = M; m_Year = Y;
	}
	void Data::SetDay(int D)
	{
		SetData(D, m_Month, m_Year);
	}
	void Data::SetMonth(int M)
	{
		SetData(m_Day, M, m_Year);
	}
	void Data::SetYear(int Y)
	{
		SetData(m_Day, m_Month, Y);
	}

	int Data::GetDay() const 
	{
		return m_Day;
	}
	int Data::GetMonth() const
	{
		return m_Month;
	}
	int Data::GetYear() const
	{
		return m_Year;
	}
	int Data::GetId() const
	{
		return m_id;
	}

	const Data& Data::operator=(const Data& fromData)
	{
		m_Day = fromData.m_Day;
		m_Month = fromData.m_Month;
		m_Year = fromData.m_Year;
		return *this;
	}
	std::ostream& operator<<(std::ostream& out, const Data& outData)
	{
		out << "\n������  #" << outData.m_id << "=> "<< outData.m_Day <<'/'<< outData.m_Month << '/' << outData.m_Year << std::endl;
		return out;
	}
	bool Data::operator>(const Data& withData) 
	{
		return m_Year > withData.m_Year ? true 
			: (m_Year < withData.m_Year ? false     /*m_Y == withData.m_Y */
			: (m_Month > withData.m_Month ? true
			: (m_Month < withData.m_Month ? false     /*m_M == withData.m_M*/
			: (m_Day > withData.m_Day ? true
			:                       false))));/*this <= withData*/
	}
	bool Data::operator<(const Data& withData)
	{
		return m_Year < withData.m_Year ? true
			: (m_Year > withData.m_Year ? false     /*m_Y == withData.m_Y */
			: (m_Month < withData.m_Month ? true
			: (m_Month > withData.m_Month ? false     /*m_M == withData.m_M*/
			: (m_Day < withData.m_Day ? true
						          : false))));/*this >= withData*/
	}

	
	const Data& Data::operator+=(int day)
	{
		do{

			if(IsLeap(m_Year) && m_Month == 2) // ���� ���������� ��� � �������
			{
				if (m_Day + day > 29)
				{
					m_Month++;
					day -= 30 - m_Day;
					m_Day = 1;
					continue;
				}
				else
				{
					m_Day += day;
					return *this;
				}
			}
			switch (m_Month)
			{
			case 2: // ��������� ������� � ������������ ����
				if (m_Day + day > 28)
				{
					m_Month++;
					day -= 29 - m_Day;
					m_Day = 1;
				}
				else
				{
					m_Day += day;
					return *this;
				}
				break;
				
			case 4: case 6: case 9: case 11:  // ��������� �������, ���������� �� 30 ����
				if (m_Day + day > 30)
				{
					m_Month++;
					day -= 31 - m_Day;
					m_Day = 1;
				}
				else
				{
					m_Day += day;
					return *this;
				}
				break;
			case 1: case 3: case 5: case 7: case 8: case 10:   // ��������� �������, ���������� �� 31 ����
				if (m_Day + day > 31)
				{
					m_Month++;
					day -= 32 - m_Day;
					m_Day = 1;
				}
				else
				{
					m_Day += day;
					return *this;
				}
				break;
			case 12: // ��������� �������
				if (m_Day + day > 31)
				{
					m_Year++; 
					m_Month = 1; 
					day -= 32 - m_Day;
					m_Day = 1;
				}
				else 
				{
					m_Day += day;
					return *this;
				}
			}

		} while (true);
	
		return *this;
	}
	const Data& Data::operator-=(int day)
	{
		do {

			if (IsLeap(m_Year) && m_Month == 3) // ���� ��� ���������� � ���������� ����� - �������
			{
				if (m_Day - day <= 0)
				{
					m_Month--;
					day -= m_Day;
					m_Day = 29;
					continue;
				}
				else
				{
					m_Day -= day;
					return *this;
				}
			}
			switch (m_Month)
			{
			case 3: // ���� ��� ������������ � ���������� ����� - �������
				if (m_Day - day <= 0)
				{
					m_Month--;
					day -= m_Day;
					m_Day = 28;
					continue;
				}
				else
				{
					m_Day -= day;
					return *this;
				}
				break;
			case 2: case 4: case 6: case 8: case 9: case 11:  // ��������� �������, ���������� � ���������� ������� �� 30 ����
				if (m_Day - day <= 0)
				{
					m_Month--;
					day -= m_Day;
					m_Day = 31;
					continue;
				}
				else
				{
					m_Day -= day;
					return *this;
				}
				break;
			case 5: case 7: case 10: case 12:    // ��������� �������, ���������� � ���������� ������� �� 31 ����
				if (m_Day - day <= 0)
				{
					m_Month--;
					day -= m_Day;
					m_Day = 30;
					continue;
				}
				else
				{
					m_Day -= day;
					return *this;
				}
				break;
			case 1: // ��������� ������� ������ � ���� - �������
				if (m_Day - day <= 0) // ���� ��� ��������� �� ������� �� ����� ������, � ������ � ����
				{
					m_Year--;
					m_Month = 12;
					day -= m_Day;
					m_Day = 31;
					continue;
				}
				else // ���� ��� ��������� ���� �� �������� � ������ ����� ������, �� ������� � � ������ ����� ����
				{
					m_Day -= day;
					return *this;
				}
			}

		} while (true);

		return *this;

	}

}