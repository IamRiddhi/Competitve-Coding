#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll len,n;
unordered_set<string> dict;
bool searchInDict(string word)
{
    if(dict.find(word)!=dict.end())
  		return true;
    return false;
}

/*variable length denotes the summation of lengths of all previously formed words.
For eg i am a boyandgirl. so there are 4 strings in the vector vs that are ["i","am","a","boyandgirl"].
Therefore length  = len("i") + len("am") + len("a") =  1+2+1 = 4.
Note that we will not consider the length of last string because this the word which we are supposed
to split now and has not yet been split.*/

void WordBreak(string lastWord,ll spacePos,string result,ll length)
{
	if(spacePos>len)
    {
      	if(searchInDict(lastWord))
      		cout<<result+lastWord<<endl;
      	return;
    }
  	ll splitLen = spacePos - length;
  	
  	WordBreak(lastWord,spacePos+1,result,length);//without giving space
  	
  	 /* splitting the last word into two words and inserting into result string if the first word is present in
    dictionary*/
  
  	string split1(lastWord.begin(),lastWord.begin()+splitLen); 
    string split2(lastWord.begin()+splitLen,lastWord.end());
  
  	if(searchInDict(split1)) //if word formed is present in dictionary
        /*deleting the last word and inserting the two spliited words formed from last word into the vector */
        WordBreak(split2,spacePos+1,result+split1+" ",length+split1.length()); // giving space.
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
  	string str;
    rep0(n)
    {
        cin>>str;
      	dict.insert(str);
    }
    string sentence;
    cin>>sentence;
    len = sentence.length();
    WordBreak(sentence,1,"",0);
    return 0;
}