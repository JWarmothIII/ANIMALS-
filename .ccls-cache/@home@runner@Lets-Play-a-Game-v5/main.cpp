#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <array>
#include <ctime>
#include <string>
#include <map>
#include <chrono>
#include <thread>
#include "myHeader.hpp"

int main() {
  std::map<std::string, Animal> animalMap;
animalMap["cat"] = Animal("land", "meat", "fur", "various", "warm", "mammal");
  
animalMap["dog"] = Animal("land", "meat", "fur", "various", "warm", "mammal");
  
animalMap["horse"] = Animal("land", "plants", "hair", "various", "warm", "mammal");
  
animalMap["lion"] = Animal("land", "meat", "fur", "yellow", "warm", "mammal");
  
animalMap["tiger"] = Animal("land", "meat", "fur", "striped", "warm", "mammal");
  
animalMap["elephant"] = Animal("land", "plants", "skin", "gray", "warm", "mammal");
  
animalMap["giraffe"] = Animal("land", "plants", "fur", "various", "warm", "mammal");
  
animalMap["zebra"] = Animal("land", "plants", "fur", "blackAndWhite", "warm", "mammal");
  
animalMap["penguin"] = Animal("waterAndLand", "fish", "feathers", "blackAndWhite", "warm", "bird");
  
animalMap["duck"] = Animal("waterAndLand", "omnivor", "feathers", "various", "warm", "bird");
  
animalMap["dolphin"] = Animal("water", "fish", "skin", "gray", "warm", "mammal");
  
animalMap["whale"] = Animal("water", "fish", "skin", "various", "warm", "mammal");
  
animalMap["shark"] = Animal("water", "fish", "scales", "various", "cold", "isfish");
  
animalMap["octopus"] = Animal("water", "fish", "noSkin", "various", "cold", "invertebrate");
  
animalMap["snake"] = Animal("land", "meat", "scales", "various", "cold", "reptile");
  
animalMap["crocodile"] = Animal("waterAndLand", "meat", "scales", "green", "cold", "reptile");
  
animalMap["frog"] = Animal("waterAndLand", "insects", "skin", "various", "cold", "amphibian");
  
animalMap["turtle"] = Animal("waterAndLand", "plants", "scales", "various", "cold", "reptile");
  
animalMap["butterfly"] = Animal("air", "nectar", "wings", "various", "cold", "insect");
  
animalMap["gorilla"] = Animal("land", "omnivore", "fur", "black", "warm", "mammal");

animalMap["bat"] = Animal("air", "insects", "fur", "black", "warm", "mammal"); 
  
animalMap["hummingbird"] = Animal("air", "nectar", "feathers", "various", "warm", "bird"); 
  
  char restart;
  std::string answer;
  std::string tempAttribute;
  std::string attributeArray[6];
  int menuChoice = 0;
  
  while(true){
     std::cout << "\x1B[2J\x1B[H";//escape sequence to clear console 
  header();
  menuSelection();
  std::cin>>menuChoice;
    
  switch(menuChoice){
    case 1 :
  rules();
  do {
    std::cin.ignore();
    
    if(restart == 'y'){
      
      std::cout << "\x1B[2J\x1B[H";//escape sequence to clear console
      header();
    }
    totalAttempts();
    answer = Randomizer("AnimalList.txt");
    // std::cout<<"animal is "<<answer;
    Animal& animal = animalMap[answer];
    animal.getAttributes();
    
    clearAttributeArray(attributeArray);
       addAttribute("attributes.txt", attributeArray);
    bool win = true;
    bool arrayChecker = true;
    int guessCounter = 10;
    int hintTracker = 0;
    while(win == true && guessCounter >=0 ){

          
      // tempAttribute = Randomizer("attributes.txt");
      tempAttribute = attributeArray[hintTracker];

      if(guessCounter % 2 == 0 || guessCounter == 1){
      showHint(tempAttribute, hintTracker);
      hintTracker++;      
      }
      
      std::string userGuess = getGuess();
      userGuess = checkGuess(userGuess);

      userGuess = lower(userGuess);
      // std::cout<<userGuess;
      std::cout<<"\n\tYou have "<<guessCounter-1<<" guesses left";
      if(userGuess == answer){
        std::cout<<"\n\n\tCongratulations you guessed the right animal!\n\n";
        winList();
        win = false;
      }//if
        else if (guessCounter == 1){
          loss(answer);     
          break;
        }
        
      else{ 
        guessCounter --;
      }//else
   }//while
    
    std::cout<<"\n\n\tWould you like to start a new game?\n\n\tInput Y for yes or N for no: ";
    std::cin>>restart;
    
  }while(restart == 'y');
  std::cout<<"\n\n\tThanks for playing ANIMALS! a guessing game!";
    break;
    
    case 2:{
      
        
      int choice2 = 0;
      while(choice2 != 1 ){     
      
        displayFile("winList.txt");
        std::cout<<"\n\n\t\t1. Main Menu";
        std::cout<<"\n\n\t\t2. Reset Win List";
        std::cout<<"\n\n\t\tInput your selection(1-2 and press Enter): ";
        std::cin>>choice2;
          if(choice2 == 1){
            break;
          }
          else if (choice2 == 2){
            std::ofstream outfile;
            outfile.open("winList.txt", std::ios::trunc);
            outfile.close();
            std::cout<<"\t\tWin List has been reset";
          }
            }
      break;
    }
    

   case 3:{
      
        
      int choice2 = 0;
      while(choice2 != 1 ){     
        std::cout<<"\n\t\t\tattempts";
        displayFile("attempts.txt");
        std::cout<<"\n\n\t\t1. Main Menu";
        std::cout<<"\n\n\t\t2. Reset Attempt List";
        std::cout<<"\n\n\t\tInput your selection(1-2 and press Enter): ";
        std::cin>>choice2;
          if(choice2 == 1){
            break;
          }
          else if (choice2 == 2){
            std::ofstream outfile;
            outfile.open("attempts.txt", std::ios::trunc);
            outfile.close();
            std::cout<<"\t\tAttempt List has been reset";
          }
            }
      break;
    }
       case 4:{
     
      std::string userAnimal;  
      int choice2 = 0;
      while(choice2 != 1 ){     
      
        std::cout<<"\n\n\t\t1.Check Animal List for an animal";
        std::cout<<"\n\n\t\t2.Display Animal List";
        std::cout<<"\n\n\t\t3.Main Menu";
        std::cout<<"\n\n\t\tInput your selection(1-3 and press Enter): ";
        std::cin>>choice2;
          if(choice2 == 1){
            char check;
            do{
              
            std::cout<<"\n\n\t\tEnter the animal you would like to check: ";
            std::cin>>userAnimal;
            checkfile(userAnimal);
            std::cout<<"\n\n\tWould you like to check another animal?";
              std::cout<<"\n\n\tInput Y for yes or N for no: ";
            std::cin>>check;
              
            check = tolower(check);
              
            }while(check == 'y');
            break;
          }
        else if(choice2 == 2){                
        displayFile("AnimalList.txt");
        }
        else if(choice2 == 3){                
        break;
        }
            }
      break;
    }
    case 5: 
    std::cout<<"\n\n\tThanks for playing ANIMALS! a guessing game!";
    
    return 0;
  }//menu switch
  
    
   
  }//game loop
  return 0;
}//main

