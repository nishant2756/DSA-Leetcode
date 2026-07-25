class Solution {
public:
    int maxProduct(int n) {
       int first = 0;
       int next = 0;

       while(n > 0){
        int x = n % 10;
         if(x > first){
            next = first;
            first = x;
         }else if(x > next){
            next = x;
         }
         n /= 10;
       }
       return first * next;

    }
};