#include "Aggregate.h"
#include "ChatRoom.h"
#include "Command.h"
#include "ConcreteUsers.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Iterator.h"
#include "MessageHistoryIterator.h"
#include "SaveMessageCommand.h"
#include "SendMessageCommand.h"
#include "UserIterator.h"
#include "Users.h"

#include <iostream>
using namespace std;

void testingMediatorAndCommand() {
    cout << "=================== Testing Mediator and Command ==================== " << endl;

    //creating chatrooms
    ChatRoom* catChatRoom = new CtrlCat("CTRLCAT");
    ChatRoom* dogChatRoom = new Dogorithm("DOGORITHM");

   //creating Users
    Users* carlos = new Name1("Carlos");
    Users* charles = new Name2("Charles");
    Users* lando = new Name1("Lando");
    Users* oscar = new Name3("Oscar");
    Users* max = new Name2("Max");
    Users* lewis = new Name1("Lewis");
    Users* george = new Name3("George");
    Users* alex = new Name2("Alex");
    Users* daniel = new Name3("Daniel");
    Users* pierre = new Name1("Pierre");

    catChatRoom->getUserList();
    dogChatRoom->getUserList();

    cout << endl;

    cout << "\n---- Testing registerUser ----\n";
    //CtrlCat only
    catChatRoom->registerUser(carlos);
    catChatRoom->registerUser(charles);
    catChatRoom->registerUser(george);
    catChatRoom->registerUser(alex);

    cout << endl;

    //Dogorithm only
    dogChatRoom->registerUser(lando);
    dogChatRoom->registerUser(daniel);
    dogChatRoom->registerUser(pierre);

    cout << endl;

    //BOTH chat rooms
    catChatRoom->registerUser(oscar);
    dogChatRoom->registerUser(oscar);

    catChatRoom->registerUser(max);
    dogChatRoom->registerUser(max);

    catChatRoom->registerUser(lewis);
    dogChatRoom->registerUser(lewis);

    cout << endl;
    
    //sending messages
    cout << "---- Testing send message in CtrlCat chatroom ----\n";
    carlos->send("Hello everyone! This is a great place to talk about cats.", catChatRoom);
    cout << endl;

    //viewing chatHistory
    cout << "---- Testing chatHistory ----\n";
    catChatRoom->printChatRoomHistory();
    dogChatRoom->printChatRoomHistory();
    cout << endl;

    //removing user
    cout << "---- Testing removeUser ----\n";
    catChatRoom->getUserList();
    catChatRoom->removeUser(george);
    catChatRoom->getUserList();

    cout << endl;

    lewis->send("I love my dog Roscoe, but I also like cats.", catChatRoom);
    cout << endl;

    //testing continued for catChatRoom
    cout << "---- Testing continued ----\n";
    charles->send("I agree Carlos! My tabby cat Mr. Whiskers loves to code with me.", catChatRoom);
    oscar->send("That's pawsome! I'm in both chat rooms - best of both worlds!", catChatRoom);
    alex->send("Welcome Oscar! What's your favorite cat breed?", catChatRoom);

    //adding to dogChatRoom
    lando->send("Woof woof! Dog lovers unite!", dogChatRoom);
    daniel->send("My golden retriever helps me debug code - he's a good boy!", dogChatRoom);
    oscar->send("Hey everyone! I'm here from CtrlCat too. Dogs are amazing!", dogChatRoom);
    max->send("Oscar, you're everywhere! My husky loves winter coding sessions.", dogChatRoom);

    cout << endl; 

    dogChatRoom->removeUser(daniel);
    cout << "\n--- Messages after user removal ---" << endl;
    pierre->send("Daniel left?", dogChatRoom);

    cout << "\n--- Adding new users mid-conversation ---" << endl;
    Users* roger = new Name2("Roger");
    Users* rafa = new Name3("Rafa");

    catChatRoom->registerUser(roger);
    dogChatRoom->registerUser(rafa);

    cout << endl;

    roger->send("Hi everyone! Roger here, excited to join the cat discussion!", catChatRoom);
    rafa->send("Hi Everyone, I'm Rafa!", dogChatRoom);

    oscar->send("Welcome Roger! Great to have more cat enthusiasts here.", catChatRoom);
    max->send("Hey Rafa! Welcome to the pack!", dogChatRoom);

    cout << endl;

    //removing user that's in both chatrooms
    dogChatRoom->removeUser(max);
    lewis->send("Bye Max! Is he still in the Cat Chatroom?", dogChatRoom);
    oscar->send("We still here.", catChatRoom);
    catChatRoom->removeUser(max);

    cout << "\n--- Final user lists and chat histories ---\n";
    catChatRoom->printChatRoomHistory();
    catChatRoom->getUserList();
    dogChatRoom->printChatRoomHistory();
    dogChatRoom->getUserList();


    //cleaning up memory
    delete catChatRoom;
    delete dogChatRoom;
    delete carlos;
    delete charles;
    delete lando;
    delete oscar;
    delete max;
    delete lewis;
    delete george;
    delete alex;
    delete daniel;
    delete pierre;
    delete roger;
    delete rafa;

}

int main() {

    testingMediatorAndCommand();


    return 0;
}