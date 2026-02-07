void moveZeros(int *arr, int n) {
    int pos = 0; // Tracks the next position to place a non-zero number

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
       // Swap the non-zero element with the element at 'pos'
        {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
            
            pos++;
        }
    }
}
