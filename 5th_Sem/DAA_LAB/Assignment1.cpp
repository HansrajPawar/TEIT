#include <bits/stdc++.h>
using namespace std;

int Knapscak(vector<int> wt, vector<int> val, int W, int n);
int zeroOneKnapscak(vector<int> wt, vector<int> val, int W, int n);

int main() {

    int n,len,W,ans1, ans2;
    while(1) {
        cout<<endl<<"Enter length of array ";
            cin>>len;

        vector<int> values(len);
        vector<int> weight(len);

        cout<<endl<<"Enter values ";
            for(int i=0;i<len;i++)
                cin>>values[i];

        cout<<endl<<"Enter weight ";
            for(int i=0;i<len;i++)
                cin>>weight[i];

        cout<<endl<<"Enter Capacity of bag ";
            cin>>W;
        

            ans1 = Knapscak(weight,values,W,len);
            cout<<endl<<"maximum value Knapscak is "<<ans1<<endl<<endl ;

            ans2 = zeroOneKnapscak(weight,values,W,len-1);
            cout<<endl<<"maximum value using zeroOneKnapscak is "<<ans2<<endl;


    }
    return 0;
}


int Knapscak(vector<int> wt, vector<int> val, int W, int n) {
    vector<int> ratio(n);
    for(int i=0;i<n;i++) 
        ratio[i] = val[i]/wt[i];

    sort(ratio.begin(), ratio.end() , greater<int>());

    int value = 0;
    int capacity = 0;
    for(int i=0;i<n;i++) {
        if(capacity+wt[i]<=W) {
            capacity+=wt[i];
            value+=val[i];
        }
    }

    return value;
}

int zeroOneKnapscak(vector<int> wt, vector<int> val, int W, int n) {
    if(n==0) {
        if(W-wt[n]>=0){
            return val[0];
        }else{
            return 0;
        }
    }
    int include = 0;
        if(W-wt[n]>=0){
            include = val[n] + zeroOneKnapscak(wt,val,W-wt[n],n-1);
        }
        int exclude = 0 + zeroOneKnapscak(wt,val,W,n-1);

        return max(include,exclude);
}

