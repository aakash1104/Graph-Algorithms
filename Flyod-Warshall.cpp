#include<iostream>
#include<vector>
using namespace std;
#define endl '\n'

const int INF = 1e9;
int n;
vector<vector<int> >graph;
vector<vector<int> >distance;

// Creating the Matrix ( graph)

void create_graph(){
   cin>>n;
   graph = vector<vector<int> >(n+1,vector<int>(n+1));

   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++)cin>>graph[i][j];
    }
}

//Using Flyod Warshall algorithm to calculate all point shortest distance

void calculate(){
    distance = vector<vector<int> >(n+1,vector<int>(n+1,INF));

    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++)distance[i][j]=graph[i][j];
    }

    for(int k=1;k<=n;k++){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          if(distance[i][j]>distance[i][k] + distance[k][j]){
            distance[i][j] = distance[i][k] + distance[k][j];
          }
        }
      }
    }
}
void solve(){
    create_graph();
    calculate();
    int start_point,end_point;
    cin>>start_point>>end_point;

    cout<<distance[start_point][end_point]<<endl;

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
}
