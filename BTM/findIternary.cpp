#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

//find RAGA journey

//US->Thila
//Thid->Bang
//India->Us

void topologicalSortUtil (string src,unordered_map<string,vector<string> >& travelG
        ,unordered_set<string>& visited,stack<string>& iStack) {

    visited.insert(src);

    vector<string> destLst = travelG[src];
    for (int i=0;i< destLst.size();i++ ) {
        string dest = destLst[i];
        if (visited.find(dest) == visited.end () )  {
            topologicalSortUtil (dest,travelG,visited,iStack);
        }
    }
    iStack.push(src);
}

vector<string> findIternary () {

    //Each adjacent pair lists the source and destination
    //TODO : list all the iternary
    string iternaryArr [] = {"US","Thiland","India","US","Thiland","Bangkok"};
    int len = sizeof(iternaryArr)/sizeof(iternaryArr[0]);
    //vector<string> iternary (iternaryArr,iternaryArr + len);

    //create graph
    unordered_map<string,vector<string> > travelG;
    for (int i=0;i<len-1;i+=2)  {
        string src = iternaryArr [i];
        string dest = iternaryArr [i+1];
        travelG[src].push_back(dest);
    }
    
    unordered_set<string> visited;
    stack<string> iStack;
    for (auto &iter : travelG) {
       string src = iter.first;
       cout << "src = " << src << endl;
       if (visited.find(src) == visited.end () )  {
            topologicalSortUtil(src,travelG,visited,iStack);
       }
    }

    vector<string> result;
    while (!iStack.empty()) {
        string visit = iStack.top();
        cout << visit  << endl;
        result.push_back(visit) ;
        iStack.pop();
    }
    return result;
}

int main () {

    findIternary ();
}




