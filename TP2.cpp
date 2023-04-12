#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <future>
#include <time.h>
#include "stack.h"
#include "q.h"
using namespace std;

void wys(Stack <double>* truck, int* m);

int main(){
    int n, actual_truck = 0, x;
    int* m;
    cout << "podaj ilosc paczek\n";
    cin >> n;
    queue<double>* packages = new queue<double>;
    future <bool> fut = async(queuegen, packages, n);
    double r;  
    vector <Stack<double>*> trucks;
    srand(time(NULL));
    r = rand()%11+10;
    trucks.push_back(new Stack <double>(r));
    fut.get();
    while(!packages->empty()){
        if(trucks[actual_truck]->push(packages->front())){
            packages->pop();
        }else{
            r = rand()%11+10;
            trucks.push_back(new Stack<double>(r));
            actual_truck++;
        }
    }
    for(int i = 0; i < trucks.size(); i++){
        x = trucks[i]->size();
        m = new int(x * 5);
        cout << '\t' << "/----|";
        wys(trucks[i], m);
        cout << '\n'<< trucks[i]->getcapacity() << '\t' << "|----|";
        for(int j = 0; j < *m; j++){
            cout << '-';
        }
        cout << '\n' << ' ' << trucks[i]->getoccupancy() << ' ' << "\t o o ";
        for(int j = 0; j < x; j++){
            cout << " o o ";
        }
        cout << "\n\n";
        delete trucks[i];
    }
    delete packages;
    cin >> n;
    return 0;
}
void wys(Stack <double>* truck, int*m){
    double g;
    while(!truck->empty()){
        g = truck->pop();
        cout << ' ' << g << ' ';
        if (g >= 10){
            (*m)++;
        }
    }
}
