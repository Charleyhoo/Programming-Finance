// Chang Huang class3

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// we have 20 arrays(students）  vote for 5 candidates
int main()
{
    /*int five_array[5]={1,2,3,4,5};*/
    const string candidate_array[] = {"dazhuge", "f", "xx", "128", "igang"};
    // u need to vote one candidate
    cout << "Enter the number of one candidate\n";
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << "." << candidate_array[i] << endl;
    }
    // Now u make your choice
    int number;                   // the candidate number
    const int people = 20;        // 20 people make their choices
    int select;                   // this is a switch to determine go and return back
    int vote[] = {0, 0, 0, 0, 0}; // we need to count votes
    for (int i = 1; i < people + 1; i++)
    {
        select = true;
        while (select)
        {
            cout << "ur the " << i << " chooses number:" << endl;
            cin >> number;
            if (number > 5 || number < 1)
            {
                cout << "u choose the wrong number please try another";
            }
            else
            {
                cout << "ur choice is: " << candidate_array[i] << " If correct choose 1: ";
            }
            // judge the choose 1
            int choose;
            cin >> choose;
            if (choose == 1)
            {
                select = false;
                vote[number - 1]++;
                cout << "u make a good decision thank u\n";
            }
        }
    }

    // let's start the apprentice part
    int apprentice_count = 0;
    int apprentice_array[2];
    int current_max = 0;

    for (int i = 0; i < 5; i++)
    {
        if (vote[i] > current_max)
        {
            current_max = vote[i];
            apprentice_count = 1;
            apprentice_array[apprentice_count - 1] = i;
        }
        else if (vote[i] == current_max)
        {
            apprentice_count++;
            if (apprentice_count <= 2)
            {
                apprentice_array[apprentice_count - 1] = i;
            }
        }
    }
    cout << endl;

    if (apprentice_count < 2)
    {
        for (int i = 0; i < apprentice_count; i++)
        {
            cout << "Apprentice is: " << candidate_array[apprentice_array[i]] << endl;
        }
    }
    else
    {
        cout << "There is no winner. " << endl;
    }

    return 0;
}