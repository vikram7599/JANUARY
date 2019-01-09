#include<bits/stdc++.h>
using namespace std ;

void update(int index , int value , int *BIT, int n){

    for(; index <= n ; index += index&(-index)){
        BIT[index] += value ;
    }

}

int query(int index , int *BIT){
    int sum = 0 ;
    for(; index>0 ; index -= index&(-index)){
        sum += BIT[index];
    }

    return sum ;
}

int main(){
    int n ;
    cout << "Enter the size of the array" <<endl;
    cin >> n ;

    int *arr = new int[n+1] ;
    int *BIT = new int[n+1] ;

    for(int i=1 ; i <= n ; i++){
        arr[i] = 0 ;
        BIT[i] = 0 ;
    }
    //Input
    for(int i =1 ; i<= n ; i++){
        cin >> arr[i] ;
        update(i , arr[i] , BIT ,n) ;

    }


    //display
    cout << "The array is\t" ;
    for(int i=1 ; i <=n ; i++){
        cout << arr[i] << " " ;
    }

    int si ,ei;


    //QUERY 1
    cout << "Enter the starting index \t" ;
    cin >> si ;
    if(si <1 || si > n){
        cout << "Out of range index. Enter again\t";
        cin >> si ;
    }
    cout << "Enter the ending index\t" ;
    cin >> ei ;
    if(ei > n || ei <si){
        cout << "Out of range index.Enter again\t" ;
        cin >> ei ;
    }
    cout << "Sum of array from index " << si << " to " << ei << "is\t" << query(ei,BIT)-query(si-1,BIT) << endl;


    //UPDATE
    int ind;
    cout << "Enter the index which has to be updated\t" ;
    cin >> ind ;
    cout << "Enter the new value\t" ;
    int val ;
    cin >> val ;
    update(ind , val -arr[ind], BIT , n) ;
    arr[ind] = val ;

    cout << "The array is\t" ;
    for(int i=1 ; i <=n ; i++){
        cout << arr[i] << " " ;
    }

    cout << "Enter the starting index \t" ;

    cin >> si ;
    if(si <1 || si > n){
        cout << "Out of range index. Enter again\t";
        cin >> si ;
    }
    cout << "Enter the ending index\t" ;
    cin >> ei ;
    if(ei > n || ei <si){
        cout << "Out of range index.Enter again\t" ;
        cin >> ei ;
    }
    cout << "Sum of array from index " << si << " to " << ei << "is\t" << query(ei,BIT)-query(si-1,BIT) << endl;

}
