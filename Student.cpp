#include <iostream>
#include "Student.h"
using namespace std;
// driver function
int main()
{
    Student s;           // creating a student object
    s.getData();         // Getting data from the user
    s.displayOriginal(); // Displaying the original array entered by the user
    s.sorting();         // Sorting the array of names entered by the user using an array of pointers
    s.printSorted();     // displaying the sorted array of pointers
    s.displayOriginal(); // Displaying the original array entered by the user again
    return 0;
}
