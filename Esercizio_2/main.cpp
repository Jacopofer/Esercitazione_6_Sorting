#include <chrono>
#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

double Average(const vector<double>& numbers) // creo una funzione per calcolare la media di un vettore di numeri
{
    double sum = 0.0;
    for (double num : numbers)
    {
        sum += num;
    }
    return sum/numbers.size();
}

int main(int argc, char ** argv)
{
    cout << "Numero di argomenti passati a linea di comando: "<< argc-1 << endl; // argc-1 perche trascuro il nome del programma
    cout << "Command line arguments: " << endl;
    for (int i=1; i<argc; i++) {
        cout << argv[i] << " ";  // command line arguments scelti come dimensioni dei vettori: 10, 50, 200
    }
    cout << endl;
    cout << "Dimensione vettore: " << argv[3] << endl;
    cout << endl;

    const int numIterations = 20; // numero di iterazioni per calcolare la media
    vector<double> mergeSortTimes(numIterations);
    vector<double> bubbleSortTimes(numIterations);

    istringstream converter(argv[3]);
    size_t dim_v;
    converter >> dim_v;  // la dimensione del vettore è un command line argument
    int n = dim_v;



    for (int i = 0; i < numIterations; i++)
    {
        vector<int> v(dim_v);
        iota(v.begin(), v.end(), n); // partiamo dal caso "migliore": un vettore già ordinato

        vector<int> v_merge = v; // copia del vettore per ordinarlo con MergeSort

        chrono::steady_clock::time_point t_begin1
            = chrono::steady_clock::now();

        MergeSort(v_merge);

        chrono::steady_clock::time_point t_end1
            = chrono::steady_clock::now();

        double timeElapsed1 = chrono::duration_cast<chrono::microseconds>
                            (t_end1 - t_begin1).count();
        mergeSortTimes[i] = timeElapsed1;

        vector<int> v_bubble = v;

        chrono::steady_clock::time_point t_begin2
            = chrono::steady_clock::now();

        BubbleSort(v_bubble);

        chrono::steady_clock::time_point t_end2
            = chrono::steady_clock::now();

        double timeElapsed2 = chrono::duration_cast<chrono::microseconds>
                            (t_end2 - t_begin2).count();
        bubbleSortTimes[i] = timeElapsed2;
    }

    double mergeSortAverage = Average(mergeSortTimes);
    double bubbleSortAverage = Average(bubbleSortTimes);

    cout << "Media tempi di MergeSort: " << mergeSortAverage << " microsecondi" << endl;
    cout << "Media tempi di BubbleSort: " << bubbleSortAverage << " microsecondi" << endl;

    if (bubbleSortAverage < mergeSortAverage)
        cout << "Su un vettore ordinato di tali dimensioni, BubbleSort risulta essere piu rapido" << endl;
    else
        cout << "Su un vettore ordinato di tali dimensioni, MergeSort risulta essere piu rapido" << endl;

    cout << endl;
    mergeSortTimes.clear();
    bubbleSortTimes.clear(); // svuoto i vettori per riutilizzarli in un altro ciclo
    mergeSortTimes.resize(numIterations);
    bubbleSortTimes.resize(numIterations);

    for (int i = 0; i < numIterations; i++)
    {
        vector<int> v(dim_v);
        generate(v.begin(), v.end(), [&n] () {return --n;}); // caso "peggiore": vettore ordinato inversamente
        vector<int> v_merge = v;

        chrono::steady_clock::time_point t_begin1
            = chrono::steady_clock::now();

        MergeSort(v_merge);

        chrono::steady_clock::time_point t_end1
            = chrono::steady_clock::now();

        double timeElapsed1 = chrono::duration_cast<chrono::microseconds>
                              (t_end1 - t_begin1).count();
        mergeSortTimes[i] = timeElapsed1;

        vector<int> v_bubble = v;

        chrono::steady_clock::time_point t_begin2
            = chrono::steady_clock::now();

        BubbleSort(v_bubble);

        chrono::steady_clock::time_point t_end2
            = chrono::steady_clock::now();

        double timeElapsed2 = chrono::duration_cast<chrono::microseconds>
                              (t_end2 - t_begin2).count();
        bubbleSortTimes[i] = timeElapsed2;
    }

    mergeSortAverage = Average(mergeSortTimes);
    bubbleSortAverage = Average(bubbleSortTimes);

    cout << "Media tempi di MergeSort: " << mergeSortAverage << " microsecondi" << endl;
    cout << "Media tempi di BubbleSort: " << bubbleSortAverage << " microsecondi" << endl;

    if (bubbleSortAverage < mergeSortAverage)
        cout << "Su un vettore inversamente ordinato di tali dimensioni, BubbleSort risulta essere piu rapido" << endl;
    else
        cout << "Su un vettore inversamente ordinato di tali dimensioni, MergeSort risulta essere piu rapido" << endl;


    cout << endl;
    mergeSortTimes.clear();
    bubbleSortTimes.clear();
    mergeSortTimes.resize(numIterations);
    bubbleSortTimes.resize(numIterations);

    for (int i = 0; i < numIterations; i++)
    {
        vector<int> v(dim_v);
        for (unsigned int i=0; i < dim_v; i++)  // caso "realistico": vettore casuale
            v[i] = rand() % 500;
        vector<int> v_merge = v;

        chrono::steady_clock::time_point t_begin1
            = chrono::steady_clock::now();

        MergeSort(v_merge);

        chrono::steady_clock::time_point t_end1
            = chrono::steady_clock::now();

        double timeElapsed1 = chrono::duration_cast<chrono::microseconds>
                              (t_end1 - t_begin1).count();
        mergeSortTimes[i] = timeElapsed1;

        vector<int> v_bubble = v;

        chrono::steady_clock::time_point t_begin2
            = chrono::steady_clock::now();

        BubbleSort(v_bubble);

        chrono::steady_clock::time_point t_end2
            = chrono::steady_clock::now();

        double timeElapsed2 = chrono::duration_cast<chrono::microseconds>
                              (t_end2 - t_begin2).count();
        bubbleSortTimes[i] = timeElapsed2;
    }

    mergeSortAverage = Average(mergeSortTimes);
    bubbleSortAverage = Average(bubbleSortTimes);

    cout << "Media tempi di MergeSort: " << mergeSortAverage << " microsecondi" << endl;
    cout << "Media tempi di BubbleSort: " << bubbleSortAverage << " microsecondi" << endl;

    if (bubbleSortAverage < mergeSortAverage)
        cout << "Su un vettore randomico di tali dimensioni, BubbleSort risulta essere piu rapido" << endl;
    else
        cout << "Su un vettore randomico di tali dimensioni, MergeSort risulta essere piu rapido" << endl;


    // RISULTATI: su vettori di piccole/medie dimensioni, BubbleSort risulta essere più rapido di MergeSort.
    // Nel caso di vettori già ordinati, BubbleSort è estremamente veloce.
    // Negli altri due casi, invece, quando si aumenta la dimensione dei vettori (dell'ordine delle centinaia di elementi),
    // MergeSort diventa più rapido, e il tempo impiegato da BubbleSort cresce esponenzialmente all'aumentare della dimensione del vettore.
    return 0;
}

