#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> A[i][j];
        }
    }
    int diagonal=0;
    for(int i=0;i<n;i++)
    {
        diagonal^=A[i][i];
    }
    int q;
    cin>>q;
    int rowCount[n]={0},colCount[n]={0};
    string res;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int i;
            cin>>i;
            i--;
            rowCount[i]^=1;
            diagonal^=1;
        }
        else if(t==2)
        {
            int i;
            cin>>i;
            i--;
            colCount[i]^=1;
            diagonal^=1;
        }
        else
        {
            res+=(diagonal+'0');
        }
    }
    cout<<res<<"\n";
    return 0;
}
