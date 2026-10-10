#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>



class Character {
    protected:
    std::string name;
    int health;
    int level;
    int attackPower;
    srand(time(0));
    
   
    public:

    // Use for generating special ability choices
    int RNG = rand() % 3 + 1;

    enum characterType
    {
        Warrior,
        Mage,
        Archer
    };

    characterType type;
   

    Character()
    {
        name = "Bot";
        level = 0;
        health = 400;
        attackPower = 50;
        type = characterType::Warrior;
    }

    Character(std::string name)
    {
        this->name = name;
        level = 0;
        health = 400;
        attackPower = 50;
        type = characterType::Warrior;
    }


    Character(std::string name, int health, int attackPower, characterType type)
    {
        this->name = name;
        this->health = health;
        this->type = type;
        this->attackPower = attackPower;
        level = 0;
    }


    // ----- At the moment we are not going to allow our player to change the character type they create -----
    // void setCharacterType(characterType type)
    // {
    //   this->type = type;
    // }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setHealth(int health)
    {
        this->health = health;
    }

    void setLevel(int level)
    {
        this->level = level;
    }

    void setAttackPower(int attackPower)
    {
        this->attackPower = attackPower;
    }

    std::string getName()
    {
        return name;
    }

    int getHealth()
    {
        return health;
    }

    int getLevel()
    {
        return level;
    }

    int getAttackPower()
    {
        return attackPower;
    }

   std::string getTypeName(characterType type){
        switch(type){
            case characterType::Warrior:
                return "Warrior";

            case characterType::Mage:
                return "Mage";

            case characterType::Archer:
                return "Archer";
        }
        return "Unknown";
   }

    // **** Virtual helps with overriding the function since it will derived several times ****
    virtual void displayPlayerInfo()
    {
        std::cout << "Name: " << name << '\n';
        std::cout << "Lvl: " << level << '\n';
        std::cout << "Hp: " << health << '\n';
        std::cout << "Attack: " << attackPower << '\n';
        std::cout << "Type: " << getTypeName(type) << '\n';
    }

    // **** Create a function to attack ****
    // Function to delete allocated memory
    virtual ~Character() = default;

};

class Warrior : public Character{
    private:

    bool dualWield = false;
    int armor;
    enum Weapons
    {
        Scythe,
        Katana,
        Staff,
        Light_Saber
    };
    Weapons weapon;

    public:

    Warrior()
    {
        weapon = Weapons::Katana;
        armor = 150;
        Character::setHealth(500);
    }

    Warrior(std::string name)
    {
        Character::name = name;
        weapon = Weapons::Katana;
        armor = 150;
        Character::setHealth(500);
    }
    

    Warrior(std::string name, int health, int armor, Weapons weapon, char dualWield)
    {
        Character::setName(name);
        Character::setHealth(health);
        this->weapon = weapon;
        this->armor = armor;
        if(dualWield == 'Y')
            {
            dualWield == true;
            castDualWield();
            }
       
    }

    void setArmor(int armor)
    {
        this->armor = armor;
    }

    int getArmor()
    {
        return armor;
    }

    void setWeaponType(std::string weaponSelected)
    {
        if(weaponSelected == "Scythe")
        {
            weapon = Weapons::Scythe;
        }
        else if(weaponSelected == "Katana")
        {
            weapon = Weapons::Katana;
        }
        else if(weaponSelected == "Staff")
        {
            weapon = Weapons::Staff;
        }
        else if(weaponSelected == "Light Saber")
        {
            weapon = Weapons::Light_Saber;
        }

    }


    std::string getWeapon(Weapons weapon)
    {
        switch(weapon)
        {
            case Weapons::Scythe:
                return "Scythe";

            case Weapons::Katana:
                return "Katana";

            case Weapons::Staff:
                return "Staff";

            case Weapons::Light_Saber:
                return "Light Saber";

            
        }
    }

    void castDualWield()
    {
        std::cout << " Your special ability: Dual Wield is Active" << '\n';
        std::cout << " Boost Applied: { Attack +100, Health +300, Armor +300 } " << '\n';   
        int attackUp = Character.getAttackPower() + 100;
        int armorUp = Character.getArmor() + 300;
        int healthUp = Character.getHealth() + 300;

        Character.setAttackPower(attackUp);
        Character.setArmor(armorUp);
        Character.setHealth(healthUp);
    }

    
    void displayPlayerInfo() override
    {
        Character::displayPlayerInfo();
        std::cout << "Armor: " << armor << '\n';
        std::cout << "Weapon: " << Warrior::getWeapon(weapon) << '\n';
    }

};

class Mage : public Character{

private:

int magicLvl;
int summonLvl;
bool summonActivated = false;

public:

enum Magic {Fire, Earth, Water, Wind};
enum CreatureSummoned {Dragon, Bear, Dinosaur, Megladon};


Magic magicType;
CreatureSummoned creature;

    Mage()
    {
        Mage::setHealth(200);
        Mage::setAttack(200);
        magicLvl = 20;
        summonLvl = 10;
        magicType = Magic::Fire;
    }

    Mage(std::string name)
    {
        Mage::setName(name)
        Mage::setHealth(10);
        magicLvl = 20;
        summonLvl = 10;
        magicType = Magic::Fire;
    }




    Mage(std::string name, int magicLvl, int summonLvl, Magic magicType, char summonsActivated)
    {
        Character::setName(name);
        this->magicLvl = magicLvl;
        this->summonLvl = summonLvl;
        this->magicType = magicType;
        if(summonsActivated == 'Y')
        {
            specialSummon();
        }
    }

    void setMagicLvl(int magicLvl)
    {
        this->magicLvl = magicLvl;
    }

    void setSummonLvl(int summonLvl)
    {
        this->summonLvl = summonLvl;
    }

    int getMagicLvl()
    {
        return magicLvl;
    }

    int getSummonLvl()
    {
        return summonLvl;
    }

    std::string getMagicType(Magic type)
    {
        switch(type)
        {
            case Magic::Earth:
                return "Earth";
        
            case Magic::Fire:
                return "Fire";

            case Magic::Water:
                return "Water";

            case Magic::Wind:
                return "Wind";
        }
        return "Unknown";
    }


    // 10/08/26
    // *** Make the getMagicType to not accept a parameter ***
    // replace the switch or fix logic in this function too
    // adjust summonLvl to creature summoned

    void setMagicType(Magic magicType)
    {
        switch(magicType)
        {
            case Magic::Fire:
                this->magicType = Magic::Fire;
                break;
            case Magic::Earth:
                this->magicType = Magic::Earth;
                break;
            case Magic::Water:
                this->magicType = Magic::Water;
                break;
            case Magic::Wind:
                this->magicType = Magic::Wind;
                break;
        }
    }


    void displayPlayerInfo() override
    {
        Character::displayPlayerInfo();
        std::cout << "Magic Lvl: " << Mage::getMagicLvl() << '\n';
        std::cout << "Summon Lvl " << Mage::getSummonLvl() << '\n';
        std::cout << "Magic Type" << Mage::getMagicType(magicType) << '\n';

    }

    void specialSummon()
    {
        std::cout << " Your special summon has been activated " << '\n';
        swtich(Character.RNG)
        {
            case 1:
                creature = Dragon;
                break;
            case 2:
                creature = Bear;
                break;
            case 3:
                creature = Dinosaur;
                break;
            case 4:
                creature = Megladon;
                 break;
        }           
    }
};


/*
10/08/26
Archer class changes:
1. look into special ability
2. use the RNG to set arrow type
3. combine all 3 character types to be able to attack 
4. Check to make sure your getBow and getArrows takes no paramters

**/
class Archer : public Character{
private:

int rangedAttack;


public:

enum Arrows {Wolf, Lightning, Fire, Underworld};
enum Bows {Legendary, Enchanted, Regular};
Arrows arrowType;
Bows bowType;

Archer()
{
    Character::setHealth(60);
    Character::setAttackPower(60);
    rangedAttack = 100;
    arrowType = Arrows::Fire;
    bowType = Bows::Regular;
}

Archer(std::string name)
{
    Character::name = name;
    Character::setHealth(60);
    Character::setAttackPower(60);
    rangedAttack = 100;
    arrowType = Arrows::Fire;
    bowType = Bows::Regular;
}

Archer(int rangedAttack, Bows bowType, Arrows arrowType)
{
    this->rangedAttack = rangedAttack;
    this->bowType = bowType;
    this->arrowType = arrowType;
}

void setRangeDamage(int rangedAttack)
{
    this->rangedAttack = rangedAttack;
}

int getRangeDamage()
{
    return rangedAttack;
}

void setBowType(Bows bowType){
    switch(bowType)
    {
        case Bows::Legendary:
        this->bowType = bowType;
        break;

        case Bows::Enchanted:
        this->bowType = bowType;
        break;

        case Bows::Regular:
        this->bowType = bowType;
        break;
    }
}

std::string getBowType(Bows bowType)
{
    switch(bowType)
    {
        case Bows::Legendary:
            return "Legendary";

        case Bows::Enchanted:
            return "Enchanted";

        case Bows::Regular:
            return "Regular";
    }
    return "Unknown";
}

void setArrowType(Arrows arrowType)
{
    switch(arrowType)
    {
        case Arrows::Fire:
        this->arrowType = arrowType;
        break;

        case Arrows::Lightning:
        this->arrowType = arrowType;
        break;

        case Arrows::Underworld:
        this->arrowType = arrowType;
        break;

        case Arrows::Wolf:
        this->arrowType = arrowType;
        break;
    }
}

std::string getArrowType(Arrows arrowType)
{
    switch(arrowType)
    {
        case Arrows::Fire:
            return "Fire";

        case Arrows::Lightning:
            return "Lightning";

        case Arrows::Underworld:
            return "Underworld";

        case Arrows::Wolf:
            return "Wolf";
    }
}


void displayPlayerInfo() override
{
    Character::displayPlayerInfo();
    std::cout << "Ranged Attack: " << rangedAttack << '\n';
    std::cout << "Bow Type: " << Archer::getBowType(bowType) << '\n';
    std::cout << "Arrow Type: " << Archer::getArrowType(arrowType) << '\n';
}
};





// 10/08/26 
// Functions I want to add:
// 1 - Simulate an attack chain (use recursion)  *
// 2 - Display character statistics (check to see if already done)
// 3 - Combine the Battle system with the first function *
void buildCharacter(std::vector<Character*>& createdCharacters, std::string typeOfCharacter);
Character* searchCharacter(std::vector<Character*>& createdCharacters, std::string selectedCharacter);
void modifyCharacter(std::vector<Character*>& createdCharacters);
void printMenu();

std::string battleSim(std::vector<Character*>& createdCharacters);
void displayAllCharacters(std::vector<Character*> createdCharacters);




int main(){
    
    std::vector<Character*> createdCharacters;

    printMenu();

    


    return 0;
}


void buildCharacter(std::vector<Character*>& createdCharacters, std::string chosenCharacter)
{
    std::string nameForNewCharacter;
    std::cout << "Choose a name for you new Character " << '\n';
    getline(std::cin>>std::ws, nameForNewCharacter);



    if(chosenCharacter == "Warrior")
        createdCharacters.push_back(new Warrior(nameForNewCharacter));
    else if(chosenCharacter == "Mage")
        createdCharacters.push_back(new Mage(nameForNewCharacter));
    else if(chosenCharacter == "Archer")
        createdCharacters.push_back(new Archer(nameForNewCharacter));
}

 Character* searchCharacter(std::vector<Character*>& createdCharacters, std::string characterName)
{
    
    for(auto itr = createdCharacters.begin(); itr != createdCharacters.end(); ++itr)
    {
        Character* temp = *itr;
        if(characterName == temp->getName())
            {
                return *itr;
            }
    }
    std::cout << " **** ERROR **** " << characterName << " NOT FOUND " << '\n';
    return nullptr;
}

void modifyCharacter(std::vector<Character*>& createdCharacters)
{
    std::string name;
    std::string change, newName, newType, newWeapon, newArrow, newMagic;
    std::string response;

    std::cout << "Enter the name of Character you would like to edit " << '\n';
    getline(std::cin, name);


    Character* temp = searchCharacter(createdCharacters, name);

    // ---- Checking to see if the character was found -----
    if(temp == nullptr)
        {
            std::cout << "Character: " << name << " was NOT found " << '\n';
        }


    do
    {
        std::cout << "What would you like to modify" << '\n';
        std::cout << " ***** CHANGES THAT CAN BE MADE ******" << '\n';

        std::cout << "1 -> Name " << '\n';
        // std::cout << "2. Type " << '\n';
        std::cout << " ***************************************** " << '\n';

        std::cout << "------ Character Type Specific Changes ------ " << '\n';
        std::cout << "| Warrior | " << std::endl;
        std::cout << "2 -> Weapon Type: [Scythe, Katana, Staff, Light Saber] " << '\n\n';

        std::cout << "| Mage | " << '\n';
        std::cout << "3 -> Magic Type: [Fire, Earth, Water, Wind] " << '\n\n';
        
        std::cout << "| Archer | " << '\n';
        std::cout << "4 -> Arrow Type: [Fire, Wolf, Lightning, Underworld] " << '\n';

        getline(std::cin>>std::ws, change);

        if(change == "name" || change == "Name")
            {
                std::cout << "What would you like to change your characters name to?" << '\n';
                getline(std::cin>>std::ws, newName);
                if(!newName.empty())
                   temp->setName(newName);
                else    
                    std::cout << "You did not enter anything " << '\n';

            }
        // else if(change == "Type" || change == "type")
        // {
        //     std::cout << "What type of character would you like to change to? [Warrior, Mage, Archer] " << '\n';
        //     getline(std::cin>>std::ws, newType);
            
        //     if(newType == "Warrior" || newType == "warrior")
        //     {
        //         temp->setCharacterType(Character::Warrior);

        //     }
        //     else if(newType == "Mage" || newType == "mage")
        //     {
        //         temp->setCharacterType(Character::Mage);
        //     }
        //     else if(newType == "Archer" || newType == "archer")
        //     {
        //         temp->setCharacterType(Character::Archer);
        //     }
        //}
        else if(change == "Weapon" || change == "weapon")
        {
            // ---- Making sure the Character is actually a warrior before editting -----

            Warrior* warriorTemp = dynamic_cast<Warrior*>(temp);
            if(warriorTemp != nullptr)
            {
                std::cout << "What weapon would you like to change to [Scythe, Katana, Staff, Light Saber]" << '\n';
                getline(std::cin>>std::ws, newWeapon);
                
                if (newWeapon == "Scythe" || newWeapon == "scythe")
                {
                    warriorTemp->setWeaponType(newWeapon);
                }
                else if(newWeapon == "Katana" || newWeapon == "katana")
                {
                    warriorTemp->setWeaponType(newWeapon);
                }
                else if(newWeapon == "Staff"|| newWeapon == "staff")
                {
                    warriorTemp->setWeaponType(newWeapon);
                }
                else if(newWeapon == "Light Saber" || newWeapon == "light saber")
                {
                    warriorTemp->setWeaponType(newWeapon);
                }
            }
            else
                 std::cout << "A null pointer was returned " << '\n';
        }
        else if(change == "Magic" || change == "magic")
        {
            Mage* mageTemp = dynamic_cast<Mage*>(temp);
            if(mageTemp != nullptr)
                {
                    std::cout << "What Magic would you like to switch to? " << '\n';
                    getline(std::cin>>std::ws, newMagic);

                    if(newMagic == "Fire" || newMagic == "fire")
                        {
                            mageTemp->setMagicType(Mage::Magic::Fire);
                        }
                    else if(newMagic == "Water" || newMagic == "water")
                        {
                            mageTemp->setMagicType(Mage::Magic::Water);
                        }
                    else if(newMagic == "Earth" || newMagic == "earth")
                        {
                            mageTemp->setMagicType(Mage::Magic::Earth);
                        }
                    else if(newMagic == "Wind" || newMagic == "wind")
                        {
                            mageTemp->setMagicType(Mage::Magic::Wind);
                        }
                }
            else
                {
                    std::cout << "A null pointer was returned " << '\n';
                }
        }
        else if(change == "Arrow" || change == "arrow")
        {
            Archer* archerTemp = dynamic_cast<Archer*>(temp);
            if(archerTemp != nullptr)
            {
                std::cout << "What arrow would you like to switch to? " << '\n';
                getline(std::cin>>std::ws, newArrow);

                if(newArrow == "Fire" || newArrow == "fire")
                    {
                        archerTemp->setArrowType(Archer::Arrows::Fire);
                    }
                else if(newArrow == "Wolf" || newArrow == "wolf")
                    {
                        archerTemp->setArrowType(Archer::Arrows::Wolf);
                    }
                else if(newArrow == "Lightning" || newArrow == "lightning")
                    {
                        archerTemp->setArrowType(Archer::Arrows::Lightning);
                    }
                else if(newArrow == "Underworld" || newArrow == "underworld")
                    {
                        archerTemp->setArrowType(Archer::Arrows::Underworld);
                    }
                
            }
            else
                 std::cout << "A null pointer was returned " << '\n';
        }

        std::cout << "Would you like to make another change? [Enter q to quit] " << '\n';
        std::cin >> response;
    
    }while(response !=  "q");
}


   void printMenu()
   {
       std::cout << "1. Create Character " << '\n';
       std::cout << "2. Display Characters " << '\n';
       std::cout << "3. Find Character " << '\n';
       std::cout << "4. Battle " << '\n';
       std::cout << "5. Level up " << '\n';
       std::cout << "6. Delete Character " << '\n';
       std::cout << "7. Exit " << '\n';
   }


   std::string battleSim(std::vector<Character*>& createdCharacters)
   {
        std::string character1;
        std::string character2;
        // need to make a function to display all the created characters
        displayAllCharacters();
        
        std::cout << " What character would you like to be? " << '\n';
        getline(std::cin>>std::ws, character1);
        Character* player1 = searchCharacter(createdCharacters, character1);



        std::cout << " Pick your opponnent " << '\n';
        getline(std::cin>>std::ws, character2);
        Character* player2 = searchCharacter(createdCharacters, character2);

        // Base case
        if(player1->getHealth() <= 0 || player2->getHealth() <= 0)
            {
                if(player1->getHealth() > player2->getHealth())
                {
                    std::cout << character1 << " you have defeated " << character2 << " in combat. " << '\n';

                }
                else
                {
                     std::cout << character2 << " you have defeated " << character1 << " in combat. " << '\n';
                }
            }
        // Use recursion to simulate a battle

       

   


   }



   /*
   Errors Made:


   **/
   void displayAllCharacters(std::vector<Character*>& createdCharacters)
   {
    if(createdCharacters.empty())
        {
            std::cout << " No Characters have been created " << '\n';
            return;
        }

   for(Character* temp : createdCharacters)
      {
       temp->displayPlayerInfo();
       }

   }