#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> L, U, R, D;

void vectorUpgrade(int x, int y, int n, vector<string> &grid){
	while(L[x]<n){
		if(grid[x][L[x]] == 'E'){
			L[x]++;
		}else break;
	}
	while(U[y]<n){
		if(grid[U[y]][y] == 'E'){
			U[y]++;
		}else break;
	}
	while(R[x]<n){
		if(grid[x][n-1-R[x]] == 'E'){
			R[x]++;
		}else break;
	}
	while(D[y]<n){
		if(grid[n-1-D[y]][y] == 'E'){
			D[y]++;
		}else break;
	}
}

bool ifPossible(vector<string> &grid, int n){
	queue<int> helper;
	int counter = 0;
	for(int i = 0; i < n; i++){
		if(grid[i][0] == 'L'){
			grid[i][0] = 'E';
			counter++;
			helper.push(n*i);
		}
		if(grid[0][i] == 'U'){
			grid[0][i] = 'E';
			counter++;
			helper.push(i);
		}
		if(grid[i][n-1] == 'R'){
			grid[i][n-1] = 'E';
			counter++;
			helper.push(i*n + n - 1);
		}
		if(grid[n-1][i] == 'D'){
			grid[n-1][i] = 'E';
			counter++;
			helper.push(i + n*(n-1));
		}
	}
	int x;
	int y;
	while(true){
		if(helper.empty())break;
		x = helper.front() / n;
		y = helper.front() % n;
		helper.pop();
		vectorUpgrade(x, y, n, grid);
		if(L[x] < n && grid[x][L[x]] == 'L'){
			counter++;
			grid[x][L[x]] = 'E';
			helper.push(x*n + L[x]);
			vectorUpgrade(x, L[x], n, grid);
		}
		if(U[y] < n && grid[U[y]][y] == 'U'){
			counter++;
			grid[U[y]][y] = 'E';
			helper.push(U[y]*n + y);
			vectorUpgrade(U[y], y, n, grid);
		}
		if(R[x] < n && grid[x][n-1-R[x]] == 'R'){
			counter++;
			grid[x][n-1-R[x]] = 'E';
			helper.push(x*n + n-1-R[x]);
			vectorUpgrade(x, R[x], n, grid);
		}
		if(D[y] < n && grid[n-1-D[y]][y] == 'D'){
			counter++;
			grid[n-1-D[y]][y] = 'E';
			helper.push((n-1-D[y])*n + y);
			vectorUpgrade(n-1-D[y], y, n, grid);
		}
	}
	return counter==n*n;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	int n;
	for(int i = 0; i < T; i++){
		cin>>n;
		vector<string> grid;
		L.assign(n, 0);
		U.assign(n, 0);
		R.assign(n, 0);
		D.assign(n, 0);
		for(int j = 0; j < n; j++){
			string line;
			cin>>line;
			grid.push_back(line);
		}
		if(ifPossible(grid, n)){
			cout<<"POSIBLE\n";
		}else{cout<<"IMPOSIBLE\n";}
	}
    return 0;
}