#include<bits/stdc++.h>
using namespace std;
struct State{
	int floor;
	int steps;
};
int result(int n,int st,int en,int u,int d){
	if(st==en)
	return 0;
	queue<State> q;
	vector<bool> visited(n+1,false);
	q.push({st,0});
	visited[st]=true;
	while(!q.empty()){
		State cur=q.front();
		q.pop();
		int cur_floor=cur.floor;
		int cur_steps=cur.steps;
		int up = cur_floor + u;
        if (up == en) return cur_steps + 1;
        if (up <= n && !visited[up]) {
            q.push({up, cur_steps + 1});
            visited[up] = true;
        }
int down = cur_floor - d;
        if (down == en) return cur_steps + 1;
        if (down >= 1 && !visited[down]) {
            q.push({down, cur_steps + 1});
            visited[down] = true;
        }
	}
	return -1;
}
int main(){
	int n,st,en,u,d;
	cin>>n>>st>>en>>u>>d;
	cout<<result(n,st,en,u,d)<<endl;
	return 0;
}
