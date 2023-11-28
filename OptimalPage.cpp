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
    void optimal(vector<long long int> s, long long int n){
        vector<int> fr;
        int hit = 0;
        int victim, tmp, length;

        for (int i = 0; i < s.size(); i++)
        {
            if (search(s[i], fr)){
                hit++;
                cout<< "\npage hit"<<endl<<endl;
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

            cout<< endl;
            for (int k = 0; k < fr.size(); k++)
            {
                cout<< fr[k] << " " << "fr" << endl;
            }
            cout << endl;
            cout << "next frame" << endl;
        }

        cout << "page hit " << hit << endl;
        cout << "page fault " << s.size() - hit << endl;
    }

};


int main() {
    OptimalPageRep op;
    srand(0);
    vector<long long int> index;
    for (int i = 0; i < 30; i++)
    {
        index.push_back(rand()%10);
        cout << index[i] << " ";
    }
    cout<< endl;
    long long int n = 3;
    op.optimal(index, n);
    return 0;
}