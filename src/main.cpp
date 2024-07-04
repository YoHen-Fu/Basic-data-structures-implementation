#include<iostream>
#include<vector>
#include"Queue.h"

int main(){
    Queue<int>* Qe = new Queue<int>();
    Qe->AddQ(12);
    Qe->AddQ(5);
    int res;
    while(!Qe->IsEmpty()){
        std::cout<<Qe->DeleteQ()<<" ";
    }
}