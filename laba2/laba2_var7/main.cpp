#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
const int MAX_SIZE = 100;
int main()
{
    int n;
    cin >> n;
    if(n <= MAX_SIZE && n > 0){
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int maxEl = abs(arr[0]);
        for (int i = 1; i < n; i++) {
            if (abs(arr[i]) > maxEl) {
                maxEl = abs(arr[i]);
            }
        }

        int first = -1, second = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                first = i;
                break;
            }
        }
        if (first != -1) {
            for (int i = first + 1; i < n; i++) {
                if (arr[i] > 0) {
                    second = i;
                    break;
                }
            }
        }
        int summ = 0;
        if (first != -1 && second != -1 ) {
            for (int i = first + 1; i < second; i++) {
                summ += arr[i];
            }
        }

        map<int, int> sorting_map;
        for (int i = 0; i < n; i++) {
            sorting_map[arr[i]]++;
        }
        sort(arr, arr + n, [&](int a, int b) {
            if (sorting_map[a] != sorting_map[b]) {
                return sorting_map[a] > sorting_map[b];
            }
            return a < b;
        });
        cout << "max abs element " << maxEl << endl;
        cout << "summa " << summ << endl;
        cout << "massiv: "<< endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else if (n > MAX_SIZE){
        cout << "slishkom mnogo elementov v massive" << endl;
    }
    else cout << "n<=0" << endl;
    return 0;
}
