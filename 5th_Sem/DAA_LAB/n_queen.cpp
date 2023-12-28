#include<bits/stdc++.h>
using namespace std ;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
	if(col == n){
		ans.push_back(board);
		return ;
	}

	for(int row = 0 ;row <n ;row++)

}
void solveNQueens(int n )
{
	vector<vector<string>> ans ;
	vector<string> board(n,string(n,','));

	solve(0,board,ans,n);

	int op = ans.size();

	if(op>5)
		op=5;


	for (int i = 0; i < op ; i++)
	{
		cout<<"Solution "<<i++<<":\n";
		for (int j = 0; j < n ; j++)
		{
			cout<<"|";
			 if (ans[i][j][k] == 'Q')
                    cout << "Q ";
                else
                    cout << ". ";

			cout<<"|"<<endl;
		}
		
	}
	cout<<endl;
}
int main()
{
	int n;
    cout << "Enter the number of Queens : ";
    cin >> n;
    solveNQueens(n);
	return 0;


	return 0;
}