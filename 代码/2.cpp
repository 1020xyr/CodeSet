#include<iostream>
using namespace std;
int months[13][2] = {
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
int getyear(int year){
	if(year%400==0||(year%4==0&&year%100!=0)) return 1;
	else return 0;
}
struct date{
	int year;
	int month;
	int day;
	date(int y,int m,int d):year(y),month(m),day(d)
	{}
	void print_date(){
		cout<<year<<" "<<month<<" "<<day<<endl; 
	}
	int  getdays(date next){
		int cnt =0;
		int index = getyear(year);
		while(*this !=next){	
			cnt++;
			day++;
			if(day>months[month][index]){
				day = 1;
				month++;
				if(month>12){
					month = 1;
					year++;
					index = getyear(year);
				}
			}
		}
		return cnt;		
	}
	bool operator <(date d){
		if(year<d.year) return true;
		if(year>d.year) return false;
		if(month<d.month) return true;
		if(month>d.month) return false;
		if(day<d.day) return true;
		if(day>d.day) return false;
		return false;
	}
	bool operator !=(date d){
		if(year==d.year&&month==d.month&&day==d.day) return false;
		else return true;
	}
};
void func(){
	int year,month,day;
	scanf("%4d%2d%2d",&year,&month,&day);
	date d1(year,month,day);
	scanf("%4d%2d%2d",&year,&month,&day);
	date d2(year,month,day);
	int cnt;
	if(d1<d2)
		cnt = d1.getdays(d2); 
	else 
		cnt = d2.getdays(d1); 
	cout<<cnt+1<<endl;
}
int main(){
	func();
	return 0;
}
