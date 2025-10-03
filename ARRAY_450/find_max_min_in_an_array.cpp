#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n)
{
    long long maxy=a[0];
    long long miny=a[0];
    
    for(long long i=1;i<n;i++)
    {
        maxy=max(maxy,a[i]);
        miny=min(miny,a[i]);
    }
    
    return {miny,maxy};
    
}


//------basic logic------------------

// pair<long long, long long> getMinMax(long long a[], int n) {
//    pair<ll,ll> pp;
//    int min = a[0], max = 0;
//    for(int i=0; i<n; i++){
//        if(a[i]>max)
//            max=a[i];
//        if(a[i]<min)
//            min=a[i];
//    }
//    pp.first = min;
//    pp.second = max;
//    return pp;
// }