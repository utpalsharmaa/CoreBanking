#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<regex>
#include "Customer.h"
#include "BankStaff.h"
using namespace std;

struct User
{
    string username;
    string password;
    User(string u, string p) : username(u), password(p) {}
};
vector<User> readUsers(const string &filename)
{
vector<User> users;
ifstream file(filename);
if (file.is_open())

{string line;
while (getline(file, line))
{istringstream iss(line);
string username, password;
if (getline(iss, username, ',') && getline(iss, password))
{
    // users.push_back( {username, password});  
users.push_back(User(username, password));
}
}
file.close();

}
    return users;
}
void Userinformation()
{
    int userid;
    string customer_id;
    string password;
    char usertype;
    int login_status = 0;
    cout << "Enter the following details for Create Customer Login Credential:\n" << endl;
    cout << "Customer ID: ";
    cin >> customer_id;
    cout << "Password: ";
    cin >> password;
    cout << "User type (B for Bank Clerk, C for Customer):\n ";
    cin >> usertype;
    // Generate unique numeric user ID
    // You can replace this with your own logic to generate unique user IDs
    userid = 1000 + rand() % 9000;
    // Check if the user ID already exists in the CSV file
    ifstream infile("userinformation.csv");
    string line;
    while (getline(infile, line))
    {
        if (line.find(to_string(userid)) != string::npos)
        {
            // User ID already exists, generate a new one
            userid = 1000 + rand() % 9000;
        }
    }
    infile.close();
    // Write user information to CSV file
    ofstream outfile("userinformation.csv", ios_base::app);
    outfile << userid << "," << customer_id << "," << password << "," << usertype << "," << login_status << endl;
    outfile.close();
    cout << "User information added successfully User ID is: " << userid << endl;
}
void CustomerAccount()
{
    cout << "Enter the following account details:" << endl;
    int account_number;
    string account_type, customer_id, account_status, opening_date;
    double balance;
    cout << "Account Number: \n";
    while(!(cin >> account_number)) 
    {
        cout << "Invalid input. Please enter a valid Account Number: "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    cout << "Account Type: ";
    cin >> account_type;
    cout << "Customer ID: ";
    cin >> customer_id;
    cout << "Account Status: ";
    cin >> account_status;
    // cout << "Opening Date: ";
    // cin >> opening_date;
    while(true){
      cout<<" Enter Opening Date: ";
        cin>>opening_date;
    if(!regex_match(opening_date, regex("\\d{2}-\\d{2}-\\d{4}"))){
        cout<<"Invalid input. Date must be in the format 'DD-MM-YYYY'.\n";}
    else{
        break;
        }
}
    cout << "Balance: ";
    while(!(cin >> balance)) 
    {
        cout << "Invalid input. Please enter a valid balance ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

    // Write account information to CSV file
    ofstream outfile("accountinformation.csv", ios_base::app);
    outfile << account_number << "," << account_type << "," << customer_id << "," << account_status << "," << opening_date << "," << balance << endl;
    outfile.close();

    cout << "Account information added successfully." << endl;


}
void writeUsers(const string &filename, const vector<User> &users)
{
    ofstream file(filename.c_str());
    if (file.is_open())
    {
        for (vector<User>::const_iterator it = users.begin(); it != users.end(); ++it)
        {
            file << it->username << "," << it->password <<endl;
        }
        file.close();
    }
}
bool isUserExists(const vector<User> &users, const string &username)
{
    for (vector<User>::const_iterator it = users.begin(); it != users.end(); ++it)
    {
        if (it->username == username)
        {
            return true;
        }
    }
    return false;
}
void signUp(vector<User> &users)
{
    string username, password;
    cout << "Enter a username for: \n";
    cin >> username;
    if (isUserExists(users, username))
    {
        cout << "User already exists. Please choose a different username." << endl;
        return;
    }
    cout << "Enter a password: \n";
    cin >> password;
    // users.push_back({username, password});
    users.push_back(User(username, password));
    writeUsers("users.csv", users);
    cout << "User registered successfully!" << endl;
}
bool signIn(const vector<User> &users)
{
    string username, password;
    cout << "Enter your username: \n";
    cin >> username;
    cout << "Enter your password: \n";
    cin >> password;
    bool found = false;
    for (vector<User>::const_iterator it = users.begin(); it != users.end(); ++it)
    {
        if (it->username == username && it->password == password)
        {
            found = true;
            break;
        }
    }
    return found;
}

bool clerk_login()
{
    int exit;
    string username, password;
    string un, pw;
    cout << "Enter Clerk Username:\n";
    cin >> username;
    cout << "Enter password:\n";
    cin >> password;
    ifstream input("clerk.csv");
    while (input >> un >> pw)
    {
        if (un == username && pw == password)
        {
            exit = 1;
        }
    }
    input.close();
    if (exit == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int exit(){
    return 0;
}
void bank()
{
     vector<User> users = readUsers("users.csv");
     int n3;
                    cout << "Enter 1 for Create Account:\n";
                    cout << "Enter 2 for DeleteCustomer:\n";
                    cout << "Enter 3 for ModifyDetails:\n";
                    cout << "Enter 4 for CreditMoney:\n";
                    cout << "Enter 5 for DebitMoney:\n";
                    cout << "Enter 6 for Query:\n";
                    cout<<"Enter 7 for Exit:\n";
                    cin >> n3;
                    BankStaff b1;
                    string customer_id;
                    switch (n3)
                    {
                    case 1:
                        b1.CreateAccount();
                        Userinformation();
                        signUp(users);
                        CustomerAccount();
                        bank();
                        break;
                    case 2:
                    cout << "Enter the customer ID to delete: ";
                        cin>>customer_id;
                        b1.DeleteCustomer(customer_id);
                        bank();
                        break;
                       
                    case 3:
                        cout << "Enter Customer ID to modify: ";
                        // getline(cin, customer_id);
                        cin >> customer_id;
                        b1.ModifyDetails(customer_id);
                        bank();
                        break;
                    case 4:
                         b1.CreditMoney();
                         bank();
                        break;
                    case 5:
                    b1.DebitMoney();
                    bank();
                        break;
                        
                    case 6:
                        b1.Query();
                        bank();
                        break;
                    case 7:
                       exit();
                        break;
                    default:
                        break;
}
}
void user(){
    Customer c1;
                    int n2;
                    cout << "Enter 1 for View Details\n";
                    cout << "Enter 2 for MoneyTransfer\n";
                    cout << "Enter 3 for Query \n";
                    cout<<"Enter 4 for Exit:\n";
                    cin >> n2;
                    switch (n2)
                    {
                    case 1:
                        c1.ViewDetails();
                        user();
                        break;
                    case 2:
                        c1.MoneyTransfer();
                        user();
                        break;
                    case 3:
                        c1.Query();
                        user();
                        break;
                    case 4:
                          exit();
                    break;
                    default:
                        break;
}
}

int main()
{
    try{
    vector<User> users = readUsers("users.csv");
    int n;
    cout << "Enter 1 for Customer login: \n";
    cout<< "Enter 2 to for BankStaff login: \n";
    cout<<"Enter 3 for Exit: \n";
    cin >> n;
    switch (n)
    {
    case 1:
        int choice1;
        while (true)
        {
            cout << "\nMenu:" << endl;
            cout << "1. Sign In " << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
                if (signIn(users) == true)
                {
                    user();
        
                    }
                
                
                else
                {
                    cout << "Username and Password is not correct!!";
                    cout << "\n Try Again!!";
                }
               break; 
        
                break;
            case 2:
                main();
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        break;
    

    case 2:
        int choice;
        while (true)
        {
            cout << "\nMenu:" << endl;
            
            cout << "1. Sign In" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                if (clerk_login() == true)
                {
                   bank();
                    }
                
                else
                {
                    cout << "Failed";
                }
                break;
            case 2:
                main();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        
        break;
    default:
        break;
    }
    }
    catch(const exception& e)
    {
        cerr << "Error: please try again !!" << e.what() <<endl;
    }

}