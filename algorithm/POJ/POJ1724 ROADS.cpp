#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int destinationCity, roadLength, toll;
    friend bool operator < (const Node &a, const Node &b)
    {
        if(a.roadLength==b.roadLength)
        {
            return a.toll>b.toll;
        }
        return a.roadLength>b.roadLength;
    }
}inputNode;

int maxCoin, cityNum, roadNum;
int sourceCity, destinationCity;
int roadLength, toll;
int distances[105];
priority_queue<Node> heap;
vector<Node> map[105];

int dijkstra()
{
    inputNode.destinationCity=1;
    inputNode.roadLength=0;
    inputNode.toll=0;
    heap.push(inputNode);
    distances[1]=0;
    for(int i=2;i<=cityNum;i++)
    {
        distances[i]=1000000000;
    }
    while(!heap.empty())
    {
        inputNode=heap.top();
        heap.pop();
        distances[inputNode.destinationCity]=inputNode.roadLength;
        if(inputNode.destinationCity==cityNum)
        {
            return distances[cityNum];
        }
        for(int i=0;i<map[inputNode.destinationCity].size();i++)
        {
            Node temp;
            temp.toll=inputNode.toll+map[inputNode.destinationCity][i].toll;
            if(temp.toll<=maxCoin)
            {
                temp.destinationCity=map[inputNode.destinationCity][i].destinationCity;
                temp.roadLength=inputNode.roadLength+map[inputNode.destinationCity][i].roadLength;
                heap.push(temp);
            }
        }
    }
    if(distances[cityNum]!=1000000000) return distances[cityNum];
    return -1;
}

int main()
{
    cin>>maxCoin>>cityNum>>roadNum;
    for(int i=0;i<roadNum;i++)
    {
        cin>>sourceCity>>destinationCity;
        cin>>roadLength>>toll;
        inputNode.destinationCity=destinationCity;
        inputNode.roadLength=roadLength;
        inputNode.toll=toll;
        map[sourceCity].push_back(inputNode);
    }
    cout<<dijkstra()<<endl;
    return 0;
}
