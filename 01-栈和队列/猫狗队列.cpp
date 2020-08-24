#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Pet {
private:
    string type;

public:
    Pet() {}
    Pet(string _type) { type = _type; }
    string getType() { return type; }
};

class Dog : public Pet {
public:
    Dog() : Pet("dog") {}
};

class Cat : public Pet {
public:
    Cat() : Pet("cat") {}
};

class PetEnterQueue {
private:
    Pet *pet;
    uint64_t cnt;

public:
    PetEnterQueue(Pet *_pet, uint64_t _cnt) {
        pet = _pet;
        cnt = _cnt;
    }
    ~PetEnterQueue() {
        if (pet != nullptr) {
            free(pet);
        }
    }
    Pet *getPet() { return pet; }

    uint64_t getCnt() { return cnt; }

    string getPetType() { return pet->getType(); }
};

class Solutiuon {
private:
    queue<PetEnterQueue *> dogQueue;
    queue<PetEnterQueue *> catQueue;
    uint64_t cnt = 0;

    Pet *pollDogQueue() {
        Pet *res = dogQueue.front()->getPet();
        free(dogQueue.front());
        dogQueue.pop();
        return res;
    }

    Pet *pollCatQueue() {
        Pet *res = catQueue.front()->getPet();
        free(catQueue.front());
        catQueue.pop();
        return res;
    }

public:
    void add(Pet *pet) {
        if (pet->getType() == "dog") {
            PetEnterQueue *petEntr = new PetEnterQueue(pet, cnt++);
            dogQueue.push(petEntr);
        } else if (pet->getType() == "cat") {
            PetEnterQueue *petEntr = new PetEnterQueue(pet, cnt++);
            catQueue.push(petEntr);
        } else {
            // error
            cout << endl;
        }
    }

    Pet *pollAll() {
        if (!dogQueue.empty() && !catQueue.empty()) {
            if (dogQueue.front()->getCnt() < catQueue.front()->getCnt()) {
                return pollDogQueue();
            } else {
                return pollCatQueue();
            }
        } else if (!dogQueue.empty()) {
            return pollDogQueue();
        } else if (!catQueue.empty()) {
            return pollCatQueue();
        } else {
            return nullptr;
        }
    }

    Dog *pollDog() {
        if (!dogQueue.empty()) {
            Pet *res = dogQueue.front()->getPet();
            free(dogQueue.front());
            dogQueue.pop();
            return (Dog*)res;
        } else {
            return nullptr;
        }
    }

    Cat *pollCat() {
        if (!catQueue.empty()) {
            Pet *res = catQueue.front()->getPet();
            free(catQueue.front());
            catQueue.pop();
            return (Cat *)res;
        } else {
            return nullptr;
        }
    }

    bool empty() { return catQueue.empty() && dogQueue.empty(); }

    bool isCatQueueEmpty() { return catQueue.empty(); }

    bool isDogQueueEmpty() { return dogQueue.empty(); }

    ~Solutiuon() {
        while (!dogQueue.empty()) {
            free(dogQueue.front());
            dogQueue.pop();
        }
        while (!catQueue.empty()) {
            free(catQueue.front());
            catQueue.pop();
        }
    }
};