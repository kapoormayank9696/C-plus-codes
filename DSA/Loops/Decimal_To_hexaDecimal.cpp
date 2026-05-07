// Decimal To HexaDecimal Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to Convert Decimal To Hexa-Decimal
void decimalToHexa(int n) {
    string result = "";
    char hexaDecimal[]={
        '0','1','2','3',
        '4','5','6','7',
        '8','9','A','B',
        'C','D','E','F'
    };
    
    if(n == 0) {
        cout << "The equivalent Hexadecimal Number : 0";
        return;
    }
    while(n != 0) {
        int remainder=n%16;
        result=hexaDecimal[remainder]+result;
        n=n/16;
    }
    cout<<"The equivalent Hexadecimal Number : "<<result;
}

// Main function
int main() {
    int n;
    cout<<"Input  any Decimal number: ";
    cin>>n;
    decimalToHexa(n);
    return 0;
}
