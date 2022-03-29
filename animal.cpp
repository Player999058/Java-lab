#include <iostream>
#include <string>

using namespace std;

enum COLOR {Green, Blue, White, Black, Brown};

class Animal{
    public:
        Animal() : _name("unknown"){
            cout<< "constructing Animal object" << _name << endl;
        }

        Animal(string n, COLOR c) : _name(n), _color(c){
            cout << "Name of animal: " << _name << " Color of animal: " << _color << endl;
        }

        ~Animal(){
            cout << "destructing Animal object " << _name << endl;
        }

        virtual void speak() const{
            cout << "Animal speaks" << endl;
        }

        virtual void move()=0;
    
    private:
        string _name;
        COLOR _color;
};

class Mammal: public Animal {
    public:
        virtual void eat() {
            cout << "Mammal eat " << endl;
        }
        Mammal(string name, COLOR color) : Animal(name,color){
        }

        ~Mammal(){
            cout << "Destroying mammal object" << endl;
        }

        void move(){
            cout << "mammal moves" << endl;
        }
};

class Dog: public Mammal {
    private: 
        string _owner;

    public:
        Dog(string name, COLOR color, string owner) : Mammal(name, color), _owner(owner){
        }

        ~Dog(){
            cout << "Destroying dog object" << endl;
        }

        virtual void speak() const{
            cout << "Woof" << endl;
        }

        void move(){
            cout << "dog runs" << endl;
        }

        virtual void eat(){
            cout << "dog eats" << endl;
        }
};

class Cat : public Mammal{
    public:
        Cat(string name, COLOR color) : Mammal(name, color){
        }

        ~Cat(){
            cout << "Destroying cats " << endl;

        }
        void speak() const{
            cout << "meow" << endl;
        }

        void move(){
            cout << "cat pounces" << endl;
        }

        void eat(){
            cout << "cat eats" << endl;
        }
};

class Lion : public Mammal{
    public:
        Lion(string name, COLOR color): Mammal(name, color){
        }

        ~Lion(){
            cout << "Destroying lion " << endl;
        }

        void speak() const{
            cout << "Roar" << endl;
        }

        void move(){
            cout << "lion runs" << endl;
        }

        void eat(){
            cout << "lion eats" << endl;
        }
};

int main(){
    int choice, numbers;
    int totalAnimals = -1;
    int index = 0;
    cout << "Enter total number of animals" << endl;
    cin >> numbers;

    Mammal *animals[numbers];

    do{
        cout << "Select the animal to send to Zoo: " << endl;
        cout << "(1) Dog" << endl;
        cout << "(2) Cat" << endl;
        cout << "(3) Lion" << endl;
        cout << "(4) Move all animals" << endl;
        cout << "(5) Make all animals eat" << endl;
        cout << "(6) Make all animals speak" << endl;
        cout << "(7) Quit" << endl;
        cin >> choice;1

        switch(choice){
            case 1:
                animals[index] = new Dog("dog", Brown, "Kae");
                index++;
                totalAnimals++;
                break;
            case 2:
                animals[index] = new Cat("cat", Green);
                index++;
                totalAnimals++;
                break;
            case 3:
                animals[index] = new Lion("Lion", Black);
                index++;
                totalAnimals++;
                break;
            case 4:
                for(int i = 0; i<=totalAnimals; i++){
                    animals[i]->move();
                }
                break;
            case 5:
                for(int j = 0; j<=totalAnimals; j++){
                    animals[j]->eat();
                }
                break;
            case 6:
                for(int k = 0; k<=totalAnimals; k++){
                    animals[k]->speak();
                }
                break;
        } 
    }while(choice < 7);
}
