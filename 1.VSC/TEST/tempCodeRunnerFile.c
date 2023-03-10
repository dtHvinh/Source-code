void change(int arr[], int at, int value){
    int n = sizeof(arr)/sizeof(int);
    if( at > n){
        printf("Unable to change!");
        return;
    }
    arr[ at ] = value;
}