#include <iostream>
#include <stack>
using namespace std;

struct Point2D{
    int x;
    int y;
    Point2D(int a,int b):x(a),y(b) {}
};


int main()
{
    int arr[6][6] = {0};
    arr[1][1] = 1;
    arr[2][1] = 1;
    arr[2][2] = 1;
    arr[1][4] = 1;
    arr[2][4] = 1;
    arr[4][1] = 1;
    arr[4][2] = 1;
    arr[4][3] = 1;
    cout<<"raw arr:"<<endl;
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j<6;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;
    int label=2;
    while(1)
    {
        stack<Point2D> st;
        bool flag = false;
        for(int i = 1; i < 5; i++)
        {
            for(int j = 1; j < 5; j++)
            {
                if(arr[i][j] == 1 && !flag)
                {
                    Point2D tmp(i,j);
                    st.push(tmp);
                    flag = true;
                    break;
                }
                if(flag)
                    break;
            }
        }
        if(!flag)
            break;
        while(!st.empty())
        {
            Point2D tmp = st.top();
            arr[tmp.x][tmp.y] = label;
            st.pop();
            if(arr[tmp.x][tmp.y-1] == 1)
                st.push(Point2D(tmp.x,tmp.y-1));
            if(arr[tmp.x][tmp.y+1] == 1)
                st.push(Point2D(tmp.x,tmp.y+1));
            if(arr[tmp.x-1][tmp.y] == 1)
                st.push(Point2D(tmp.x-1,tmp.y));
            if(arr[tmp.x+1][tmp.y] == 1)
                st.push(Point2D(tmp.x+1,tmp.y));

        }
        label++;

    }



    cout<<"dst arr:"<<endl;
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j<6;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }







    return 0;
}
