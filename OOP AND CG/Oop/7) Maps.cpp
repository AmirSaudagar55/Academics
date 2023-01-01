//Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. 
//No two mapped values can have the same key values. Basically SAME LIKE DICTIONARY in python

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
typedef map<string,int> mapType;  //Typedefs allow you to give descriptive names to standard data types, which can also help you self-document your code.
mapType populationMap;

populationMap.insert(pair<string, int>("Maharashtra", 7026357));
populationMap.insert(pair<string, int>("Rajasthan", 6578936));
populationMap.insert(pair<string, int>("Karanataka", 6678993));
populationMap.insert(pair<string, int>("Punjab", 5789032));
populationMap.insert(pair<string, int>("West Bengal", 6676291));

mapType::iterator iter;
 //Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequences of numbers, characters etc. 
 //They reduce the complexity and execution time of the program.

cout<<"========Population of states in India==========\n";
cout<<"\n Size of populationMap"<<populationMap.size()<<"\n";

string state_name;
cout<<"\n Enter name of the state :";
cin>>state_name;

iter = populationMap.find(state_name);

if( iter!= populationMap.end() )
 cout<<state_name<<" 's population is "<<iter->second ;

else
 cout<<"Key is not populationMap"<<"\n";

populationMap.clear();
}
