// Md. Shakibul Islam

#include <bits/stdc++.h>
using namespace std;

#define nl cout<<"\n"   // newline

int main () {

    int A[500][6];
     // 0 = Process ID, 1 = Arrival Time, 2 = Burst Time, 3 = Completion Time, 4 = Turnaround Time, 5 = Waiting Time

     int n; cout<<"Enter the number of Processes: "; cin>>n;

    cout<<"Enter Arrival Time and Burst Time:\n";
    for(int i = 0; i < n; i++) {
        cout<<"P"<<i+1<<": ";
        cin>>A[i][1]>>A[i][2];  // 1 = Arrival Time, 2 = Burst Time
        A[i][0] = i + 1;        // Process ID
    }


    // Sort by AT = 1     // BT = 2

    for(int i = 0; i < n-1; i++){
            for(int j = i+1; j<n; j++){
                if(A[i][1] > A[j][1] ){

                    for(int k = 0; k<6; k++){
                        swap(A[i][k], A[j][k]);
                    }
                }
            }

    }


    A[0][3] = A[0][1] + A[0][2];  // Completion Time for first process

    for(int i  =1 ; i<n; i++){      // CT = Previous CT + Current BT

        if(A[i-1][3] < A[i][1]){  // previous CT < AT

            int CT = A[i][1] ;  //AT

            n = n+1;
            int insertRow = i;      // where we need an empty row
            for(int x = n; x > insertRow; x-- ){
                for(int y = 0; y<6; y++){
                    A[x][y] = A[x-1][y];    // Shift Row downward by 1
                }
            }

            for(int j = 0; j<6; j++){   //clear the inserted row and set all values to 0
                A[insertRow][j] = 0;
            }

            A[insertRow][3] = CT;


        }
        else{
            A[i][3] = A[i-1][3] + A[i][2];  // Completion Time =3,    BT = 2
        }
    }

    int avgTAT = 0;
    for(int i = 0; i < n; i++) {
        A[i][4] = A[i][3] - A[i][1];  // Turnaround Time = Completion Time - Arrival Time
        avgTAT += A[i][4];
    }

    int avgWT = 0;
    for(int i = 0; i < n; i++) {
        A[i][5] = A[i][4] - A[i][2];  // Waiting Time = Turnaround Time - Burst Time
        avgWT += A[i][5];
    }

    nl;
    cout << setw(46) << "First-Come First-Served with Arrival Time"; nl; nl;


    cout << setw(6) << "P" << setw(8) << "AT" << setw(8) << "BT"
         << setw(8) << "CT" << setw(8) << "TAT" << setw(8) << "WT"; nl; nl;

    // Print Table
    for(int i = 0; i < n; i++) {

            if(A[i][0] == 0) continue;

        cout << setw(5) << "P" << A[i][0]
             << setw(8) << A[i][1]       // Arrival Time
             << setw(8) << A[i][2]       // Burst Time
             << setw(8) << A[i][3]       // Completion Time
             << setw(8) << A[i][4]       // Turnaround Time
             << setw(8) << A[i][5]; nl;  // Waiting Time
    }

    cout << "\nAverage Turnaround Time: " << (float)avgTAT / n;
    cout << "\nAverage Waiting Time: " << (float)avgWT / n; nl;nl;

    cout << "Gantt Chart:\n";

    cout << "_";
    for(int i = 0; i<n; i++) {
        cout<< setw(8) << "_______ ";
    }nl;

    cout << "|";
    for(int i = 0; i<n; i++) {

        if(A[i][0] == 0){
            cout << setw(7) <<" //// ";
        }
        else{
            cout << setw(5) << ("P" + to_string(A[i][0])) << "  ";
        }
        cout << "|";
    } nl;

    cout << "-";
    for(int i = 0; i<n; i++) {
        cout << setw(8) << "------- ";
    }nl;

    cout << 0;  // Start time
    for(int i = 0; i<n; i++) {
        cout << setw(8) << A[i][3];  // Completion Time
    } nl;


}
