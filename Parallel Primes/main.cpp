//
//  main.cpp
//  Parallel Primes
//
//  Created by Will Gibson on 8/31/23.
//

#include <iostream>
#include <vector>
#include "DoubleLinkedList.hpp"
#include "DoubleLinkedList.cpp"
#include <cmath>
#include <fstream>
#include <chrono>


using namespace std;

const int UPPER_LIM = 20000000;

const int NUM_THREADS = 1;

DoublyLinkedList<int> primes;


bool isPrime(int currNum){
    if (currNum <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(currNum); ++i) {
        if (currNum % i == 0) {
            return false;
        }
    }
    return true;
}

void singleThreadedPrimes(int upperLimit){
    primes.addToDLLTail(2);
    int curr = 3;
    while(curr < upperLimit) {
        if (isPrime(curr)) {
            primes.addToDLLTail(curr);
        }
        curr += 2;
    }
}

void multiThreadedPrimes(int numThreads, int upperLimit){
    return;
}


int main(int argc, const char * argv[]) {
    
    auto start = chrono::system_clock::now();
    
    int numThreads = NUM_THREADS;
    int upperLimit = UPPER_LIM;
    
//    string outfile = "output.txt";
    
    if (numThreads == 1) {
         singleThreadedPrimes(upperLimit);
    }else {
        // multiThreadedPrimes(numThreads, upperLimit);
    }
    
    auto end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    
//    cout << "Primes between 1 and " << upperLimit << endl;
//    cout << "Number of primes: " << primes.numElements << endl;
//    cout << "-------------------------" << endl;
//    primes.printDLList();
//    cout << "-------------------------" << endl;
//    cout << "Primes between 1 and " << upperLimit << endl;
//    cout << "Number of primes: " << primes.numElements << endl;
    
    primes.outputToFile("output.txt", upperLimit);
    
    cout << "Runtime (in seconds) " << elapsed_seconds.count() << "s" << endl;

}
