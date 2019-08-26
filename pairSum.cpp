/*
Developer: Hamed Mirlohi
Date: Aug 25 2019
In this program we want to find all pairs of numbers which sums to a total given. for example 
{4,1,-1,7,3}    total = 5
result = (4,1)

Note: you are not allowed to use the brute force way to calculate the pair since the complexity is O(n^2)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

vector<std::pair<int,int>> get_pairs(const int* arr, const int&& size, const int& total)
{

    std::unordered_map<int,int> myHash;
    vector<std::pair<int,int> > pairs;

    for (int i = 0; i < total; i++)
    {
        int result = total - arr[i];

        // element exist in Hash?
        if(myHash.find(result) != myHash.end())
        {
            // add the result and element as pair to the final answer
            pairs.push_back(std::pair<int,int>(arr[i],result));
        }
        // store element to hash
        myHash[arr[i]] = 100;
    }
    
    return pairs;
}


int main(void)
{
    int arr[] = {1 ,5 ,7 ,-1 ,50 };
    int total = 6;




    auto answer = get_pairs(arr, std::move(sizeof(arr[0])), total);

    for(auto& x : answer)
    {
        std::cout << "( " << x.first << ", " << x.second << " )" <<  std::endl;
    }

}
