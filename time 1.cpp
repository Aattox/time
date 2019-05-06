// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CMyDate
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minte;
	int scound;
	int check();
public:
	CMyDate();
	int setDate(int y, int m, int d, int h, int min, int s);
	void addTime();
	void displayDate();
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinte();
	int getScound();
};
CMyDate::CMyDate()
{
	year = 2019;
	month = 1;
	day = 1;
	hour = 1;
	minte = 1;
	scound = 1;
}
void CMyDate::addTime()
{
	scound++;
	int leapyear[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int flatyear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapyear[month - 1] < day)
		{
			month++;
			day = 1;
		}
	}
	else
	{
		if (flatyear[month - 1]<day)
		{
			month++;
			day = 1;
		}
	}
	if(month>12||month<1)
	{
		year++;
		month = 1;
	}
	if(hour>24||hour<1)
	{
		day++;
		hour = 1;
	}
	if(minte>60||minte<1)
	{
		hour++;
		minte = 1;
	}
	if(scound>60||minte<1)
	{
		minte++;
		scound = 1;
	}
}
void CMyDate::displayDate()
{
	cout << year << "年" << month << "月" << day << "日" << hour << "时" << minte << "分" << scound << "秒" << endl;
}
int CMyDate::setDate(int y, int m, int d, int h, int min, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minte = min;
	scound = s;
	if(check()==-1)
	{
		month = 1;
		day = 1;
		hour = 1;
		minte = 1;
		scound = 1;
		cout << "错误，已重置为1" << endl;
	}
	return 0;
}
int CMyDate::check()
{
	int leapyear[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int flatyear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return 1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapyear[month - 1]<day)
		{
			return -1;
		}
	}
	else if (flatyear[month - 1]<day)
	{
		return -1;
	}
	if(hour>24||hour<1)
	{
		return -1;
	}
	if(minte>60||minte<1)
	{
		return -1;
	}
	if(scound>60||scound<1)
	{
		return -1;
	}
}
int main()
{
	CMyDate time;
	time.setDate(2019,5,6,16,42,1);
	time.displayDate();
    return 0;
}

