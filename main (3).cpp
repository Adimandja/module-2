/* Program name: RPG Characters
* Author: Adolphe Dimandja
* Date last updated: 7/27/2024
* Purpose: Demonstrate the functionality of the RPG characters and their special abilities.
*/

#include <iostream>
#include "character.h"

using namespace std;

int main() {
    // Create characters
    string name;
    
    cout << "What is your fighter's name: ";
    getline(cin, name);
    Fighter fighter(name);

    cout << "What is your rogue's name: ";
    getline(cin, name);
    Rogue rogue(name);

    cout << "What is your magician's name: ";
    getline(cin, name);
    Magician magician(name);

    cout << "What is your cleric's name: ";
    getline(cin, name);
    Cleric cleric(name);

    // Display starting stats
    cout << "\nTesting Fighter Starting Stats\n" << fighter.toString();
    cout << "\nTesting Rogue Starting Stats\n" << rogue.toString();
    cout << "\nTesting Magician Starting Stats\n" << magician.toString();
    cout << "\nTesting Cleric Starting Stats\n" << cleric.toString();

    // Demonstrate special abilities
    cout << "\n" << fighter.getName() << " Strong Attack " << rogue.getName() << "\n";
    fighter.specialAbility(rogue);
    cout << "\nUpdated Rogue Stats\n" << rogue.toString();

    cout << "\n" << rogue.getName() << " Steal " << fighter.getName() << "\n";
    rogue.specialAbility(fighter);
    cout << "\nUpdated Rogue Stats\n" << rogue.toString();
    cout << "\nUpdated Fighter Stats\n" << fighter.toString();

    cout << "\n" << magician.getName() << " Cast " << rogue.getName() << "\n";
    magician.specialAbility(rogue);
    cout << "\nUpdated Magician Stats\n" << magician.toString();
    cout << "\nUpdated Rogue Stats\n" << rogue.toString();

    cout << "\n" << cleric.getName() << " Heal " << rogue.getName() << "\n";
    cleric.specialAbility(rogue);
    cout << "\nUpdated Cleric Stats\n" << cleric.toString();
    cout << "\nUpdated Rogue Stats\n" << rogue.toString();

    return 0;
}
