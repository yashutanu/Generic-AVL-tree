#include<iostream>
#include<string>
using namespace std;
struct mystruct{
	string name;
	int age;
	
	mystruct():name(""),age(0){}
	
	mystruct(string s,int age_)
	:name(s),age(age_){}
	
	mystruct(const mystruct &rhs){
		name=rhs.name;
		age=rhs.age;
	}//copy constructor 
	
	mystruct& operator=(const mystruct &rhs){
	if(this != &rhs){
			name=rhs.name;
			age=rhs.age;
		}
		return *this;
	 }//copy assignment since u r doing  key = k in node stucture
	
	
	bool operator==(const mystruct &rhs){
			if(this != &rhs){
			return name==rhs.name && age==rhs.age;
		}
	 }
	
	
	bool operator!=(const mystruct &rhs){
			return !((*this)==rhs);
	 }
	
	friend bool operator<(const mystruct &lhs,const mystruct &rhs){
		return lhs.name<rhs.name;
	}
	
	friend bool operator>(const mystruct &lhs,const mystruct &rhs){
		return lhs.name>rhs.name;
	}
	
	bool operator>(const mystruct &rhs){
		return (this->name > rhs.name);
	}
	
	bool operator<(const mystruct &rhs){
		return (this->name < rhs.name);
	}	
	
	friend ostream& operator<<(ostream &o,const mystruct &rhs){
		return o<<"( "<<rhs.name<<" , "<<rhs.age<<" )\n";
	}

};




