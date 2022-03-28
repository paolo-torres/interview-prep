/*
    Implement a Central Banking algorithm.

    Netting Engine - ACH association
    Minimum number of transfers required at the end of the day based on the 
    net balances of individual banks

A B C banks -> list of input transfers -> output transfers

    Central Bank Algorithm
    ----------------------

    1. Calc net balance of each bank
    2. Generate one transfer with either send/receive the net amount

STEP 1
    // A, B, amount
    // int[] sendAmts {}
    // int[] receiveAmts {}
    // int[] netbalance {}

STEP 2
    // If the balance is positive, there is transfer from Bank A to Bank i 
        with amount netbalance
    // Else if the balance is negative, there is a transfer from Bank i to 
        Bank A with amount mod(netbalance)

    positive balances
    _ _ _ -> _A_ dest post balance

    negative balance
    _ _ _ -> src _A_ Mod(-neg balance)

Examples:

    Input:
        AB1
        BA2
        ------
        BA1

    Input:
        AB1         A 1   s:2 r:3 -> 1
        BA2 -> BA1  B -2  s:2+1 r:1 -> -2
        BC1 -> BC1  C 1   r:2 -> 2
        AC1         D     s:1 -> -1
        DA1

        Net Balances:
        A: 1  (send 1, receive 2) [receive - send] = net balance
        B: -2 (send 2, receive 1, send 1)
        C: 1  (receive 1)

     Output:
        BA2
        AC2
        DA1

            B,C,D --------> (A) ------->    B,C,D


Input
    B:-2 C:0 D:2

    BC2
    CD2

    B,C,D --------> (A) ------->    B,C,D

Output
    BA2
    AD2

*/

#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <float.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class CentralBank {
public:
    CentralBank() {

    }

    vector<string> generateMinimumTransfers(vector<string> transferDetails) {
        vector<string> v;
        if (transferDetails.empty()) {
            return {};
        }

        vector<int> sendAmount(26, 0);
        vector<int> receiveAmount(26, 0);
        vector<int> netBalance(26, 0);

        for (int i = 0; i < transferDetails.size(); i++) {
            string details = transferDetails[i];
            int source = details[0] - 'A';
            int destination = details[1] - 'A';
            int amount = details[2];

            sendAmount[source] += amount;
            receiveAmount[destination] += amount;
        }

        for (int i = 0; i < 26; i++) {
            if (i == CENTRAL_BANK_ID) {
                continue;
            }

            netBalance[i] = receiveAmount[i] - sendAmount[i];
            string transfer = "";
            
            if (netBalance[i] > 0) {
                transfer += CENTRAL_BANK;
                transfer += (char)(i + 'A');
                transfer += netBalance[i];
                v.push_back(transfer);
            } else if (netBalance[i] < 0) {
                transfer += (char)(i + 'A');
                transfer += CENTRAL_BANK;
                transfer += abs(netBalance[i]);
                v.push_back(transfer);
            }
        }

        return v;
    }
private:
    const char CENTRAL_BANK = 'A';
    const int CENTRAL_BANK_ID = 0;
};

int main()
{
    CentralBank* obj = new CentralBank();

    vector<string> test = obj->generateMinimumTransfers({"AB1", "BA2"});
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    test = obj->generateMinimumTransfers({"AB1", "BA2", "BC1"});
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    test = obj->generateMinimumTransfers({"AB1", "BA2", "BC1", "DA1"});
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    test = obj->generateMinimumTransfers({"BC1", "CD1"});
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    test = obj->generateMinimumTransfers({"BC2", "CD1"});
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    test = obj->generateMinimumTransfers({"BC203", "CD198"});
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    test = obj->generateMinimumTransfers({"BC2", "CD009"});
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    return 0;
}
