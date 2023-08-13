
#include <bits/stdc++.h>
using namespace std;



   
    
bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
     }
     
       int daysInMonth(int year, int month) {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year))
            return 29;
        return days[month];
    }
     
int daysInMonthWithLeap(int year, int month) {
        static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year))
            return 29;
        return daysInMonth[month];
    }
    

    

class Date
{
   public:
   string day;
   int month;
   int dayofMonth;
   int year;
   
   bool operator!=(const Date& other) const {
        return !(dayofMonth == other.dayofMonth && month == other.month && year == other.year);
    }
    Date(){
        dayofMonth = 0;
        month = 0;
        year = 0;
    }
   Date(int m , int d, int y)
   {
      dayofMonth=d;
      month=m;
      year=y;

   }

};

class Notes{
    public:
        string content;
        Date date;
        Notes(Date d,string c){
            content = c;
            date =d;
        }
};

class Calendar
{
      
    
   public:
   vector<pair<Date,string>> noteee;
   
     
    public:
    bool isholiday(Date d)
    {
        bool chk=false;
        
        for(int i=0;i<holidayz.size();i++)
        {
            Date temp=holidayz[i];
            if(temp.month==d.month && temp.year==d.year && temp.dayofMonth==d.dayofMonth)
            return true;
        }
        
        
        
        
        return chk;
    }

    public:
    int dayOfWeekCalc(int year, int month, int day) {
        if (month < 3) {
            month += 12;
            year -= 1;
        }
        int century = year / 100;
        year %= 100;
        int dayOfWeek = (day + 13 * (month + 1) / 5 + year + year / 4 + century / 4 + 5 * century) % 7;
        return (dayOfWeek + 6) % 7; // Convert to 0-indexed (0 = Sunday, 6 = Saturday)
    }

    
    
    
    
    public:
    vector<Date> holidayz;
    
    public:
    vector<Date> sat_sun;
   
    
    public:
    //1 Day
    string getDay(Date date) {
        int d=date.dayofMonth;
        int yr=date.year;
        int m=date.month;

        int p[12]={0,3,2,5,0,3,5,1,4,6,2,4};
        int q=m<3;
        yr=yr-q;
        int a=yr+yr/4 -yr/100 + yr/400 + p[m-1] + d;
        a=a%7;
        string day;
        switch(a)
        {
            case 0:day="Sunday"; break;
            case 1: day="Monday"; break;
            case 2:day="Tuesday"; break;
            case 3:day="Wednesday"; break;
            case 4:day="Thrusday"; break;
            case 5:day="Friday"; break;
            default: day="Saturday"; break;
        }


return day;

    }
    
    //2 Month
    string getMonth(Date date)
    {
        int mnth=date.month;
        string MONTH;
    
        switch(mnth)
        {
case 1: MONTH="january";
break;
case 2: MONTH="Feburary";
break;
case 3: MONTH="March";
break;
case 4: MONTH="April";
break;
case 5: MONTH="May";
break;
case 6: MONTH="June";
break;
case 7: MONTH="July";
break;
case 8: MONTH="August";
break;
case 9: MONTH="September";
break;
case 10: MONTH="October";
break;
case 11: MONTH="November";
break;
case 12: MONTH="December";
break;


        }

return MONTH;

     }
     
     
     //3 Get year
     int getYear(Date d)
     {
         int yrr=d.year;
         return yrr;
     };
     
     //4 Add a holiday
     void addHoliday(Date d) {
          holidayz.push_back(d);
          
     }


     //5 Next Holiday
     Date getNextHoliday(Date d) {
         
         int dte=d.dayofMonth;
         int mnth=d.month;
         int ye=d.year;
         //days to shift
         int add=0;
         
         //Original date's copy
         int pp=dte;
         int qq=mnth;
         int rr=ye;
         
         
         int p[12]={0,3,2,5,0,3,5,1,4,6,2,4};
        int q=mnth<3;
        ye=ye-q;
        int a=ye+ye/4 -ye/100 + ye/400 + p[mnth-1] + dte;
        a=a%7;
        
        switch(a)
        {
            case 0:add=6; break;
            case 1: add=5; break;
            case 2:add=4; break;
            case 3:add=3; break;
            case 4:add=2; break;
            case 5:add=1; break;
            default:add=1; break;
        }
         
         
        
         
         bool leap=false;
         if ((ye % 4 == 0 && ye % 100 != 0) || (ye % 400 == 0)) 
        leap= true;
        
        //if leap
     if(leap)
     {
          if(mnth==1||3||5||7||8||10||12)
          {
              int newdte=dte;
              newdte+=add;
              newdte=newdte%31;
              //if date becomes 31
              if(newdte==0)
              newdte=31;
              //if month doesnt changes
              if(newdte>dte)
              dte=newdte;
              
              //if month changes
              else
              {
                  dte=newdte;
                  if(mnth==12)
                  {
                  mnth =1;
                  ye++;
                  }
                  else
                  mnth+=1;
              }
              
          }
       
        
        else if(mnth == 2)
        {
            int newdte=dte;
            newdte+=add;
            newdte=newdte%29;
            if(newdte==0)
            newdte=29;
            if(newdte>dte)
              dte=newdte;
               else
              {
                  dte=newdte;
                  mnth=3;
              }
            
            
        }
        
        else
        {
              int newdte=dte;
              newdte+=add;
              newdte=newdte%30;
              //if date becomes 31
              if(newdte==0)
              newdte=30;
              //if month doesnt changes
              if(newdte>dte)
              dte=newdte;
              
              //if month changes
              else
              {
                  dte=newdte;
                  mnth+=1;
                  
              }
              
        }
        
        
        d.year=ye;
        d.month=mnth;
        d.dayofMonth=dte;
        
        
    holidayz.push_back(d);
    
      
        sort(holidayz.begin(), holidayz.end(), [](const Date& a, const Date& b) {
            if (a.year != b.year) {
                return a.year < b.year;
            } else if (a.month != b.month) {
                return a.month < b.month;
            } else {
                return a.dayofMonth < b.dayofMonth;
            }
       });
    
         
     }
     else
     {
          if(mnth==1||3||5||7||8||10||12)
          {
              int newdte=dte;
              newdte+=add;
              newdte=newdte%31;
              //if date becomes 31
              if(newdte==0)
              newdte=31;
              //if month doesnt changes
              if(newdte>dte)
              dte=newdte;
              
              //if month changes
              else
              {
                  dte=newdte;
                  if(mnth==12)
                  {
                  mnth =1;
                  ye++;
                  }
                  else
                  mnth+=1;
              }
              
          }
       
        
        else if(mnth == 2)
        {
            int newdte=dte;
            newdte+=add;
            newdte=newdte%28;
            if(newdte==0)
            newdte=28;
            if(newdte>dte)
              dte=newdte;
               else
              {
                  dte=newdte;
                  mnth=3;
              }
            
            
        }
        
        else
        {
              int newdte=dte;
              newdte+=add;
              newdte=newdte%30;
              //if date becomes 31
              if(newdte==0)
              newdte=30;
              //if month doesnt changes
              if(newdte>dte)
              dte=newdte;
              
              //if month changes
              else
              {
                  dte=newdte;
                  mnth+=1;
                  
              }
              
        }
        
        
        d.year=ye;
        d.month=mnth;
        d.dayofMonth=dte;
        
        
        
      holidayz.push_back(d);
    
     
        sort(holidayz.begin(), holidayz.end(), [](const Date& a, const Date& b) {
            if (a.year != b.year) {
                return a.year < b.year;
            } else if (a.month != b.month) {
                return a.month < b.month;
            } else {
                return a.dayofMonth < b.dayofMonth;
            }
        });
    
     }
     
     
     
     for (const Date& holiday : holidayz) {
         if(0);
            else if (holiday.year > rr ||
                (holiday.year == rr && holiday.month > qq) ||
                (holiday.year == rr && holiday.month == qq && holiday.dayofMonth > pp)) {
                    d.dayofMonth=holiday.dayofMonth;
                    d.month=holiday.month;
                    d.year=holiday.year;
                    break;
                }
            
        }
               
     
     return d;
     
     }
     
     //6 next week day
    Date getNextWeekDay(Date d) {
         Date curDate = Date(d.dayofMonth,d.month,d.year);
        while(isholiday(curDate)){
            curDate = iterateDates(curDate,1);
        }
         return curDate;
      }
     
     
     //7 Compare Date
     bool isPreceded(Date d1, Date d2)
     {
         if (d1.year > d2.year ||
                (d1.year == d2.year && d1.month > d2.month) ||
                (d1.year == d2.year && d1.month == d2.month && d1.dayofMonth > d2.dayofMonth)) {
                   return 1;
                    
                }
                else return 0;
     }
     
     //8 Print calender
     void printMonthOfYear(int month, int year)
     {
         int p[12]={0,3,2,5,0,3,5,1,4,6,2,4};
        int q=month<3;
        year=year-q;
        int a=year+year/4 -year/100 + year/400 + p[month-1] + 1;
        a=a%7;
        int firstDayOfWeek = a;
        
        //getting number of days
        int daysInMonth;
        bool leap=false;
         if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
        leap= true;
        //if leap
        if(leap)
        {
            if(month==1||3||5||7||8||10||12)
            daysInMonth=31;
            else if(month==2)
            daysInMonth=29;
            else
            daysInMonth=30;
            
        }
        else
        {
            if(month==1||3||5||7||8||10||12)
            daysInMonth=31;
            else if(month==2)
            daysInMonth=28;
            else
            daysInMonth=30;
        }
        
        
        //getting month name
        string MONTH;
        
        switch(month)
        {
case 1: MONTH="January";
break;
case 2: MONTH="Feburary";
break;
case 3: MONTH="March";
break;
case 4: MONTH="April";
break;
case 5: MONTH="May";
break;
case 6: MONTH="June";
break;
case 7: MONTH="July";
break;
case 8: MONTH="August";
break;
case 9: MONTH="September";
break;
case 10: MONTH="October";
break;
case 11: MONTH="November";
break;
case 12: MONTH="December";
break;
        
}
        // Prining month and year header
        cout << "Calendar for " << MONTH << " " << year <<endl;

        // Printing day names
        cout << "Su Mo Tu We Th Fr Sa" <<endl;

        // Print leading spaces for the first week
        int i;
        for (i = 0; i < firstDayOfWeek; i++) {
            cout << "   ";
        }

        // Printing dates for the month
        int day;
        for (day = 1; day <= daysInMonth; day++) {
            cout << (day < 10 ? " " : "") << day << " ";

            if ((firstDayOfWeek + day) % 7 == 0 || day == daysInMonth) {
                cout << std::endl;
            }
        }
    
     };
     
     //9 distance between two dates
      int getDistanceBetweenDates(Date d1,Date d2)
      {
          int distance = 0;
          int monthwisedate[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
          
          
          if(0);
        else if (d2.year < d1.year || (d2.year == d1.year && d2.month < d1.month) || (d2.year == d1.year && d2.month == d1.month && d2.dayofMonth < d1.dayofMonth)) {
            swap(d1, d2);
        }
        

        while (d1 != d2) {
            ++distance;
            ++d1.dayofMonth;

            if (d1.dayofMonth > monthwisedate[d1.month]) {
                d1.dayofMonth = 1;
                ++d1.month;

                if (d1.month > 12) {
                    d1.month = 1;
                    ++d1.year;
                }
            }
        }

        return distance;
    };
    
    //10 Number of holidays 
    int getNumberOfHolidays(int month,int year)
    {
          int numHolidays = 0;
       // vector<Date> holidays;

        // Add weekends (Saturdays and Sundays) as default holidays
        int daysInMonth = daysInMonthWithLeap(year, month);
        int day;
        for (day = 1; day <= daysInMonth; day++) {
            int dayOfWeek = dayOfWeekCalc(year, month, day);
            if (dayOfWeek == 0 || dayOfWeek == 6) { // 0 = Sunday, 6 = Saturday
              sat_sun.push_back(Date(year, month, day));
                numHolidays++;
            }
        }
        
        int cnt=0;
        for(int i=0;i<holidayz.size();i++)
        {
            Date temp = holidayz[i];
            if(temp.month==month && temp.year==year)  
            cnt++;
            
        }
        
        numHolidays+=cnt;
        

        return numHolidays;

    };
    
    //11 Shift date : iterate date
    Date iterateDates(Date d, int t) {
        
         while (t > 0) {
            int remainingDaysInMonth = daysInMonth(d.year, d.month) - d.dayofMonth + 1;
            if(0);
            else if (t < remainingDaysInMonth) {
                d.dayofMonth += t;
                t = 0;
            } 
            else if(0);
            else {
                t -= remainingDaysInMonth;
                d.dayofMonth = 1;
                d.month++;
                if (d.month > 12) {
                    d.year++;
                    d.month = 1;
                }
            }
        }
      
      
    return d;
    }
    
    //12 noteee
    void addNoteToDate(Date d, string note)
    {
        noteee.push_back({d,note});
    };
    
    //13 remove a note
    bool removeNoteFromDate(Date d)
    {
        int index =-1;
        for(int i=0;i<noteee.size();i++){
            Date curDate = noteee[i].first;
            if(curDate.dayofMonth==d.dayofMonth && curDate.month==d.month && curDate.year==d.year){
                index = i;
                break;
            }
        }
        if(index==-1){
            return false;
        }
        noteee.erase(noteee.begin()+index); 
        return true;
    };
      //new method
     vector<Notes> getNotesFromDateTillN(Date d, int n){
        vector<Notes> result; 
    Date curDate = Date(d.dayofMonth,d.month,d.year);
        for(int i=0;i<n;i++){
            curDate = iterateDates(curDate,1);
            for(auto &note:noteee){
                Date temp = note.first;
                if(temp.dayofMonth==curDate.dayofMonth && temp.month==curDate.month && temp.year==curDate.year){
                    result.push_back(Notes(curDate,note.second));
                }
            }
            
        }
        return result;
     }
   
    
    //14 user 1 AND user 28
    
    
    
};

vector<Date> getFreeDates(Calendar c1, Calendar c2, int month, int year)
    {
        vector<Date> freexx; 
        int monthsize=daysInMonth(year,month);
        bool chk[monthsize+1]={0};
        
        int m=daysInMonth(year,month);
        
        for(int i=0;i<=c1.holidayz.size();i++)
        {
            if(c1.holidayz[i].month==month)
            chk[c1.holidayz[i].dayofMonth]=1;
            if(c1.sat_sun[i].month==month)
            chk[c1.holidayz[i].dayofMonth]=1;
            
        }
        
        for(int i=0;i<=c2.holidayz.size();i++)
        {
            if(c2.holidayz[i].month==month)
            chk[c2.holidayz[i].dayofMonth]=1;
            if(c2.sat_sun[i].month==month)
            chk[c2.holidayz[i].dayofMonth]=1;
            
        }
        
        
       for(int i=1;i<=daysInMonth(year,month);i++)
       {
           int flag = false;
           int curDate = 0;
           for(int j=0;j<c1.noteee.size();j++){
               Date tempD = c1.noteee[j].first;
               if(tempD.month==month && tempD.year==year && tempD.dayofMonth==i){
                   flag = true;
                   curDate = i;
               }
           }
           if(flag){
               chk[curDate] = 1;
           }
           flag = false;
          for(int j=0;j<c2.noteee.size();j++){
               Date tempD = c2.noteee[j].first;
               if(tempD.month==month && tempD.year==year && tempD.dayofMonth==i){
                   flag = true;
                   curDate = i;
               }
           }
           if(flag){
               chk[curDate] = 1;
           }

       }
     
     
     for(int i=1;i<=monthsize;i++){
         freexx.push_back(Date(i,month,year));
     }
     return freexx;
        
    };

int main() {


//   Calendar c1;
//   Calendar c2;

//      int dayofmonth;
//      int month;
//      int year;
     
    
     
//      cin>>dayofmonth;
//      cin>>month;
//      cin>>year;
     
//      //buffer current Date
//       int bufferdays=dayofmonth;
//      int buffermonth=month;
//      int bufferyear=year;
     
//      Calendar cd;
//      Date d(month,dayofmonth,year);

//      cout<<endl<<cd.getDay(d)<<endl;
//      cout<<cd.getMonth(d)<<endl;
//      cout<<cd.getYear(d)<<endl;
     
//      cout<<"Enter date u want to be a holiday"<<endl;
//      cin>>dayofmonth;
//      cin>>month;
//      cin>>year;
//      cout<<endl;
//      Date dt(month,dayofmonth,year);
//      cd.addHoliday(dt);
//      c1.addHoliday(dt);
     

//      Date newdate=cd.getNextHoliday(d);
     
//      cout<<newdate.dayofMonth<<"/"<<newdate.month<<"/"<<newdate.year<<endl;
     
     
//      //to check date 1 , date 2 to wheather d1<d2 or not;
     
//      bool chk=false;
     
//      cout<<"Enter two dates to check if d1>d2 not"<<endl<<"d1"<<endl;
//      cin>>dayofmonth;
//      cin>>month;
//      cin>>year;
//      Date d1(month,dayofmonth,year);
     
//      cout<<endl<<"d2"<<endl;
//      cin>>dayofmonth;
//      cin>>month;
//      cin>>year;
//      Date d2(month,dayofmonth,year);
     
     
//      chk=cd.isPreceded(d1, d2);
//      if(chk)
//      cout<<"True";
//      else
//      cout<<"False";
     
//      int mth;
//      int yrr;
//      cout<<endl<<"Print month and year to print its calander"<<endl;
//      cin>>mth;
//      cin>>yrr;
//      cd.printMonthOfYear(mth,yrr);
    
    
     
//      //Diatance bwtween two dates
//      int distance=cd.getDistanceBetweenDates(d1,d2);
//      cout<<"Distance Between Two dates"<<" "<<distance<<endl;
 
     
//      //After shifting n dates from current the date is
     
//      Date shiftcurrent(buffermonth,bufferdays,bufferyear);
     
//      int t;
//      cout<<"Enter number of days to shift curent date"<<endl;
//      cin>>t;
//      cout<<endl<<"After shifting "<<shiftcurrent.dayofMonth<<"/"<<shiftcurrent.month<<"/"<<shiftcurrent.year<<" by "<<t<<" days, the new date is: ";
//      shiftcurrent=cd.iterateDates(shiftcurrent,t);
//     cout<<shiftcurrent.dayofMonth<<"/"<<shiftcurrent.month<<"/"<<shiftcurrent.year<<endl;
    
    
    
        
//     int total_holidays=cd.getNumberOfHolidays(buffermonth,bufferyear);
   
//      //number of holidays
//      cout<<"Number of Holidays"<<" "<<total_holidays<<endl;
     
     
    
//      Date nxtwkday=cd.getNextWeekDay(d);
//      bool notedel;
//      cout<<"Next week day"<<endl<<nxtwkday.dayofMonth<<"/"<<nxtwkday.month<<"/"<<nxtwkday.year<<endl;
     
//      notedel=cd.removeNoteFromDate(d);
//      cout<<"For deleting Note: "<<notedel<<endl;
     
     
//      cout<<"Add holiday for user 2:"<<endl;
//      int userday;
//      int usermonth;
//      int useryear;
     
//      cin>>userday;
//      cin>>usermonth;
//      cin>>useryear;
     
//      Date ddd(userday, usermonth,useryear);
//      c2.addHoliday(ddd);
     
//      int freemonth;
//      cout<<"Enter month to find free dayes: "<<endl;
//      cin>>freemonth;
     
//      int freeyear;
//      cout<<"Enter year to find free dayes: "<<endl;
//      cin>>freeyear;
     
//      vector<Date> xx;
//      xx=getFreeDates(c1,c2,freemonth,year);
     
     
//      cout<<"Total of dates free: "<<endl;
//      cout<<xx.size();
     
     
     
return 0;
}








