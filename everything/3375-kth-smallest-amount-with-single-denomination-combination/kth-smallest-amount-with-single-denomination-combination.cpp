class Solution {
public:

    bool check(long long mid, vector<int>& coins, int k){

        int n = coins.size();
        long long count = 0;

        for(int mask = 1; mask < (1 << n); mask++){

            long long l = 1;
            int bits = 0;
            bool ok = true;

            for(int j = 0; j < n; j++){

                if(mask & (1 << j)) {

                    bits++;

                    long long g = gcd(l, (long long)coins[j]);

                   
                    if(l > mid / (coins[j] / g)){
                        ok = false;
                        break;
                    }

                    l = l / g * coins[j];
                }
            }

            if(!ok || l > mid)
                continue;

            long long ways = mid / l;

            if(bits % 2 == 1)
                count += ways;
            else
                count -= ways;
        }

        return count >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k){

        long long lo = 1;

        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while(lo < hi) {

            long long mid = lo + (hi-lo)/2;

            if(check(mid, coins, k))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};