#include "../lib/imports.h"
ListResults::ListResults(){
    this->first=NULL;
    this->last=NULL;
    this->lenght=0;
}
ListResults::~ListResults(){
    while(!this->isEmpty())
        this->pop();
}
bool ListResults::isEmpty(){
    if(this->lenght == 0){
        return true;
    }
    else{
        return false;
    }
}

void ListResults::push(double *result){
    NodeResult *node;
    node=new NodeResult;
    node->result=result;
    node->next=NULL;

    if(this->isEmpty()){
        this->first=node;
        this->last=node;
    }
    else{
        this->last->next=node;
        this->last=node;
    }
    this->lenght= this->lenght+1;
}

double* ListResults::pop(){
    NodeResult *node;
    if(this->isEmpty()){
        cout << "Está vazia. UnderFlow" << endl;
        node=NULL;
    }
    else{
        this->lenght=this->lenght-1;
        node=this->first;
        this->first=node->next;
    }
    return node->result;
}
int ListResults::getLength(){
    return this->lenght;
}
