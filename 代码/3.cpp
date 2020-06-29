#include<stdio.h>
#include<string.h>
int dates[3002][13][32];
char NameofWeek[7][20] =
{
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};
int dayOfMonth[13][2] = {
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
char NameofMonth[13][20] =
{
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
int isleap(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}
struct date {
	int year;
	int month;
	int day;
	int cnt;
	date(int y, int m, int d, int c) :year(y), month(m), day(d), cnt(c) {}
	void nextday() {
		int index = isleap(year);
		while (year < 3001) {
			dates[year][month][day] = cnt;
			day++;
			cnt++;
			if (day > dayOfMonth[month][index]) {
				day = 1;
				month++;
				if (month > 12) {
					month = 1;
					year++;
					index = isleap(year);
				}
			}
		}
	}
};
int main() {
	date start(1000, 1, 1, 0);
	start.nextday();
	int year, month, day;
	char tmp[10];
	scanf("%d %s %d", &day, tmp, &year);
	for (int i = 1;i < 13;i++) {
		if (strcmp(NameofMonth[i], tmp) == 0) {
			month = i;
			break;
		}
	}
	int days = dates[2020][1][24] - dates[year][month][day];
	printf("%s", NameofWeek[(12-days % 7) % 7]);
	return 0;
}
