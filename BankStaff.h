#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
class BankStaff
{
public:
    void CreateAccount();
    void DeleteCustomer(string CustomerId);
    void ModifyDetails(string CustomerId);
    void CreditMoney();
    void DebitMoney();
    void Query();
};
bool IsCutomerIdUnique(string CustomerId){
    ifstream customer_file("customer.csv");
    string line;
    while(getline(customer_file,line)){
        stringstream ss(line);
        string id;
        getline(ss,id,',');
        if(id==CustomerId){
            return false;
        }
        
        }
        return true;
}

void BankStaff ::CreateAccount()
{
    
       
        string CustomerId, Name, Type, Address1, Address2, Address3, City, State, Country, Pincode;
        cout << "Enter customer details:" << endl;
        cout << "Customer ID: ";
        cin >> CustomerId;
        while(!IsCutomerIdUnique(CustomerId)){
            cout<<"Customer Already Exist. please enter another Customer Id!!!"<<endl;
            cin>>CustomerId;
        }
        cout << "Name: ";
        cin >> Name;
        cout << "Type: ";
        cin >> Type;
        cout << "Address line 1: ";
        cin >> Address1;
        cout << "Address line 2: ";
        cin >> Address2;
        cout << "Address line 3: ";
        cin >> Address3;
        cout << "City: ";
        cin >> City;
        cout << "State: ";
        cin >> State;
        cout << "Country: ";
        cin>>Country;
       
        cout << "Pin code: ";
       cin>>Pincode;
   
        // Open the customer CSV file in append mode and write the new customer's details to it
        ofstream customer_file("customer.csv",ios::out | ios::app);
        // customer_file << "CustomerId, Name, Type, Address1, Address2, Address3, City, State, country, pincode" << endl;
        vector<string> customer_details;
        customer_details.push_back(CustomerId);
        customer_details.push_back(Name);
        customer_details.push_back(Type);
        customer_details.push_back(Address1);
        customer_details.push_back(Address2);
        customer_details.push_back(Address3);
        customer_details.push_back(City);
        customer_details.push_back(State);
        customer_details.push_back(Country);
        customer_details.push_back(Pincode);
        for (vector<string>::const_iterator i = customer_details.begin(); i != customer_details.end(); ++i)
        {
            customer_file << *i <<",";
        }
        customer_file<<endl;
        customer_file.close();
    }

void BankStaff ::DeleteCustomer(string CustomerId)
{
        ifstream customer_file("customer.csv");
        ofstream temp_file("temp.csv");
        string line;
        while (getline(customer_file, line))
        {
            stringstream ss(line);
            string id;
            getline(ss, id, ',');
            if (id != CustomerId)
            {
            temp_file << line << endl;
            }
        }
        customer_file.close();
        temp_file.close();

        // Remove the old customer CSV file and rename the temp file to customer.csv
        remove("customer.csv");
        rename("temp.csv", "customer.csv");

    ifstream customer_file1("accountinformation.csv");
    ofstream temp_file1("temp1.csv");
    string line1;
    while (getline(customer_file1, line1))
    {
        stringstream ss(line1);
        string col1, col2, col3,col4,col5,col6;
        getline(ss, col1, ',');
        getline(ss, col2, ',');
        getline(ss, col3, ',');
        getline(ss, col4, ',');
        getline(ss,col5, ',');
        getline(ss,col6, ',');
        if (col3 != CustomerId)
        {
            temp_file1 << col1 << "," << col2 << "," << col3 <<','<<col4<<','<<col5<<','<<col6<<endl;
        }
    }
    customer_file1.close();
    temp_file1.close();

    // Remove the old customer CSV file and rename the temp file to customer.csv
    remove("accountinformation.csv");
    rename("temp1.csv", "accountinformation.csv");
}

void BankStaff::ModifyDetails(string CustomerId)
{

string search_value = CustomerId;
    string filename = "customer.csv";
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
    
    int n;
cout<<"Enter 1 Name: "<<endl;
cout<<"Enter 2 Type: "<<endl;
cout<<"Enter 3 Address1: "<<endl;
cout<<"Enter 4 Address2: "<<endl;
cout<<"Enter 5 Address3: "<<endl;
cout<<"Enter 6 City: " <<endl;
cout<<"Enter 7 State: "<<endl;
cout<<"Enter 8 Country: "<<endl;
cout<<"Enter 9 Pincode: "<<endl;
cin>>n;
   string s1;
cout<<"Enter Detail to be update : ";
cin>>s1;
    
    // Search for the data and update it
   
    for (vector<vector<string> >::size_type i = 0; i < data.size(); i++) {
        if (data[i][0] == search_value) { // Change "0" to the column index you want to search
            // Update the data in the row
           // cout<<data[i][2];
           
            data[i][n] = s1;
           
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
}

void BankStaff ::CreditMoney()
{
    int accountNumber;
    double amount;
    cout<<"Enter Account Number :\n";
    while (!(cin >> accountNumber)) { 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid account number: ";
    }
    cout<<"Enter Amount :\n";
    while (!(cin >> amount)) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid amount: ";
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
    string search_value;
    stringstream ss3;
    ss3<<accountNumber;
    ss3>>search_value;
    
  
    // Search for the data and update it
   
    for (vector<vector<string> >::size_type i = 0; i < data.size(); i++) {
        if (data[i][0] == search_value) { // Change "0" to the column index you want to search
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

    
}
void BankStaff::DebitMoney()
{
    int accountNumber;
    double amount;
    cout<<"Enter Account Number :\n";
    while (!(cin >> accountNumber)) { 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid account number: ";
    }
    cout<<"Enter Amount :\n";
    while (!(cin >> amount)) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid amount: ";
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
    string search_value;
    stringstream ss3;
    ss3<<accountNumber;
    ss3>>search_value;
   
    for (vector<vector<string> >::size_type i = 0; i < data.size(); i++) {
        if (data[i][0] == search_value) { // Change "0" to the column index you want to search
            // Update the data in the row
          
           string s= data[i][5];
           string s1;
            stringstream ss;
            int number;
            ss<<s;
            ss>>number;
            if(number<amount){
                cout<<"Insufficient Balance Try Again:\n";
                DebitMoney();
            }
            else{
            number=number-amount;
            stringstream ss1;
            ss1<<number;
            ss1>>s1;
            data[i][5] = s1;
        
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
            break; 
        }
        }
    }
}

// void BankStaff ::Query()
// {
    
            // ifstream file("userinformation.csv");
            // string line;
            // while(getline(file,line)){
            //     cout<<line<<endl;
            // }
struct Node {
    string data;
    Node* next;
};
void BankStaff :: Query()  { 
            
    ifstream file("userinformation.csv");
    string line;
    Node* head = nullptr;
    Node* tail = nullptr;

    while (getline(file, line)) {
        Node* newNode = new Node;
        newNode->data = line;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
