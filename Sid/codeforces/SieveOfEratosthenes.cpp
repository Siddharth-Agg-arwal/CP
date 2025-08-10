#include <bits/stdc++.h>
using namespace std;



int main(){
    
    int n;
    cin >> n;
    const long long maxim = LLONG_MAX;
    vector<bool> seive(n + 1, true);
    vector<long long> primes;
    vector<long long> smallest_prime(n + 1, maxim);
    
    seive[0] = seive[1] = false;
    for(int i = 2; i <= n; i++){
        // seive[i] = 0;
        smallest_prime[i] = i;
    }
    
    // primes.push_back(2);
    // smallest_prime[2] = 2;
    
    for(int i = 2; i*i <= n; i++){
        if(!seive[i]) continue;
        else{
            primes.push_back(i);
            // smallest_prime[i] = i;
        }
        for(int j = i * i; j <= n; j += i){
            smallest_prime[j] = i;
            seive[j] = false;
        }   
    }
    
    for(int i = 2; i <= n; i++){
        if(seive[i]) cout << i << " ";
    }
    cout << endl;
    
    for(int j = 0; j <= smallest_prime.size(); j++){
        cout << smallest_prime[j] << " ";
    }
}