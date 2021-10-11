#include<iostream>
using namespace std;

int pill_count=-1;//number of pills
int fact =-1;//taking walk
int hours_slept=-1; //no. of hours slept

//Description: A function that returns factorial of given value 
//Pre: values greater 0
//Post: No of steps returned 
int taking_a_walk(const int legs)
{
    int fact =1;
    int i=0;

    for (int i=1; i<=legs ;i++)
        {
            fact = fact * i;
        }
    cout << fact <<" steps";

    return fact;
}

//Description: Asks user number of legs and displays number of steps
//Pre: None
//Post: Displays output on the terminal
int number_of_steps()
{
    int legs=0;
    cout << "enter number of legs:" ;
    cin >> legs;
    cout << legs << "legs for walk\n";
    if (legs==0)
    {
        cout<< 0 << " ";
        return 0;
    }
    return taking_a_walk(legs);
}

//Description: The anxiety_level() function will request user for anxiety level in 1-10 range if fails asks again
//Pre: None
//Post: returns anxiety level inputted by the user.
int anxiety_level()
{
    int anxiety_level = 0;
    cout << "Please enter your anxiety level on a scale of 1-10\n";
    cin >> anxiety_level;
    while (anxiety_level>10 or anxiety_level<1)
    {
        cout << "Please enter your anxiety level on a scale of 1-10\n";
        cin >> anxiety_level;
        break;

    }
    return anxiety_level;
}

//Description: The anxiety_level() function will request user for week in 1-7 range if fails asks again
//Pre: None
//Post: returns week inputted by the user.
int day()
{
    int week = 0;
    cout << "Please choose day of the week from 1-7\n";
    cin >> week;
    while (week>7 or week<1)
    {
        cout << "Please enter your week on a scale of 1-7\n";
        cin >> week; 
        break;    
    }
    return week;
}

//Description: The number_of_pills() displays pills to take by user and if less that 0 will return 0 only
//Pre: integer
//Post: Number of pills to take by the user will be displayed on the screen
int number_of_pills( int number_of_pills)
{
    

    if (number_of_pills > 0)
    {
        cout << "number of pills to take " << number_of_pills;
        cout << endl;
        return number_of_pills;
    }
    else
    {
        cout << "number of pills to take " << 0 ;
        cout << endl;
        return 0;
    } 
    
}

//Description: medications() calculates pill count by substracting anxiety level by day and returns the values to display function 
//Pre: anxiety level in range of 1 -10 and day in range of 1-7
//Post: return pill count to display function
int medications(const int anxiety_level,const int day)
{
    //int pill_count=0;
    pill_count = anxiety_level - day;

    return number_of_pills(pill_count);
}

//Description: The display_min_spent acts as a print function for nap_time function
//Pre: integers >= 0
//Post: displays minutes spent
int display_min_spent(float minutes)
{
    cout <<"minutes: "<< minutes;
    return 0;
}

//Description: The total_hours_slept asks user for number of hours slept previous night in between 0 to 24 hours 
//Pre: None
//Post: returns hours slept
int total_hours_slept()
{
    int hours_slept = 0;
    cout << "Enter the hours you have slept previous night?";
    cin >> hours_slept;
    while(hours_slept < 0 || hours_slept > 24)
    {
        cout << "please enter valid hours!";
        cin >> hours_slept;
    }
    return hours_slept;
}

//Description: The nap_time() function calculates the minutes to take a nap it cannot work with out option 1 and 2 before
//Pre: Distance,pills,hrs_slept integers >=0
//Post: return minutes to display function

int nap_time(int distance=0,int pills=0,
             int hrs_slept=0)
{
    float minutes=0;
    if (pills == 0)
    {
        pills = 1;
    }
    minutes = hrs_slept + (distance/pills);
    return display_min_spent(minutes);

}

//Description: The display_cals acts as a print function for calorie intake function
//Pre: float >= 0
//Post: displays calorie intake on terminal
int display_cals(const float cals)
{
    cout <<"calorie intake: " << cals << "\n";
    return 0;
}

//Description: Calculates amount of calories required by using weight,height,room temperature and requires steps from option 1 to be pre calculated
//Pre: None
//Post: returns calorie count to display function
int calorie_intake()
{
    float weight=0;
    float height=0;
    float room_temp=0;
    float cals=0;
    if (fact == -1)
    {
        cout << "REFUSED\n";
        cout << "Please finish option 1 to find Calorie intake\n";
        return 0;
    }
    cout << "Please enter your weight\n";
    cin >> weight;
    cout << "Please enter your height\n";
    cin >> height;
    cout << "Please enter your room temperature in fahrenheit\n";
    cin >> room_temp;

    cals = (6 * weight) + (2 * height) + 1/room_temp + fact;

    return display_cals(cals); 
}

//Description: Has all the options present available in this algorithm
//Pre: None
//Post: Displays all functionalities in order to choose 
int menu()
{
    int option = 0;
    cout << "\nHealth-o-Matic Options\n";
    cout << "-----------------------\n";
    cout << "1. Taking a Walk!\n2. Your Medications\n3. Nap Time!!\n4. Caloric Intake\n5. Quit\n";
    cout << "Choose an option:\n";  
    cin >> option;
    return option;
}

//Description: Greets welcome to the new users
//Pre: None
//Post: displays welcome
int greetings()
{
    cout << "Welcome \n";
    return 0;
}

//Description: Main call lets user choose an option if incorrect option choosed will be request again to choose the right option
//Pre: None
//Post: Error handling messages are displayed in wrong option case
int main()
{
    int option = 0;
    int quit=false;

    while(quit==false)
    {
        option = menu();
        switch(option) {
            case 1 :
                fact = number_of_steps();
                break;
            case 2:
                pill_count = medications(anxiety_level(),day());
                break;
            case 3:
                if (pill_count == -1 || fact == -1)
                {
                    cout << "REFUSED\n";
                    cout << "Please finish options 1 and 2 to find Nap time\n";
                    break;
                }
                nap_time(fact,pill_count,total_hours_slept());
                break;
            case 4:
                calorie_intake();
                break;  
            case 5:
                quit = true;
                break;
            default:
                cout << "Choose an option between 1 to 5\n";
        }

    }
    return 0;
}
