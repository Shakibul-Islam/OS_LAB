#include <bits/stdc++.h>
using namespace std;

#define nl cout<<"\n"   // newline

int main (){

    int A[500][5];

    int n;
    cout<<"Enter the number of Process :";
    cin>>n;

    cout<<"Enter Burst Time:"; nl;

    for(int i =0 ; i<n; i++){
        cout<<"P"<< i +1 <<": ";

        cin>>A[i][1];       // 1 = Burst Time

        A[i][0] = i+1;
    }


    // Compute CT=2 , TAT = 3, WT = 4,
    A[0][2] = A[0][1];
    for(int i = 1; i<n; i++){
        A[i][2] = A[i-1][2] + A[i][1] ;  // CT = Previous CT + Current BT
    }

    int avgTAT = 0;
    for(int i = 0; i<n; i++){
       A[i][3] = A[i][2];         // // TAT = CT - AT    here AT = 0

       avgTAT += A[i][3];
    }

    int avgWT = 0;
    for(int i = 0; i<n; i++){
        A[i][4] = A[i][3] - A[i][1];     // WT = TAT - BT

        avgWT += A[i][4];
    }



    cout<<setw(35) <<"First-Come First-Served"; nl; nl;

    cout<< setw(6) << "P" << setw(8) << "BT" << setw(8) <<"CT" << setw(8) << "TAT" <<setw(8)<< "WT"; nl;nl;

    // Print Table

    for(int i = 0; i<n; i++){
        cout<< setw(5) << "P" <<A[i][0]
        << setw(8) << A[i][1]       // 1 = BT
        << setw(8) << A[i][2]       // 2 = CT
        << setw(8) << A[i][3]       // 3 = TAT
        << setw(8) << A[i][4]; nl;  // 4 =WT
    }

    nl; nl;

    cout<< "Average Waiting Time = " << (float)avgWT/n; nl;
    cout<< "Average Turnaround Time = " << (float) avgTAT/n; nl; nl;


    cout<<"Gantt Chart: "; nl;

    cout<<"_";
    for(int i = 0; i<n; i++){
        cout<< setw(8) << "_______ ";
    }nl;

    for(int i = 0; i<n; i++){
        cout<<"|";
        cout<< setw(5) << ("P" + to_string(A[i][0])) << "  ";
    }cout<<"|"; nl;

    cout<<"-";
    for(int i = 0; i<n; i++){
        cout<< setw(8) << "------- ";
    }nl;

    cout<<0;
    for(int i = 0; i<n; i++){
        cout<< setw(8) << A[i][2];  // CT= 2
    }




}
