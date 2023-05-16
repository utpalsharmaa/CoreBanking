#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


void ModifyDetails(string CustomerId)
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
int main(){
    cout<<" Welcome To Modify Details\n";
    string customerID;
    cout<<"Enter CustomerID to be modified: \n";
    cin>>customerID;
    ModifyDetails(customerID);
    cout<<"Details Modified Sucessfully!! \n";


}