#include<iostream>
using namespace std;

int main(){

    int np;
    cout<<"Enter Number of Process : ";
    cin>>np;

    int pid[np],at[np],bt[np],tat[np],ct[np],wt[np],rt[np];
    double totwt=0,tottat=0,totrt=0;

    for(int i=0;i<np;i++){
        cout<<"For Process "<<i+1<<":"<<endl;
        cout<<"Enter Process ID : ";
        cin>>pid[i];
        cout<<"Enter Process Arrival-Time : ";
        cin>>at[i];
        cout<<"Enter Process Burst-Time : ";
        cin>>bt[i];
        cout<<"-------------------------------"<<endl;

        if(i==0)
            ct[i] = at[i] + bt[i];
        else
            ct[i] = max(at[i],ct[i-1]) + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i];

        tottat += tat[i];
        totwt += wt[i];
        totrt += rt[i];
    }

    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"| PID | Arrival-Time | Burst-Time | Completion-Time | Turnaround-Time | Waiting-Time | Response-Time |"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<np;i++){
        cout<<"|  "<<pid[i]<<"  |      "<<at[i]<<"      |      "<<bt[i]<<"      |        "<<ct[i]<<"        |       "<<tat[i]<<"       |      "<<wt[i]<<"      |      "<<rt[i]<<"      |"<<endl;
    }
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Avrage Turnaround-Time is : "<<tottat/np<<endl;
    cout<<"Avrage Wating-Time is : "<<totwt/np<<endl;
    cout<<"Avrage Response-Time is : "<<totrt/np<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Gantt Chart:"<<endl;
    for(int i=0;i<np;i++){
        cout<<"+----";
    }
    cout<<"+"<<endl;
    for(int i=0;i<np;i++){
        cout<<"| P"<<pid[i]<<" ";
    }
    cout<<"|"<<endl;
    for(int i=0;i<np;i++){
        cout<<"+----";
    }
    cout<<"+"<<endl;
    cout<<"0";
    for(int i=0;i<np;i++){
        cout<<"   "<<ct[i];
    }

    return 0;
}