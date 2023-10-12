#ifndef MYHEADER_HPP
#define MYHEADER_HPP
#include <string>
#include <fstream>
#include <map>

class Animal {
public:
Animal () {}
Animal(const std::string& habitat, const std::string& food, const std::string& skin, const std::string& color, const std::string& blooded, const std::string& classification)
: m_habitat(habitat), m_food(food), m_skin(skin), m_color(color), m_blooded(blooded), m_classification(classification) {}

std::string getHabitat() const { return m_habitat; }
std::string getFood() const { return m_food; }
std::string getSkin() const { return m_skin; }
std::string getColor() const { return m_color; }
std::string getBlooded() const { return m_blooded; }
std::string getClassification() const { return m_classification; }



void getAttributes(){
  std::ofstream outfile;
  outfile.open("attributes.txt", std::ios::trunc);
  outfile<< getHabitat()<<'\n';
  outfile<< getFood()<<'\n';
  outfile<< getSkin()<<'\n';
  outfile<< getColor()<<'\n';
  outfile<< getBlooded()<<'\n';
  outfile<< getClassification();
  outfile.close();
}

private:
std::string m_habitat;
std::string m_food;
std::string m_skin;
std::string m_color;
std::string m_blooded;
std::string m_classification;
};

// class Mammal : public Animal {
// public:
//  bool marsupial;
 


// };



//prototypes
std::string getGuess();
std::string checkGuess(std::string);
std::string Randomizer(std::string);
std::string lower(std::string);
void winList();
void getAttributes(const std::string& animal);
void header();
void rules();
void showHint(std::string&,int);
void specificQuestion(std::string);
void typeWriter(std::string);
void questionChecker(std::string);
void menuSelection();
void totalAttempts();
void attemptsReset();
void loss(std::string&);
void clearAttributeArray(std::string (&attributeArray)[6]);
void addAttribute(std::string, std::string (&attributeArray)[6]);
void displayFile(std::string);
void checkfile(std::string);

//definitions
std::string getGuess(){
  std::ofstream outfile;
  std::string userGuess;
  std::cout<<"\n\tEnter a guess: ";
  std::getline(std::cin,userGuess);
  outfile.open("shared.txt");
  outfile<<userGuess;
  outfile.close();
  return userGuess;
}

std::string checkGuess(std::string userGuess){ 
std::ifstream infile;
  system("python3 main.py");
  infile.open("check.txt");
  std::getline(infile, userGuess);
  infile.close();
  return userGuess;
}
// std::string RandomizeAnimal(){
//   std::ifstream infile;
//   infile.open("AnimalList.txt");
//   std::vector<std::string> animals;
//   std::string animal;
//   while (infile >> animal){
//     animals.push_back(animal);
//   }

//   std::srand(std::time(nullptr));
//   int i = std::rand() % animals.size();
//   std::string randomAnimal = animals[i];
//   infile.close();
//   return randomAnimal;
// }

std::string Randomizer(std::string file){
  std::ifstream infile;
  infile.open(file);
  std::vector<std::string> randomizerVector;
  std::string list;
  while (std::getline(infile, list)){
    randomizerVector.push_back(list);
  }

  std::srand(std::time(nullptr));
  int i = std::rand() % randomizerVector.size();
  std::string randomized = randomizerVector[i];
  infile.close();
  return randomized;
}

void header(){
std::cout<<"\t ___  _  _  ___  __  __  ___  _     ___   _ \n"; 
std::cout<<"\t/   \\| \\| ||_ _||  \\/  |/   \\| |   / __| | | \n"; 
std::cout<<"\t| ^ || .  | | | | |\\/| || ^ || |__ \\__ \\ |_|  \n";
std::cout<<"\t|_|_||_|\\_||___||_|  |_||_|_||____||___/ (_)  \n";
std::cout<<"--------------------------------------------------------\n";
}

void rules(){
  std::string welcome = "\n\tYou will be given 10 tries to guess the animal.\n\tYou will get a total of 6 hints to help you.\n\tTo make a guess type an answer and hit enter.\n\tGood luck and have fun!\n\n";

  typeWriter(welcome);
}
// void getAttributes(const Animal& animal){
//   std::ofstream outfile;
//   outfile.open("attributes.txt");
//   outfile<< animal.m_habitat;
//   outfile.close();
// }

void showHint(std::string& tempAttribute,int hintTracker){
  std::string question;
  
  
  if (tempAttribute == "land") {
        question = "\n\tThis animal lives on land.";
    }
    else if (tempAttribute == "water") {
        question = "\n\tThis animal lives in the water.";
    }
    else if (tempAttribute == "air") {
        question = "\n\tThis animal can fly.";
    }
    else if (tempAttribute == "waterAndLand") {
        question = "\n\tThis animal can live both on land and in the water.";
    }
    else if (tempAttribute == "meat") {
        question = "\n\tThis animal eats meat.";
    }
    else if (tempAttribute == "plants") {
        question = "\n\tThis animal eats plants.";
    }
    else if (tempAttribute == "fish") {
        question = "\n\tThis animal eats fish.";
    }
    else if (tempAttribute == "omnivor") {
        question = "\n\tThis animal eats both plants and meat.";
    }
    else if (tempAttribute == "insects") {
        question = "\n\tThis animal eats insects.";
    }
    else if (tempAttribute == "nectar") {
        question = "\n\tThis animal feeds on nectar.";
    }
    else if (tempAttribute == "fur") {
        question = "\n\tThis animal has fur.";
    }
    else if (tempAttribute == "hair") {
           question = "\n\tThis animal has hair.";
    }
    else if (tempAttribute == "skin") {
        question = "\n\tThis animal has smooth skin.";
    }
    else if (tempAttribute == "feathers") {
        question = "\n\tThis animal has feathers.";
    }
    else if (tempAttribute == "scales") {
        question = "\n\tThis animal has scales.";
    }
    else if (tempAttribute == "noSkin") {
        question = "\n\tThis animal does not have skin.";
    }
    else if (tempAttribute == "wings") {
        question = "\n\tThis animal has wings.";
    }
    else if (tempAttribute == "various") {
        question = "\n\tThis animal has various colors.";
    }
    else if (tempAttribute == "yellow") {
        question = "\n\tThis animal is yellow.";
    }
    else if (tempAttribute == "striped") {
        question = "\n\tThis animal has stripes.";
    }
    else if (tempAttribute == "gray") {
        question = "\n\tThis animal is gray.";
    }
    else if (tempAttribute == "blackAndWhite") {
        question = "\n\tThis animal is black and white.";
    }
    else if (tempAttribute == "green") {
        question = "\n\tThis animal is green.";
    }
    else if (tempAttribute == "black") {
        question = "\n\tThis animal is black.";
    }
    else if (tempAttribute == "warm") {
        question = "\n\tThis animal is warm-blooded.";
    }
    else if (tempAttribute == "cold") {
        question = "\n\tThis animal is cold-blooded.";
    }
    else if (tempAttribute == "mammal") {
        question = "\n\tThis animal is a mammal.";
    }
    else if (tempAttribute == "bird") {
        question = "\n\tThis animal is a bird.";
    }
    else if (tempAttribute == "reptile") {
        question = "\n\tThis animal is a reptile.";
    }
    else if (tempAttribute == "isfish") {
        question = "\n\tThis animal is a fish.";
    }
    else if (tempAttribute == "invertebrate") {
        question = "\n\tThis animal is an invertebrate.";
    }
    else if (tempAttribute == "amphibian") {
        question = "\n\tThis animal is an amphibian.";
    }
    else if (tempAttribute == "insect") {
        question = "\n\tThis animal is an insect.";
    }
  
 typeWriter(question);
}//showquestion function


// void specificQuestion(std::string answer){
//   if(answer == "")
//     std::cout<< "";
// }
 void typeWriter(std::string word){
    int len = word.length();
      for (int i = 0; i < len; i++) {
          std::cout << word[i];
          std::cout.flush();
          std::this_thread::sleep_for(std::chrono::milliseconds(20));
       }
 }
std::string lower(std::string input){  
  for (int i = 0; i < input.length(); i++)
  {
    input[i] = tolower(input[i]);
  }
  return input;
}

// void questionChecker(std::string){

  
// }

void menuSelection(){
  std::cout<<"\n\n\tWelcome to ANIMALS! a guessing game!";
  std::cout<<"\n\n\t\tMain menu";
  std::cout<<"\n\n\t\t1. start a new game";
  std::cout<<"\n\n\t\t2. View Win List";
  std::cout<<"\n\n\t\t3. View Attempt list";
  std::cout<<"\n\n\t\t4. View Animal list"; 
  std::cout<<"\n\n\t\t5. Exit Program";  
  std::cout<<"\n\n\t\tInput your selection(1-5 then press Enter): ";  
}

void winList(){
  std::ofstream outfile;
  std::string winnerInitials;
  std::cout<<"Enter your initals: ";
  std::getline(std::cin, winnerInitials);
  outfile.open("winList.txt",std::ios::app);
  outfile<< winnerInitials<<std::endl;
  outfile.close();  
}

void totalAttempts(){
  int attempts = 1;
  std::ofstream outfile;
  std::ifstream infile;
  infile.open("attempts.txt");
  while(infile>>attempts){
    attempts++;
  }
  infile.close();
  
  outfile.open("attempts.txt");
  outfile<<attempts;
  outfile.close();  
}

void attemptsReset(){
  int attempts = 0;
  std::ofstream outfile;  
  outfile.open("attempts.txt");
  outfile<<attempts;
  outfile.close();  
}
  void loss(std::string& answer){    
  std::string loss = "\n\n\tThat's 10 guesses! Better luck next time!\n\tThe animal is a(n) ";
  typeWriter(loss);
    typeWriter(answer + '!');
        }

void clearAttributeArray(std::string (&attributeArray)[6]){
  for(int i = 0; i < 6; i++){ 
    attributeArray[i]= "";
  }
}

void addAttribute(std::string file, std::string (&attributeArray)[6]){
  std::string attribute;
  int counter = 0;
  std::ifstream infile;
  infile.open("attributes.txt");
    while(std::getline(infile, attribute)){ 
    attributeArray[counter] = attribute;
  counter++;
}
infile.close();
}
 
void displayFile(std::string file) {
  int wins = 0;
  std::ifstream infile;
  infile.open(file);
  std::string word;
  while (std::getline(infile, word)) {
    std::cout<<"\t\t"<< word <<'\n';
    wins++;
  }
  infile.close();
  if(file == "attempts.txt"){
    return;
  }
    std::cout<<"\t\t"<<"Total: "<<wins<<'\n';
}

void checkfile(std::string animal){
    bool check = false;
   std::ifstream infile;
  infile.open("AnimalList.txt");
  std::string word;
  while (std::getline(infile, word)) {
    if (word == animal){
      check = true;
    }
  }
  infile.close();
    if (check == true){      
    std::cout<<"\n\t\t"<<animal<<" is on the list.\n";
    }
  
    if (check == false) {    
    std::cout<<"\n\t\t"<<animal<<" is not on the list.\n";
  }
  
}

#endif