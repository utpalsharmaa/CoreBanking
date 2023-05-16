#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
void ViewDetails()
{
    string customer_id, name, type, address1, address2, address3, city, state, country, pincode;
    
    cout<<"Enter customer Id for View Details :\n";
    cin>>customer_id;
    ifstream customer_file("customer.csv");
    string customer_line;
    while (getline(customer_file, customer_line))
    {
        stringstream customer_ss(customer_line);
        string customer_field;
        getline(customer_ss, customer_field, ',');
        if (customer_field == customer_id)
        {
            getline(customer_ss, name, ',');
            getline(customer_ss, type, ',');
            getline(customer_ss, address1, ',');
            getline(customer_ss, address2, ',');
            getline(customer_ss, address3, ',');
            getline(customer_ss, city, ',');
            getline(customer_ss, state, ',');
            getline(customer_ss, country, ',');
            getline(customer_ss, pincode, ',');

            break;
        }
    }
    customer_file.close();

    ifstream account_file("accountinformation.csv");
    string account_line;
    cout << "Account details for customer ID " << customer_id << ":\n";
    cout << "Account Number\tType\t\tStatus\tBalance\tOpening Date\n";
    while (getline(account_file, account_line))
    {
        stringstream account_ss(account_line);
        string account_field;
        getline(account_ss, account_field, ',');
        if (account_field == customer_id)
        {
            string account_number, account_type, account_status, account_balance, account_date;
            getline(account_ss, account_number, ',');
            getline(account_ss, account_type, ',');
            getline(account_ss, account_status, ',');
            getline(account_ss, account_balance, ',');
            getline(account_ss, account_date, ',');
            cout << account_number << "\t\t" << account_type << "\t\t" << account_status << "\t" << account_balance << "\t" << account_date << std::endl;
        }
    }
    account_file.close();

    cout << "\nCustomer details for ID " << customer_id << ":\n";
    cout << "Name: " << name<< endl;
    cout << "Type: " << type << endl;
    cout << "Address1: " << address1 << endl;
    cout << "Address2: " << address2 << endl;
    cout << "Address3: " << address3 << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Country: " << country << endl;
    cout << "Pincode: " << pincode << endl;
   
}
int main(){
    cout<<"Welcome to View Details \n";
    ViewDetails();
}

