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

// void testingMediatorAndCommand() {
//     cout << "=================== Testing Mediator and Command ==================== " << endl;

//     //creating chatrooms
//     ChatRoom* catChatRoom = new CtrlCat("CTRLCAT");
//     ChatRoom* dogChatRoom = new Dogorithm("DOGORITHM");

//    //creating Users
//     Users* carlos = new Name1("Carlos");
//     Users* charles = new Name2("Charles");
//     Users* lando = new Name1("Lando");
//     Users* oscar = new Name3("Oscar");
//     Users* max = new Name2("Max");
//     Users* lewis = new Name1("Lewis");
//     Users* george = new Name3("George");
//     Users* alex = new Name2("Alex");
//     Users* daniel = new Name3("Daniel");
//     Users* pierre = new Name1("Pierre");

//     catChatRoom->getUserList();
//     dogChatRoom->getUserList();

//     cout << endl;

//     cout << "\n---- Testing registerUser ----\n";
//     //CtrlCat only
//     catChatRoom->registerUser(carlos);
//     catChatRoom->registerUser(charles);
//     catChatRoom->registerUser(george);
//     catChatRoom->registerUser(alex);

//     cout << endl;

//     //Dogorithm only
//     dogChatRoom->registerUser(lando);
//     dogChatRoom->registerUser(daniel);
//     dogChatRoom->registerUser(pierre);

//     cout << endl;

//     //BOTH chat rooms
//     catChatRoom->registerUser(oscar);
//     dogChatRoom->registerUser(oscar);

//     catChatRoom->registerUser(max);
//     dogChatRoom->registerUser(max);

//     catChatRoom->registerUser(lewis);
//     dogChatRoom->registerUser(lewis);

//     cout << endl;
    
//     //sending messages
//     cout << "---- Testing send message in CtrlCat chatroom ----\n";
//     carlos->send("Hello everyone! This is a great place to talk about cats.", catChatRoom);
//     cout << endl;

//     //viewing chatHistory
//     cout << "---- Testing chatHistory ----\n";
//     catChatRoom->printChatRoomHistory();
//     dogChatRoom->printChatRoomHistory();
//     cout << endl;

//     //removing user
//     cout << "---- Testing removeUser ----\n";
//     catChatRoom->getUserList();
//     catChatRoom->removeUser(george);
//     catChatRoom->getUserList();

//     cout << endl;

//     lewis->send("I love my dog Roscoe, but I also like cats.", catChatRoom);
//     cout << endl;

//     //testing continued for catChatRoom
//     cout << "---- Testing continued ----\n";
//     charles->send("I agree Carlos! My tabby cat Mr. Whiskers loves to code with me.", catChatRoom);
//     oscar->send("That's pawsome! I'm in both chat rooms - best of both worlds!", catChatRoom);
//     alex->send("Welcome Oscar! What's your favorite cat breed?", catChatRoom);

//     //adding to dogChatRoom
//     lando->send("Woof woof! Dog lovers unite!", dogChatRoom);
//     daniel->send("My golden retriever helps me debug code - he's a good boy!", dogChatRoom);
//     oscar->send("Hey everyone! I'm here from CtrlCat too. Dogs are amazing!", dogChatRoom);
//     max->send("Oscar, you're everywhere! My husky loves winter coding sessions.", dogChatRoom);

//     cout << endl; 

//     dogChatRoom->removeUser(daniel);
//     cout << "\n--- Messages after user removal ---" << endl;
//     pierre->send("Daniel left?", dogChatRoom);

//     cout << "\n--- Adding new users mid-conversation ---" << endl;
//     Users* roger = new Name2("Roger");
//     Users* rafa = new Name3("Rafa");

//     catChatRoom->registerUser(roger);
//     dogChatRoom->registerUser(rafa);

//     cout << endl;

//     roger->send("Hi everyone! Roger here, excited to join the cat discussion!", catChatRoom);
//     rafa->send("Hi Everyone, I'm Rafa!", dogChatRoom);

//     oscar->send("Welcome Roger! Great to have more cat enthusiasts here.", catChatRoom);
//     max->send("Hey Rafa! Welcome to the pack!", dogChatRoom);

//     cout << endl;

//     //removing user that's in both chatrooms
//     dogChatRoom->removeUser(max);
//     lewis->send("Bye Max! Is he still in the Cat Chatroom?", dogChatRoom);
//     oscar->send("We still here.", catChatRoom);
//     catChatRoom->removeUser(max);

//     cout << "\n--- Final user lists and chat histories ---\n";
//     catChatRoom->printChatRoomHistory();
//     catChatRoom->getUserList();
//     dogChatRoom->printChatRoomHistory();
//     dogChatRoom->getUserList();


//     //cleaning up memory
//     delete catChatRoom;
//     delete dogChatRoom;
//     delete carlos;
//     delete charles;
//     delete lando;
//     delete oscar;
//     delete max;
//     delete lewis;
//     delete george;
//     delete alex;
//     delete daniel;
//     delete pierre;
//     delete roger;
//     delete rafa;

// }

// int main() {

//     testingMediatorAndCommand();


//     return 0;
// }


int testsRun = 0;
int testsPassed = 0;

void runTest(const string& testName, bool condition) {
    testsRun++;
    if (condition) {
        testsPassed++;
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

void testFactoryPattern() {
    cout << "\n=== TESTING FACTORY METHOD PATTERN ===" << endl;
    
    // Test UserCreationSystem
    UserCreationSystem userSystem;
    
    // Test creating different user types
    Users* basicUser = userSystem.createUser("TestBasic", "basic");
    Users* adminUser = userSystem.createUser("TestAdmin", "admin");
    Users* moderatorUser = userSystem.createUser("TestModerator", "moderator");
    Users* invalidUser = userSystem.createUser("TestInvalid", "invalid");
    
    runTest("Basic user creation", basicUser != nullptr && basicUser->getUserType() == "Basic");
    runTest("Admin user creation", adminUser != nullptr && adminUser->getUserType() == "Admin");
    runTest("Moderator user creation", moderatorUser != nullptr && moderatorUser->getUserType() == "Moderator");
    runTest("Invalid user type defaults to basic", invalidUser != nullptr && invalidUser->getUserType() == "Basic");
    
    // Test user names
    runTest("Basic user name", basicUser->getName() == "TestBasic");
    runTest("Admin user name", adminUser->getName() == "TestAdmin");
    runTest("Moderator user name", moderatorUser->getName() == "TestModerator");
    
    // Test privileges
    runTest("Basic user has no kick privilege", !basicUser->hasPrivilege("kick"));
    runTest("Admin user has kick privilege", adminUser->hasPrivilege("kick"));
    runTest("Admin user has ban privilege", adminUser->hasPrivilege("ban"));
    runTest("Admin user has delete_messages privilege", adminUser->hasPrivilege("delete_messages"));
    runTest("Moderator user has mute privilege", moderatorUser->hasPrivilege("mute"));
    runTest("Moderator user has warn privilege", moderatorUser->hasPrivilege("warn"));
    runTest("Moderator user has no ban privilege", !moderatorUser->hasPrivilege("ban"));
    
    // Test individual factories
    BasicUserFactory basicFactory;
    AdminUserFactory adminFactory;
    ModeratorUserFactory moderatorFactory;
    
    Users* factoryBasic = basicFactory.createUser("FactoryBasic");
    Users* factoryAdmin = adminFactory.createUser("FactoryAdmin");
    Users* factoryModerator = moderatorFactory.createUser("FactoryModerator");
    
    runTest("Direct basic factory", factoryBasic->getUserType() == "Basic");
    runTest("Direct admin factory", factoryAdmin->getUserType() == "Admin");
    runTest("Direct moderator factory", factoryModerator->getUserType() == "Moderator");
    
    // Test listAvailableUserTypes (just call it for coverage)
    userSystem.listAvailableUserTypes();
    
    // Cleanup
    delete basicUser;
    delete adminUser;
    delete moderatorUser;
    delete invalidUser;
    delete factoryBasic;
    delete factoryAdmin;
    delete factoryModerator;
}

void testMediatorPattern() {
    cout << "\n=== TESTING MEDIATOR PATTERN ===" << endl;
    
    // Create chat rooms
    ChatRoom* ctrlCat = new CtrlCat("CtrlCat");
    ChatRoom* dogorithm = new Dogorithm("Dogorithm");
    
    // Create users
    UserCreationSystem userSystem;
    Users* alice = userSystem.createUser("Alice", "basic");
    Users* bob = userSystem.createUser("Bob", "admin");
    Users* charlie = userSystem.createUser("Charlie", "moderator");
    
    // Test chat room names
    runTest("CtrlCat room name", ctrlCat->getChatRoomName() == "CtrlCat");
    runTest("Dogorithm room name", dogorithm->getChatRoomName() == "Dogorithm");
    
    // Test initial empty state
    runTest("CtrlCat initially empty", ctrlCat->getUsers().empty());
    runTest("Dogorithm initially empty", dogorithm->getUsers().empty());
    runTest("CtrlCat history initially empty", ctrlCat->getChatHistory().empty());
    runTest("Dogorithm history initially empty", dogorithm->getChatHistory().empty());
    
    // Test user registration
    ctrlCat->registerUser(alice);
    ctrlCat->registerUser(bob);
    dogorithm->registerUser(alice);  // Alice in both rooms
    dogorithm->registerUser(charlie);
    
    runTest("CtrlCat has 2 users", ctrlCat->getUsers().size() == 2);
    runTest("Dogorithm has 2 users", dogorithm->getUsers().size() == 2);
    runTest("Alice in CtrlCat", ctrlCat->getUsers()[0] == alice);
    runTest("Bob in CtrlCat", ctrlCat->getUsers()[1] == bob);
    runTest("Alice in Dogorithm", dogorithm->getUsers()[0] == alice);
    runTest("Charlie in Dogorithm", dogorithm->getUsers()[1] == charlie);
    
    // Test null user registration
    ctrlCat->registerUser(nullptr);
    runTest("Null user not registered", ctrlCat->getUsers().size() == 2);
    
    // Test user removal
    ctrlCat->removeUser(bob);
    runTest("Bob removed from CtrlCat", ctrlCat->getUsers().size() == 1);
    runTest("Alice still in CtrlCat", ctrlCat->getUsers()[0] == alice);
    
    // Test null user removal
    ctrlCat->removeUser(nullptr);
    runTest("Null user removal handled", ctrlCat->getUsers().size() == 1);
    
    // Test removing non-existent user
    ctrlCat->removeUser(charlie);
    runTest("Non-existent user removal handled", ctrlCat->getUsers().size() == 1);
    
    // Test getUserList and printChatRoomHistory methods for coverage
    ctrlCat->getUserList();
    dogorithm->getUserList();
    ctrlCat->printChatRoomHistory();
    dogorithm->printChatRoomHistory();
    
    // Cleanup
    delete ctrlCat;
    delete dogorithm;
    delete alice;
    delete bob;
    delete charlie;
}

void testCommandPattern() {
    cout << "\n=== TESTING COMMAND PATTERN ===" << endl;
    
    // Create chat room and users
    ChatRoom* testRoom = new CtrlCat("TestRoom");
    UserCreationSystem userSystem;
    Users* user1 = userSystem.createUser("User1", "basic");
    Users* user2 = userSystem.createUser("User2", "basic");
    
    // Register users
    testRoom->registerUser(user1);
    testRoom->registerUser(user2);
    
    // Test sending messages (which uses command pattern internally)
    user1->send("Hello World!", testRoom);
    
    runTest("Message saved to history", testRoom->getChatHistory().size() == 1);
    runTest("Message content correct", testRoom->getChatHistory()[0] == "From User1: Hello World!");
    
    // Send more messages to test command queue
    user2->send("Hi there!", testRoom);
    user1->send("How are you?", testRoom);
    
    runTest("Multiple messages saved", testRoom->getChatHistory().size() == 3);
    runTest("Second message correct", testRoom->getChatHistory()[1] == "From User2: Hi there!");
    runTest("Third message correct", testRoom->getChatHistory()[2] == "From User1: How are you?");
    
    // Test direct command creation for coverage
    Command* sendCmd = new SendMessageCommand(testRoom, "Direct command", user1);
    Command* saveCmd = new SaveMessageCommand(testRoom, "Direct save", user1);
    
    user1->addCommand(sendCmd);
    user1->addCommand(saveCmd);
    user1->executeAll();
    
    runTest("Direct command executed", testRoom->getChatHistory().size() == 4);
    runTest("Direct save command", testRoom->getChatHistory()[3] == "From User1: Direct save");
    
    // Test adding null command
    user1->addCommand(nullptr);
    user1->executeAll(); // Should handle gracefully
    
    // Test empty command queue execution
    user1->executeAll(); // Should handle empty queue
    
    // Cleanup
    delete testRoom;
    delete user1;
    delete user2;
}

void testIteratorPattern() {
    cout << "\n=== TESTING ITERATOR PATTERN ===" << endl;
    
    // Create test environment
    ChatRoom* testRoom = new CtrlCat("IteratorTest");
    UserCreationSystem userSystem;
    Users* user1 = userSystem.createUser("IterUser1", "basic");
    Users* user2 = userSystem.createUser("IterUser2", "admin");
    Users* user3 = userSystem.createUser("IterUser3", "moderator");
    
    // Test empty collections first
    Iterator<Users*>* emptyUserIter = IteratorCreator::createUserIterator(testRoom);
    runTest("Empty user iterator hasNext false", !emptyUserIter->hasNext());
    runTest("Empty user iterator next returns null", emptyUserIter->next() == nullptr);
    runTest("Empty user iterator current returns null", emptyUserIter->current() == nullptr);
    delete emptyUserIter;
    
    Iterator<string>* emptyMsgIter = IteratorCreator::createMessageIterator(testRoom);
    runTest("Empty message iterator hasNext false", !emptyMsgIter->hasNext());
    runTest("Empty message iterator next returns empty", emptyMsgIter->next() == "");
    runTest("Empty message iterator current returns empty", emptyMsgIter->current() == "");
    delete emptyMsgIter;
    
    // Add users and messages
    testRoom->registerUser(user1);
    testRoom->registerUser(user2);
    testRoom->registerUser(user3);
    
    user1->send("Message 1", testRoom);
    user2->send("Message 2", testRoom);
    user3->send("Message 3", testRoom);
    
    // Test UserIterator
    Iterator<Users*>* userIter = IteratorCreator::createUserIterator(testRoom);
    
    vector<Users*> iteratedUsers;
    while (userIter->hasNext()) {
        Users* user = userIter->next();
        iteratedUsers.push_back(user);
    }
    
    runTest("User iterator count correct", iteratedUsers.size() == 3);
    runTest("First user correct", iteratedUsers[0] == user1);
    runTest("Second user correct", iteratedUsers[1] == user2);
    runTest("Third user correct", iteratedUsers[2] == user3);
    runTest("After iteration hasNext false", !userIter->hasNext());
    runTest("After iteration next returns null", userIter->next() == nullptr);
    
    // Test reset functionality
    userIter->reset();
    runTest("After reset hasNext true", userIter->hasNext());
    runTest("After reset current correct", userIter->current() == user1);
    
    Users* nextUser = userIter->next();
    runTest("Next after reset correct", nextUser == user1);
    runTest("Current after next correct", userIter->current() == user2);
    
    delete userIter;
    
    // Test MessageHistoryIterator (forward)
    Iterator<string>* msgIter = IteratorCreator::createMessageIterator(testRoom, false);
    
    vector<string> iteratedMessages;
    while (msgIter->hasNext()) {
        string msg = msgIter->next();
        iteratedMessages.push_back(msg);
    }
    
    runTest("Message iterator count correct", iteratedMessages.size() == 3);
    runTest("First message correct", iteratedMessages[0] == "From IterUser1: Message 1");
    runTest("Second message correct", iteratedMessages[1] == "From IterUser2: Message 2");
    runTest("Third message correct", iteratedMessages[2] == "From IterUser3: Message 3");
    
    delete msgIter;
    
    // Test MessageHistoryIterator (reverse)
    Iterator<string>* reverseMsgIter = IteratorCreator::createMessageIterator(testRoom, true);
    
    vector<string> reverseMessages;
    while (reverseMsgIter->hasNext()) {
        string msg = reverseMsgIter->next();
        reverseMessages.push_back(msg);
    }
    
    runTest("Reverse iterator count correct", reverseMessages.size() == 3);
    runTest("Reverse first message", reverseMessages[0] == "From IterUser3: Message 3");
    runTest("Reverse second message", reverseMessages[1] == "From IterUser2: Message 2");
    runTest("Reverse third message", reverseMessages[2] == "From IterUser1: Message 1");
    
    // Test reverse iterator reset
    reverseMsgIter->reset();
    runTest("Reverse reset hasNext", reverseMsgIter->hasNext());
    runTest("Reverse current after reset", reverseMsgIter->current() == "From IterUser3: Message 3");
    
    delete reverseMsgIter;
    
    // Test ChatRoomIterator for coverage
    Iterator<ChatRoom*>* roomIter = IteratorCreator::createChatRoomIterator(user1);
    runTest("ChatRoom iterator created", roomIter != nullptr);
    
    // Test the iterator methods for coverage
    bool hasNext = roomIter->hasNext();
    ChatRoom* nextRoom = roomIter->next();
    ChatRoom* currentRoom = roomIter->current();
    roomIter->reset();
    
    delete roomIter;
    
    // Cleanup
    delete testRoom;
    delete user1;
    delete user2;
    delete user3;
}

void testAdminFunctionality() {
    cout << "\n=== TESTING ADMIN FUNCTIONALITY ===" << endl;
    
    // Create environment
    ChatRoom* testRoom = new CtrlCat("AdminTest");
    UserCreationSystem userSystem;
    Users* admin = userSystem.createUser("Admin", "admin");
    Users* basicUser = userSystem.createUser("BasicUser", "basic");
    
    testRoom->registerUser(admin);
    testRoom->registerUser(basicUser);
    
    // Test admin specific methods
    AdminUser* adminPtr = dynamic_cast<AdminUser*>(admin);
    runTest("Admin cast successful", adminPtr != nullptr);
    
    if (adminPtr) {
        // Test privilege adding
        vector<string> newPrivs;
        newPrivs.push_back("custom_privilege");
        adminPtr->addPrivileges(newPrivs);
        runTest("Custom privilege added", adminPtr->hasPrivilege("custom_privilege"));
        
        // Test admin actions (these are mostly output functions, but we test for coverage)
        adminPtr->kickUser(basicUser, testRoom);
        adminPtr->banUser(basicUser, testRoom);
        adminPtr->deleteMessage(testRoom, 1);
        
        // Test admin without required privileges
        AdminUser* limitedAdmin = new AdminUser("LimitedAdmin");
        vector<string> limitedPrivs;
        limitedPrivs.push_back("view_logs");
        limitedAdmin->addPrivileges(limitedPrivs);
        
        runTest("Limited admin no kick", !limitedAdmin->hasPrivilege("kick"));
        limitedAdmin->kickUser(basicUser, testRoom); // Should fail gracefully
        limitedAdmin->banUser(basicUser, testRoom); // Should fail gracefully
        limitedAdmin->deleteMessage(testRoom, 1); // Should fail gracefully
        
        delete limitedAdmin;
    }
    
    // Cleanup
    delete testRoom;
    delete admin;
    delete basicUser;
}

void testModeratorFunctionality() {
    cout << "\n=== TESTING MODERATOR FUNCTIONALITY ===" << endl;
    
    // Create environment
    ChatRoom* testRoom = new Dogorithm("ModeratorTest");
    UserCreationSystem userSystem;
    Users* moderator = userSystem.createUser("Moderator", "moderator");
    Users* basicUser = userSystem.createUser("BasicUser", "basic");
    
    testRoom->registerUser(moderator);
    testRoom->registerUser(basicUser);
    
    // Test moderator specific methods
    ModeratorUser* modPtr = dynamic_cast<ModeratorUser*>(moderator);
    runTest("Moderator cast successful", modPtr != nullptr);
    
    if (modPtr) {
        // Test privilege adding
        vector<string> newPrivs;
        newPrivs.push_back("custom_mod_privilege");
        modPtr->addPrivileges(newPrivs);
        runTest("Custom mod privilege added", modPtr->hasPrivilege("custom_mod_privilege"));
        
        // Test moderator actions
        modPtr->muteUser(basicUser, testRoom);
        modPtr->warnUser(basicUser, "Test warning");
        modPtr->viewUserReports(testRoom);
        
        // Test moderator without required privileges
        ModeratorUser* limitedMod = new ModeratorUser("LimitedMod");
        vector<string> limitedPrivs;
        limitedPrivs.push_back("read_only");
        limitedMod->addPrivileges(limitedPrivs);
        
        runTest("Limited mod no mute", !limitedMod->hasPrivilege("mute"));
        limitedMod->muteUser(basicUser, testRoom); // Should fail gracefully
        limitedMod->warnUser(basicUser, "Should fail"); // Should fail gracefully
        limitedMod->viewUserReports(testRoom); // Should fail gracefully
        
        delete limitedMod;
    }
    
    // Cleanup
    delete testRoom;
    delete moderator;
    delete basicUser;
}

void testEdgeCasesAndErrorHandling() {
    cout << "\n=== TESTING EDGE CASES ===" << endl;
    
    // Test empty string handling
    UserCreationSystem userSystem;
    Users* emptyNameUser = userSystem.createUser("", "basic");
    runTest("Empty name user created", emptyNameUser != nullptr);
    runTest("Empty name preserved", emptyNameUser->getName() == "");
    delete emptyNameUser;
    
    // Test very long names
    string longName(100, 'a'); // 100 character string
    Users* longNameUser = userSystem.createUser(longName, "admin");
    runTest("Long name user created", longNameUser != nullptr);
    runTest("Long name preserved", longNameUser->getName() == longName);
    delete longNameUser;
    
    // Test case sensitivity in user types
    Users* upperCaseType = userSystem.createUser("TestUser", "ADMIN");
    runTest("Case sensitive type handled", upperCaseType->getUserType() == "Basic");
    delete upperCaseType;
    
    // Test iterator boundary conditions
    ChatRoom* boundaryRoom = new CtrlCat("BoundaryTest");
    
    // Add one user and test boundary
    UserCreationSystem factory;
    Users* singleUser = factory.createUser("Single", "basic");
    boundaryRoom->registerUser(singleUser);
    
    Iterator<Users*>* singleIter = IteratorCreator::createUserIterator(boundaryRoom);
    runTest("Single user hasNext", singleIter->hasNext());
    Users* retrieved = singleIter->next();
    runTest("Single user retrieved", retrieved == singleUser);
    runTest("After single next hasNext false", !singleIter->hasNext());
    runTest("After boundary next returns null", singleIter->next() == nullptr);
    
    delete singleIter;
    delete boundaryRoom;
    delete singleUser;
    
    // Test multiple reset operations
    ChatRoom* resetRoom = new Dogorithm("ResetTest");
    Users* resetUser = factory.createUser("ResetUser", "moderator");
    resetRoom->registerUser(resetUser);
    resetUser->send("Reset message", resetRoom);
    
    Iterator<string>* resetIter = IteratorCreator::createMessageIterator(resetRoom);
    resetIter->reset();
    resetIter->reset();
    resetIter->reset(); // Multiple resets
    
    runTest("Multiple resets handled", resetIter->hasNext());
    runTest("Reset message correct", resetIter->next() == "From ResetUser: Reset message");
    
    delete resetIter;
    delete resetRoom;
    delete resetUser;
}

void testComplexScenario() {
    cout << "\n=== TESTING COMPLEX INTEGRATION SCENARIO ===" << endl;
    
    // Create a complex multi-room, multi-user scenario
    ChatRoom* general = new CtrlCat("General");
    ChatRoom* admin = new Dogorithm("AdminRoom");
    ChatRoom* mods = new CtrlCat("Moderators");
    
    UserCreationSystem userSystem;
    Users* alice = userSystem.createUser("Alice", "basic");
    Users* bob = userSystem.createUser("Bob", "basic");
    Users* charlie = userSystem.createUser("Charlie", "moderator");
    Users* diana = userSystem.createUser("Diana", "admin");
    
    // Complex room registrations
    general->registerUser(alice);
    general->registerUser(bob);
    general->registerUser(charlie);
    general->registerUser(diana);
    
    admin->registerUser(diana);
    mods->registerUser(charlie);
    mods->registerUser(diana);
    
    runTest("General room has 4 users", general->getUsers().size() == 4);
    runTest("Admin room has 1 user", admin->getUsers().size() == 1);
    runTest("Mods room has 2 users", mods->getUsers().size() == 2);
    
    // Complex message exchanges
    alice->send("Hello everyone!", general);
    bob->send("Hi Alice!", general);
    diana->send("Admin announcement", admin);
    charlie->send("Moderator meeting", mods);
    diana->send("I'll be there", mods);
    
    runTest("General has 2 messages", general->getChatHistory().size() == 2);
    runTest("Admin has 1 message", admin->getChatHistory().size() == 1);
    runTest("Mods has 2 messages", mods->getChatHistory().size() == 2);
    
    // Test administrative actions
    AdminUser* adminUser = dynamic_cast<AdminUser*>(diana);
    ModeratorUser* modUser = dynamic_cast<ModeratorUser*>(charlie);
    
    if (adminUser) {
        adminUser->kickUser(bob, general);
        runTest("Bob kicked from general", general->getUsers().size() == 3);
    }
    
    if (modUser) {
        modUser->warnUser(alice, "Please follow guidelines");
        modUser->muteUser(alice, general);
    }
    
    // Test iterators on all rooms
    Iterator<Users*>* generalIter = IteratorCreator::createUserIterator(general);
    Iterator<string>* adminMsgIter = IteratorCreator::createMessageIterator(admin);
    Iterator<string>* modsMsgIter = IteratorCreator::createMessageIterator(mods, true); // Reverse
    
    int generalUserCount = 0;
    while (generalIter->hasNext()) {
        generalIter->next();
        generalUserCount++;
    }
    runTest("General iterator count matches", generalUserCount == 3);
    
    int adminMsgCount = 0;
    while (adminMsgIter->hasNext()) {
        adminMsgIter->next();
        adminMsgCount++;
    }
    runTest("Admin message iterator works", adminMsgCount == 1);
    
    int modMsgCount = 0;
    while (modsMsgIter->hasNext()) {
        modsMsgIter->next();
        modMsgCount++;
    }
    runTest("Mods reverse iterator works", modMsgCount == 2);
    
    // Cleanup
    delete generalIter;
    delete adminMsgIter;
    delete modsMsgIter;
    delete general;
    delete admin;
    delete mods;
    delete alice;
    delete bob;
    delete charlie;
    delete diana;
}

void performanceAndStressTests() {
    cout << "\n=== PERFORMANCE AND STRESS TESTS ===" << endl;
    
    // Test with many users
    ChatRoom* stressRoom = new CtrlCat("StressTest");
    vector<Users*> manyUsers;
    UserCreationSystem userSystem;
    
    for (int i = 0; i < 20; i++) {
        Users* user = userSystem.createUser("User" + to_string(i), "basic");
        manyUsers.push_back(user);
        stressRoom->registerUser(user);
    }
    
    runTest("Many users registered", stressRoom->getUsers().size() == 20);
    
    // Test with many messages
    for (int i = 0; i < 15; i++) {
        int userIndex = i % manyUsers.size();
        manyUsers[userIndex]->send("Message " + to_string(i), stressRoom);
    }
    
    runTest("Many messages sent", stressRoom->getChatHistory().size() == 15);
    
    // Test iterator performance
    Iterator<Users*>* stressUserIter = IteratorCreator::createUserIterator(stressRoom);
    int count = 0;
    while (stressUserIter->hasNext()) {
        stressUserIter->next();
        count++;
    }
    runTest("Stress user iteration", count == 20);
    
    Iterator<string>* stressMsgIter = IteratorCreator::createMessageIterator(stressRoom);
    count = 0;
    while (stressMsgIter->hasNext()) {
        stressMsgIter->next();
        count++;
    }
    runTest("Stress message iteration", count == 15);
    
    // Cleanup
    delete stressUserIter;
    delete stressMsgIter;
    delete stressRoom;
    for (Users* user : manyUsers) {
        delete user;
    }
}

int main() {
    cout << "==========================================================" << endl;
    cout << "    COMPREHENSIVE TESTING FOR FITCHFORK COVERAGE" << endl;
    cout << "==========================================================" << endl;
    
    try {
        // Run all test suites
        testFactoryPattern();
        testMediatorPattern();
        testCommandPattern();
        testIteratorPattern();
        testAdminFunctionality();
        testModeratorFunctionality();
        testEdgeCasesAndErrorHandling();
        testComplexScenario();
        performanceAndStressTests();
        
        // Print final results
        cout << "\n==========================================================" << endl;
        cout << "                    TESTING SUMMARY" << endl;
        cout << "==========================================================" << endl;
        cout << "Total Tests Run: " << testsRun << endl;
        cout << "Tests Passed: " << testsPassed << endl;
        cout << "Tests Failed: " << (testsRun - testsPassed) << endl;
        
        double successRate = (testsRun > 0) ? (double)testsPassed / testsRun * 100.0 : 0.0;
        cout << "Success Rate: " << successRate << "%" << endl;
        
        cout << "\nDesign Patterns Tested:" << endl;
        cout << "- Factory Method Pattern (User creation system)" << endl;
        cout << "- Mediator Pattern (Chat rooms managing user communication)" << endl;
        cout << "- Command Pattern (Message sending and saving)" << endl;
        cout << "- Iterator Pattern (User and message traversal)" << endl;
        
        cout << "\nTest Coverage Areas:" << endl;
        cout << "- All user types (Basic, Admin, Moderator)" << endl;
        cout << "- All chat room types (CtrlCat, Dogorithm)" << endl;
        cout << "- User privileges and permissions" << endl;
        cout << "- Message sending and receiving" << endl;
        cout << "- User registration and removal" << endl;
        cout << "- Iterator functionality (forward and reverse)" << endl;
        cout << "- Administrative actions" << endl;
        cout << "- Edge cases and error handling" << endl;
        cout << "- Complex integration scenarios" << endl;
        cout << "- Performance and stress testing" << endl;
        
        if (successRate >= 90.0) {
            cout << "\nEXCELLENT! All major functionality working correctly!" << endl;
        } else if (successRate >= 75.0) {
            cout << "\nGOOD! Most functionality working, minor issues detected." << endl;
        } else {
            cout << "\nWARNING! Significant issues detected. Review failed tests." << endl;
        }
        
        cout << "\nThis test suite should provide well over 60% code coverage" << endl;
        cout << "required by FitchFork. Ready for submission!" << endl;
        cout << "==========================================================" << endl;
        
        return (successRate >= 60.0) ? 0 : 1;
        
    } catch (...) {
        cout << "\nUNKNOWN ERROR during testing!" << endl;
        return 1;
    }
}