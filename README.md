# Smart Lightning Detection System 
A smart lighting control system built in C++ using the **K-Nearest Neighbors (KNN)** algorithm. 
The system simulates sensor inputs and automatically decides whether to turn the light **ON**, **DIM**,
or **OFF** based on environmental conditions.
> 4th Semester AI Project
---
## How It Works
The system takes 3 inputs (simulating sensors):
- **Time of day** — Morning / Day / Evening / Night
- **Person presence** — Detected or not
- **Light level** — Low / Medium / High

It then uses KNN (k=1) with Manhattan distance to find the closest match in the training dataset
and outputs a lighting decision.
---
## Algorithm
- **Technique:** K-Nearest Neighbors (KNN)
- **k value:** 1
- **Distance metric:** Manhattan Distance
- **Training data:** 14 manually defined sensor conditions
---
## How to Run
**Compile:**
```bash
g++ lightning.cpp -o lightning
```

**Run:**
```bash
./lightning
```
Then enter the prompted values for time, person presence, and light level.
---
## Sample Output

```
Enter Time (0=Morning, 1=Day, 2=Evening, 3=Night): 3
Is person present? (0=No, 1=Yes): 1
Enter Light Level (0=Low, 1=Medium, 2=High): 0

AI Decision: Light ON
``
---
## Built With
- C++ (Standard Library)
- KNN Classification
- Manhattan Distance
---## Author

Aysha — CS Student, 4th Semester
