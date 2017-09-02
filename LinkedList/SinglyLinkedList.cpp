#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
int data;
struct Node *next;
};

Node* createLinkList(){
    Node *start=NULL,*fresh;
    fresh=new Node;
    if(fresh==NULL){
        cout<<"Memory not allocated";
    }
    if(start==NULL){
        cout<<"Enter data";
        cin>>fresh->data;
        start=fresh;
        start->next=NULL;
    }
    return start;
}

void display(Node *start){
    Node *loc;
    loc=start;
    cout<<"Resulted List: "<<endl;
    while(loc!=NULL){
        cout<<loc->data<<"->";
        loc=loc->next;
    }
}

void insertAtPos(Node *start,int pos,int data){
Node *loc,*fresh,*temp,*prev;
int i=0;
fresh=new Node;
fresh->data=data;
fresh->next=NULL;
loc=start;
while(i!=pos){
   prev=loc;
   loc=loc->next;
   i++;
}
temp=loc;
prev->next=fresh;
fresh->next=temp;
cout<<"INSERTION DONE"<<endl;
}

void insertInLinkList(Node *start,int data){
Node *loc,*fresh;
loc=start;
fresh=new Node;
fresh->data=data;
fresh->next=NULL;
if(fresh==NULL){
    cout<<"Memory not allocated";
}
while(loc->next!=NULL){
    loc=loc->next;
}
loc->next=fresh;
}

void deleteAtPos(Node*start,int pos){
Node *loc,*prev,*temp;
int i=0;
loc=start;
while(i!=pos){
   prev=loc;
   loc=loc->next;
   i++;
}
temp=loc->next;
prev->next=temp;
free(loc);
}

void reverseList(Node *start){
Node *prev=NULL,*current,*nex;
current=start;
while(nex!=NULL){
    nex=current->next;
    current->next=prev;
    prev=current;
    current=nex;
}
start=prev;
Node *loc;
loc=start;
cout<<"Resulted List: "<<endl;
while(loc!=NULL){
    cout<<loc->data<<"->";
    loc=loc->next;
}
}

//Merge two sorted list in single sorted list
void mergeList(Node *startA,Node *startB){
Node *p,*q,*s;
p=startA;
q=startB;
if(p==NULL){
   cout<<"No startA";
}
if(q==NULL){
   cout<<"No startB";
}
if(p && q){
    if(p->data<=q->data){
        s=p;
        p=s->next;
    }
    else{
        s=q;
        q=s->next;
    }
}
while(p && q){
    if(p->data<=q->data){
        s->next=p;
        s=p;
        p=s->next;
    }
    else{
        s->next=q;
        s=q;
        q=s->next;
    }
}
if(p==NULL){
    s->next=q;
}
if(q==NULL){
  s->next=p;
}
}

int main() {
Node *start;
start=createLinkList();
insertInLinkList(start,2);
insertInLinkList(start,3);
insertInLinkList(start,4);
insertInLinkList(start,5);
insertAtPos(start,3,12);
display(start);
cout<<"\nAfter deletion: ";
deleteAtPos(start,2);
display(start);
cout<<"\nAfter reversing";
reverseList(start);
return 0;
}
