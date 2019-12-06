class Solution {
public:
    int totalHammingDistance(vector<int>& A) {
        long mod = 1e9 + 7;
        int n  = A.size();
        long s = 0;

        for(int i = 0; i < 31; i++)
        {
            int zeroes = 0;
            for(int j = 0; j < n ; j++)
                if( (A[j] & (1<<i) ) == 0 )
                    zeroes ++;
            long ones = n - zeroes;
            long addi = (zeroes*ones)%mod;
            s = (s+addi)%mod;
        }
        return (int)s;
    }
};
