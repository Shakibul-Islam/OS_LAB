// Md. Shakibul Islam

#include <bits/stdc++.h>
using namespace std;

#define nl cout<<"\n"   // newline

int A[100][6];


struct process{
    int PID, AT, BT, CT, TAT, WT;
};


void findCT(process proc[], int n){             // Completion Time = Burst Time + Previous Completion Time
    
    bool ok[n];                                 // which process is e
    proc[0].CT = proc[0].BT + proc[0].AT-0;    //CT of 1st Process ; CT = BT + AT -0

    ok[0] = true;   // First Process is Executed

    int idx = 0, k = 0;

    for(int j = 1; j<n;j++){
        int mn = 1e9;   // Initialize minimum burst time to a large value
        bool test = false;

        for(int i = 1; i<n; i++){
            if(proc[k].CT >= proc[i].AT  && ok[i] == false){
                if(mn > proc[i].BT){
                    mn = proc[i].BT;
                    idx = i;
                }
            }
        }

        proc[idx].CT = proc[idx].BT  +  proc[k].CT; // CT = BT + Previous CT  // proc[0].CT = proc[0].BT + proc[0].AT;  // Completion Time for first process
        ok[idx] = true;
        k = idx;
    }

}


void findTAT (process proc[], int n){       // Turnaround Time = Completion Time - Arrival Time  (TAT = CT - AT)

    for(int i = 0; i<n; i++){
        proc[i].TAT = proc[i].CT  - proc[i].AT;
    }
}

void findWT(process proc[], int n){      // Waiting Time = Turnaround Time - Burst Time (WT = TAT - BT)

    for(int i = 0; i<n; i++){
        proc[i].WT = proc[i].TAT -  proc[i].BT;

        if(proc[i].WT < 0 ) proc[i].WT = 0;
    }

}



bool compareByAT(const process &a, const process &b){

    return a.AT < b.AT;

}

bool compareByCT(const process &a, const process &b){

    return a.CT < b.CT;

}




int main() {

    int n;
    cout<<"Enter the number of Process: "; nl;
    cin>>n;

    process proc[n];        // Array of processes

    cout<<"Enter AT and BT of the Process: "; nl;
    for(int i = 0; i<n; i++){

        proc[i].PID = i+1; // Process ID

        cout<<"P" << proc[i].PID << ": ";
        cin>>proc[i].AT >> proc[i].BT;
    }

    sort(proc, proc+n, compareByAT);    // Sort processes by Arrival Time

    findCT(proc, n);        // Find Completion Time for each process // proc[0].CT = proc[0].BT + proc[0].AT;  // Completion Time for first process
    
    findTAT(proc, n);
    findWT(proc, n);

    sort(proc, proc+n, compareByCT);  // Sort processes by Completion Time

    int avgTAT, avgWT;

    cout << setw(30) << "Shortest Job First"; nl; nl;
    //                  0                 1                   2                 3                   4                 5
    cout << setw(6) << "PID" << setw(8) << "AT" << setw(8) << "BT" << setw(8) << "CT" << setw(8) << "TAT" << setw(8)<< "WT"; nl; nl;
    for (int i = 0; i<n; i++) {
        cout << setw(6) << proc[i].PID << setw(8) << proc[i].AT << setw(8) << proc[i].BT << setw(8) << proc[i].CT << setw(8) << proc[i].TAT << setw(8) << proc[i].WT; nl;

    }
    cout << "Average Turnaround Time: " << (float)avgTAT/n;  nl;
    cout << "Average Waiting Time: " << (float)avgWT/n ;  nl;


    cout << "Gantt Chart: "; nl;

    cout<<"_";
        for(int i = 0; i<n; i++){
            cout<< setw(8) << "_______ ";
        } nl;


        for(int i= 0; i<n;i++){
            cout<<"|";
            cout<<setw(5) << ("P" + to_string(proc[i].PID)) <<"  ";
        } cout<<"|"; nl;

        cout<<"-";
        for(int i = 0; i<n; i++){
            cout<< setw(8) << "------- ";
        } nl;

        cout<<0;
        for(int i = 0; i<n ; i++){
            cout<< setw(8) << proc[i].CT;
        }
        nl;


}
