#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
class Customer
{
private:
public:
    void ViewDetails();
    void MoneyTransfer();
    void Query();
};
void Customer ::ViewDetails()
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
            // std::cout <<"Account Number:"<< account_number <<endl;
            // cout <<"Account Type: "<< account_type <<endl;
            // cout<<"Account Status: "<< account_status << endl;
            // cout <<"Account Balance: "<<account_balance << endl;
            // cout<<"Account Opening Date: " <<account_date << std::endl;
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


void Customer ::MoneyTransfer()
{ 
   int accountNumberSrc, accountNumberDest;
    double amount;
    cout<<"Enter Source Account Number :\n";
    while(!(cin >> accountNumberSrc)) 
    {
        cout << "Invalid input. Please enter a int type Account Number ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    cout<<"Enter Dest Account Number :\n";
    while(!(cin >> accountNumberDest)) 
    {
        cout << "Invalid input. Please enter a int type Account Number ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    
    cout<<"Enter Amount :\n";
    while(!(cin >> amount)) 
    {
        cout << "Invalid input. Please enter a valid amount ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    string filename = "accountinformation.csv";
    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "File not found!" << endl;
        
    }
    // Read the CSV file into a 2D vector
    vector<vector<string> > data;
    string line;
    while (getline(fin, line)) {
        vector<string> row;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    string search_value1,search_value2;
    stringstream ss4;
    ss4<<accountNumberDest;
    ss4>>search_value2;
    stringstream ss3;
    ss3<<accountNumberSrc;
    ss3>>search_value1;
     
    
  
    // Search for the data and update it
   
    for (vector<vector<string> >::size_type i = 0; i < data.size(); i++) {
        if (data[i][0] == search_value2) { // Change "0" to the column index you want to search
            // Update the data in the row
           // cout<<data[i][2];
           string s= data[i][5];
           string s1;
            stringstream ss;
            int number;
            ss<<s;
            ss>>number;
            
           
            number=number+amount;
            stringstream ss1;
            ss1<<number;
            ss1>>s1;
            data[i][5] = s1;
           
            // Add more updates as needed
            
            // Write the updated data back to the CSV file
            ofstream fout(filename.c_str());
            for (vector<vector<string> >::size_type j = 0; j < data.size(); j++) {
                for (vector<string>::size_type k = 0; k < data[j].size(); k++) {
                    fout << data[j][k];
                    if (k != data[j].size() - 1) {
                        fout << ",";
                    }
                }
                fout << endl;
            }
            fout.close();
            break; // Exit the loop after the first match is found (if there are multiple matches, this can be modified)
        
        }
    }

    for (vector<vector<string> >::size_type i = 0; i < data.size(); i++) {
        if (data[i][0] == search_value1) { // Change "0" to the column index you want to search
            // Update the data in the row
           // cout<<data[i][2];
           string s= data[i][5];
           string s1;
            stringstream ss;
            int number;
            ss<<s;
            ss>>number;
            
           
            number=number-amount;
            stringstream ss1;
            ss1<<number;
            ss1>>s1;
            data[i][5] = s1;
           
            // Add more updates as needed
            
            // Write the updated data back to the CSV file
            ofstream fout(filename.c_str());
            for (vector<vector<string> >::size_type j = 0; j < data.size(); j++) {
                for (vector<string>::size_type k = 0; k < data[j].size(); k++) {
                    fout << data[j][k];
                    if (k != data[j].size() - 1) {
                        fout << ",";
                    }
                }
                fout << endl;
            }
            fout.close();
            break; // Exit the loop after the first match is found (if there are multiple matches, this can be modified)
        
        }
    }
    char c = 'D';
    int TransId;
    TransId = 1000 + rand() % 9000;
    ofstream file("transactiondetails.csv");
    file<<accountNumberSrc<<","<<c<<","<<accountNumberSrc<<","<<accountNumberDest<<","<<amount<<","<<TransId;
    file.close();
}
void Customer ::Query()
{
    vector<string>record;
  ifstream file;
  file.open("transactiondetails.csv");
  bool found_record = false;
  string f_name;
  string l_name;
  string number;
  cout<<""<<endl;
  cout<<"Enter your Account : "<<endl;
   cin>>number;

  while(getline(file,f_name, ','))
  {
      getline(file,l_name);
      if(f_name==number)
      {
        found_record=true;
        record.push_back(f_name);
        record.push_back(l_name);
      }
  }
  cout<<""<<endl;
  for(int i=0;i<record.size();i+=2)
  {
    
    cout<<record[i]<<" "<<record[i+1]<<endl;
  }
    cout<<""<<endl;
}