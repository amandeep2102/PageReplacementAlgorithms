#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class OptimalPageRep{
private:
vector<int> index;
    int searchlength(int key, vector<long long int>& s, int x){
        for (int i = x; i < s.size(); i++)
            if (s[i] == key) return i;
        return INT_MAX;
    }

    bool search(int key, vector<int>& fr){
        for (int i = 0; i < fr.size(); i++)
            if (fr[i] == key) return true;
        return false;
    }

public:
    int optimal(vector<long long int> s, long long int n){
        vector<int> fr;
        int hit = 0;
        int victim, tmp, length;

        for (int i = 0; i < s.size(); i++)
        {
            if (search(s[i], fr)){
                hit++;
                // cout<< "\n-----------------Page Hit--------------------"<<endl<<endl;
                continue;
            }
        
            if (fr.size() < n){
                fr.push_back(s[i]);
            }

            else{
                tmp = 0;
                for (int j = 0; j < fr.size(); j++)
                {
                    length = searchlength(fr[j], s, i+1);
                    if (length >= tmp){ 
                        victim = j;
                        tmp = length;
                    }
                }
                fr[victim] = s[i];
            }

            // cout<< endl;
            // for (int k = 0; k < fr.size(); k++)
            // {
            //     // cout<< fr[k] << " " << "fr" << endl;
            // }
            // cout << endl;
            // cout << "--------------Next Frame--------------" << endl;
        }

        // cout << "Page Hits -> " << hit << endl;
        // cout << "Page Faults -> " << s.size() - hit << endl;

        return (s.size() - hit);
    }

};


int main() {
    OptimalPageRep op;
    long long int stringsize = 500;
    long long int framesize = 100;

    srand(time(0));
    vector<long long int> refstring;

    for (int i = 0; i < stringsize; i++)
    {
        refstring.push_back(rand()%100);
        // cout << index[i] << " ";
    }

    for (int i = 5; i <= framesize; i = i+5)
    {
        cout << op.optimal(refstring, i) << " " <<  i << endl;
    }
    return 0;
}