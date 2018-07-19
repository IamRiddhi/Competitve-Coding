#include <stdio.h>
#include<stdlib.h>
int main()
{
    float cost;
    int t,totalWeight,noOfItems,left,val[101],wt[101],sortedIndex[101],i,j;
	float valPerWt[101];
    scanf("%d",&t);
    while(t--)
    {
    	cost=0;
        scanf("%d%d",&noOfItems,&totalWeight);
        for(i=1;i<=noOfItems;i++)
        {
        	scanf("%d%d",&val[i],&wt[i]);
        	valPerWt[i]=(float)val[i]/(float)wt[i];
        	sortedIndex[i]=i;
        	
        	//applying insertion sort on basis of val[i]/wt[i]
        	
        	for(j=i;j>1;j--)
        	{
        		if( valPerWt[sortedIndex[j-1]] < valPerWt[i])
        		{
        			sortedIndex[j-1]=sortedIndex[j-1]^ sortedIndex[j];
		        	sortedIndex[j]=sortedIndex[j-1]^ sortedIndex[j];
					sortedIndex[j-1]=sortedIndex[j-1]^ sortedIndex[j];
				}
				else break;
			 } 
		}
	        
	    
			left=totalWeight;
			i=1;
			while(i<=noOfItems && wt[sortedIndex[i]]<=left ) // there are items left and total weight of a particular element is less than equal to left
			{
			 	left-=wt[sortedIndex[i]];
			 	cost+=val[sortedIndex[i]];
			 	i++;
		    }	 
		    if(i<=noOfItems && left) //there are items left and weight left in knapsack to be filled.
		    	cost+=(left*valPerWt[sortedIndex[i]]);
	        	
        	printf("%.2f\n",cost);
    }
	return 0;
}


/* print internal things */

// 	for(i=1;i<=noOfItems;i++)
// 		{
// 		    printf("%d ",val[i]);
// 		}printf("\n");
// 		for(i=1;i<=noOfItems;i++)
// 		{
// 		    printf("%d ",wt[i]);
// 		}printf("\n");
// 		for(i=1;i<=noOfItems;i++)
// 		{
// 		    printf("%f ",valPerWt[i]);
// 		}printf("\n");
// 		for(i=1;i<=noOfItems;i++)
// 		{
// 		    printf("%d ",sortedIndex[i]);
// 		}printf("\n");
