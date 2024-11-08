#include<iostream>
using namespace std;

int main (){

    int np,tc;
    cout<<"Enter Number of Process : ";
    cin>>np;
    cout<<"Enter Time Quantum : ";
    cin>>tc;

    int pid[np],at[np],bt[np],rt[np],ct[np],wt[np],tat[np];
    double tottat=0,totwt=0;

    for(int i=0;i<np;i++){
        cout<<"For Process "<<i+1<<endl;
        cout<<"Enter Process ID : ";
        cin>>pid[i];
        cout<<"Enter Process Arrival-Time : ";
        cin>>at[i];
        cout<<"Enter Process Burst-Time : ";
        cin>>bt[i];
        rt[i]=bt[i];
        cout<<"---------------------------------"<<endl;
    }

    int complete = 0;
    int curt = 0;

    while(complete<np){
        for(int i=0;i<np;i++){
            if(rt[i]>0){
                curt = max(at[i],curt);
                if(rt[i]>tc){
                    rt[i] -= tc;
                    curt += tc; 
                }
                else{
                    curt += rt[i];
                    rt[i] = 0;
                    ct[i] = curt;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    complete++;
                    tottat += tat[i];
                    totwt += wt[i];
                }
            }
        }
    }

    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"| PID | Arrival-Time | Burst-Time | Completion-Time | Turnaround-Time | Waiting-Time |"<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<np;i++){
        cout<<"|  "<<pid[i]<<"  |      "<<at[i]<<"      |      "<<bt[i]<<"      |        "<<ct[i]<<"        |       "<<tat[i]<<"       |      "<<wt[i]<<"      |"<<endl;
    }
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"Avrage Turnaround-Time is : "<<tottat/np<<endl;
    cout<<"Avrage Wating-Time is : "<<totwt/np<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
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