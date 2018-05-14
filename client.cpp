#include <iostream>
#include <vector>
#include "avltree.cpp"
#include "mystruct.cpp"
using namespace std;

int main()
{
{
cout<<"case 1:int key,myless predicate\n";	
	 myless<int> l;
	 AVL<int,myless<int>> myroot(l);
	 vector<int> v{20,10,5,30,25,40};
	 myroot.generate_avl(v.begin(),v.end());
	  
	cout<<"forward traversal\n";
	auto itr = myroot.begin();
	for(; itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }

	cout<<"\n\nbackward traversal\n";
	//AVL<int,myless<int>>::MyIterator itr1=new AVL<int,myless<int>>::MyIterator();
	auto itr1 = myroot.end();
	while(itr1!=myroot.begin()){	
		itr1--;
		cout<< *itr1<<" ";
	}
	
	int  num=5;
	cout<<"\n\ngeneric find : "<<num<<"\n";
	auto ff=find(myroot.begin(),myroot.end(),num);
	if(ff==myroot.end()) {
		cout<<"not found\n";
	}
	else{
		cout<<"found,element is: "<<*ff<<"\n";
	}

	num=100;
	cout<<"\n\ngeneric find :  "<<num<<"\n";
	auto ff1=find(myroot.begin(),myroot.end(),num);
	if(ff1==myroot.end()) {
		cout<<"not found\n\n";
	}
	else{
		cout<<"found,element is: "<<*ff1<<"\n\n";
	}
	
	
	cout<<"copy tree elements to vector and display from vector\n";
	vector<int> v1;
	mycopy(myroot.begin(),myroot.end(),v1);
	for(auto e:v1){
		cout<<e<<" ";
	}
	
	 num=40;
	cout<<"\n\ndeleting element :"<<num<<"\n";
	
	myroot.del(num);
	cout<<"after delete\n";
	cout<<"forward traversal\n";
	//myroot.traversal();
	for(auto itr = myroot.begin(); itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	cout<<"\n\n\n\n";
	
}

{	
	cout<<"case 2:string key,myless predicate\n";
	 myless<string> l;
	 AVL<string,myless<string>> myroot(l);
	 vector<string> v{"ab","bc","cd","de","ef"};
	 myroot.generate_avl(v.begin(),v.end());
	 //myroot.traversal();
	  
	cout<<"forward traversal\n";
	auto itr = myroot.begin();
	for(; itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	//cout<<"*itr:"<<*itr<<"\n";

	cout<<"\n\nbackward traversal\n";
	//AVL<int,myless<int>>::MyIterator itr1=new AVL<int,myless<int>>::MyIterator();
	auto itr1 = myroot.end();
	while(itr1!=myroot.begin()){	
		itr1--;
		cout<< *itr1<<" ";
	}

	string ele="myname";
	cout<<"\n\ngeneric find ele: "<<ele<<"\n";
	auto ff=find(myroot.begin(),myroot.end(),ele);
	if(ff==myroot.end()) {
		cout<<"not found\n";
	}
	else{
		cout<<"found,element is: "<<*ff<<"\n";
	}

	ele="ab";
	cout<<"\n\ngeneric find ele:  "<<ele<<"\n";
	auto ff1=find(myroot.begin(),myroot.end(),ele);
	if(ff1==myroot.end()) {
		cout<<"not found\n\n";
	}
	else{
		cout<<"found,element is: "<<*ff1<<"\n\n";
	}
	
	
	cout<<"copy tree elements to vector and display vector\n";
	vector<string> v1;
	mycopy(myroot.begin(),myroot.end(),v1);
	for(auto e:v1){
		cout<<e<<" ";
	}
	
	
	string st="ab";
	cout<<"\n\n\ndeleting element :"<<st<<"\n";
	myroot.del(st);
	cout<<"after delete\n";
	cout<<"forward traversal\n";
	for(auto itr = myroot.begin(); itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	cout<<"\n\n\n\n";
	
}
	
{	
cout<<"case 3:strcture key,myless predicate\n";
	myless<mystruct> l;
	AVL<mystruct,myless<mystruct>> myroot(l);
	vector<mystruct> v{
		mystruct("de",12),
		mystruct("bc",11),
		mystruct("fg",55),
		mystruct("ab",77),
		mystruct("cd",66),
		mystruct("ef",44),
		mystruct("gh",33)
	};
	myroot.generate_avl(v.begin(),v.end());
	cout<<"forward traversal\n";
	auto itr = myroot.begin();
	for(; itr != (myroot.end()); itr++){
		 cout << (*itr);
	 }
	//cout<<"*itr:"<<*itr<<"\n";

	cout<<"\n\nbackward traversal\n";
	//AVL<int,myless<int>>::MyIterator itr1=new AVL<int,myless<int>>::MyIterator();
	auto itr1 = myroot.end();
	while(itr1!=myroot.begin()){	
		itr1--;
		cout<< *itr1;
	}
	
	mystruct ele("de",12);
	cout<<"\n\ngeneric find ele: "<<ele<<"\n";
	auto ff=find(myroot.begin(),myroot.end(),ele);
	if(ff==myroot.end()) {
		cout<<"not found\n";
	}
	else{
		cout<<"found,element is: "<<*ff<<"\n";
	}
	
	mystruct ele1("myname",44);
	cout<<"\n\ngeneric find ele:  "<<ele1<<"\n";
	auto ff1=find(myroot.begin(),myroot.end(),ele1);
	if(ff1==myroot.end()) {
		cout<<"not found\n\n";
	}
	else{
		cout<<"found,element is: "<<*ff1<<"\n\n";
	}
	
	
	cout<<"copy tree elements to vector a display vector\n";
	vector<mystruct> v1;
	mycopy(myroot.begin(),myroot.end(),v1);
	for(auto e:v1){
		cout<<e<<" ";
	}
	
	
	mystruct st("de",12);
	cout<<"\ndeleting element :"<<st<<"\n";
	myroot.del(st);//2,4,5 ok    1,3 not ok
	cout<<"after delete\n";
	cout<<"forward traversal\n";
	for(auto itr = myroot.begin(); itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	cout<<"\n\n\n\n";
	
}
{	 
	cout<<"case 4:int key,mygreter predicate\n";
	#if 1 
	 mygreater<int> l;
	 AVL<int,mygreater<int>> myroot(l);
	 vector<int> v{20,10,5,30,25,40};
	 myroot.generate_avl(v.begin(),v.end());
	  
	cout<<"forward traversal\n";
	auto itr = myroot.begin();
	for(; itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }

	cout<<"\n\nbackward traversal\n";
	//AVL<int,myless<int>>::MyIterator itr1=new AVL<int,myless<int>>::MyIterator();
	auto itr1 = myroot.end();
	while(itr1!=myroot.begin()){	
		itr1--;
		cout<< *itr1<<" ";
	}
	
	int  num=5;
	cout<<"\n\ngeneric find : "<<num<<"\n";
	auto ff=find(myroot.begin(),myroot.end(),num);
	if(ff==myroot.end()) {
		cout<<"not found\n";
	}
	else{
		cout<<"found,element is: "<<*ff<<"\n";
	}

	num=100;
	cout<<"\n\ngeneric find :  "<<num<<"\n";
	auto ff1=find(myroot.begin(),myroot.end(),num);
	if(ff1==myroot.end()) {
		cout<<"not found\n\n";
	}
	else{
		cout<<"found,element is: "<<*ff1<<"\n\n";
	}
	
	
	cout<<"copy tree elements to vector and display from vector\n";
	vector<int> v1;
	mycopy(myroot.begin(),myroot.end(),v1);
	for(auto e:v1){
		cout<<e<<" ";
	}
	
	 num=40;
	cout<<"\n\ndeleting element :"<<num<<"\n";
	
	myroot.del(num);
	cout<<"after delete\n";
	cout<<"forward traversal\n";
	//myroot.traversal();
	for(auto itr = myroot.begin(); itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	
	cout<<"\n\n\n\n";
	#endif
}

{	
	
 	#if 1
 	cout<<"case 5:string key,mygreater predicate\n";
	 mygreater<string> l;
	 AVL<string,mygreater<string>> myroot(l);
	 vector<string> v{"ab","bc","cd","de","ef"};
	 myroot.generate_avl(v.begin(),v.end());
	 //myroot.traversal();
	  
	cout<<"forward traversal\n";
	auto itr = myroot.begin();
	for(; itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	//cout<<"*itr:"<<*itr<<"\n";

	cout<<"\n\nbackward traversal\n";
	//AVL<int,myless<int>>::MyIterator itr1=new AVL<int,myless<int>>::MyIterator();
	auto itr1 = myroot.end();
	while(itr1!=myroot.begin()){	
		itr1--;
		cout<< *itr1<<" ";
	}

	string ele="myname";
	cout<<"\n\ngeneric find ele: "<<ele<<"\n";
	auto ff=find(myroot.begin(),myroot.end(),ele);
	if(ff==myroot.end()) {
		cout<<"not found\n";
	}
	else{
		cout<<"found,element is: "<<*ff<<"\n";
	}

	ele="ab";
	cout<<"\n\ngeneric find ele:  "<<ele<<"\n";
	auto ff1=find(myroot.begin(),myroot.end(),ele);
	if(ff1==myroot.end()) {
		cout<<"not found\n\n";
	}
	else{
		cout<<"found,element is: "<<*ff1<<"\n\n";
	}
	
	
	cout<<"copy tree elements to vector and display vector\n";
	vector<string> v1;
	mycopy(myroot.begin(),myroot.end(),v1);
	for(auto e:v1){
		cout<<e<<" ";
	}
	
	
	string st="ab";
	cout<<"\n\n\ndeleting element :"<<st<<"\n";
	myroot.del(st);
	cout<<"after delete\n";
	cout<<"forward traversal\n";
	for(auto itr = myroot.begin(); itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	cout<<"\n\n\n\n";
	#endif
	
 }
 
 {
	#if 1
	cout<<"case 6:struct key,mygreater predicate\n";
	mygreater<mystruct> l;
	AVL<mystruct,mygreater<mystruct>> myroot(l);
	vector<mystruct> v{
		mystruct("de",12),
		mystruct("bc",11),
		mystruct("fg",55),
		mystruct("ab",77),
		mystruct("cd",66),
		mystruct("ef",44),
		mystruct("gh",33)
	};
	myroot.generate_avl(v.begin(),v.end());
	cout<<"forward traversal\n";
	auto itr = myroot.begin();
	for(; itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	//cout<<"*itr:"<<*itr<<"\n";

	cout<<"\n\nbackward traversal\n";
	//AVL<int,myless<int>>::MyIterator itr1=new AVL<int,myless<int>>::MyIterator();
	auto itr1 = myroot.end();
	while(itr1!=myroot.begin()){	
		itr1--;
		cout<< *itr1<<" ";
	}

	mystruct ele("ab",77);
	cout<<"\n\ngeneric find ele: "<<ele<<"\n";
	auto ff=find(myroot.begin(),myroot.end(),ele);
	if(ff==myroot.end()) {
		cout<<"not found\n";
	}
	else{
		cout<<"found,element is: "<<*ff<<"\n";
	}

	mystruct st1("myname",11);
	cout<<"\n\ngeneric find ele:  "<<st1<<"\n";
	auto ff1=find(myroot.begin(),myroot.end(),st1);
	if(ff1==myroot.end()) {
		cout<<"not found\n\n";
	}
	else{
		cout<<"found,element is: "<<*ff1<<"\n\n";
	}
	
	mystruct st("gh",33);
	cout<<"deleting element :"<<st<<"\n";
	myroot.del(st);//2,4,5 ok    1,3 not ok
	cout<<"after delete\n";
	cout<<"forward traversal\n";
	for(auto itr = myroot.begin(); itr != (myroot.end()); itr++){
		 cout << (*itr) <<" ";
	 }
	cout<<"\n\n\n\n";
	
#endif
}
 return 0; 
}

