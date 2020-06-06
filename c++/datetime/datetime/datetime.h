class DateTime
{
private:
	int second,minute,hour,day,month,year;
	friend int getDays(DateTime date);
public:
	DateTime(int second,int minute,int hour,int day,int month,int year);
	DateTime();
	bool isleap();
	static bool isleap(int year);
	void addYears(int k);
	void addMonthes(int k);
	void addDays(int k);
	void addHours(int k);
	void addMinutes(int k);
	void addSeconds(int k);
	DateTime operator +(DateTime b);
	DateTime operator -(DateTime b);
	bool operator ==(DateTime b);
	bool operator >(DateTime b);
	bool operator >=(DateTime b);
	bool operator <(DateTime b);
	bool operator <=(DateTime b);
};