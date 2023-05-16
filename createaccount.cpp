#include <iostream>
#include <fstream>
#include <vector>
#include<regex>
#include <sstream>
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
void CustomerAccount()
{
    cout << "Enter the following account details:" << endl;
    int account_number;
    string account_type, customer_id, account_status, opening_date;
    double balance;
    cout << "Account Number: ";
    while(!(cin >> account_number)) 
    {
        cout << "Invalid input. Please enter a valid AccountNumber\n:";
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

void CreateAccount()
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
    int main(){
         vector<User> users = readUsers("users.csv");
                        CreateAccount();
                        Userinformation();
                        signUp(users);
                        CustomerAccount();
                        return 0;
    }