#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


void DebitMoney()
{
    int accountNumber;
    double amount;
    // cout<<"Enter Account Number :\n";
    // cin>>accountNumber;
    // cout<<"Enter Amount :\n";
    // cin>>amount;
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
}
int main(){
    cout<<"Welcome to Debit Money:\n";
    DebitMoney();
    cout<<"Money Debited Sucessfully!! \n";
}