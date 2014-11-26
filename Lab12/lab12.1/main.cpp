#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    //Payfile is defined as the input file
    ifstream payfile;
    //Variables
    float gross;
    float net;
    float hours;
    float payRate;
    float stateTax;
    float fedTax;
    
    cout<<fixed<<setprecision(2)<<showpoint;
    
    //Infile opens as payroll.dat
    payfile.open("payroll.dat");
    
    if (!payfile)
    {
        cout<<"Error opening file.\n";
        cout<<"Perhaps the file is not where indicated.\n";
        return 1;
    }
    
    cout<<"Payrate      Hours   Gross Pay       Net Pay"
            <<endl <<endl;
    //Priming the read
    payfile>>hours;
    
    while (payfile){
      payfile>>payRate>>stateTax>>fedTax;
      gross=payRate*hours;
      net=gross-(gross*stateTax)-(gross*fedTax);
      cout<<payRate<<setw(15)<<hours<<setw(12)<<gross<<setw(12)<<net<<endl;
      payfile>>gross;
    }
    
    payfile.close();
    return 0;
}

