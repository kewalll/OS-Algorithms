#include <iostream>
using namespace std;
struct Process {
  int id;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int turnaroundTime;
  int waitingTime;
};
void calculateTimes(Process processes[], int n, int quantum) {
  int remainingTime[n];
  for (int i = 0; i < n; i++) {
    remainingTime[i] = processes[i].burstTime;
  }
  int currentTime = 0;
  bool allDone = false;
  while (!allDone) {
    allDone = true;
    for (int i = 0; i < n; i++) {
      if (remainingTime[i] > 0) {
        allDone = false;
        if (remainingTime[i] > quantum) {
          currentTime = currentTime + quantum;
          remainingTime[i] = remainingTime[i] - quantum;
        } else {
          currentTime = currentTime + remainingTime[i];
          processes[i].completionTime = currentTime;
          remainingTime[i] = 0;
        }
      }
    }
  }
}
void calculateTurnaroundTime(Process processes[], int n) {
  for (int i = 0; i < n; i++)
    processes[i].turnaroundTime =
        processes[i].completionTime - processes[i].arrivalTime;
}

void claculateWaitingTime(Process processes[], int n) {
  for (int i = 0; i < n; i++)
    processes[i].waitingTime =
        processes[i].turnaroundTime - processes[i].burstTime;
}

void printTable(Process processes[], int n) {
 
  cout << "ID\tAt\tBT\tCT\tTAT\tWT\n";
  float twt=0,ttat=0;

  for (int i = 0; i < n; i++) {
    cout << "\t" << processes[i].id << "\t"
         << processes[i].arrivalTime << "\t" << processes[i].burstTime
         << "\t" << processes[i].completionTime
         << "\t" << processes[i].turnaroundTime
         << "\t" << processes[i].waitingTime << "\t\n";
         twt+=processes[i].waitingTime;
         ttat+=processes[i].turnaroundTime;
  }
  float avgwt=twt/n;
    float avgtat=ttat/n;
    cout<<"Average waiting time : "<<avgwt<<endl;
    cout<<"Average turnaround time : "<<avgtat;

  
}
int main() {
  int n=4, quantum=2;
  

  Process processes[n];
  cout << "Enter process details:\n";
  for (int i = 0; i < n; i++) {
    cout << "Process " << i + 1 << ":\n";
    processes[i].id = i + 1;
    cout << "Arrival Time: ";
    cin >> processes[i].arrivalTime;
    cout << "Burst Time: ";
    cin >> processes[i].burstTime;
  }

  calculateTimes(processes, n, quantum);
  calculateTurnaroundTime(processes, n);
  claculateWaitingTime(processes, n);

  cout << "\nRound Robin Scheduling Results:\n";
  printTable(processes, n);

  return 0;
}
