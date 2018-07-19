#include<bits/stdc++.h>
#include<cmath>
using namespace std;
class  PrimePolynom
{
	public:
		int reveal(int a,int b,int c)
        {
            int m;
            for(m=0;m<=80;m++)
            {
                int no= (m*m)*a + b*m + c;
                if(no<=1)
                    break;
                int sq= sqrt(no);
                bool flag= true;
                for(int i=2;i<=sq;i++)
                {
                    if(no%i==0)
                    {
                        flag= false;
                        break;
                    }
                }
				if(!flag)
                        break;                    
            }
            return m;
        }
};