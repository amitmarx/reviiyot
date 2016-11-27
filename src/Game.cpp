//
// Created by amitmarx on 22/11/16.
//

#include <fstream>
#include "../include/Game.h"


Game::Game(char* config):deck(){
    ifstream file(config); // pass file name as argument
    string lineBuffer;
    int i=0;
    while (file && getline(file, lineBuffer)){
        if (lineBuffer.length() == 0 || lineBuffer[0]=='#')
            continue;
        switch(i) {
            {
                case 0:
                    Game::setVerbal(lineBuffer);
                break;
                case 1:
                    Game::setHighest(lineBuffer);
                break;
                case 2:
                    setDeck(lineBuffer);
                break;
                default:
                    setPlayer(lineBuffer,i-3);
                break;
            }
        }
        i++;
    }
}
void Game::setVerbal(string basic_string) {
    Game::isVerbal = basic_string[0]=='1';
}

void Game::setHighest(string basic_string) {
    int i=0;
    int sum=0;
    while(basic_string[i]>='0' && basic_string[i]<='9'){
        sum*=10;
        sum+=basic_string[i] - '0';
        i++;
    }
    highest = sum;
}

void Game::setDeck(string basic_string) {
    deck.initDeck(basic_string);
}

void Game::setPlayer(string str,int position) {
    Player* p;
    string name = str.substr(0,str.length()-2);
    char type = str[str.length()-1];
    switch(type) {
        {
            case '1':
                p = new PlayerType1(name,position);
            break;
            case '2':
                p = new PlayerType2(name,position);
            break;
            case '3':
                p = new PlayerType3(name,position);
            break;
            default:
                p = new PlayerType4(name,position);
            break;
        }
    }
    players.push_back(p);
}

void Game::play() {
while(!isThereAWinner()){
    Player* p = players[turns%players.size()];
    CardRequest * request = p->playTurn();
    Player * playerToAsk = findPlayerToAsk(request,turns%players.size());
    string cardValue = request->getValue();
    if(isVerbal){
        cout<<"Turn "<<turns+1<<endl;
        printState();
        cout<<p->getName()<<" asked "<< playerToAsk->getName()<< " for the value "<<cardValue<<endl;
    }
    vector<Card*> cards = playerToAsk->tryGetCards(cardValue);

    if( cards.size()>0) {
        for (int x = 0; x < cards.size(); x++) {
            p->addCard(*cards[x]);
            playerToAsk->removeCard(*cards[x]);
        }
        if (playerToAsk->getNumberOfCards() > 0) {
            for (int x = 0; x < cards.size() && deck.getNumberOfCards() > 0; x++) {
                playerToAsk->addCard(*deck.fetchCard());
            }
        }
    }
    else
    {
        if(deck.getNumberOfCards()>0){
            p->addCard(*deck.fetchCard());
        }
    }
    turns++;
}
    printEndState();
}

void Game::printState() {
    cout<< stateString();
}
std::string Game::stateString() {
    string s="";
    s+= "Deck: "+deck.toString()+ "\n";
    for(int i=0; i<players.size();i++){
        Player* p =players[i];
        s+=p->getName()+": "+p->toString()+"\n";
    }
    return s;
}



void Game::init() {
    for(int i=0; i<players.size();i++){
        for(int x=0;x<7;x++){
            players[i]->addCard(*deck.fetchCard());
        }
    }
    this->initState = stateString();
}

Game::~Game() {
    for(int i=0; i<players.size();i++){
        delete players[i];
    }
}

bool Game::isThereAWinner() {
    for(int i=0; i<players.size();i++){
        if(players[i]->getNumberOfCards()==0){
            return true;
        }
    }
    return false;
}

Player *Game::findPlayerToAsk(CardRequest *request,int playerPosition) {
    if(InOrderCardRequest * inOrderReq =
            dynamic_cast<InOrderCardRequest*>(request)){
        int playerToAsk =inOrderReq->getPosition() % players.size();
        if(playerToAsk==playerPosition){
            playerToAsk++;
            playerToAsk = playerToAsk % players.size();
            players[playerPosition]->increaseLocationToAskByOne();
        }
        return players[playerToAsk];
    }

    int maxNumOfCards =0;
    int pos=0;
    for(int i=0; i<players.size();i++)
    {
        if(i!=playerPosition && maxNumOfCards<= players[i]->getNumberOfCards()){
            pos=i;
            maxNumOfCards=players[i]->getNumberOfCards();
        }
    }
    return players[pos];
}

void Game::printWinner() {
    vector<Player*> winners;
    for(int i=0; i<players.size();i++){
        if(players[i]->getNumberOfCards()==0){
            winners.push_back(players[i]);
        }
    }
    string names =winners[0]->getName();
    for(int x=1; x<winners.size();x++){
        names+= "and " + winners[x]->getName();
    }
    if(winners.size()>1) {

        cout<<"***** The winners are: "<<names<<" *****";
    }
    else{
        cout<<"***** The winner is: "<<names<<" *****";
    }
}

void Game::printEndState() {
    printWinner();
    cout<<endl<<"Number of turns: "<<turns+1<<endl<<"----------"<<endl;

    cout<<"Initial state:"<<endl<<initState<<endl<<"----------"<<endl;
    cout<<"Final state:"<<endl;
    printState();
}

Game::Game(const Game &obj) {
    this->deck=obj.deck;
    this->highest = obj.highest;
    this->initState = obj.initState;
    this->isVerbal = obj.isVerbal;
    this->turns = obj.turns;

    //TODO: Change this!!!!!
    this->players = obj.players;
}

void Game::printNumberOfTurns() {
    cout<<"Turn "<<turns+1<<endl;
}





























