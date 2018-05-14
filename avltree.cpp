#include<iostream>
#include<vector>
using namespace std;
#define MAX(a,b) (((a)>(b))?(a):(b)) 

//AVL tree class
//T-class Node<Type>
//C-comparator<l,r>

template<typename T>
struct myless
{
	bool operator()(const T& lhs, const T& rhs)  const
	{
		return lhs<rhs;
	}
};


template<typename T>
struct mygreater
{
	bool operator()(const T& lhs, const T& rhs)  const
	{
	
			return lhs>rhs;
	}
};

template<typename T>
struct Node
{
	T key;  //element
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent;//for ++ and --  u need to know the parent
	int height;
	int bf;
	Node<T>(T k=0)
	{  key=k;
	   left=nullptr;
	   right=nullptr;
	   parent=nullptr;
	   height=0;
	   bf=0;	
	}
	
	 friend ostream& operator<<(ostream &o,const  Node<T> &r){
		return o<<r.key;	
         }
         
        bool operator==(const  Node<T> &r){
		return this->key==r.key;	
         }
         
         bool operator<(const  Node<T> &r){
		return this->key<r.key;	
         }
         
};



template<typename T,typename Compare>
class AVL
{       private:
	Compare comp_;
	Node<T>* parent;  
 	public:
	explicit AVL(Compare c) :comp_(c), parent(nullptr){ }
	bool operator()(T l,T r) { 
		return comp_(l,r);
	}
	
	//start of iterator
	
        class MyIterator:public std::iterator<bidirectional_iterator_tag,Node<T> >
	{
	private:
		Node<T>* node;//pointer to treenode
		Node<T>* root_it;
	public:
		typedef bidirectional_iterator_tag iterator_category;
		
		MyIterator(Node<T> *n_,Node<T> *pp=nullptr){
			node=n_;
			root_it=pp;
		}
	
		MyIterator& operator=(MyIterator &r){//copy assignment
			node=r.node;
			root_it=r.root_it;
			return *this;
		}
		
		MyIterator(MyIterator &r){//copy constr
			node=r.node;
			root_it=r.root_it;
		}
		
		MyIterator(const MyIterator &r_){node=&(*r_);}
	
		MyIterator& operator=(const MyIterator  &r_){
			node=&(*r_);
			return *this;
		}
	
		MyIterator& operator++(){
			    Node<T> *temp;
			    //node has a right child
			    // so successor is leftmost node of right subtree
			    if(node->right != nullptr)
			    {
				temp = node->right; //go right
				//go all the way left
				while(temp->left != nullptr)
				{
				    temp = temp->left; 
				}
				node=temp;
				return *this;
			    }
			   else{	
			    //node has no right child
			    //if we are someone's left child, go up one
			    if(node->parent->left == node)
			    {
				//return your parent
				temp = node->parent;
				node=temp;
				return *this;
			    }
			    //if node is someone's right child, go up until the current node
			    //if node is left child, then go up one more
			    temp = node->parent;
			    while(temp->parent && temp->parent->left!= temp)
			    {
				temp = temp->parent; 
			    }
			    //return your parent
			    temp = temp->parent;
			    node=temp;
			    return *this;
			}
		    }
			
	
	
		MyIterator& operator--(){
		if(node==nullptr){
			Node<T> *temp=root_it;
			while(temp->right!=nullptr){
					temp=temp->right;
				}
				node=temp;
			return *this;
		}
		else{
		Node<T> * temp;
		if(node->left != nullptr)
			    {
				temp = node->left; //go left
				//go all the way right
				while(temp->right != nullptr)
				{
				    temp = temp->right; 
				}
				node=temp;
				return *this;
			    }
		else{
			
			 if(node->parent->right == node)
			    {
			//if node is right child of its parent
				temp = node->parent;
				node=temp;
				return *this;
			    }
			    //if node is left child, then go up one more
			    temp = node->parent;
			    while(temp->parent && temp->parent->right!= temp)
			    {
				temp = temp->parent; //go up 
			    }
			    //return your parent
			    temp = temp->parent;
			    node=temp;
			    return *this;
		    }
		}
		}	
	
		MyIterator operator++(int){
			MyIterator temp(*this);
			this->operator++();
			return temp;
		}
	
		MyIterator operator--(int){
			MyIterator temp(*this);
			this->operator--();
			return temp;
		}
	
		Node<T>& operator*()const{
			return *node;
		}
	
		Node<T>* operator->() const{
			return node;
		}
	
		bool operator==(const MyIterator &r){
			return (node)==(r.node);
		}
	
		bool operator!=(const MyIterator  &r){
			return !(node==r.node);
		}
			
	};


	
	MyIterator begin()
	{
	  Node<T> *curr = parent;
	   if (curr != nullptr)
	    while (curr->left != nullptr){
	      		curr = curr->left;
	  	}
	  return MyIterator(curr,parent);
	}

	
	 MyIterator end()
	{
	  return MyIterator(nullptr,parent);
	}

	typedef MyIterator iterator;	
	
	//end of iterator functions

	int height(Node<T>* root)
   	  {
     		if(root==nullptr)
       			return -1;
      		return (root->height);
   	  }

          Node<T>* insert(Node<T>*root,T key)
   	  {
	   	  if(root==NULL)
	   	     {
	      		Node<T>* temp=new Node<T>(key);
	      		return temp;
	     	     }
		  if((*this)(key,root->key))
		     {
			root->left=(*this).insert(root->left,key);
			(root->left)->parent=root;
			//cout<<"parent of:"<<(root->left)->key<<":"<<((root->left)->parent)->key<<"\n";
		     }
		  else{
		  root->right=(*this).insert(root->right,key);
		  (root->right)->parent=root;
		  //cout<<"parent of:"<<(root->right)->key<<":"<<((root->right)->parent)->key<<"\n";

		  }
		  root->bf=(*this).balanced_factor(root);
		  if((root->bf)>1)
		    {
	      		if((*this).height((root->left)->left)>=(*this).height((root->left)->right))
	      			{  return (*this).rotate_right(root);}
	      		else
		 		{ root->left=(*this).rotate_left(root->left); 
		         		return (*this).rotate_right(root);
		 		}
	   	    }
	   	  if((root->bf) < -1)
	   	    {
	     		if((*this).height((root->right)->right)>=(*this).height((root->right)->left)) 
	      			{   return (*this).rotate_left(root);}
	      		else
		 		{ root->right=(*this).rotate_right(root->right); 
		         		return (*this).rotate_left(root);
		 		}
	   	    }
	   	    root->height=MAX((*this).height(root->left),(*this).height(root->right))+1;
	   	    return root;
 	  }

 	  int balanced_factor(Node<T> *root)
 	  { 
   		int l=(*this).height(root->left);
       		int r=(*this).height(root->right);
   		return l-r;
 	  }

	  Node<T>* rotate_right(Node<T>*root)
 	  {
   		if(root==NULL || (root->left)==NULL) return root;
                Node<T>* newroot=root->left;
    		root->left=newroot->right;
		if((newroot->right) != NULL)
		{
  		    newroot->right->parent=root;
		}
		newroot->parent=root->parent;
		if((root->parent) != NULL)
		{
			 if(root== (root->parent)->right)
			 	root->parent->right=newroot;
			else
				root->parent->left=newroot;
		}
		root->parent=newroot;
		newroot->right=root;
   		root->height=MAX((*this).height(root->left),(*this).height(root->right))+1;
   		newroot->height=MAX((*this).height(newroot->left),(*this).height(newroot->right))+1;
   		root->bf=(*this).balanced_factor(root);
   		newroot->bf=(*this).balanced_factor(root);
   		return newroot;
  	  }

          Node<T>* rotate_left(Node<T>* root)
  	  {   
                if(root==NULL || (root->right)==NULL) return root;
                Node<T>* newroot=root->right;
    		root->right=newroot->left;
		if((newroot->left) != NULL)
		{
  		    newroot->left->parent=root;
		}
		newroot->parent=root->parent;
		if((root->parent) != NULL)
		{
			 if(root== (root->parent)->left)
			 	root->parent->left=newroot;
			else
				root->parent->right=newroot;
		}
		root->parent=newroot;
		newroot->left=root;
    		root->height=MAX((*this).height(root->left),(*this).height(root->right))+1;
    		newroot->height=MAX((*this).height(newroot->left),(*this).height(newroot->right))+1;
    		root->bf=(*this).balanced_factor(root);
    		newroot->bf=(*this).balanced_factor(root);
    		return newroot;
  	  }

	 

	template<typename it>
        void generate_avl(it first,it end)
	{
                  while(first!=end){
				
					parent=(*this).insert(parent,*first);
			                ++first;
			}
        }
        void inorder(Node<T>* t)
 	  {
  		if(t != NULL)
  		{  
                    (*this).inorder(t->left);
       	           // if(t!=parent)
       	             //      	cout<<t->key<<":parent"<<(t->parent)->key<<":"<<"\n";
       	                   	
       	            //else
       	             //cout<<t->key<<"\n";
       		     (*this).inorder(t->right);
                    
  		}  
 	  }
   
	 Node<T>* balance_tree(Node<T>* root)
	  {
  	  if((root->bf) >1)
   	     {
	        if((*this).height((root->left)->left)>=(*this).height((root->left)->right)) 
     		      {return (*this).rotate_right(root); }
      		else
                {
                 root->left=(*this).rotate_left(root->left);  
                 return (*this).rotate_right(root);
	         }
	     }
   	   if((root->bf) < -1)
             {
		if((*this).height((root->right)->right)>=(*this).height((root->right)->left))
                {  return (*this).rotate_left(root);}
      		else 
         	{
                 	root->right=(*this).rotate_right(root->right); 
                 	return (*this).rotate_left(root);
		 }
	     }
           return root;
	   }

          Node<T>* deleteNode(Node<T>* root,T key)
	  {
  		Node<T>* p=NULL;
  		Node<T>* prev;
  		if((root->key)==key)
  		{
     			Node<T>* lt=NULL;
    			Node<T>* rt=NULL;
     			lt=root->left;
     			rt=root->right;
     			if(lt==NULL && rt==NULL)
            			return NULL;
    		 	else if(lt==NULL)
    			{
          			p=rt;
          			p->parent=root->parent;
          			//cout<<"lt\n";
          			return p;
     			}
     			else if(rt==NULL)
     			{
          			p=lt;
          			p->parent=root->parent;
          			//cout<<"rt\n";
          			return p;
     			}
     			else
     			{       
				prev=NULL;
				p=rt;
				while((p->left)!=NULL)
				{       prev=p;
					p=p->left;
					
				}
        			root->key=p->key;
  				if(prev==NULL)
				{	
				        root->right=p->right;
				        if(p->right != NULL)
				             (p->right)->parent=root;
				       
				
				}
                             	else
				{	prev->left=p->right;
				       if(p->right != NULL)
				             (p->right)->parent=prev;
				        
				
				}
        			return root;
     			 }
       		}
     		if((*this)(key,root->key))
		{ 
		  root->left=(*this).deleteNode(root->left,key);
	        }
    		else
		{
		 root->right=(*this).deleteNode(root->right,key);
	        }
    		if(root)
		{        
	      		 root->height=MAX((*this).height(root->left),(*this).height(root->right))+1;
	 		 int bal=(*this).balanced_factor(root);
         		 root->bf=bal;
	 		 if((bal > 1) || (bal < -1))  {
           		 root = (*this).balance_tree(root);
             		 root->height=MAX((*this).height(root->left),(*this).height(root->right))+1;
           		 root->bf=(*this).balanced_factor(root);
          	}
        } 
	return root;
   	}

        void traversal()
	{
		(*this).inorder(parent);
	}
 
 	
 
       void del(T k)
	{      // cout<<"delteting\n";
		parent=(*this).deleteNode(parent,k);
		//cout<<"end\n";
	}	
        
};


template<typename itr_t,typename T>
itr_t find(itr_t first,itr_t last,T k){
	while(first!=last && (((*first).key)!=k)){
		//cout<<"while_in_find\n";
		first++;
	}
	return first;
}


template<typename fitr_t,typename P>
void mycopy(fitr_t first,fitr_t last,P &p){
	while(first!=last){
		//cout<<"while_in_find\n";
		p.push_back((*first).key);
		first++;
	}
}		 

   		
