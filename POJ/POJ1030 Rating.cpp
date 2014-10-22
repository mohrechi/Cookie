#include <iostream>
int ct[2][101], ctn[2], N ;
class rankNode
{
public:
    int No, r[2], pt ;
    rankNode * next, *right;
    rankNode()
    {
        next=right=NULL;
    }

    bool operator < (const rankNode & rn)
    {
        if( pt==rn.pt )
        return r[0]+r[1]<rn.r[0]+rn.r[1] ;
        return false;
    }

    bool operator == (const rankNode & rn)
    {
        if( pt==rn.pt )
            return r[0]+r[1]==rn.r[0]+rn.r[1] ;
        return false;
    }
} rnode[101];

class rankList
{
public:
    rankNode * head;
    rankList(){ head=NULL; }
    void checkInsert(int i,rankNode* bg, rankNode* ed,int k);
    bool checkAdd(int k,int i);
    void insert(int k);
    void printRank();
} rlist;

void rankList::checkInsert(int i,rankNode* bg, rankNode* ed,int k)
{
    rankNode *p=bg, *tp ;
    int temp=rnode[k].r[i];
    i = 1-i;
    if(p==NULL && (ed==head || head->r[i]>temp ))
    {
        rnode[k].next=head;
        head=&rnode[k];
        return;
    }
    if(p==NULL && head->r[i]<=temp)
        p=head;
    tp=p;
    if(bg!=NULL && bg->next==ed)
    {
        rnode[k].next=ed;
        bg->next=&rnode[k];
        return;
    }
    while(p!=ed && p->r[i]<temp)
    {
       tp=p;
       p=p->next;
    }
    if(p!=NULL && p->r[i]==temp)
    {
        rankNode *temp=p;
        while(temp!=NULL && ( temp->r[1-i]==0 || temp->r[1-i]==rnode[k].r[1-i] ) )
            temp=temp->right;
        if( temp!=NULL )
        {
            rnode[k].next=tp->next;
            tp->next=&rnode[k];
            return;
        }
        rnode[k].right=p->right;
        p->right=&rnode[k];
    }
    else
    {
        rnode[k].next=tp->next;
        tp->next=&rnode[k];
    }
}

bool rankList::checkAdd(int k,int i)
{
    rankNode *p, *tp, *bg, *ed;
    int temp=rnode[k].r[i] , flag=0;
    p=head; bg=ed=NULL;
    while( p!=NULL )
    {
        if( p->r[i] && p->r[i]<temp ) bg=p;
        tp=p ;
        while( tp!=NULL && tp->r[i]<temp )
        {
            if( p->r[i] )
                bg=p;
            tp=tp->right;
        }
        if(tp!=NULL)
        {
            while( tp!=NULL && (tp->r[i]==0 || tp->r[i]>temp) )
                tp=tp->right;
            if(tp!=NULL)
                return false;
            ed=p;
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        checkInsert(i,bg,ed,k);
        return true;
    }
    if( bg==ed )
        return false;
    p=p->next;
    while( p!=NULL )
    {
        if( p->r[i] && p->r[i]<=temp )
            return false;
        tp=p->right;
        while( tp!=NULL && (tp->r[i]==0 || tp->r[i]>temp) )
            tp=tp->right;
        if(tp!=NULL)
            return false;
        p=p->next;
    }
    checkInsert(i,bg,ed,k);
    return true;
}
void rankList::insert(int k)
{
    if(head==NULL)
    {
        head=&rnode[k];
        return;
    }
    rankNode *pre=head, *p=head;
    while( p!=NULL && *p<rnode[k] )
    {
        pre=p;
        p=p->next;
    }
    if(p==NULL)
    {
        pre->next = &rnode[k];
    }
    else if( *p==rnode[k] )
    {
        rnode[k].right=p->right;
        p->right=&rnode[k];
    }
    else if(p==head)
    {
        rnode[k].next=head;
        head=&rnode[k];
    }
    else
    {
        pre->next=&rnode[k];
        rnode[k].next=p;
    }
}

void rankList::printRank()
{
    rankNode *tp, *p=head, *del;
    while( p!=NULL )
    {
        bool flag = false;
        while(true)
        {
            tp=p;
            int temp=110;
            while(tp!=NULL)
            {
                if(tp->No<temp)
                {
                    del=tp;
                    temp=tp->No;
                }
                tp=tp->right;
            }
            if(temp==110)
            {
                printf("\n");break;
            }
            printf("%s%d",(flag?" ":""),temp);
            flag=true;
            del->No = 110;
        }
        p=p->next;
    }
}

void rankTeams()
{
    int i, j ;
    for(i=1; i<=N; ++i)
        if( rnode[i].pt==3 )
            rlist.insert(i);
    rankNode * p , *q, *temp;
    for(i=1; i<=N; ++i)
        if( rnode[i].pt && rnode[i].pt!=3 )
        {
            for(p=q=NULL,j=1; j<=N; ++j)
            if( rnode[j].pt==3 && ( rnode[i].r[0]==rnode[j].r[0] || rnode[i].r[1]==rnode[j].r[1] ) )
            {
                if( p==NULL )
                {
                    p=&rnode[j];
                    continue;
                }
                else q = &rnode[j];
                temp=p->right;
                while( temp!=NULL &&temp!=q )
                    temp=temp->right;
                if(temp!=NULL)
                {
                    q=NULL;
                    continue;
                }
                temp=q->right;
                while( temp!=NULL &&temp!=p )
                    temp=temp->right;
                if(temp==NULL)
                    break;
            }
            if( p!=NULL && q==NULL )
            {
                rnode[i].right = p->right ;
                p->right = &rnode[i];
                rnode[i].pt *= 4;
            }
            else if(q!=NULL)
                rnode[i].pt *= 16;
        }
    bool res;
    for(res=false,i=0;i<2;++i)
        for(j=0; j<ctn[i]; ++j)
            if( rnode[ct[i][j]].pt<3 )
            {
                if(res && j>0 && rnode[ct[i][j-1]].r[i]==rnode[ct[i][j]].r[i] )
                {
                    rnode[ct[i][j]].right=rnode[ct[i][j-1]].right;
                    rnode[ct[i][j-1]].right=&rnode[ct[i][j]];
                    continue;
                }
                res=rlist.checkAdd( ct[i][j], i );
            }
}

int main()
{
    int i , j , r;
    char line[300] ,*ptr;
    gets(line);
    sscanf(line,"%d",&ctn[0]);
    for(i=j=0,r=1; i<ctn[0]; ++i,r=j+1)
    {
        gets(line);
        ptr=strtok(line," \n");
        while(ptr!=NULL)
        {
            ct[0][j]=atoi(ptr);
            if(ct[0][j]>N) N=ct[0][j];
            rnode[ ct[0][j] ].r[0] = r ;
            rnode[ ct[0][j++] ].pt = 1 ;
            ptr=strtok(NULL," \n");
        }
    }
    ctn[0]=j;
    gets(line);
    gets(line);
    sscanf(line,"%d",&ctn[1]);
    for(i=j=0,r=1; i<ctn[1]; ++i,r=j+1)
    {
        gets(line);
        ptr=strtok(line," \n");
        while(ptr!=NULL)
        {
            ct[1][j]=atoi(ptr);
            if(ct[1][j]>N) N=ct[1][j];
            rnode[ ct[1][j] ].r[1] = r ;
            rnode[ ct[1][j] ].pt = ( rnode[ ct[1][j] ].pt ? 3:2 ) ;
            ++j;
            ptr=strtok(NULL," \n");
        }
    }
    ctn[1]=j;
    for(i=0;i<=N;++i)
        rnode[i].No=i;
    rankTeams();
    rlist.printRank();
    return 0;
}
