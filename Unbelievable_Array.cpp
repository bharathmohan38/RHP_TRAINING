#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int p[N],id[N],val[N],a[N];
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=100000;i++){
            p[i]=i;
            id[i]=0;
            val[i]=i;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!id[a[i]]){
                id[a[i]]=++cnt;
                p[cnt]=cnt;
                val[cnt]=a[i];
            }
            a[i]=id[a[i]];
        }
        cout<<"Case "<<tc<<":\n";
        while(q--){
            int t;
            cin>>t;
            if(t==1){
                int x,y;
                cin>>x>>y;
                if(x==y) continue;
                if(!id[x]) continue;
                if(!id[y]){
                    id[y]=id[x];
                    val[id[y]]=y;
                    id[x]=0;
                }else{
                    p[find(id[x])]=find(id[y]);
                    id[x]=0;
                }
            }
            else{
                int idx;
                cin>>idx;
                cout<<val[find(a[idx])]<<"\n";
            }
        }
    }
}
