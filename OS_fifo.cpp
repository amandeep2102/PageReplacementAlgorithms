#include <iostream>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
using namespace std;

class FIFO{
    private:
    int numframes, numpages, size = 0, pagefaults = 0;

    struct Node
    {
        int Data;
        struct Node *next;
    };

    void delAtfront(struct Node **head)
    {
        struct Node *ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }

    void createLL(struct Node **head, int value)
    {
        struct Node *traverse = *head;
        if (size == numframes)
        {
            while (traverse->next != NULL && traverse->Data != value)
            {
                traverse = traverse->next;
            }
            if (traverse->Data != value)
            {
                delAtfront(head);
                struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp->Data = value;
                tmp->next = NULL;
                traverse->next = tmp;
                pagefaults++;
            }
        }
        else
        {
            while (traverse->next != NULL && traverse->Data != value)
            {
                traverse = traverse->next;
            }
            if (traverse->Data != value)
            {
                struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp->Data = value;
                tmp->next = NULL;
                traverse->next = tmp;
                size++, pagefaults++;
            }
        }
    }

    void PrintLL(struct Node *head)
    {
        struct Node *ptr = head;
        cout << "\t" << ptr->Data ;
        ptr = ptr->next;
        while (ptr != NULL)
        {
            cout << "\t" << ptr->Data ;
            ptr = ptr->next;
        }
    }
public:
    void fifo(vector<int> s, int n) {
        numframes=n;
        numpages = s.size();
        struct Node *head = (struct Node *)malloc(sizeof(struct Node));
        head->Data = s[0];
        size++, pagefaults++;
        head->next = NULL;
        cout << "\nInserting " << s[0] << " into the queue - ";
        PrintLL(head);
        for (int i = 1; i < numpages; i++)
        {
            cout << "\nInserting " << s[i] << " into the queue - ";
            createLL(&head, s[i]);
            PrintLL(head);
        }
        cout << "\nTotal Page Faults: " << pagefaults << "\n";  

    }

};

int main(int argc, char** argv)
{
    // char* arg1 = "5";
    // char* arg2 = "3";
    // if (argc>=1){
    //     arg1 = argv[1];
    //     arg2 = argv[2];
    // }
    // FIFO f;
    // srand(0);
    // vector<int> s;
    // int n = stoi(arg1);
    // cout<< "arg1 " << arg1 << " arg2 " << arg2 << endl;

    // for (int i = 0; i < stoi(arg2); i++)
    // {
    //     s.push_back(rand()%10);
    // }
    // f.fifo(s, n);
    FIFO f;
    srand(0);
    vector<int> s;
    int n=5;
    for (int i = 0; i < 30; i++)
    {
        s.push_back(rand()%10);
    }
    f.fifo(s, n);
}
