// 33. Rain Water Trapping

#include<bits/stdc++.h>
using namespace std;
    
long long trappingWater(int arr[], int n){
    long long int water = 0;
    
    int maxLftArr[n-2];
    int maxRgtArr[n-2];
    
    int maxLft = arr[0];
    for (int i=1; i<n-1; i++){
        maxLftArr[i] = maxLft;
        if (maxLft < arr[i]){
            maxLft = arr[i];
        }
    }
    
    int maxRgt = arr[n-1];
    for (int i=n-2; i>0; i--){
        maxRgtArr[i] = maxRgt;
        if (maxRgt < arr[i]){
            maxRgt = arr[i];
        }
    }
    
    
    for (int i=1; i<n-1; i++){
        int temp = min(maxLftArr[i], maxRgtArr[i]);
        if (temp>=arr[i])
            water+= temp - arr[i];
    }
    
    return water;
}


int main(){
    
    int n;
    cin >> n;
    
    int a[n];
    
    //adding elements to the array
    for(int i =0;i<n;i++){
        cin >> a[i];            
    }
    cout <<"Maximum Water that can be trapped: "<< trappingWater(a, n) << endl;
    
    
    return 0;
}