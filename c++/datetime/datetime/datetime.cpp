#include "datetime.h"
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int getDays(DateTime &date)
{
	if(date.month==2)
	{
		if(date.isleap())return 29;
		else return 28;
	}
	return month[date.month];
}
DateTime::DateTime(int second,int minute,int hour,int day,int month,int year)
{
	if(second>59 || minute>59 || hour>23 || day>getDays(this) || month>12)throw "Something in data is wrong";
	this->second=second;
	this->minute=minute;
	this->hour=hour;
	this->day=day;
	this->month=month;
	this->year=year;
}
DateTime::DateTime()
{
	this->second=0;
	this->minute=0;
	this->hour=0;
	this->day=1;
	this->month=1;
	this->year=1990;
}
bool DateTime::isleap()
{
	return this->year%400==0 || (this->year%4==0 && this->year%100!=0);
}
static bool DateTime::isleap(int year)
{
	return year%400==0 || (year%4==0 && year%100!=0);
}
void DateTime::addYears(int k)
{
	this->year+=k;
}
void DateTime::addMonthes(int k)
{
	int month=this->month;
	month--;
	month+=k;
	if(month>0)
	{
		this->addYears(month/12);
		month%=12;
		month++;
	}
	else
	{
		month++;
		this->addYears(month/12-1);
		month=12-abs(month)%12;
	}
	this->month=month;
}
void DateTime::addDays(int k)
{
	int day=this->day;
	day+=k;
	while(day>getDays(this))
	{
		day-=getDays(this);
		this->addMonthes(1);
	}
	while(day<1)
	{
		day+=getDays(this);
		this->addMonthes(-1);
	}
	this->day=day;
}
void DateTime::addHours(int k)
{
	hour=this->hour;
	hour+=k;
	if(hours>=0)
	{
		this->addDays(hour/24);
		hour%=24;
	}
	else
	{
		this->addDays(hour/24-1);
		hour+=abs(hour/24-1)*24;
	}
	this->hour=hour;
}
void DateTime::addMinutes(int k)
{
	minute=this->minute;
	minute+=k;
	if(minutes>=0)
	{
		this->addHours(minute/60);
		minute%=60;
	}
	else
	{
		this->addHours(minute/60-1);
		minute+=abs(minute/60-1)*60;
	}
	this->minute=minute;
}
void DateTime::addSeconds(int k)
{
	minute=this->second;
	second+=k;
	if(seconds>=0)
	{
		this->addHours(second/60);
		second%=60;
	}
	else
	{
		this->addHours(second/60-1);
		second+=abs(second/60-1)*60;
	}
	this->second=second;
}
DateTime DateTime::operator +(DateTime b)
{
	DateTime c=*this;
	c.addSeconds(b.second);
	c.addMinutes(b.minutes);
	c.addHours(b.hours);
	c.addDays(b.day);
	c.addMonthes(b.month);
	c.addYears(b.year);
	return c;
}
DateTime DateTime::operator -(DateTime b)
{
	DateTime c=*this;
	c.addSeconds(-b.second);
	c.addMinutes(-b.minutes);
	c.addHours(-b.hours);
	c.addDays(-b.day);
	c.addMonthes(-b.month);
	c.addYears(-b.year);
	return c;
}
bool DateTime::operator ==(DateTime b)
{
	return this->second==b.second && this->minute==b.minute && this->hour==b.hour && this->day==b.day && this->month==b.month && this->year==b.year;
}
bool DateTime::operator >(DateTime b)
{
	if(this->year==b.year)
	{
		if(this->month==b.month)
		{
			if(this->day==b.day)
			{
				if(this->hour==b.hour)
				{
					if(this->minute==b.minute)
					{
						return this->second>b.second;
					}
					else return this->minute>b.minute;
				}
				else return this->hour>b.hour;
			}
			else return this->day>b.day;
		}
		else return this->month>b.month;
	}
	else return this->year>b.year;
}
bool DateTime::operator >=(DateTime b)
{
	if(this->year==b.year)
	{
		if(this->month==b.month)
		{
			if(this->day==b.day)
			{
				if(this->hour==b.hour)
				{
					if(this->minute==b.minute)
					{
						return this->second>=b.second;
					}
					else return this->minute>b.minute;
				}
				else return this->hour>b.hour;
			}
			else return this->day>b.day;
		}
		else return this->month>b.month;
	}
	else return this->year>b.year;
}
bool DateTime::operator <(DateTime b)
{
	if(this->year==b.year)
	{
		if(this->month==b.month)
		{
			if(this->day==b.day)
			{
				if(this->hour==b.hour)
				{
					if(this->minute==b.minute)
					{
						return this->second<b.second;
					}
					else return this->minute<b.minute;
				}
				else return this->hour<b.hour;
			}
			else return this->day<b.day;
		}
		else return this->month<b.month;
	}
	else return this->year<b.year;
}
bool DateTime::operator <=(DateTime b)
{
	if(this->year==b.year)
	{
		if(this->month==b.month)
		{
			if(this->day==b.day)
			{
				if(this->hour==b.hour)
				{
					if(this->minute==b.minute)
					{
						return this->second<=b.second;
					}
					else return this->minute<b.minute;
				}
				else return this->hour<b.hour;
			}
			else return this->day<b.day;
		}
		else return this->month<b.month;
	}
	else return this->year<b.year;
}