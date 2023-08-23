#include<iostream>
#include<cstring>
using namespace std;

class node{

    public:
    char number[11];
    char gmail[20];
    char name[30];
    node* next;
    node* prev;

    node(char na[],char r[],char g[]){
      strcpy(name,na);
      strcpy(number,r);
      strcpy(gmail,g);
        next=NULL;
        prev=NULL;
    }//constructor
};
void insertAtHead(node* &head, char na[],char r[],char g[]){

    node* n = new node(na,r,g);

    n->next = head;

    if(head!=NULL){
        head->prev = n;
    }
    
    head = n;
    cout<<"Contact successfully added\n";
}
void insertAtTail(node* &head, char na[],char r[],char g[]){
    
    if(head==NULL){     //if head is NULL we can't access its previous
        insertAtHead(head,na,r,g);
        return;
    }
    
    node* n = new node(na,r,g);
    node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = n;
    n->prev = temp;
    cout<<"Contact successfully added\n";
}
void searchbyname(node* &head,char na[]){

    if (head == NULL) {
        cout << "Not found" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL && strcmp(temp->name, na) != 0) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        cout << "Search result Found" << endl;
        cout << "Name:"<<temp->name << " "<<endl;
        cout << "Contact No.:"<<temp->number << " "<<endl;
        cout << "Email:"<<temp->gmail << " "<<endl;
    } else {
        cout << "Not found" << endl;
    }
}
void deletebyname(node* &head,char na[]){

    if (head == NULL) {
        cout << "Not found" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL && strcmp(temp->name, na) != 0) {
        temp = temp->next;
    }
  if (temp == NULL) {
        cout << "Not found" << endl;
        return;
    }
     if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        
        head = temp->next;
    }

    if(temp->next!=NULL){   //as we can't access temp->next->prev of last node
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout<<"Contact successfully deleted\n";
}
void searchbynumber(node* &head,char r[]){

    if (head == NULL) {
        cout << "Not found" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL && strcmp(temp->number, r) != 0) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        cout << "Search result Found" << endl;
        cout << "Name:"<<temp->name << " "<<endl;
        cout << "Contact No.:"<<temp->number << " "<<endl;
        cout << "Email:"<<temp->gmail << " "<<endl;
    } else {
        cout << "Not found" << endl;
    }
}
void deletebynumber(node* &head,char r[]){

    if (head == NULL) {
        cout << "Not found" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL && strcmp(temp->number, r) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Not found" << endl;
        return;
    }
     if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        
        head = temp->next;
    }

    if(temp->next!=NULL){   //as we can't access temp->next->prev of last node
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout<<"Contact successfully deleted\n";
}
void searchbyEmail(node* &head,char g[]){

    if (head == NULL) {
        cout << "Not found" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL && strcmp(temp->gmail, g) != 0) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        cout << "Search result Found" << endl;
        cout << "Name:"<<temp->name << " "<<endl;
        cout << "Contact No.:"<<temp->number << " "<<endl;
        cout << "Email:"<<temp->gmail << " "<<endl;
    } else {
        cout << "Not found" << endl;
    }
}
void deletebyemail(node* &head,char g[]){

    if (head == NULL) {
        cout << "Not found" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL && strcmp(temp->gmail, g) != 0) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Not found" << endl;
        return;
    }
     if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        
        head = temp->next;
    }

    if(temp->next!=NULL){   //as we can't access temp->next->prev of last node
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout<<"Contact successfully deleted\n";
}

void display(node* &head){
    node* temp = head;
if(head==NULL){
    cout<<"no element found in the list"<<endl;
}
    while(temp!=NULL){
      
        cout << "Name:"<<temp->name<<endl;
        cout << "Contact No.:"<<temp->number<<endl;
        cout << "Email:"<<temp->gmail<<endl;
         cout<<endl;
        temp=temp->next;
        
    }
     cout<<endl;
    
}

int main()
{char na[30];
char r[11];
char g[20];
bool res=true;
node* head=NULL;
while(res){
int n;
cout<<"WELCOME TO PHONEBOOK DICTIONARY"<<endl;
cout<<"1.Insert a new contact \n";
cout<<"2.Display all contacts\n";
cout<<"3.Search by Name\n";
cout<<"4.Search by Contact No.\n";
cout<<"5.Search by Email\n";
cout<<"6.Delete by Name\n";
cout<<"7.Delete by Contact No.\n";
cout<<"8.Delete by Email\n";
cout<<"9.Exit\n";
cin>>n;
switch (n)
{
case 1:{
cout<<"Enter your Name\n";
cout<<"note- type underscore(_) instead of space\n";
cin>>na;
cout<<"Enter your Email\n";
cin>>g;
cout<<"Enter your Contact No.\n";
cin>>r;
int length=strlen(r);
if(length==10){
     insertAtTail(head,na,r,g);
    break;
}

    cout<<"not valid"<<endl;
    break;

}
case 2:{
   display(head); 
   break;
}
case 3:{
  cout<<"Enter Name:\n"; 
  cout<<"note- type underscore(_) instead of space\n"; 
  cin>>na;
  searchbyname(head,na);
  break;
}
case 4:{
  cout<<"Enter Contact No.:\n";  
  cin>>r;
  searchbynumber(head,r);
  break;
}
case 5:{
 cout<<"Enter Email:\n";  
  cin>>g;
  searchbyEmail(head,g);
  break;
}
case 6:{
  cout<<"Enter Name:\n"; 
  cout<<"note- type underscore(_) instead of space\n"; 
  cin>>na;
  deletebyname(head,na);
  break;
}
case 7:{
  cout<<"Enter Contact No.:\n";  
  cin>>r;
  deletebynumber(head,r);
  break;
}
case 8:{
  cout<<"Enter Email:\n";  
  cin>>g;
  deletebyemail(head,g);
  break;
}
case 9:{
    cout<<"BYE BYE"<<endl;
    res=false;
}
}
}
    return 0;
}