#include<iostream>
#include<iomanip>
using namespace std;

#include "Sales.h"

int main(){
int total_sale;
cout<<"Enter sales in dollars <-1 to end>: ";
cin>>total_sale;
while(total_sale!=-1){
Sales obj;
obj.set_totalsales(total_sale);
obj.calculate_salary();
obj.print_salary();
cout<<"Enter sales in dollars <-1 to end>: ";
cin>>total_sale;
}
}
