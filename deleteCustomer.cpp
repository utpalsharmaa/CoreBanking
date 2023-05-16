#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void DeleteCustomer(string CustomerId)
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
int main(){
                    string customer_id;
                    cout << "Enter the customer ID to delete: ";
                        cin>>customer_id;
                    DeleteCustomer(customer_id);
                    cout<<"Customer Deleted Sucessfully!! \n";
                    return 0;
}