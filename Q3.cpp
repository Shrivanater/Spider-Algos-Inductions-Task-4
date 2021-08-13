#include<iostream>
#include<algorithm>

const int M = 1e5 + 1;
using namespace std;
 
int Solve(int arr[], int n, int k){
    int fw[n], bw[n], i, j;
    int arraySum = arr[0], maxSum = arr[0], ans;

    fw[0] = arr[0];
    for(i = 1; i < n; i++){
        arraySum = max(arr[i], arraySum + arr[i]);
        maxSum = max(maxSum, arraySum);
        fw[i] = arraySum;
    }

    arraySum = maxSum = bw[n - 1] = arr[n - 1];
    for(i = n - 2; i >= 0; i--){
        arraySum = max(arr[i], arraySum + arr[i]);
        maxSum = max(maxSum, arraySum);
    	bw[i] = arraySum;
    }

    ans = maxSum;

	for(j = 1; j <= k; j++){
	    for(i = 1; i < n - j; i++){
	        ans = max(ans, max(0, fw[i - 1]) + max(0, bw[i + j]));
	    }
	    
	    if(ans == 0){
	        return *max_element(arr, arr + n);
	    }
	}
    
    return ans; 
}
 
int main(){
    int i, N, K, arr[M];
	cin >> N >> K;
	
	for(i = 0; i < N; i++){
		cin >> arr[i];
	}
	
    cout << Solve(arr, N, K);
    return 0;
}
