#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using std::vector;
using std::count;
using std::cout;
using std::endl;
using std::pair;

using namespace std;

void compute_frequency(vector<double> &prices, double start, double end, double step)
{
    int nbins = int(std::abs(end-start)/step);
    vector<pair<int,int>> count(nbins, std::make_pair(0,0));
    for (int i=0; i<nbins; ++i)
    {
        count[i].second = i;
    }
    for (int i=0; (unsigned)i<prices.size(); ++i)
    {
        if(start <=prices[i] && prices[i] <= end)
        {
            int pos = int((prices[i] - start)/step);
            count[pos].first++;
        }
    }
    std::sort(count.begin(), count.end());
    for (int i=0; i<nbins; ++i)
    {
        int k = count[i].second;
        cout<<(start+k *step) << "-" << (start + (k+1) *step) << ":" << (count[i].first)<<endl;
    }
}

int main()
{
    vector<double> prices ={32.3, 34, 35.6, 39.2, 38.7, 31.17, 33.14};
    compute_frequency(prices, 31.0, 39.0, 0.1);
    return 0;
}


