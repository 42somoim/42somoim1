#include <iostream>

using namespace std;

int     main(void)
{
    int n;
    int set;
    std::string cmd;
    int arg;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    set = 0;

    while (n--) {
        cin >> cmd;
        if (cmd.compare("add") == 0) {
            cin >> arg;
            set |= (1 << (arg - 1));
        } else if (cmd.compare("remove") == 0) {
            cin >> arg;
            set &= ~(1 << (arg - 1));
        } else if (cmd.compare("check") == 0) {
            cin >> arg;
            int check = set & (1 << (arg - 1));
            if (check)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (cmd.compare("toggle") == 0) {
            cin >> arg;
            set ^= (1 << (arg - 1));
        } else if (cmd.compare("all") == 0) {
            set = (1 << 21) - 1;
        } else if (cmd.compare("empty") == 0) {
            set = 0;
        }
    }
    return 0;
}
