// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

// Function to find the process with the shortest burst time
int findShortestJob(Process proc[], int n, int currentTime) {
    int shortestJob = -1;
    int minBurstTime = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (proc[i].at <= currentTime && proc[i].bt < minBurstTime && proc[i].bt > 0) {
            minBurstTime = proc[i].bt;
            shortestJob = i;
        }
    }

    return shortestJob;
}

void sjf(Process proc[], int n) {
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortestJob = findShortestJob(proc, n, currentTime);

        if (shortestJob == -1) {
            currentTime++;
            continue;
        }

        proc[shortestJob].ct = currentTime + proc[shortestJob].bt;
        proc[shortestJob].tat = proc[shortestJob].ct - proc[shortestJob].at;
        proc[shortestJob].wt = proc[shortestJob].tat - proc[shortestJob].bt;
        proc[shortestJob].bt = 0;
        completed++;
        currentTime = proc[shortestJob].ct;
    }
}

void print(Process proc[], int n) {
    cout << "SJF Table" << endl;
    float twt = 0, ttat = 0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;

    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].at << "\t" << proc[i].bt << "\t" << proc[i].ct << "\t" << proc[i].tat << "\t" << proc[i].wt << endl;
        twt += proc[i].wt;
        ttat += proc[i].tat;
    }

    float avgwt = twt / n;
    float avgtat = ttat / n;
    cout << "Average waiting time: " << avgwt << endl;
    cout << "Average turnaround time: " << avgtat << endl;
}

int main() {
    int n = 5;
    Process proc[n] = {{1, 0, 3}, {2, 2, 6}, {3, 4, 4}, {4, 6, 5}, {5, 8, 2}};

    sjf(proc, n);
    print(proc, n);

    return 0;
}
