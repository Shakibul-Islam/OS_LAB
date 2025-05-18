#include <bits/stdc++.h>
using namespace std;

#define nl cout<<"\n"   // newline

int main() {
    int A[500][5];

    int n;
    cout<<"Enter the number of Process :";
    cin>>n;

    cout<< "Enter Burst Time" << endl;
    for(int i = 0; i<n; i++){
        cout<<"P" << i+1 << ": ";
        cin >> A[i][1];        // Column 1 = Burst Time

        A[i][0] = i+1;        // Column 0 = Process Number
    }

    // sorting According their Burst Time Because it is SJF CPU scuddling
    for(int i=0 ; i < n; i++){    // i = Previous row number
        int index = i;              // Let i is the Smallest Burst Time
        for(int j = i+1; j<n; j++){
            if(A[j][1] <= A[index][1] ){
                index = j;
            }
        }

        swap(A[i][1], A[index][1]); // swap Burst Time
    
        swap(A[i][0], A[index][0]); // swap Process Number

        
        
        // int temp = 0;

        // temp = A[i][1]; // swap Burst Time
        // A[i][1] = A[index][1];
        // A[index][1] = temp;

        // temp = A[i][0]; // swap Process Number
        // A[i][0] = A[index][0];
        // A[index][0] = temp;

        
        
       

    }

        // First Completion time = first Burst Number
        A[0][2] = A[0][1];

        for(int i = 1; i<n; i++){       // CT = Previous CT + Current BT
            A[i][2] = A[i-1][2] + A[i][1];
        }


        int avgTAT = 0;
        for(int i = 0; i< n; i++){  // TAT calculate
            A[i][3] = A[i][2];      // TAT = CT - AT    here AT = 0

            avgTAT += A[i][3];
        }


        int avgWT = 0;
        A[0][4] = 0;
        for(int i = 1; i<n; i++){               // WT Calculate
            A[i][4] =  A[i][3]  -  A[i][1];    // WT = TAT - BT

            avgWT += A[i][4];
        }


        cout<<setw(30)<<"Shortest Job First"; nl;nl;
        //                  0               1                 2                 3                 4
        cout<< setw(6) << "P" <<setw(8) << "BT" <<setw(8) << "CT" <<setw(8) << "TAT" <<setw(8)<< "WT"; nl; nl;
        // print table

        for(int i = 0; i<n; i++){
            cout<<setw(5)<< "P"<< A[i][0]
            << setw(8) << A[i][1]
            << setw(8) << A[i][2]
            << setw(8) << A[i][3]
            << setw(8) << A[i][4]; nl;


        }
        nl; nl;

        cout<< "Average Waiting Time = " << (float)avgWT/n; nl;
        cout<< "Average Turnaround Time = " << (float) avgTAT/n; nl; nl;

        cout<<"Gantt Chart: "; nl;

        cout<<"_";
        for(int i = 0; i<n; i++){
            cout<< setw(8) << "_______ ";
        } nl;


        for(int i= 0; i<n;i++){
            cout<<"|";
            cout<<setw(5) << ("P" + to_string(A[i][0])) <<"  ";
        } cout<<"|"; nl;

        cout<<"-";
        for(int i = 0; i<n; i++){
            cout<< setw(8) << "------- ";
        } nl;

        cout<<0;
        for(int i = 0; i<n ; i++){
            cout<< setw(8) << A[i][2];
        }
        nl;





}
