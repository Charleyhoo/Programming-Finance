#include <iostream>

using namespace std;

class stringarray
{

private:
    int size;

    string *s;

public:
    stringarray();

    stringarray(int);

    stringarray(stringarray &s);

    int know_size();

    void outputstrings();

    void input_strings();

    void compare(int, int);
};

stringarray::stringarray()
{

    size = 5;

    s = new string[size];
}

stringarray::stringarray(int S)
{

    size = S;

    s = new string[size];
}

stringarray::stringarray(stringarray &S)
{

    size = S.size;

    s = new string[size];
}

void stringarray::outputstrings()
{

    for (int i = 0; i < size; i++)

        cout << s[i] << " ";

    cout << endl;
}

void stringarray::input_strings()
{

    for (int i = 0; i < size; i++)

        cin >> s[i];
}

int stringarray::know_size()
{

    return size;
}

void stringarray::compare(int i, int j)
{

    if (s[i] > s[j])

        cout << "Greater\n";

    else

        cout << "Smaller\n";
}

int main()
{

    stringarray A(3);

    A.input_strings();

    A.outputstrings();

    A.compare(1, 2);
    stringarray B(A);

    cout << B.know_size();
}