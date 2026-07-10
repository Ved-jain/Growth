class Solution {
public:
    const long long mod = 1e9+7;
    int maximumXorProduct(long long a, long long b, int n) {
        long long A = 0;
        long long B = 0;

        // Copy bits above n
        for(int i = 50; i >= n; i--){
            if(a & (1LL<<i)) A |= (1LL<<i);
            if(b & (1LL<<i)) B |= (1LL<<i);
        }


        for(int i = n-1; i>=0 ; i--){
            bool abit = (a>>i) & 1 ;
            bool bbit = (b>>i) & 1 ;

            if(abit == bbit){
                A|= (1LL<<i);
                B|= (1LL<<i);
            }

            else if(A>B){
                B|= (1LL<<i);
            }
            else{
                A|= (1LL<<i);
            }
        }
        
        return (A % mod) * (B % mod) % mod;

    }
};