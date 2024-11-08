#include<iostream>
using namespace std;

int main(){

    int np;
    cout<<"Enter The Number of Process : ";
    cin>>np;

    int pid[np],at[np],bt[np],wt[np],tat[np],ct[np],completed[np];
    double tottat=0,totwt=0;

    for(int i=0;i<np;i++){

        cout<<"For Process "<<i+1<<":"<<endl;
        cout<<"Enter Process ID : ";
        cin>>pid[i];
        cout<<"Enter Process Arrival-Time : ";
        cin>>at[i];
        cout<<"Enter Process Burst-Time : ";
        cin>>bt[i];
        completed[i]=0;

    }

    int comp_p=0,curt=0;

    while(comp_p<np){

        int shortest = -1;
        int min_bt = 99999;

        for(int i=0;i<np;i++){

            if(at[i] <= curt && bt[i] < min_bt && !completed[i]){
                min_bt = bt[i];
                shortest = i;
            }

        }

        if(shortest == -1){
            curt++;
            continue;
        }

        curt += bt[shortest];
        ct[shortest] = curt;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        tottat += tat[shortest];
        totwt += wt[shortest];

        completed[shortest] = 1;
        comp_p++;

    }

    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"| PID | Arrival-Time | Burst-Time | Completion-Time | Turnaround-Time | Waiting-Time |"<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<np;i++){
        cout<<"|  "<<pid[i]<<"  |     "<<at[i]<<"     |     "<<bt[i]<<"     |       "<<ct[i]<<"       |       "<<tat[i]<<"       |     "<<wt[i]<<"     |"<<endl;
    }
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"Avrage Turnaround-Time is : "<<tottat/np<<endl;
    cout<<"Avrage Waiting-Time is : "<<totwt/np<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    for(int i=0;i<np;i++){
        cout<<"+----";
    }
    cout<<"+"<<endl;
    for(int i=0;i<np;i++){
        cout<<"| P"<<pid[i]<<" ";
    }
    cout<<"|";
    cout<<endl;
    for(int i=0;i<np;i++){
        cout<<"+----";
    }
    cout<<"+"<<endl;
    cout<<"0    ";
    for(int i=0;i<np;i++){
        cout<<ct[i]<<"    ";
    }

    return 0;
}