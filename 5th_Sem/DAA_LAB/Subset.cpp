// #include <bits/stdc++.h>
// using namespace std;


// void find_r(int n, vector<int> arr, vector<int> req, int sum, int i){
//     if(sum == 0){
//         cout << "\nRequired sum found: ";
//         for(auto ele : req) cout << ele << " ";
//         cout << endl;
//         return;
//     }
//     if(i==n) return;

//     find_r(n, arr, req, sum, i+1);
//     if(arr[i] <= sum){
//         req.push_back(arr[i]);
//         find_r(n, arr, req, sum-arr[i], i+1);
//         req.pop_back();
//     }
// }


// int main(){
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;

//     vector<int> arr;
//     cout << "Enter the elements: ";
//     for(int i=0; i<n; i++) {
//         int ele;
//         cin >> ele;
//         arr.push_back(ele);
//     }

//     int sum;
//     cout << "Enter the sum: ";
//     cin >> sum;

//     vector<int> req;
    
//     find_r(n, arr, req, sum, 0);

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std ;

void findr(int n, vector<int>arr,vector<int>req,int sum,int i)
{
	if(sum==0)
	{
		cout<<"found";
		for(auto ele : req) cout<<ele<<" ";
		cout<<endl;
		return;
	}

	if(i==n)return;

	findr(n,arr,req,sum,i+1);

	if(arr[i] <= sum)
	{
		req.push_back(arr[i]);
		findr(n,arr,req,sum-arr[i],i+1);
		req.pop_back();

	}
}
int main ()
{
	int n ;
	cout<<"Eenter n  :- ";cin>>n;

	vector<int>arr;
	vector<int>req;
	cout<<"Eenter The values :- ";

	for(int i =0; i<n;i++)
	{
		int ele ;
		cin>>ele;
		arr.push_back(ele);
	}

	int sum;
	cout<<"Eenter The Sum :- ";
	cin>>sum;

	findr(n,arr,req,sum,0);



	return 0;
}

