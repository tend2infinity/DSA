class Solution {
public:
    #define ll long long
    ll sumDigit(ll n){
        ll num=n;
        ll sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    
    
    long long makeIntegerBeautiful(long long n, int target) {
        ll sum=0;
        ll num = n;
        sum = sumDigit(num);
        int counter=1;
        while(sum>target){
            num+= (ll)(pow(10,counter)) - num% (ll)(pow(10,counter));
            sum = sumDigit(num);
            counter++;
        }
        return num-n;
    }
};