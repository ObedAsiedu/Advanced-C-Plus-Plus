#include  <iostream>
#include "Week.h"
int main() {//main
Week myWeek;
double sales;
double salary;
std::cout << "Enter a sales amount (negative to end): ";
std::cin >> sales;
  
while( sales >= 0 ) {
salary = myWeek.calculate(sales);
myWeek.update(salary);
std::cout << "Enter a sales amount (negative to end): ";
std::cin >> sales;
}
myWeek.display();
return 0;
}
