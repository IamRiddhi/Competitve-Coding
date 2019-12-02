bool satisfy(int A, int B, vector<int> &C,long time)
{
    int painterIndex = 0;
    long totalTime = 0;
    int i = 0;
    for(i=0;i<C.size();)
    {
        if((totalTime + B*(long)C[i]) > time )
        {
            totalTime = 0;
            painterIndex++;
            if(painterIndex == A)
                break;
        }
        else
        {
            totalTime += (B*(long)C[i]);
            i++;
        }
        
    }
    
    return (i == C.size());
}

int Solution::paint(int A, int B, vector<int> &C) {
    long mod = 10000003;
    long n = C.size();
    long maxi = *(max_element(C.begin(),C.end()));
    if(A >= n) // every painter will take one board
        return (int)((maxi*B)%mod);
    
    long lo = maxi * B;
    long sum = 0;
    for(int x : C)
        sum += x;
    long hi = sum * B;
    while(lo <= hi)
    {
        long mid = lo + (hi-lo)/2;
        if(satisfy(A,B,C,mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    hi = (hi+1)%mod;
    return (int)hi;
}
