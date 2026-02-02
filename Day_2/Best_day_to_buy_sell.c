int maxProfit(int* prices, int pricesSize) {
    if(pricesSize == 0) return 0;
   int min_pr = prices[0];
   int max_p = 0;
   for(int i = 0; i < pricesSize; i++){
    if( prices[i] < min_pr ){
        min_pr = prices[i];
    }
    int cp = prices[i] - min_pr;
    if(cp > max_p){
        max_p = cp ;
    }
   }
   return max_p;

}
