#include <iostream>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
using namespace std;

class FIFO{
    public:
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
                struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp->Data = value;
                tmp->next = NULL;
                traverse->next = tmp;
                delAtfront(head);
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
        // cout << "\t" << ptr->Data ;
        ptr = ptr->next;
        while (ptr != NULL)
        {
            // cout << "\t" << ptr->Data ;
            ptr = ptr->next;
        }
    }
public:
    int fifo(vector<int> s, int n) {
        numframes=n;
        numpages = s.size();
        struct Node *head = (struct Node *)malloc(sizeof(struct Node));
        head->Data = s[0];
        size++, pagefaults++;
        head->next = NULL;
        // cout << "\nInserting " << s[0] << " into the queue - ";
        PrintLL(head);
        for (int i = 1; i < numpages; i++)
        {
            // cout << "\nInserting " << s[i] << " into the queue - ";
            createLL(&head, s[i]);
            PrintLL(head);
        }
        // cout << "\nTotal Page Faults: " << pagefaults << "\n";  
        while (head->next != NULL)
        {
            struct Node *tmp = head;
            head = head->next;
            free(tmp);
        }
        
        
        return pagefaults;
    }

};

int main(int argc, char** argv)
{
    FIFO f;
    srand(time(0));
    vector<int> RefString;
    int FrameNum=10;
    cout << "Refrence String: ";
    for (int i = 0; i < 15; i++)
    {
        RefString.push_back(rand()%10);
        cout << RefString[i] << " ";
    }
    cout << "\nFrame size: " << FrameNum << endl;

    // for (int i = 1; i <= 100; i=i+4)
    // {
    //     cout << f.fifo(s, i) << " " << i << endl;
    //     f.pagefaults = 0;
    //     f.size = 0;
    // }
    
    cout << "Page Faults: " << f.fifo(RefString, FrameNum) << endl;
    
}
