// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void findct(Process proc[], int n){
    proc[0].ct = proc[0].bt;
    for(int i=1;i<n;i++){
        proc[i].ct = proc[i-1].ct+proc[i].bt;
    }
}

void findtat(Process proc[], int n){
    for(int i=0;i<n;i++){
        proc[i].tat=proc[i].ct-proc[i].at;
    }
}

void findwt(Process proc[], int n){
    proc[0].wt = 0;
    for(int i=1;i<n;i++){
        proc[i].wt=proc[i].tat-proc[i].bt;
    }
}

void print(Process proc[], int n){
    cout<<"FCFS Table"<<endl;
    float twt=0,ttat=0;
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
        twt+=proc[i].wt;
        ttat+=proc[i].tat;
    }
    float avgwt=twt/n;
    float avgtat=ttat/n;
    cout<<"Average waiting time : "<<avgwt<<endl;
    cout<<"Average turnaround time : "<<avgtat;
}

int main(){
    int n=5;
    Process proc[n]={{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
    findct(proc,n);
    findtat(proc,n);
    findwt(proc,n);
    print(proc,n);
    return 0;
}
