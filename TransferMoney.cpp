#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void MoneyTransfer()
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
    for (vector<vector<string> >::size_type i = 0; i < data.size(); i++) {
        if (data[i][0] == search_value2) { // Change "0" to the column index you want to search
          
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
int main(){
    cout<<"Welcome To Money Transfer\n";
    MoneyTransfer();
    cout<<"Money Transfered Sucessfully!! \n";
}