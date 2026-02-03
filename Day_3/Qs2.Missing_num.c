int missingNum(int *arr, int size) {
    long long total_sum,c_sum,n;
    
    n=size+1;
    total_sum = ((n)*(n+1))/2;
    c_sum = 0;
    
    for(int i=0;i<size;i++){
        c_sum += arr[i];
    }
    int m_num = (int)(total_sum - c_sum);
    return m_num;
}
