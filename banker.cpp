#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    int alloc[n][m];       
    int max[n][m];         
    int avail[m];         
    int need[n][m];        
    int f[n] = {0};       
    int ans[n];            
    
    cout << "Enter the Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }
   
    cout << "Enter the Available resources:\n";
    for (int j = 0; j < m; j++) {
        cin >> avail[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    int ind = 0; 
    int y = 0;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) { 
            
                
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];  
                    }
                    f[i] = 1;  
                }
            }
        }
    }
    
    bool safe = true;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            safe = false;  
            cout << "The system is not in a safe state.\n";
            break;
        }
    }

    if (safe) {
        cout << "The system is in a safe state.\n";
        cout << "Following is the SAFE Sequence: ";
        for (int i = 0; i < n - 1; i++) {
            cout << "P" << ans[i] << " -> ";
        }
        cout << "P" << ans[n - 1] << endl;
    }

    return 0;
}
