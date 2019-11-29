bool satisfy(vector<int> &books, int students,long mid) // mid is the maximum we want to acheive
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
    if(booksInd < books.size()) // increase the maximum, with such less maximum we can't allocate all the books. 
        return false;
    /* please note i am not checking whether all students are served or not because if all students are not served,that means maximum value
    is too high. Therefore we need to decrease the maximum. Hence we are returing true because even if we allocated successfully,
    we would have decreased our hi and we also know we have a solution within this. */
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
