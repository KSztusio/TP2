#pragma once
#include <queue>
#include <time.h>
using namespace std;
bool queuegen(queue <double>* t, int n){
srand(time(NULL));
double r;
    for (int i = 0 ; i < n; i++){
        r = rand()%101+20;
        t->push(r/10);
    }
    return 1;
}