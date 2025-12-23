#include <iostream>
#include <iomanip>

using namespace std;

int decision(int a, int b)
{
    //1: A赢， 0：平，01：B赢
    if(a==b)
    {
        return 0;
    }

    if(a==0) //A出了石头
    {
        if(b==2){//B出了剪刀
            return 1;
        }
        else
        {
            return -1;
        }
    }
    if(a==2)//A出了剪刀
    {
        if(b==5)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }
    if(a==5)//A出了布
    {
        if(b==0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    const int MAX=100;
    int rounds, length_a, length_b;
    cin>>rounds>>length_a>>length_b;

    int a[MAX], b[MAX];
    for(int i =0;i<length_a;i++){
        cin>>a[i];
    }
    for(int i =0;i<length_b;i++){
        cin>>b[i];
    }

    int win_a=0, win_b=0;

    for(int i=1;i<=rounds;i++)
    {
        int choice_a=a[(i-1)%length_a];
        int choice_b=b[(i-1)%length_b];

        int result=decision(choice_a, choice_b);
        if(result==1)
        {
            win_a++;
        }
        else if(result==-1)
        {
            win_b++;
        }
    }

    if(win_a>win_b)
    {
        cout<<"A"<<endl;
    }
    else if(win_a<win_b)
    {
        cout<<"B"<<endl;
    }
    else 
    {
        cout<<"draw"<<endl;
    }
    return 0;
}
