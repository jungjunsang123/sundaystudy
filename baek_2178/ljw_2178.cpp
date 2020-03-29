#include <iostream>
#include <queue>

using namespace std;

typedef struct _node
{
	int x;
	int y;
	int time;
	_node(int X,int Y,int t) : x(X),y(Y),time(t) {}
}Node;

queue<Node> container;
int space[102][102];
bool visited[102][102];
char line[102];

int main(void)
{
	int N,M,tmp,end_time;
	int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	cin>>N>>M;

	for (int i=0;i<102;i++)
	{
		visited[0][i]=true;
		visited[i][0]=true;
		visited[101][i]=true;
		visited[i][101]=true;
	}

	for (int i=1;i<=N;i++)
	{
		cin>>line;
		for (int k=1;k<=M;k++)
		{
			space[i][k]=line[k-1]-'0';
		}
	}

	container.push(Node(1,1,1));
	visited[1][1]=true;

	while (!container.empty())
	{
		Node temp=container.front();
		container.pop();

		if (temp.x==N && temp.y==M)
		{
			end_time=temp.time;
			break;
		}

		for (int k=0;k<4;k++)
		{
			int to_x=temp.x+direction[k][0];
			int to_y=temp.y+direction[k][1];
			if (!visited[to_x][to_y] && space[to_x][to_y]==1)
			{
				visited[to_x][to_y]=true;
				container.push(Node(to_x,to_y,temp.time+1));
			}
		}
	}

	cout<<end_time<<endl;

	return 0;
}
