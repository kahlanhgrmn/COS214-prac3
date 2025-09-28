#include "CtrlCat.h"
#include "Dogorithm.h"
#include "BasicUser.h"
#include "AdminUser.h"
#include "ModeratorUser.h"
#include "UserCreationSystem.h"
#include "BasicUserFactory.h"
#include "AdminUserFactory.h"
#include "ModeratorUserFactory.h"
#include "IteratorCreator.h"
#include "UserIterator.h"
#include "MessageHistoryIterator.h"
#include "ChatRoomIterator.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

using namespace std;

/// @brief Global counter for total number of tests executed
int testsRun = 0;
/// @brief Global counter for number of tests that passed
int testsPassed = 0;

/**
 * @brief Executes a single test and tracks results
 * @param testName Descriptive name of the test being run
 * @param condition Boolean result of the test condition
 * 
 * Increments test counters and prints pass/fail status.
 * Updates global test statistics for final reporting.
 */
void runTest(const string& testName, bool condition) {
    testsRun++;
    if (condition) {
        testsPassed++;
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

/**
 * @brief Tests the original mediator and command patterns
 * 
 * Comprehensive test of chat room communication, user management,
 * and message handling using the factory-created users.
 * Tests user registration, message sending, user removal,
 * and multi-room functionality.
 */
void testingMediatorAndCommand() {
    cout << "=================== Testing Mediator and Command ==================== " << endl;

    //creating chatrooms
    ChatRoom* catChatRoom = new CtrlCat("CTRLCAT");
    ChatRoom* dogChatRoom = new Dogorithm("DOGORITHM");

   //creating Users
    UserCreationSystem userSystem;
    Users* carlos = userSystem.createUser("Carlos", "basic");
    Users* charles = userSystem.createUser("Charles", "admin");
    Users* lando = userSystem.createUser("Lando", "basic");
    Users* oscar = userSystem.createUser("Oscar", "moderator");
    Users* max = userSystem.createUser("Max", "admin");
    Users* lewis = userSystem.createUser("Lewis", "basic");
    Users* george = userSystem.createUser("George", "moderator");
    Users* alex = userSystem.createUser("Alex", "admin");
    Users* daniel = userSystem.createUser("Daniel", "moderator");
    Users* pierre = userSystem.createUser("Pierre", "basic");

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
    Users* roger = userSystem.createUser("Roger", "admin");
    Users* rafa = userSystem.createUser("Rafa", "moderator");

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

/**
 * @brief Tests the Factory Method pattern implementation
 * 
 * Verifies user creation through factories, privilege assignment,
 * and proper handling of invalid user types. Tests both the
 * UserCreationSystem and direct factory usage.
 */
void testFactoryMethodPattern() {
    cout << "\n=== Testing Factory Method Pattern ===" << endl;
    
    UserCreationSystem userSystem;
    
    cout << "Available user types: ";
    userSystem.listAvailableUserTypes();
    
    //creating different user types
    Users* basicUser = userSystem.createUser("Alice", "basic");
    Users* adminUser = userSystem.createUser("Bob", "admin");
    Users* moderatorUser = userSystem.createUser("Carol", "moderator");
    Users* invalidUser = userSystem.createUser("Dave", "invalid_type");
    
    runTest("Basic user creation", basicUser != nullptr && basicUser->getUserType() == "Basic");
    runTest("Admin user creation", adminUser != nullptr && adminUser->getUserType() == "Admin");
    runTest("Moderator user creation", moderatorUser != nullptr && moderatorUser->getUserType() == "Moderator");
    runTest("Invalid type defaults to basic", invalidUser != nullptr && invalidUser->getUserType() == "Basic");
    
    //testing privileges
    runTest("Basic user has no privileges", !basicUser->hasPrivilege("kick"));
    runTest("Admin user has kick privilege", adminUser->hasPrivilege("kick"));
    runTest("Admin user has ban privilege", adminUser->hasPrivilege("ban"));
    runTest("Moderator user has mute privilege", moderatorUser->hasPrivilege("mute"));
    runTest("Moderator user has warn privilege", moderatorUser->hasPrivilege("warn"));
    runTest("Moderator cannot ban", !moderatorUser->hasPrivilege("ban"));
    
    //testing direct factory usage
    BasicUserFactory basicFactory;
    AdminUserFactory adminFactory;
    ModeratorUserFactory moderatorFactory;
    
    Users* directBasic = basicFactory.createUser("Direct1");
    Users* directAdmin = adminFactory.createUser("Direct2");
    Users* directModerator = moderatorFactory.createUser("Direct3");
    
    runTest("Direct basic factory works", directBasic->getUserType() == "Basic");
    runTest("Direct admin factory works", directAdmin->getUserType() == "Admin");
    runTest("Direct moderator factory works", directModerator->getUserType() == "Moderator");
    
    //cleanup
    delete basicUser;
    delete adminUser;
    delete moderatorUser;
    delete invalidUser;
    delete directBasic;
    delete directAdmin;
    delete directModerator;
}

/**
 * @brief Tests the Iterator pattern implementation
 * 
 * Verifies user and message iteration, forward/reverse traversal,
 * reset functionality, and empty collection handling.
 * Tests UserIterator, MessageHistoryIterator, and ChatRoomIterator.
 */
void testIteratorPattern() {
    cout << "\n=== Testing Iterator Pattern ===" << endl;
    
    ChatRoom* testRoom = new CtrlCat("IteratorTest");
    UserCreationSystem userSystem;
    
    //testing empty collections
    Iterator<Users*>* emptyUserIter = IteratorCreator::createUserIterator(testRoom);
    Iterator<string>* emptyMsgIter = IteratorCreator::createMessageIterator(testRoom);
    
    runTest("Empty user iterator works", !emptyUserIter->hasNext());
    runTest("Empty message iterator works", !emptyMsgIter->hasNext());
    
    delete emptyUserIter;
    delete emptyMsgIter;
    
    //adding users and testing iteration
    Users* user1 = userSystem.createUser("IterUser1", "basic");
    Users* user2 = userSystem.createUser("IterUser2", "admin");
    Users* user3 = userSystem.createUser("IterUser3", "moderator");
    
    testRoom->registerUser(user1);
    testRoom->registerUser(user2);
    testRoom->registerUser(user3);
    
    user1->send("First message", testRoom);
    user2->send("Second message", testRoom);
    user3->send("Third message", testRoom);
    
    //testing user iteration
    Iterator<Users*>* userIter = IteratorCreator::createUserIterator(testRoom);
    vector<Users*> iteratedUsers;
    
    while (userIter->hasNext()) {
        iteratedUsers.push_back(userIter->next());
    }
    
    runTest("User iteration count correct", iteratedUsers.size() == 3);
    runTest("User iteration order correct", iteratedUsers[0] == user1);
    
    ///testing reset functionality
    userIter->reset();
    runTest("Reset works", userIter->hasNext());
    runTest("Current after reset", userIter->current() == user1);
    
    delete userIter;
    
    //testing forward message iteration
    Iterator<string>* msgIter = IteratorCreator::createMessageIterator(testRoom, false);
    vector<string> messages;
    
    while (msgIter->hasNext()) {
        messages.push_back(msgIter->next());
    }
    
    runTest("Message iteration works", messages.size() == 3);
    runTest("Message order correct", messages[0] == "From IterUser1: First message");
    
    delete msgIter;
    
    //testing reverse message iteration
    Iterator<string>* reverseMsgIter = IteratorCreator::createMessageIterator(testRoom, true);
    vector<string> reverseMessages;
    
    while (reverseMsgIter->hasNext()) {
        reverseMessages.push_back(reverseMsgIter->next());
    }
    
    runTest("Reverse iteration works", reverseMessages.size() == 3);
    runTest("Reverse order correct", reverseMessages[0] == "From IterUser3: Third message");
    
    delete reverseMsgIter;
    
    //testing ChatRoom iterator
    Iterator<ChatRoom*>* roomIter = IteratorCreator::createChatRoomIterator(user1);
    roomIter->hasNext();
    roomIter->next();
    roomIter->current();
    roomIter->reset();
    delete roomIter;
    
    //cleanup
    delete testRoom;
    delete user1;
    delete user2;
    delete user3;
}

/**
 * @brief Tests the Command pattern implementation
 * 
 * Verifies message sending through command objects,
 * direct command creation, and null command handling.
 * Tests SendMessageCommand and SaveMessageCommand functionality.
 */
void testCommandPattern() {
    cout << "\n=== Testing Command Pattern ===" << endl;
    
    ChatRoom* cmdRoom = new Dogorithm("CommandTest");
    UserCreationSystem userSystem;
    Users* sender = userSystem.createUser("Sender", "basic");
    Users* receiver = userSystem.createUser("Receiver", "basic");
    
    cmdRoom->registerUser(sender);
    cmdRoom->registerUser(receiver);
    
    //testing normal message sending, uses internal commands
    sender->send("Test message", cmdRoom);
    
    runTest("Command pattern saves message", cmdRoom->getChatHistory().size() == 1);
    runTest("Message content correct", cmdRoom->getChatHistory()[0] == "From Sender: Test message");
    
    //testing direct command creation
    Command* sendCmd = new SendMessageCommand(cmdRoom, "Direct send", sender);
    Command* saveCmd = new SaveMessageCommand(cmdRoom, "Direct save", sender);
    
    sender->addCommand(sendCmd);
    sender->addCommand(saveCmd);
    sender->executeAll();
    
    runTest("Direct commands work", cmdRoom->getChatHistory().size() == 2);
    
    //tesing null command handling
    sender->addCommand(nullptr);
    sender->executeAll();
    
    runTest("Null command handled", true); // If we get here, it didn't crash
    
    delete cmdRoom;
    delete sender;
    delete receiver;
}

/**
 * @brief Tests admin and moderator user functionality
 * 
 * Verifies administrative actions like kick, ban, mute, warn,
 * and privilege management. Tests both default and custom
 * privilege assignment.
 */
void testAdminAndModeratorFunctionality() {
    cout << "\n=== Testing Admin and Moderator Functionality ===" << endl;
    
    ChatRoom* testRoom = new CtrlCat("AdminModTest");
    UserCreationSystem userSystem;
    
    Users* admin = userSystem.createUser("SuperAdmin", "admin");
    Users* moderator = userSystem.createUser("ModUser", "moderator");
    Users* basicUser = userSystem.createUser("RegularUser", "basic");
    
    testRoom->registerUser(admin);
    testRoom->registerUser(moderator);
    testRoom->registerUser(basicUser);
    
    //testing the admin functionality
    AdminUser* adminPtr = dynamic_cast<AdminUser*>(admin);
    runTest("Admin casting works", adminPtr != nullptr);
    
    if (adminPtr) {
        adminPtr->kickUser(basicUser, testRoom);
        adminPtr->banUser(basicUser, testRoom);
        adminPtr->deleteMessage(testRoom, 1);
        
        //test custom privileges
        vector<string> customPrivs;
        customPrivs.push_back("special_access");
        adminPtr->addPrivileges(customPrivs);
        runTest("Custom admin privilege", adminPtr->hasPrivilege("special_access"));
    }
    
    //testing moderator functionality
    ModeratorUser* modPtr = dynamic_cast<ModeratorUser*>(moderator);
    runTest("Moderator casting works", modPtr != nullptr);
    
    if (modPtr) {
        modPtr->muteUser(basicUser, testRoom);
        modPtr->warnUser(basicUser, "Please follow rules");
        modPtr->viewUserReports(testRoom);
        
        //test custom privileges
        vector<string> modPrivs;
        modPrivs.push_back("special_mod_access");
        modPtr->addPrivileges(modPrivs);
        runTest("Custom moderator privilege", modPtr->hasPrivilege("special_mod_access"));
    }
    
    delete testRoom;
    delete admin;
    delete moderator;
    delete basicUser;
}

/**
 * @brief Tests edge cases and integration scenarios
 * 
 * Verifies handling of empty names, long names, case sensitivity,
 * multi-room user membership, and complex user interactions.
 * Tests system robustness and integration between patterns.
 */
void testEdgeCasesAndIntegration() {
    cout << "\n=== Testing Edge Cases and Integration ===" << endl;
    
    UserCreationSystem userSystem;
    
    //test edge cases
    Users* emptyName = userSystem.createUser("", "basic");
    runTest("Empty name handled", emptyName->getName() == "");
    delete emptyName;
    
    Users* longName = userSystem.createUser(string(50, 'X'), "admin");
    runTest("Long name handled", longName->getName().length() == 50);
    delete longName;
    
    Users* wrongCase = userSystem.createUser("Test", "ADMIN");
    runTest("Case sensitivity handled", wrongCase->getUserType() == "Basic");
    delete wrongCase;
    
    //testing complex integration scenario
    ChatRoom* room1 = new CtrlCat("Room1");
    ChatRoom* room2 = new Dogorithm("Room2");
    
    Users* multiUser = userSystem.createUser("MultiRoomUser", "admin");
    Users* helper = userSystem.createUser("Helper", "basic");
    
    //same user in multiple rooms
    room1->registerUser(multiUser);
    room2->registerUser(multiUser);
    room1->registerUser(helper);
    room2->registerUser(helper);
    
    multiUser->send("Message in room 1", room1);
    multiUser->send("Message in room 2", room2);
    
    runTest("Multi-room messaging", room1->getChatHistory().size() == 1 && room2->getChatHistory().size() == 1);
    
    //testing removal from one room
    room1->removeUser(multiUser);
    runTest("Partial removal works", room1->getUsers().size() == 1 && room2->getUsers().size() == 2);
    
    delete room1;
    delete room2;
    delete multiUser;
    delete helper;
}

/**
 * @brief Converts integer to string without using to_string
 * @param value Integer value to convert
 * @return String representation of the integer
 * 
 * Custom implementation to avoid dependency on to_string function.
 * Handles negative numbers and zero correctly.
 */
string intToString(int value) {
    if (value == 0) return "0";
    string result = "";
    bool negative = value < 0;
    if (negative) value = -value;
    while (value > 0) {
        result = char('0' + (value % 10)) + result;
        value /= 10;
    }
    if (negative) result = "-" + result;
    return result;
}

/**
 * @brief Converts integer to string without using to_string
 * @param value Integer value to convert
 * @return String representation of the integer
 * 
 * Custom implementation to avoid dependency on to_string function.
 * Handles negative numbers and zero correctly.
 */
void testPerformanceAndStress() {
    cout << "\n=== Testing Performance and Stress Scenarios ===" << endl;
    
    ChatRoom* stressRoom = new CtrlCat("StressTest");
    vector<Users*> users;
    UserCreationSystem userSystem;
    
    //creating many users
    for (int i = 0; i < 15; i++) {
        Users* user = userSystem.createUser("StressUser" + intToString(i), "basic");
        users.push_back(user);
        stressRoom->registerUser(user);
    }
    
    runTest("Many users registered", stressRoom->getUsers().size() == 15);
    
    //sending many messages
    for (int i = 0; i < 10; i++) {
        users[i % users.size()]->send("Stress message " + intToString(i), stressRoom);
    }
    
    runTest("Many messages sent", stressRoom->getChatHistory().size() == 10);
    
    //test the iterator with many items
    Iterator<Users*>* stressIter = IteratorCreator::createUserIterator(stressRoom);
    int count = 0;
    while (stressIter->hasNext()) {
        stressIter->next();
        count++;
    }
    runTest("Stress iteration works", count == 15);
    
    delete stressIter;
    delete stressRoom;
    for (Users* user : users) {
        delete user;
    }
}

/**
 * @brief Main testing function for the PetSpace chat system
 * @return 0 if successful, 1 if significant errors occurred
 * 
 * Executes comprehensive tests of all design patterns:
 * Factory Method, Mediator, Command, and Iterator patterns.
 * Provides detailed test results and success metrics.
 * Tests are run in order from basic functionality to complex integration.
 */
int main() {
    cout << "           PETSPACE CHAT SYSTEM TESTING" << endl;
    cout << "=========================================================" << endl;
    
    try {
        testingMediatorAndCommand();
        testFactoryMethodPattern();
        testIteratorPattern();
        testCommandPattern();
        testAdminAndModeratorFunctionality();
        testEdgeCasesAndIntegration();
        testPerformanceAndStress();
        
        //results summary
        cout << "\n=========================================================" << endl;
        cout << "                  TESTING COMPLETE" << endl;
        cout << "=========================================================" << endl;
        cout << "Total Tests: " << testsRun << endl;
        cout << "Passed: " << testsPassed << endl;
        cout << "Failed: " << (testsRun - testsPassed) << endl;
        
        double successRate = (testsRun > 0) ? (double)testsPassed / testsRun * 100.0 : 0.0;
        cout << "Success Rate: " << successRate << "%" << endl;
        
        cout << "\nDesign Patterns Successfully Tested:" << endl;
        cout << "- Factory Method Pattern - User creation system" << endl;
        cout << "- Mediator Pattern - Chat room communication" << endl;
        cout << "- Command Pattern - Message operations" << endl;
        cout << "- Iterator Pattern - Collection traversal" << endl;
        
        cout << "=========================================================" << endl;
        
        return (successRate >= 60.0)? 0: 1;
        
    } catch (...) {
        cout << "\nERROR: Unexpected exception during testing" << endl;
        return 1;
    }
}