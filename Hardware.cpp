#include <iostream>
#include <fstream> //for filestream methods
#include <iomanip>//for setw() method
#include "Hardware.h"//contains class HardwareData
using namespace std;
/**
 * ADDED: Function prototypes
*/
bool openFile(fstream&);
void listHardwareDatas(fstream&);
void inputData(fstream&);
void initializeFile(fstream&);

int main() {

  fstream file;
  int choice;

  do {
    cout << "\n***************************************" << endl;
    cout << "Enter 1 for opening data file" << endl;
    cout << "Enter 2 for listing all the records" << endl;
    cout << "Enter 3 for entering a new record" << endl;
    cout << "Enter 4 to exit" << endl;
    cout << "***************************************" << endl;
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        // open data file
        openFile(file);
        break;
      case 2:
        listHardwareDatas(file);
        break;
      case 3:
        inputData(file);
        break;
      default:
        break;
    } // end switch
  } while (choice != 4); // end do while

  file.close();
  return 0;
} // end main

bool openFile(fstream & file) {
  string fileName;
  cout << "\nEnter the file name: ";
  cin >> fileName;
  file.open(fileName, ios:: in | ios::out | ios::binary);

  if (file) {
    cout << "file open success.\n";
    return true;
  }

  ofstream outFile(fileName, ios::out | ios::binary);
  outFile.close();
  cout << "File does not exist. create the data file.\n";

  file.clear();
  file.open(fileName, ios:: in | ios::out | ios::binary);

  initializeFile(file);
  return true;
}

void initializeFile(fstream & fRef) {
  HardwareData blankItem; // empty HardwareData object

  // write 100 blank records to fRef file

  //ADDED: Writing 100 Blank record to the file using fRef
  //Run loop till 100
  for(int i=0;i<100;i++){
    //Writing blank file
    fRef.write(reinterpret_cast < char * > (&blankItem), sizeof(HardwareData));
  }

}

void inputData(fstream & fRef) {
  HardwareData temp; // temporary HardwareData object

  // temporary variables used to hold user input
  int number;
  char name[30];
  double price;
  int stock;

  // ask user for and set partNumber
  cout << "Enter the part number (0 - 99, -1 to end input): ";
  cin >> number;

  // set HardwareData members until -1 is entered
  while (number != -1) {

    // ask the user to enter and then store the data to temp using set functions
    /**
     * ADDED: Asking For user inputs for data members of class HardwareData and setting the values for object temp
    */
    cout<<"Enter the tool name: ";
    cin>>name;
    cout<<"Enter quantity and price: ";
    cin>>stock>>price;
    //Setting the values using setter functions defined
    temp.isFilled();//set that object is no longer empty
    temp.setName(name); //Set name value
    temp.setPartNumber(number); //set record number
    temp.setCost(price); //set cost
    temp.setQuantity(stock); //set quantity

    // place file position pointer at next write location
    fRef.seekp((temp.getPartNumber()) * sizeof(HardwareData));

    // write data to file
    fRef.write(reinterpret_cast < char * > ( & temp), sizeof(HardwareData));

    // ask user for next part number
    cout << "Enter the part number (0 - 99, -1 to end input): ";
    cin >> number;
  } // end while
}

void listHardwareDatas(fstream & fRef) {
  HardwareData temp;

  // display column headings
  cout << setw(7) << "Record#" << " " << left <<
    setw(30) << "HardwareData name" << left <<
    setw(13) << "Quantity" << left << setw(10) << "Cost" << endl;

  // continue until 100 tools are displayed
  for (int count = 0; count < 100; count++) {
    /**
     * ADDED: Reading all the 100 data stored in the file and displaying it to the user
    */
    HardwareData temp; //To read the data into
    fRef.seekg(count*sizeof(HardwareData),ios::beg); //set get pointer location to read object data
    fRef.read(reinterpret_cast <char*> (&temp), sizeof(HardwareData)); //reading the data into the object
    //Printing the data
    /**
     * Print only those object data whose value is not empty else don't print gibberish
    */
    if(!temp.isEmpty()){
      cout << setw(7) << temp.getPartNumber() << " " << left <<
      setw(30) << temp.getName() << left <<
      setw(13) << temp.getQuantity() << left << setw(10) << temp.getCost() << endl;
    }
  }
}
