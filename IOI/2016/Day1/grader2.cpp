#include <cstdio>
#include <vector>
#include <cassert>

#include "roller.cpp"

int main() {
    int n;
    assert(1 == scanf("%d", &n));
    std::vector<int> s(n), t(n);
    for (int i = 0; i < n; i++){
        assert(2 == scanf("%d %d", &s[i], &t[i]));
    }
    printf("%lld\n", plan_roller_coaster(s, t));
}
