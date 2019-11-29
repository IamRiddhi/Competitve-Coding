bool satisfy(vector<int> &books, int students,long mid)
{
    int booksInd = 0;
    int st = 0;
    long totPages = 0;
    while(st < students && booksInd < books.size())
    {
        if(totPages+books[booksInd] > mid)
        {
            totPages = 0;
            st++;
        }
        else
        {
            totPages += books[booksInd];
            booksInd++;
            if(booksInd == books.size())
                st++;
        }
    }
    if(booksInd < books.size())
        return false;
    return true;
}
int Solution::books(vector<int> &books, int students) {
    if(students > books.size())
        return -1;
    long hi = 0;
    for(int i=0;i<books.size();i++)
        hi += books[i];
    long lo = *(max_element(books.begin(),books.end()));
    while(lo <= hi)
    {
        long mid = lo + (hi-lo)/2;
        if(satisfy(books,students,mid))
            hi = mid - 1;
        else
            lo = mid + 1;
            
    }
    return hi + 1;
}
