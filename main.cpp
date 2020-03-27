#include <bits/stdc++.h>
 
using namespace std;
ifstream f("nfa.in");
ofstream g("nfa.out");
 
const int Max=1e3+3;
int ok,lungime,dr[Max],n,m,a,x,y,st,p,r;
char z;
 
vector < pair<int,char> > vect[Max];
 
char str[Max];
bool vizitat[Max][Max];
 
void rezolvare(int k, int nod)
{
 
    if(ok)
        return;
 
    if(k == lungime + 1)
    {
        if(dr[nod])
            ok=1;
        return;
    }
 
    for(int i=0; i<vect[nod].size(); i++)
        if(str[k]==vect[nod][i].second&&!vizitat[vect[nod][i].first][k])
        {
            vizitat[vect[nod][i].first][k]=1;
            rezolvare(k+1,vect[nod][i].first);
        }
}
 
void aranjare()
{
 
    f >> r;
 
    while(r--)
    {
        for(int i=1; i<=1000; i++)
            for(int j=1; j<=1000; j++)    ///Sau puteam folosi functia memset(vizitat, 0, sizeof(vizitat))
                vizitat[i][j]=0;
        f>>(str + 1);
        lungime = strlen(str + 1);
        ok = 0;
        rezolvare(1, st);
        g << ok << '\n';
    }
}
 
void read()
{
    f >> n >> m;
    f >> p;
    f >> st;
 
    for(int i=1; i<=p; ++i)
    {
        f >> a;
        dr[a] = 1;
    }
    for(int i=1; i<=m; ++i)
    {
        f >> x >> y >> z;
        vect[x].push_back(make_pair(y, z));
    }
}
int main()
{
 
    read();
    aranjare();
 
    return 0;
}
