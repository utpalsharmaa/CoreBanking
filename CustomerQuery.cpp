 #include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
 void Query()
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
int main(){
    cout<<"Welcome to Customer Query \n";
    Query();
}