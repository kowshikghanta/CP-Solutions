using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define pb push_back

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vvll alice;
        vvll bob;

        alice.pb({stoi(arriveAlice.substr(0, 2)), stoi(arriveAlice.substr(3, 2))});
        alice.pb({stoi(leaveAlice.substr(0, 2)), stoi(leaveAlice.substr(3, 2))});

        bob.pb({stoi(arriveBob.substr(0, 2)), stoi(arriveBob.substr(3, 2))});
        bob.pb({stoi(leaveBob.substr(0, 2)), stoi(leaveBob.substr(3, 2))});

        vll days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        ll a1 = days[alice[0][0] - 1] + alice[0][1];
        ll a2 = days[alice[1][0] - 1] + alice[1][1];

        ll b1 = days[bob[0][0] - 1] + bob[0][1];
        ll b2 = days[bob[1][0] - 1] + bob[1][1];

        return max(0LL, min(a2, b2) - max(a1, b1) + 1);
    }
};