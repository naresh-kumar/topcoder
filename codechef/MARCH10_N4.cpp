// https://www.codechef.com/MARCH10/status/N4,nemausus
// https://www.codechef.com/viewplaintext/198819
#include<iostream>
using namespace std;
int minMove=10;
int movess[2][7];
int moveCount=0;
int move[2][7];
void rotate1A(int* arr)
{
	int index[]={0,3,6,8,5,2};
	int temp=arr[index[0]];
	for(int i=0;i<5;i++) arr[index[i]]=arr[index[i+1]];
	arr[index[5]]=temp;
}
void rotate1C(int* arr)
{
	int index[]={0,3,6,8,5,2};
	int temp=arr[index[5]];
	for(int i=5;i>0;i--) arr[index[i]]=arr[index[i-1]];
	arr[index[0]]=temp;
}
void rotate2A(int* arr)
{
	int index[]={1,4,7,9,6,3};
	int temp=arr[index[0]];
	for(int i=0;i<5;i++) arr[index[i]]=arr[index[i+1]];
	arr[index[5]]=temp;
}
void rotate2C(int* arr)
{
	int index[]={1,4,7,9,6,3};
	int temp=arr[index[5]];
	for(int i=5;i>0;i--) arr[index[i]]=arr[index[i-1]];
	arr[index[0]]=temp;
}
void rotate3A(int* arr)
{
	int index[]={6,9,11,12,10,8};
	int temp=arr[index[0]];
	for(int i=0;i<5;i++) arr[index[i]]=arr[index[i+1]];
	arr[index[5]]=temp;
}
void rotate3C(int* arr)
{
	int index[]={6,9,11,12,10,8};
	int temp=arr[index[5]];
	for(int i=5;i>0;i--) arr[index[i]]=arr[index[i-1]];
	arr[index[0]]=temp;
}
void printConfig(int* arr)
{
	cout<<"  "<<arr[0]<<"   "<<arr[1]<<endl;
	cout<<arr[2]<<"   "<<arr[3]<<"   "<<arr[4]<<endl;
	cout<<arr[5]<<"   "<<arr[6]<<"   "<<arr[7]<<endl;
	cout<<"  "<<arr[8]<<"   "<<arr[9]<<endl;
	cout<<"  "<<arr[10]<<"   "<<arr[11]<<endl;
	cout<<"    "<<arr[12]<<endl;
	cout<<endl;
}
int isAns(int* arr)//returns 0 on success
{
	int ans[]={0,0,0,1,0,0,1,0,1,1,0,0,0};
	int sum =0;
	for(int i=0;i<13;i++)
	sum+=arr[i]^ans[i];
	return sum;
}
void solve(int moveCount,int hex,int dir,int* arr)
{
	if(!isAns(arr)){
		if(moveCount<minMove){
			minMove=moveCount;
			for(int i=0;i<moveCount;i++){
				movess[0][i]=move[0][i];
				movess[1][i]=move[1][i];
			}


		}
		return;// moveCount;
	}
	if(moveCount==(minMove-1) || moveCount==7){
		return;// 100;
	}
	if(!(hex==0 && dir==1)){
		rotate1A(arr);
		move[0][moveCount]=0;
		move[1][moveCount]=0;
		moveCount++;
		solve(moveCount,0,0,arr);
		moveCount--;
		rotate1C(arr);
	}
	if(!(hex==0 && dir==0)){
		rotate1C(arr);
		move[0][moveCount]=0;
		move[1][moveCount]=1;
		moveCount++;
		solve(moveCount,0,1,arr);
		moveCount--;
		rotate1A(arr);
	}
	if(!(hex==1 && dir==1)){
		rotate2A(arr);
		move[0][moveCount]=1;
		move[1][moveCount]=0;
		moveCount++;
		solve(moveCount,1,0,arr);
		moveCount--;
		rotate2C(arr);
	}

	if(!(hex==1 && dir==0)){
		rotate2C(arr);
		move[0][moveCount]=1;
		move[1][moveCount]=1;
		moveCount++;
		solve(moveCount,1,1,arr);
		moveCount--;
		rotate2A(arr);
	}

	if(!(hex==2 && dir==1)){
		rotate3A(arr);
		move[0][moveCount]=2;
		move[1][moveCount]=0;
		moveCount++;
		solve(moveCount,2,0,arr);
		moveCount--;
		rotate3C(arr);
	}
	if(!(hex==2 && dir==0)){
		rotate3C(arr);
		move[0][moveCount]=2;
		move[1][moveCount]=1;
		moveCount++;
		solve(moveCount,2,1,arr);
		moveCount--;
		rotate3A(arr);
	}


	/*int m=a[0];
	move[0][moveCount]=0;
	move[1][moveCount]=0;
	for(int i=0;i<5;i++){
		if(a[i+1]<a[i]){
			m=a[i+1];
			move[0][moveCount]=(i+1)/2;
			move[1][moveCount]=(i+1)%2;
		}
	}
	return m;*/
}
int main()
{
	int testCases;
	cin>>testCases;
	while(testCases--){
		int arr[13];
		char ch;
		for(int i=0;i<13;i++){
			cin>>ch;
			arr[i]=ch-48;
		}
		//printConfig(arr);
		solve(moveCount,6,6,arr);
		cout<<minMove<<endl;
		for(int i=0;i<minMove;i++)
		cout<<movess[0][i]<<" "<<movess[1][i]<<endl;
		//cout<<endl;
		minMove=10;
		/*
		rotate1A(arr);
		printConfig(arr);
		rotate1C(arr);
		printConfig(arr);
		rotate2A(arr);
		printConfig(arr);
		rotate2C(arr);
		printConfig(arr);
		rotate3A(arr);
		printConfig(arr);
		rotate3C(arr);
		printConfig(arr);
		*/
	}
	return 0;
}
