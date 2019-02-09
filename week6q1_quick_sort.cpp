/*bubble sort takes n**2 time to sort
quick sort takes n**2 time but it is faster on an average
worst O(n2)
avg O(nlog(n))

Logic -
1. choose pivot
2. partition
3. recursion
4. stop conditon is when the partition  has one element

*/

#include<iostream>
using namespace std;
//displays the array elements
void display(int arr[],int len){
	for(int a=0;a<len;a++){
		cout<<arr[a]<<" ";
	}
	cout<<endl;
}
//interchanges the 2 specified positions in the array
void swap(int arr[], int s1, int s2){
	int p = arr[s2];
	arr[s2]=arr[s1];
	arr[s1]=p;
}
//partition logic - place pivot in such a position where the elements to its right is larger than pivot and that to its left are smaller the pivot 
int partition(int arr[],int low,int high){
	int pivot = high;

	//i denotes the position where the low lies and hence will undergo swap
	int i = low-1;
	
	//j runs through the whole array
	int j = low;
	while(j<=high-1){
		if (arr[j]<=arr[pivot]){
			i+=1;
			swap(arr,i,j);
		}
		j+=1;
	}
	//now i with be the junction between smaller set of elements and the bigger one
	swap(arr,i+1,pivot);
	//returning the junction position
	return i+1;	
}
//quick sort function - applies partition function recursively	
void QS(int arr[],int low,int high){
	if(low<high){
		int p=partition(arr,low,high);
		//recursive statement
		QS(arr,low,p-1);
		QS(arr,p+1,high);
	}
}
//main
int main(){
	int arr[10]={3,4,7,6,5,1,2,8,10,9};
	display(arr,10);
	QS(arr,0,9);
	display(arr,10);
	
	return 7;
}

