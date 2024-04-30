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

void srtf(Process proc[], int n)
{
    int rt[n];
    for (int i = 0; i < n; i++)
    {
        rt[i] = proc[i].bt;
    }
    int t = 0;
    int complete = 0;
    int shortest = 0;
    int minbt = 9999;
    while (complete < n)
    {
        minbt = 9999;
        for (int i = 0; i < n; i++)
        {
            if (proc[i].at <= t && rt[i] < minbt && rt[i] > 0)
            {
                minbt = rt[i];
                shortest = i;
            }
        }
        rt[shortest]--;
        if (rt[shortest] == 0)
        {
            complete++;
            proc[shortest].ct = t + 1;
            proc[shortest].tat = proc[shortest].ct - proc[shortest].at; 
            proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;
        }
        t++;
    }
}

void print(Process proc[], int n)
{
    cout << "SRTF Table" << endl;
    float twt = 0, ttat = 0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << "\t" << proc[i].at << "\t" << proc[i].bt << "\t" << proc[i].ct << "\t" << proc[i].tat << "\t" << proc[i].wt << endl;
        twt += proc[i].wt;
        ttat += proc[i].tat;
    }
    float avgwt = twt / n;
    float avgtat = ttat / n;
    cout << "Average waiting time : " << avgwt << endl;
    cout << "Average turnaround time : " << avgtat;
}

int main()
{
    int n = 5;
    Process proc[n] = {{1, 0, 3}, {2, 2, 6}, {3, 4, 4}, {4, 6, 5}, {5, 8, 2}};
    
    srtf(proc, n);
    print(proc, n);
    return 0;
}
