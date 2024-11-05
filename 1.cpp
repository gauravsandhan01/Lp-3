#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item
{
    int value,weight;
    Item(int value, int weight):value(value),weight(weight){}

};


bool compare(Item a,Item b)
{
    double r1 =(double)a.value/a.weight;
    double r2 =(double)b.value/b.weight;
    return r1>r2;
}

double fractionalKnapsack(int W, vector<Item>& items)
{
    sort(items.begin(),items.end(),compare);
    double totalValue=0.0;

    for(auto& item: items)
    {
        if(W>=item.weight)
        {
            W -=item.weight;
            totalValue +=item.value;
        }
        else
        {
            totalValue +=item.value *((double)W/item.weight);
            break;
        }
    }
    return totalValue;
}
int main()
{
    int n,W;
    cout<<"enter rhe numer";
    cin>>n;
    cout<<"enter the weight";
    cin>>W;

    vector<Item>items;
    cout<<"enter the nubmer of knapsack:\n";
    for(int i=0;i<n; i++)
    {
        int value,weight;
        cout<<"enter the value and weight of knapsack"<<i +1 <<":";
        cin>>value>>weight;
        items.emplace_back(value,weight);

    }
    
    double maxValue =fractionalKnapsack(W,items);
    cout<<"max value of item"<<maxValue<< endl;

    return 0;

}