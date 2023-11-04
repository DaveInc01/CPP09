#include <iostream>
#include <vector>
#include <list>

typedef std::list<unsigned long>::iterator lstIt;

void merge_vect(std::vector<unsigned long> &leftvect, std::vector<unsigned long> &rightvect, std::vector<unsigned long> &vect){
    int len = (int)vect.size();
    int leftSize = len / 2;
    int rightSize = len - leftSize;
    int i = 0;
    int l = 0;
    int r = 0;

    while(l < leftSize && r < rightSize)
    {
        if (leftvect[l] < rightvect[r])
        {
            vect[i] = leftvect[l];
            l++;
            i++;
        }
        else{
            vect[i] = rightvect[r];
            r++;
            i++;
        }
    }
    while (l < leftSize)
    {
        vect[i] = leftvect[l];
        i++;
        l++;
    }
    while (r < rightSize)
    {
        vect[i] = rightvect[r];
        i++;
        r++;
    }
}

void split_vect(std::vector<unsigned long> &vect)
{
    int len = (int)vect.size();
    if (len <= 1)
        return ;
    std::vector<unsigned long> left;
    std::vector<unsigned long> right;
    int mid = len / 2;
    left.resize(mid);
    right.resize(len - mid);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (i < mid)
            left[i] = vect[i];
        else
            right[j++] = vect[i]; // Increment j after assigning value
    } 
    split_vect(left);
    split_vect(right);
    merge_vect(left, right, vect);
}

void merge_list(std::list<unsigned long> &lst, std::list<unsigned long> &left, std::list<unsigned long> &right)
{
    lstIt rIt = right.begin();
    lstIt lIt = left.begin();
    while (lIt != left.end() && rIt != right.end())
    {
        if (*lIt < *rIt)
        {
            lst.push_back(*lIt);
            ++lIt;
        }
        else
        {
            lst.push_back(*rIt);
            ++rIt;
        }
    }
    while (lIt != left.end())
    {
        lst.push_back(*lIt);
        ++lIt;
    }
    while (rIt != right.end())
    {
        lst.push_back(*rIt);
        ++rIt;
    }
    
}

void split_list(std::list<unsigned long> &lst)
{
    int len = (int)lst.size();
    if (len <= 1)
        return ;
    int mid = len / 2;
    std::list<unsigned long> left;
    std::list<unsigned long> right;
    
    std::list<unsigned long>::iterator it = lst.begin();
    std::advance(it, mid); // Move the iterator to the middle position

    left.splice(left.begin(), lst, lst.begin(), it);
    right.splice(right.begin(), lst, it, lst.end());

    split_list(left);
    split_list(right);
    merge_list(lst, left, right);
}

int main(){
    // std::vector<unsigned long> vect{12, 21, 223, 2, 45, 2};
    // split_vect(vect);
    std::list<unsigned long> lst{12, 21, 223, 2, 45};
    split_list(lst);
    lstIt i = lst.begin();
    while (i != lst.end())
    {
        std::cout << *i << " ";
        ++i;
    }
    return 0;
}