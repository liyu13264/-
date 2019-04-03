#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 10000
int board[MAXSIZE][MAXSIZE];
int tile=1;//覆盖L型方格的序号
struct chess
{
    int tr,tc,dr,dc,size;
    //tr、tc是棋盘左上角方格的行号和列号，dr、dc是特殊方格所在的行号和列号，size为棋盘的规模（size*size）
};
stack<chess> st;//定义一个chess类型的栈（st）
queue<chess> qu;//定义一个chess类型的队列（qu）
void chess_queue(int tr,int tc,int dr,int dc,int size)
{
    chess q,q1;
    q.tr=tr;
    q.tc=tc;
    q.dr=dr;
    q.dc=dc;
    q.size=size;
    qu.push(q);//当前棋盘q入队
    while (!qu.empty())//队不为空时循环
    {
        q=qu.front();//取队首元素
        qu.pop();//队首出队
        int s=q.size/2;//分割棋盘
        if(q.size!=1)
        {//若特殊方格在分割后的棋盘中，则直接入队，否则将左上角（右上角/左下角/右下角）的方格覆盖后再入队
            //top left
            if (q.dr < q.tr + s && q.dc < q.tc + s)
            {
                q1.tr = q.tr;
                q1.tc = q.tc;
                q1.dr = q.dr;
                q1.dc = q.dc;
                q1.size = s;
                qu.push(q1);
            }
            else
            {
                q1.tr = q.tr;
                q1.tc = q.tc;
                q1.dr = q.tr + s - 1;
                q1.dc = q.tc + s - 1;
                q1.size = s;
                qu.push(q1);
                board[q1.dr][q1.dc]=tile;//
            }
            //top right
            if (q.dr < q.tr + s && q.dc >= q.tc + s)
            {
                q1.tr = q.tr;
                q1.tc = q.tc + s ;
                q1.dr = q.dr;
                q1.dc = q.dc;
                q1.size = s;
                qu.push(q1);
            }
            else
            {
                q1.tr = q.tr;
                q1.tc = q.tc + s ;
                q1.dr = q.tr + s - 1;
                q1.dc = q.tc + s;
                q1.size = s;
                qu.push(q1);
                board[q1.dr][q1.dc]=tile;
            }
            //bottom left
            if (q.dr >= q.tr + s && q.dc < q.tc + s)
            {
                q1.tr = q.tr + s;
                q1.tc = q.tc;
                q1.dr = q.dr;
                q1.dc = q.dc;
                q1.size = s;
                qu.push(q1);
            }
            else
            {
                q1.tr = q.tr + s;
                q1.tc = q.tc;
                q1.dr = q.tr + s;
                q1.dc = q.tc + s - 1;
                q1.size = s;
                qu.push(q1);
                board[q1.dr][q1.dc]=tile;
            }
            //bottom right
            if (q.dr >= q.tr + s && q.dc >= q.tc + s)
            {
                q1.tr = q.tr + s;
                q1.tc = q.tc + s;
                q1.dr = q.dr;
                q1.dc = q.dc;
                q1.size = s;
                qu.push(q1);
            }
            else
            {
                q1.tr = q.tr + s;
                q1.tc = q.tc + s;
                q1.dr = q.tr + s;
                q1.dc = q.tc + s;
                q1.size = s;
                qu.push(q1);
                board[q1.dr][q1.dc]=tile;
            }
            tile++;
        }
    }
    return;
}
void chess_stack(int tr,int tc,int dr,int dc,int size)
{
    chess t,t1;
    t.tr=tr;
    t.tc=tc;
    t.dr=dr;
    t.dc=dc;
    t.size=size;
    st.push(t);//当前棋盘t入栈
    while (!st.empty())//栈不为空时循环
    {
        t=st.top();//取栈顶元素
        st.pop();//出栈
        int s=t.size/2;//分割棋盘
        if(t.size!=1)
        {//若特殊方格在分割后的棋盘中，则直接入栈，否则将左上角（右上角/左下角/右下角）的方格覆盖后再入栈
            //top left
            if (t.dr < t.tr + s && t.dc < t.tc + s)
            {
                t1.tr = t.tr;
                t1.tc = t.tc;
                t1.dr = t.dr;
                t1.dc = t.dc;
                t1.size = s;
                st.push(t1);
            }
            else
            {
                t1.tr = t.tr;
                t1.tc = t.tc;
                t1.dr = t.tr + s - 1;
                t1.dc = t.tc + s - 1;
                t1.size = s;
                st.push(t1);
                board[t1.dr][t1.dc]=tile;
            }
            //top right
            if (t.dr < t.tr + s && t.dc >= t.tc + s)
            {
                t1.tr = t.tr;
                t1.tc = t.tc + s ;
                t1.dr = t.dr;
                t1.dc = t.dc;
                t1.size = s;
                st.push(t1);
            }
            else
            {
                t1.tr = t.tr;
                t1.tc = t.tc + s ;
                t1.dr = t.tr + s - 1;
                t1.dc = t.tc + s;
                t1.size = s;
                st.push(t1);
                board[t1.dr][t1.dc]=tile;
            }
            //bottom left
            if (t.dr >= t.tr + s && t.dc < t.tc + s)
            {
                t1.tr = t.tr + s;
                t1.tc = t.tc;
                t1.dr = t.dr;
                t1.dc = t.dc;
                t1.size = s;
                st.push(t1);
            }
            else
            {
                t1.tr = t.tr + s;
                t1.tc = t.tc;
                t1.dr = t.tr + s;
                t1.dc = t.tc + s - 1;
                t1.size = s;
                st.push(t1);
                board[t1.dr][t1.dc]=tile;
            }
            //bottom right
            if (t.dr >= t.tr + s && t.dc >= t.tc + s)
            {
                t1.tr = t.tr + s;
                t1.tc = t.tc + s;
                t1.dr = t.dr;
                t1.dc = t.dc;
                t1.size = s;
                st.push(t1);
            }
            else
            {
                t1.tr = t.tr + s;
                t1.tc = t.tc + s;
                t1.dr = t.tr + s;
                t1.dc = t.tc + s;
                t1.size = s;
                st.push(t1);
                board[t1.dr][t1.dc]=tile;
            }
            tile++;
        }
    }
    return;
}

void chess_recursion(int tr, int tc, int dr, int dc, int size)
{//跟课本上一样，就不抄了0.0
    if(size == 1)
        return;
    int t = tile++;
    int sz = size / 2;//分割棋盘
    //top left
    if(dr < tr+sz && dc < tc+sz)
        chess_recursion(tr, tc, dr, dc, sz);
    else
    {
        board[tr+sz-1][tc+sz-1] = t;
        chess_recursion(tr, tc, tr+sz-1, tc+sz-1, sz);
    }
    //top right
    if(dr < tr+sz && dc >= tc+sz)
        chess_recursion(tr, tc+sz, dr, dc, sz);
    else
    {
        board[tr+sz-1][tc+sz] = t;
        chess_recursion(tr, tc+sz, tr+sz-1, tc+sz, sz);
    }
    //bottom left
    if(dr >= tr+sz && dc < tc+sz)
        chess_recursion(tr+sz, tc, dr, dc, sz);
    else
    {
        board[tr+sz][tc+sz-1] = t;
        chess_recursion(tr+sz, tc, tr+sz, tc+sz-1, sz);
    }
    //bottom right
    if(dr >= tr+sz && dc >= tc+sz)
        chess_recursion(tr+sz, tc+sz, dr, dc, sz);
    else
    {
        board[tr+sz][tc+sz] = t;
        chess_recursion(tr+sz, tc+sz, tr+sz, tc+sz, sz);
    }
}
void print_board(int size)//输出棋盘
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            printf("%3d ",board[i][j]);
        }
        cout<<endl;
    }
}
void init()//初始化棋盘
{
    memset(board,0, sizeof(board));//将保存棋盘的二维数组初始化为0
    tile=1;//初始化序号
}
int main()
{
    int dr,dc,size;
    cout<<"Input initial point and chessboard size:";
    cin>>dr>>dc>>size;//输入特殊方格的坐标和棋盘的规模（size*size）

    cout<<"Recursion:"<<endl;//递归实现
    init();
    chess_recursion(0,0,dr,dc,size);
    print_board(size);

    cout<<"Stack:"<<endl;//栈实现
    init();
    chess_stack(0,0,dr,dc,size);
    print_board(size);

    cout<<"Queue:"<<endl;//队列实现
    init();
    chess_queue(0,0,dr,dc,size);
    print_board(size);

    return 0;
}