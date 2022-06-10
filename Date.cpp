#include "Date.h"
#include "TestDate"
#include <iostream>
#include <stdexcept>
#include <array>
using namespace std;
int main()
{
        int choice;
        string monthStr;
        int month, day, year;
        Date* myDate;
          
        do
        {
                cout << "Enter 1 for format: MM/DD/YYYY" << endl;
                cout << "Enter 2 for format: Month DD, YYYY" << endl;
                cout << "Enter 3 to exit" << endl;
                cout << "Choice: \n";
                cin >> choice;
                  
                try {
                        switch (choice) {
                                case 1:
                                        cout << "Enter Month <1-12>: ";
                                        cin >> month;
                                        cout << "Enter Day of Month: ";
                                        cin >> day;
                                        cout << "Enter Year: ";
                                        cin >> year;
                                        cout << endl;       
                                        myDate = new Date( month, day, year );
                                        myDate->print();
                                        myDate->printFullDate();
                                        cout<<"**********"<<endl<<endl;
                                        break;
                                case 2:
                                        //read the month day and year from user 
                                        cout<< "Enter Month Name: ";
                                        cin>>monthStr;
                                        cout<<"Enter Day of Month: ";
                                        cin >> day;
                                        cout << "Enter Year: ";
                                        cin >> year;
                                        cout << endl;
                                        myDate = new Date( monthStr, day, year ); //call the appropriate constructor of the Date class
                                        //print the details
                                        cout<<"month:"<<monthStr<<endl;
                                        myDate->print();
                                        myDate->printFullDate();
                                        cout<<"**********"<<endl<<endl;
                                        break;
                        }
                        
                } catch (invalid_argument& e) {
                        cerr << e.what() << endl << endl;
                }
        } while (choice !=3 );
}

static const array<string, 13> monthNames {"", "January", "February", "March", "April",
                                   "May", "June", "July","August", "September",
                                   "October", "November", "December"};


Date::Date(int mm, int dd, int yy)
{
          setMonth( mm );
      setDay( dd );
      setYear( yy );  
}
  
int convertMonth( string mstr )
{
    for(int i=1; i<= 12; i++)
    {
       if(monthNames[i] == mstr){
            return i;
        }
    }  
        return 0;     //added the statement to avoid compile errors
}

Date::Date(std::string mstr, int dd, int yy)
{
    setDay( dd );
    setYear( yy );
    setMonth( convertMonth(mstr) );
}
  
void Date::setMonth( int mm )
{
    if( mm >= 1 && mm <=12 )
        month = mm;
    else
    {
        month = 1;
        string str = "Error in your month: " + to_string(mm)+ ". Set to defaut month 1";
        throw invalid_argument ( str );
    }
}
void Date::setDay ( int dd )
{
        if(dd>=1 && dd<=31)//check for vaild date
                day = dd;
        else //if not a valid day
            {
                day = 1;
                string str = "Error in your day: " + to_string(dd)+ ". Set to defaut day 1";
                throw invalid_argument ( str );
            }           
}
void Date::setYear ( int yy)
{
        if(yy>0) //check for year if it is +ve
                year = yy; 
        else //if not positive year
        {
            year = 1;
            string str = "Error in your year: " + to_string(yy)+ ". Set to defaut Year 1";
            throw invalid_argument ( str );
        }    
}     
int Date::getMonth()
{
    return month;  
}
int Date::getDay()
{
    return day;  
}
int Date::getYear()
{
    return year;  
}
void Date::print()
{
      cout << "MM/DD/YYYY: " << month << "/" << day << "/" << year << endl;
}
void Date::printFullDate()
{
        string monthStr= monthNames[getMonth()]; //get the month string
        //print the details 
    cout << "Month DD, YYYY: " << monthStr << " " << day << "," << year << endl;   

}


