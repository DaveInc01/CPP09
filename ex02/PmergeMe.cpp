#include "includes/PmergeMe.hpp"

std::vector<unsigned long> PmergeMe::vect;
std::list<unsigned long> PmergeMe::lst;
typedef std::list<unsigned long>::iterator lstIt;

PmergeMe::PmergeMe( const PmergeMe &copy)
{
	this->vect = copy.vect;
	this->lst = copy.lst;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &obj)
{
	this->vect = obj.vect;
	this->lst = obj.lst;
	return *this;
}

int check_arg(char* arg)
{

	int i = 0;
	if (arg[0] == '0' && arg[1] != '\0')
		return -1;
	while(arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return -1;
	}
	if ((i >= 19 && strcmp(arg, "18446744073709551615") > 0) || i > 20)
	{
		std::cout << "Too big number" << std::endl;
		return -1;
	}
	return 0;
}


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

void sort_vect(std::vector<unsigned long> &vect)
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
            right[j++] = vect[i];
    }
    sort_vect(left);
    sort_vect(right);
    merge_vect(left, right, vect);
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

void sort_list(std::list<unsigned long> &lst)
{
    int len = (int)lst.size();
    if (len <= 1)
        return ;
    int mid = len / 2;
    std::list<unsigned long> left;
    std::list<unsigned long> right;

    std::list<unsigned long>::iterator it = lst.begin();
    std::advance(it, mid);

    left.splice(left.begin(), lst, lst.begin(), it);
    right.splice(right.begin(), lst, it, lst.end());

    sort_list(left);
    sort_list(right);
    merge_list(lst, left, right);
}
