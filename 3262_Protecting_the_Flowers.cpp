//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class cow {
private:
    long long rate;
    long long time;
public:
    cow(long long rate, long long time);
    bool operator < (cow rhs) const;
    bool operator > (cow rhs) const;
    void send_home(long long& cost, long long& threats_in_field);
};

// redundent
bool cow::operator < (cow rhs) const{
    if(rhs.time*rate < rhs.rate*time) return true;
    return false;
}

bool cow::operator > (cow rhs) const{
    if(rhs.time*rate > rhs.rate*time) return true;
    return false;
}

cow::cow(long long r, long long t){
    rate = r;
    time = t;
}

void cow::send_home(long long& cost, long long& threats_in_field){
    threats_in_field -= rate;
    cost += (threats_in_field*time*2);
    //cout << cost << ' ' << threats_in_field << endl;
}


int main(){
    long long n;
    cin >> n;
    vector<cow> v;
    long long sum = 0, t, r;
    while(n--){
        cin >> t >> r;
        v.push_back(cow(r,t));
        sum += r;
    }
    long long cost = 0;
    sort(v.begin(),v.end(),greater<cow>());
    for(long long i = 0; i < v.size(); i++){
        v[i].send_home(cost,sum);
    }
    cout << cost << endl;
    return 0;
}
