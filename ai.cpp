#include <iostream>
#include <cmath>
using namespace std;

// Structure to store training data
struct Data {
    int time;     // 0=Morning, 1=Day, 2=Evening, 3=Night
    int person;   // 0=No, 1=Yes
    int light;    // 0=Low, 1=Medium, 2=High
    int output;   // 0=OFF, 1=DIM, 2=ON
};

int main() {

    // Step 1: Training dataset (14 conditions)
    Data dataset[] = {
        {0, 1, 0, 2}, // Morning, Yes, Low -> ON
        {0, 1, 1, 1}, // Morning, Yes, Medium -> DIM
        {0, 0, 0, 0}, // Morning, No, Low -> OFF

        {1, 1, 0, 2}, // Day, Yes, Low -> ON
        {1, 1, 1, 0}, // Day, Yes, Medium -> OFF
        {1, 1, 2, 0}, // Day, Yes, High -> OFF
        {1, 0, 1, 0}, // Day, No, Medium -> OFF

        {2, 1, 0, 2}, // Evening, Yes, Low -> ON
        {2, 1, 1, 1}, // Evening, Yes, Medium -> DIM
        {2, 0, 0, 0}, // Evening, No, Low -> OFF

        {3, 1, 0, 2}, // Night, Yes, Low -> ON
        {3, 1, 1, 1}, // Night, Yes, Medium -> DIM
        {3, 1, 2, 0}, // Night, Yes, High -> OFF
        {3, 0, 0, 0}  // Night, No, Low -> OFF
    };

    int size = 14;

    // Step 2: Take user input (simulated sensors)
    int time, person, light;

    cout << "Enter Time (0=Morning, 1=Day, 2=Evening, 3=Night): ";
    cin >> time;

    cout << "Is person present? (0=No, 1=Yes): ";
    cin >> person;

    cout << "Enter Light Level (0=Low, 1=Medium, 2=High): ";
    cin >> light;

    // Step 3: k-NN (k=1) distance calculation
    int minDistance = 999;
    int prediction = -1;

    for (int i = 0; i < size; i++) {
        int distance =
            abs(dataset[i].time - time) +
            abs(dataset[i].person - person) +
            abs(dataset[i].light - light);

        if (distance < minDistance) {
            minDistance = distance;
            prediction = dataset[i].output;
        }
    }

    // Step 4: Output result
    cout << "\nAI Decision: ";

    if (prediction == 0)
        cout << "Light OFF";
    else if (prediction == 1)
        cout << "Light DIM";
    else
        cout << "Light ON";

    return 0;
}