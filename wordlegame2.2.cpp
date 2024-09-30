#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;
string randomMenu(string wordleWord);
void gamePlay(string wordleWord);


string wordleWord;

int main(){
randomMenu(wordleWord);
gamePlay(wordleWord);

  
return 0;
}




string randomMenu(string){
bool tryAgain;
int menuOption;
int categoryOption;
int wordOption;
//string wordleWord;

cout<<"Welcome to wordle! Please select an option below:\n"<<endl;

do{
cout<<"1. Play with a completely random word"<<endl;
cout<<"2. Play with a word from a specific category\n"<<endl;
cout<<"Menu option: ";
cin>>menuOption;
if (menuOption!=1 && menuOption !=2){
  cout<<"Please choose either option 1 or 2.\n"<<endl;
  tryAgain=true;
}
}while (menuOption!=1 && menuOption !=2);



if (menuOption == 1){
srand(time(0));
categoryOption = rand() % 4 + 1;

srand(time(0));
wordOption = rand() % 10 + 1;
}

if (menuOption==2){
  do{
    cout<<"Please choose from the following categories: \n"<<endl;
    cout<<"1. Fruits \n2. Animals \n3. Colors\n4. Countries\n"<<endl;
    cout<<"Choice: ";
    cin>>categoryOption;

    if(categoryOption == 1 ||categoryOption == 2||categoryOption == 3 ||categoryOption == 4){
    srand(time(0));
    wordOption = rand() % 10 + 1;
    }

    if(categoryOption != 1 &&categoryOption != 2&&categoryOption != 3 &&categoryOption != 4){
      cout<<"Please choose only choose from options 1 to 4."<<endl;
    }

  }while(categoryOption != 1 &&categoryOption != 2&&categoryOption != 3 &&categoryOption != 4);
}

if (menuOption==1 || menuOption ==2){
  switch(categoryOption){
    case 1:
        switch(wordOption){
          case 1:
          wordleWord="apple";
          break;
          case 2:
          wordleWord="mango";
          break;
          case 3:
          wordleWord="lemon";
          break;
          case 4:
          wordleWord="grape";
          break;
          case 5:
          wordleWord="peach";
          break;
          case 6:
          wordleWord="berry";
          break;
          case 7:
          wordleWord="melon";
          break;
          case 8:
          wordleWord="olive";
          break;
          case 9:
          wordleWord="guava";
          break;
          case 10:
          wordleWord="raisin";
          break;
  
        }
  break;
    case 2:
        switch(wordOption){
          case 1:
          wordleWord="tiger";
          break;
          case 2:
          wordleWord="zebra";
          break;
          case 3:
          wordleWord="horse";
          break;
          case 4:
          wordleWord="eagle";
          break;
          case 5:
          wordleWord="panda";
          break;
          case 6:
          wordleWord="shark";
          break;
          case 7:
          wordleWord="gecko";
          break;
          case 8:
          wordleWord="llama";
          break;
          case 9:
          wordleWord="otter";
          break;
          case 10:
          wordleWord="rhino";
          break;
        }
    break;
    case 3:
        switch(wordOption){
          case 1:
          wordleWord="azure";
          break;
          case 2:
          wordleWord="black";
          break;
          case 3:
          wordleWord="coral";
          break;
          case 4:
          wordleWord="green";
          break;
          case 5:
          wordleWord="olive";
          break;
          case 6:
          wordleWord="peach";
          break;
          case 7:
          wordleWord="ivory";
          break;
          case 8:
          wordleWord="white";
          break;
          case 9:
          wordleWord="amber";
          break;
          case 10:
          wordleWord="brown";
          break;
        }
    break;
    case 4:
        switch(wordOption){
          case 1:
          wordleWord="japan";
          break;
          case 2:
          wordleWord="chile";
          break;
          case 3:
          wordleWord="egypt";
          break;
          case 4:
          wordleWord="india";
          break;
          case 5:
          wordleWord="qatar";
          break;
          case 6:
          wordleWord="nepal";
          break;
          case 7:
          wordleWord="ghana";
          break;
          case 8:
          wordleWord="spain";
          break;
          case 9:
          wordleWord="china";
          break;
          case 10:
          wordleWord="kenya";
          break;
        }
  break;
  }
}
// cout<<categoryOption<<endl;
// cout<<wordleWord<<endl;
return wordleWord;
}

void gamePlay(string){
  int wordCompleted = 0;
  int attempts = 0;
  int lowerLetter = 0;
  bool yellowUsed =false;
  string color[7][6];
  //bool greened[5]={false};
  //bool greened[6][5];
  string wordRow[6];
  string wordRowLetter[7][6];
  string wordleWordletters[wordleWord.length()];
  int wordleLettercout = 0;
  int LetterCount=0;
  for(int count =1;count<=wordleWord.length();count++){
  wordleWordletters[count]=wordleWord[wordleLettercout];
  wordleLettercout++;
  }

  // for(int count =1; count<=5;count++){
  //   greened[count]=false;
  // }

  for(int count =1; count<=6; count++){
    do{
    cout<<"Enter word for row "<<count<<": ";
    cin>>wordRow[count];
    if(wordRow[count].length()<=4||wordRow[count].length()>=6){
      cout<<"You entered an invalid number of letters. Please try again."<<endl;
    }
    for(int count1 =0;count1<=wordRow[count].length();count1++){
    wordRow[count][count1]=tolower(wordRow[count][count1]);
  }
  }while(wordRow[count].length()<=4||wordRow[count].length()>=6);
  int LetterCount=0;
  attempts++;
  for(int count2=1;count2<=wordRow[count].length();count2++){
    wordRowLetter[count][count2]=wordRow[count][LetterCount];
    LetterCount++;
  }
  // for(int count1 =1;count1<=wordRow[count].length();count1++){
  //    wordRowLetter[count][count1][lowerLetter]=tolower(wordRowLetter[count][count1][lowerLetter]);
  // }

  int yellowCount=0;
  bool greened[6] = {false};
  for(int count = attempts; count<=attempts; count++){
    for(int count2 =1; count2 <=5;count2++){
    
    yellowUsed=false;
    if(wordRowLetter[count][count2] == wordleWordletters[count2]){
      greened[count2]=true;
      color[count][count2]="green";
    }
    for (int count3 = 1;count3<=5;count3++){
      
      if(wordRowLetter[count][count2]==wordleWordletters[count3]&&wordRowLetter[count][count2] != wordleWordletters[count2]&&yellowUsed==false&&greened[count2]!=true){
        color[count][count2]="yellow";
        yellowUsed=true;
      }

      if(wordRowLetter[count][count2]==wordleWordletters[count3]&&wordRowLetter[count][count2] != wordleWordletters[count2]&&greened[count2]!=true){
        yellowCount++;
      }
      
    }
    if(wordRowLetter[count][count2] != wordleWordletters[count2] && yellowUsed==false){
      color[count][count2]="gray";

    }
    // for (int count3 = 1;count3<=5;count3++){
      
    //   if(wordRowLetter[count][count2]==wordleWordletters[count3]&&wordRowLetter[count][count2] != wordleWordletters[count2]&&yellowUsed==false&&greened[count2]!=true){
    //     color[count][count2]="yellow";
    //     yellowUsed=true;
    //   }
    // }
    // if(wordRowLetter[count][count2] != wordleWordletters[count2] && yellowUsed==false){
    //   color[count][count2]="gray";

    // }

  //   for(int count3 = 1;count3<=5;count3++){
  // if(wordRowLetter[count][count2]==wordleWordletters[count3]&&color[count][count2]=="yellow"&&greened[count2]==true){
  //   color[count][count2]="gray";
  //   }
  // }

    // yellowUsed=false;

    //   if(wordRowLetter[count][count2] == wordleWordletters[count2]){
    //   greened[count2]=true;
    //   color[count][count2]="green";
    // }
    // for (int count3 = 1;count3<=5;count3++){
      
    //   if(wordRowLetter[count][count2]==wordleWordletters[count3]&&wordRowLetter[count][count2] != wordleWordletters[count2]&&yellowUsed==false&&greened[count3]!=true){
    //     color[count][count2]="yellow";
    //     yellowUsed=true;
    //   }
    // }
    // if(wordRowLetter[count][count2] != wordleWordletters[count2] && yellowUsed==false){
    //   color[count][count2]="gray";

    // }

    }
    // cout<<""<<endl;
  }

    int letterCounter[6] = {0};
    string individualLetters[6];
    for (int count = 1; count<=5; count++){
      for(int count2 = 1; count2<5; count2++){
        if(wordleWordletters[count]==wordleWordletters[count2]){
          letterCounter[count]++;
        }
      }
    }
    //cout<<letterCounter[1]<<endl;

    int count1 = attempts;
    //cout<<yellowCount<<endl;
    for(int count2 = 1; count2<=5; count2++){
      for(int count3= 1; count3<=5; count3++){
        if(wordRowLetter[count][count2]==wordleWordletters[count3]&&color[count][count2]=="yellow"&&greened[count3]==true){
          color[count][count2]="gray1";
        }
      }  
  }

  for(int count2 = 1; count2<=5; count2++){
      for(int count3= 1; count3<=5; count3++){
        if(color[count][count2]=="gray1"&&color[count][count3]=="gray"||color[count][count2]=="yellow1"&&wordleWordletters[count3]==wordRowLetter[count][count2]){
          color[count][count2]="yellow1";
        }
      }  
  }




  for(int count = 1; count<=attempts; count++){
  for(int count2 =1; count2 <=5;count2++){
  if(color[count][count2]=="green"){
    cout << "\033[1;32m" << wordRowLetter[count][count2] << "\033[0m";
    cout<<" ";
  }
  if(color[count][count2]=="yellow"||color[count][count2]=="yellow1"){
    cout << "\033[1;33m" << wordRowLetter[count][count2] << "\033[0m";
    cout<<" ";
  }
  if(color[count][count2]=="gray"||color[count][count2]=="gray1"){
    cout << "\033[1;37m" << wordRowLetter[count][count2] << "\033[0m";
    cout<<" ";
  }
  }
  cout<<""<<endl;
}

if(wordRow[count]==wordleWord){
  cout<<"\nCongratulations, you have found the correct word and have won the game!"<<endl;
  count=7;
}

if(count == 6 && wordRow[count]!=wordleWord){
  cout<<"\nYou have lost the game. The correct word was "<<wordleWord<<"."<<endl;
}

  }

}