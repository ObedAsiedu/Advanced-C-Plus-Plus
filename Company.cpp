#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include "Company.h"

double Calculate(int quantity, double price) { 
    double res = price;    if(quantity > 20) {
        // 25% off
        res = price - (price * 25)/100;
    }
    else if(quantity > 10) {
        // 10% off
        res = price - (price * 10)/100;
    }
    else {
        // No discount
        res = res;
    }
    
    return res;
}

int main() {
    Company c1;
    bool k = true;
    while (k) {
        int n, m;
        cout << "Enter product number (1-5) (0 to stop): ";
        cin >> n;
        if (n == 0) {
            break;           // break from outer loop
        }
        cout << "Enter quantity sold: ";
        cin >> m;
        double price;
        double discount_price;
        
        switch(n) {
            case 1:
                price = m * 2.98;
                discount_price = Calculate(m, price);
                c1.a += discount_price;
                cout << "The sales for this product " << n << " is $" << discount_price << endl << endl;
                break;
            case 2:
                price = m * 4.50;
                discount_price = Calculate(m, price);
                c1.b += discount_price;
                cout << "The sales for this product " << n << " is $" << discount_price << endl<< endl;
                break;
            case 3:
                price = m * 9.98;
                discount_price = Calculate(m, price);
                c1.c += discount_price;
                cout << "The sales for this product " << n << " is $" << discount_price << endl<< endl;
                break;
            case 4:
                price = m * 4.49;
                discount_price = Calculate(m, price);
                c1.d += discount_price;
                cout << "The sales for this product " << n << " is $" << discount_price << endl<< endl;
                break;
            case 5:
                price = m * 6.87;
                discount_price = Calculate(m, price);
                c1.e += discount_price;
                cout << "The sales for this product " << n << " is $" << discount_price << endl<< endl;
                break;
            case 0:
                k = false;
                break;
            default:
                cout << "Kindly enter valid input!!" << endl;
                break;
        }
    }
    cout << "Total sales for this week:"<<endl;
    cout << "---------------------------" << endl;
    
    cout << "Product " << 1 << " : $" << c1.a<<endl; 
    cout << "Product " << 2 << " : $" << c1.b<<endl;
    cout << "Product " << 3 << " : $" << c1.c<<endl;
    cout << "Product " << 4 << " : $" << c1.d<<endl;
    cout << "Product " << 5 << " : $" << c1.e<<endl;
    
}
