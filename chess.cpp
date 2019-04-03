#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 10000
int board[MAXSIZE][MAXSIZE];
int tile=1;//����L�ͷ�������
struct chess
{
    int tr,tc,dr,dc,size;
    //tr��tc���������ϽǷ�����кź��кţ�dr��dc�����ⷽ�����ڵ��кź��кţ�sizeΪ���̵Ĺ�ģ��size*size��
};
stack<chess> st;//����һ��chess���͵�ջ��st��
queue<chess> qu;//����һ��chess���͵Ķ��У�qu��
void chess_queue(int tr,int tc,int dr,int dc,int size)
{
    chess q,q1;
    q.tr=tr;
    q.tc=tc;
    q.dr=dr;
    q.dc=dc;
    q.size=size;
    qu.push(q);//��ǰ����q���
    while (!qu.empty())//�Ӳ�Ϊ��ʱѭ��
    {
        q=qu.front();//ȡ����Ԫ��
        qu.pop();//���׳���
        int s=q.size/2;//�ָ�����
        if(q.size!=1)
        {//�����ⷽ���ڷָ��������У���ֱ����ӣ��������Ͻǣ����Ͻ�/���½�/���½ǣ��ķ��񸲸Ǻ������
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
    st.push(t);//��ǰ����t��ջ
    while (!st.empty())//ջ��Ϊ��ʱѭ��
    {
        t=st.top();//ȡջ��Ԫ��
        st.pop();//��ջ
        int s=t.size/2;//�ָ�����
        if(t.size!=1)
        {//�����ⷽ���ڷָ��������У���ֱ����ջ���������Ͻǣ����Ͻ�/���½�/���½ǣ��ķ��񸲸Ǻ�����ջ
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
{//���α���һ�����Ͳ�����0.0
    if(size == 1)
        return;
    int t = tile++;
    int sz = size / 2;//�ָ�����
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
void print_board(int size)//�������
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
void init()//��ʼ������
{
    memset(board,0, sizeof(board));//���������̵Ķ�ά�����ʼ��Ϊ0
    tile=1;//��ʼ�����
}
int main()
{
    int dr,dc,size;
    cout<<"Input initial point and chessboard size:";
    cin>>dr>>dc>>size;//�������ⷽ�����������̵Ĺ�ģ��size*size��

    cout<<"Recursion:"<<endl;//�ݹ�ʵ��
    init();
    chess_recursion(0,0,dr,dc,size);
    print_board(size);

    cout<<"Stack:"<<endl;//ջʵ��
    init();
    chess_stack(0,0,dr,dc,size);
    print_board(size);

    cout<<"Queue:"<<endl;//����ʵ��
    init();
    chess_queue(0,0,dr,dc,size);
    print_board(size);

    return 0;
}