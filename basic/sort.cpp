/*
*          选择排序   1<=i<=n
*/
#if 0
int A{maxn}, n; 
void SelectSort()
{
	for(int i=1; i<=n; ++i)        //进行n趟操作 
	{
		int k=i;
		for(int j=i; j<=n; j++)
		{
			if(A[k]>A[j])             //比前面大，记录下来 
			{
				k=j;
			} 
		}
		swap(A[k], A[i]);
	}
}


/*
*          插入排序   1<=i<=n
*/

int A[maxn], n;
void InsertSort()
{
	for(int i=2; i<=n; ++i)        //进行n-1趟查找 
	{
		int temp=A[i],j=i;	
		while(A[j-1]>temp && j>1)   //只要temp小于前面一个元素 
		{
			A[j]=A[j-1];           //覆盖
			j--; 
		}
		A[j]=temp;         //插入 
	}	
} 

/*
*          冒泡排序   0<i<n
*/

int A[maxn], n;
void BubbleSort()
{
	for(int i=0; i<n-1; ++i)          //n-1次排序 
	{
		bool flag =false;          //只要某一趟没有交换元素，则说明排序完成 
		for(int j=0; j<n-i-1; ++j)
		{
			if(A[j+1] < A[j])
			{
				swap(A[j], A[j+1]);
				flag=true;        //交换了元素 
			}
		}	
		if(!flag)	break; 
	} 
}
#endif

/*
*          归并排序   0<i<n         
*/

void merge(int s[], int l, int r)
{
	if(l>=r)	return ;   //当l=r时没必要再排序 
	int mid=l+r>>1;
	merge(s,l,mid);
	merge(s,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r)
	{
		if(s[i]<s[j])	temp[k++]=s[i++];
		else	temp[k++]=s[j++];
	}
	while(i<=mid)	temp[k++]=s[i++];
	while(j<=r)	temp[k++]=s[j++];
	for(int i=l,j=0; i<=r; i++,j++)	s[i]=temp[j];
}

/*
*          快速排序   0<i<n         
*/
void quick_sort(int q[], int l, int r)
{
    if(l>=r)    return ;//只有一个数不用再排序
    int i = l-1,j = r+1,x = q[l+r>>1];
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i<j) swap(q[i], q[j]);     //因为最后确定位置的数不知道在哪，所以两边都要递归
    }
    quick_sort(q, l, j);               //不用i的原因是，比如 1，2两个数的情况会出错 分为两边，一边小于等于一边大于等于 --------j-i-1----------- 
                                //可以这样改：用i的时候x不能为左边界，用j的时候x不能为有边界，改q[l+r>>1]即可
    quick_sort(q, j+1, r);
}

