#include <iostream>
using namespace std;
const int maxn=100010;
int heap[maxn],size;
int m,n;
void down(int u)
{
	int t=u;
	if(u*2<=size && heap[u*2]<heap[t])     	t=u*2;  //有左儿子并且小于它 
	if(u*2+1<=size && heap[u*2+1]<heap[t])	t=u*2+1; //有右儿子并且小于它 
	if(u!=t)
	{
		swap(heap[t], heap[u]);
		down(t);            //递归dowm下去 ,不加判断会死循环
	 } 
}

void up(int u)   //插入使用 
{
	while(u/2 && heap[u/2]>heap[u])  //有祖先并且祖先比它大 
	{
		swap(heap[u], heap[u/2]);
		u/=2;
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)	cin>>heap[i];
	size=n;        //size指向最后一个元素 
	for(int i=n/2; i; --i)	down(i);          //利用二叉树性质，最后一个父节点开始down 
	for(int i=1; i<=6; i++)	cout<<heap[i]<<' ';
	cout<<endl;
	while(m--)
	{
		cout<<heap[1]<<" "; 
		heap[1]=heap[size];      //删掉堆顶元素 
		size--;    //删掉元素
		down(1); 
	 } 	
}

