#include<iostream>
#include<string.h>
using namespace std;
void score_board(int p1,int p2,int result,int score_card[][3])
{
    if(p1==p2)
    {
        score_card[p1][p2]=0;
        score_card[p2][p1]=0;
    }
    else{
        score_card[p1][p2]=result;
        score_card[p2][p1]=2-result;
    }
}
void getResult(int p1,int score_card[][3])
{
    int result=0,sum=0;
    for(int i=0;i<3;i++)
    {
        sum+=score_card[p1][i];
    }
    cout<<"The Result is:"<<sum<<endl;
}
void display(int score_card[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<score_card[i][j]<<" ";
        }
        cout<<endl;
    }
}
void winner(int score_card[][3])
{
        int result=0,sum,p1;
        for(int i=0;i<3;i++)
        {
            sum=0;
            for(int j=0;j<3;j++)
            {
                sum+=score_card[i][j];
            }
            if(result<sum)
            {
                result=sum;
                p1=i;
            }


        }
        cout<<"The Highest score of the player "<<p1<<" is :"<<result<<endl;
}
void rank_player(int score_card[][3])
{
    int rak=3;
    int sum[3],result[3];
     for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                sum[i]=score_card[i][j];
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(sum[i]<sum[j])
                {
                    int temp=sum[j];
                    sum[j]=sum[i];
                    sum[i]=temp;
                    result[i]=j;
                }
                else{
                    result[i]=i;
                }

            }
        }
        char c='A';
        for(int i=0;i<3;i++)
        {
            cout<<"The Rank of the player "<< result[i]<<" is:"<<c++<<endl;
        }

}
int main()
{
    int score_card[3][3];
    score_board(0,1,2,score_card);
    score_board(0,2,2,score_card);
    score_board(2,1,0,score_card);
    score_board(0,0,0,score_card);
    score_board(1,1,0,score_card);
    score_board(2,2,0,score_card);
    display(score_card);
    getResult(1,score_card);
    winner(score_card);
    rank_player(score_card);
    return 0;
}



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0;
        int m=0,n=prices.size()-1;
        if(prices[m]==prices[n])
            {
                return 0;
            }
        while(m!=n)
        {
            if(prices[m]>prices[n])
            {
                m++;
            }
            if(prices[m]<prices[n])
            {
                int price=prices[n]-prices[m];
                if(price>sell)
                {
                    sell=price;
                }
                n--;
            }
        }
        return sell;

    }
};
