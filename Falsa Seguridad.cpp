#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

map <string, string> mapeo;
map <string, string> sim;

char cadena[MAXN];
vector <int> num;
string ans;

int main() {
    mapeo[".-"] = "A";
    sim["A"] = ".-";
    mapeo["-..."] = "B";
    sim["B"] = "-...";
    mapeo["-.-."] = "C";
    sim["C"] = "-.-.";
    mapeo["-.."] = "D";
    sim["D"] = "-..";
    mapeo["."] = "E";
    sim["E"] = ".";

    mapeo["..-."] = "F";
    sim["F"] = "..-.";
    mapeo["--."] = "G";
    sim["G"] = "--.";
    mapeo["...."] = "H";
    sim["H"] = "....";
    mapeo[".."] = "I";
    sim["I"] = "..";
    mapeo[".---"] = "J";
    sim["J"] = ".---";

    mapeo["-.-"] = "K";
    sim["K"] = "-.-";
    mapeo[".-.."] = "L";
    sim["L"] = ".-..";
    mapeo["--"] = "M";
    sim["M"] = "--";
    mapeo["-."] = "N";
    sim["N"] = "-.";
    mapeo["---"] = "O";
    sim["O"] = "---";

    mapeo[".--."] = "P";
    sim["P"] = ".--.";
    mapeo["--.-"] = "Q";
    sim["Q"] = "--.-";
    mapeo[".-."] = "R";
    sim["R"] = ".-.";
    mapeo["..."] = "S";
    sim["S"] = "...";
    mapeo["-"] = "T";
    sim["T"] = "-";


    mapeo["..-"] = "U";
    sim["U"] = "..-";
    mapeo["...-"] = "V";
    sim["V"] = "...-";
    mapeo[".--"] = "W";
    sim["W"] = ".--";
    mapeo["-..-"] = "X";
    sim["X"] = "-..-";
    mapeo["-.--"] = "Y";
    sim["Y"] = "-.--";
    mapeo["--.."] = "Z";
    sim["Z"] = "--..";

    mapeo["..--"] = "_";
    sim["_"] = "..--";
    mapeo[".-.-"] = ",";
    sim[","] = ".-.-";
    mapeo["---."] = ".";
    sim["."] = "---.";
    mapeo["----"] = "?";
    sim["?"] = "----";


    while(cin >> cadena){
        ans = "";
        num.clear();
        string morce = "";
        ans = "";
        for(int i = 0; cadena[i]; i++){
            string b = "";
            b += cadena[i];
            string c = sim[b];
            morce += c;
            num.push_back(c.size());
        }
        reverse(num.begin(), num.end());
        int pos = 0;
        int sig = 0;
        for(int i = 0; i < num.size(); i++){
            sig = num[i];
            ans += mapeo[morce.substr(pos, sig)];
            pos += sig;
        }
        cout << ans << endl;
    }

	return 0;
}
