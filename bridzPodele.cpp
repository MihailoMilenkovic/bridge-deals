#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 5;

vector<string> boje = {"C", "D", "H", "S"};
vector<string> karte = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
vector<string> spil;
vector<string> karteIgraca[4];
vector<string> igrac = {"North", "East", "South", "West"};
map<char, int> vrednostBoje;
map<char, int> vrednostBroja;
map<char, string> imeBoje;
void init()
{
    vrednostBoje['C'] = 0;
    vrednostBoje['D'] = 1;
    vrednostBoje['H'] = 2;
    vrednostBoje['S'] = 3;
    imeBoje['C'] = "Tref";
    imeBoje['D'] = "Karo";
    imeBoje['H'] = "Herc";
    imeBoje['S'] = "Pik";
    vrednostBroja['2'] = 2;
    vrednostBroja['3'] = 3;
    vrednostBroja['4'] = 4;
    vrednostBroja['5'] = 5;
    vrednostBroja['6'] = 6;
    vrednostBroja['7'] = 7;
    vrednostBroja['8'] = 8;
    vrednostBroja['9'] = 9;
    vrednostBroja['T'] = 10;
    vrednostBroja['J'] = 11;
    vrednostBroja['Q'] = 12;
    vrednostBroja['K'] = 13;
    vrednostBroja['A'] = 14;
}
void ispisiKarte(string imeIgraca, vector<string> kartetrenutnog)
{
    cout << "Karte " << imeIgraca << "-a:\n";

    for (int i = 0; i < kartetrenutnog.size(); i++)
    {
        if (i == 0 || kartetrenutnog[i][0] != kartetrenutnog[i - 1][0])
        {
            if (i != 0)
            {
                cout << "\n";
            }
            cout << imeBoje[kartetrenutnog[i][0]] << ":\t ";
        }
        cout << kartetrenutnog[i][1];
    }
    cout << "\n\n";
}
int main()
{
    //freopen("in.txt","r",stdin);
    freopen("podela.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    for (int i = 0; i < boje.size(); i++)
    {
        for (int j = 0; j < karte.size(); j++)
        {
            string nw = "";
            nw += boje[i];
            nw += karte[j];
            spil.pb(nw);
        }
    }
    shuffle(spil.begin(), spil.end(), rng);
    for (int i = 0; i < 52; i++)
    {
        karteIgraca[i / 13].pb(spil[i]);
    }
    /*for(auto&x:spil){
        cout<<x<<"\n";
    }*/
    for (int i = 0; i < 4; i++)
    {
        /*for(auto&x:karteIgraca[i]){
            cout<<x<<" ";
        }*/
        sort(karteIgraca[i].begin(), karteIgraca[i].end(), [](string karta1, string karta2) {
            if (karta1[0] != karta2[0])
            {
                return vrednostBoje[karta1[0]] < vrednostBoje[karta2[0]];
            }
            else
            {
                return vrednostBroja[karta1[1]] > vrednostBroja[karta2[1]];
            }
        });
        ispisiKarte(igrac[i], karteIgraca[i]);
    }
    return 0;
}