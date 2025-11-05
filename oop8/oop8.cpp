#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);
    generate(v.begin(), v.end(), []() { return rand() % 21 - 10; });

    cout << "\nGenerated array:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "\nSum of elements: " << sum << endl;

    auto it_min = min_element(v.begin(), v.end());
    auto it_max = max_element(v.begin(), v.end());

    if (it_min > it_max) swap(it_min, it_max);

    long long product = 1;
    if (distance(it_min, it_max) > 1) {
        product = accumulate(next(it_min), it_max, 1LL, multiplies<long long>());
    } else {
        product = 0;
    }

    cout << "Product of elements between min and max: " << product << endl;

    sort(v.begin(), v.end());
    cout << "\nArray sorted in ascending order:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    system("pause");
    return 0;
}
