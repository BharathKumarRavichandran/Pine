#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>
#include <fstream.h>
#include <process.h>
#include <dos.h>
#include <time.h>

char chpass[32];
int p[2][2];
int i, j;
int o;
int score1 = 0;
int n2, n1, n3;

const int MAXLENGTH = 80;
const int MAX_TRIES = 5;
const int MAXROW = 7;

int letterFill(char, char[], char[]);
void initUnknown(char[], char[]);

void checkid(char *);
void checkeid(char *);
void totalscore(int);
void coan();
void guess();
void norush();
void d_lay();
void logout();

class get_info
{
public:
    char name[32];
    char userid[32];
    char eid[64];
    char pass[32];
    int tscore;

    get_info()
    {
        tscore = 0;
    }
} I;

void create()
{
bh:
    cleardevice();
    gotoxy(1, 1);
    fstream f1("datb.dat", ios::binary | ios::in | ios::out | ios::app);
    cout << "\nhttps://www.ThePine.com/createacc.php";
    cout << "\n\n\n\t\t\t\tCreate a account";

    cout << "\n\n\t\t  Name              :\t";
    cin >> I.name;
    cout << "\n\n\t\t  Username          :\t";
    cin >> I.userid;
    checkid(I.userid);
    cout << "\n\n\t\t  E-Mail            :\t";
    cin >> I.eid;
    checkeid(I.eid);
    cout << "\n\n\t\t  Password          :\t";
    cin >> I.pass;

    cout << "\n\n\t\t  Re-enter Password :\t";
    cin >> chpass;

    if (strcmp(I.pass, chpass) != 0)
    {
        cout << "\n\n\t\tPasswords do not match!!!";
        cout << "\n\n\t\tSorry, Try again.";
        delay(2000);
        goto bh;
    }
    f1.write((char *)&I, sizeof(I));

    f1.close();
    d_lay();
    cleardevice();
    gotoxy(1, 1);
    cout << "\n\n\n\n\n\n\tWe assure you that your details will never be shared...";
    delay(2000);
    cout << "\n\n\n\tThank you for Signing up!";
    delay(2000);
    cout << "\n\n\n\tEnjoy Pine Gaming experience";
}

void checkid(char c[32])
{
    get_info K;
    ifstream f2("datb.dat", ios::binary);
    while (f2.read((char *)&K, sizeof(K)))
        if (strcmp(K.userid, c) == 0)
        {
            cout << "\n\n\t\tThe ID Is Already In Use!";
            delay(2000);
            cout << "\n\n\n\t\tSorry, Try again.";
            create();
        }
    f2.close();
}
void checkeid(char c[64])
{
    get_info F;
    ifstream f3("datb.dat", ios::binary);
    while (f3.read((char *)&F, sizeof(F)))
        if (strcmp(F.eid, c) == 0)
        {
            cout << "\n\n\t\tThe E-Mail ID Is Already In Use!";
            delay(2000);
            cout << "\n\n\n\t\tSorry, Try again.";
            create();
        }
    f3.close();
}

void begin()
{
    int a = DETECT, b;
    initgraph(&a, &b, "..\\bgi");
    delay(250);
    setcolor(GREEN);
    line(0, 0, 7000, 0);
    line(0, 1, 7000, 1);
    line(0, 2, 7000, 2);
    delay(250);
    line(0, 0, 0, 7000);
    line(1, 0, 1, 7000);
    line(2, 0, 2, 7000);
    delay(250);
    line(639, 0, 639, 500);
    line(637, 0, 637, 500);
    line(638, 0, 638, 500);
    delay(250);
    line(0, 478, 700, 478);
    line(0, 480, 700, 480);
    line(0, 479, 700, 479);
    line(0, 477, 700, 477);

    delay(1000);
    setcolor(RED);
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(100, 50, "$P");
    delay(500);
    outtextxy(155, 50, "I");
    delay(500);
    outtextxy(170, 50, "N");
    delay(500);
    outtextxy(200, 50, "E$");
    delay(500);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(220, 175, " presents");

    delay(750);
    int i = 0;
    for (i; i <= 3; i++)
    {
        int a = 1;
        delay(300);
        if (a % 2 != 0)
        {
            setcolor(RED);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1 + i);
            outtextxy(10, 270, "a Gaming Platform");
            a++;
        }
        if (a % 2 == 0)
        {
            setcolor(BLACK);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, i);
            outtextxy(10, 270, "a Gaming Platform");
            a++;
        }
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n  \t\t           PRESS ANY KEY TO CONTINUE....";
    getch();
    closegraph();
}
void menu()
{
    int c;
    char cr;
    int gd = DETECT, gm;
men:
    initgraph(&gd, &gm, "..//bgi");
    cleardevice();
    gotoxy(1, 1);
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(100, 100, " * MENU:");
    gotoxy(60, 5);
    cout << "SCORE : " << I.tscore;
    cout << "\n\n\n\n\n                     1. Guessing game ";
    cout << "\n\n                     2. Analyser      ";
    cout << "\n\n                     3. Number rush          ";
    cout << "\n\n                     4. Credits               ";
    cout << "\n\n                     5. Logout                ";
    cout << "\n\n\n\n      Enter your choice...   :   ";
    cin >> c;
    switch (c)
    {
    case 2:
    back1:
        cleardevice();
        gotoxy(1, 1);
        coan();
        //  cleardevice();
        gotoxy(1, 1);
        cout << "Do you want to play again...?";
        cin >> cr;
        if (cr == 'y' || cr == 'Y')
        {
            goto back1;
        }
        else
        {
            goto men;
        }

    case 1:
    back2:
        cleardevice();
        gotoxy(1, 1);
        guess();
        cleardevice();
        gotoxy(1, 1);
        cout << "Do you want to play again...?";
        cin >> cr;
        if (cr == 'y' || cr == 'Y')
        {
            goto back2;
        }
        else
        {
            goto men;
        }

    case 3:
    back3:
        cleardevice();
        gotoxy(1, 1);
        norush();
        cleardevice();
        gotoxy(1, 1);
        cout << "Do you want to play again...?";
        cin >> cr;
        if (cr == 'y' || cr == 'Y')
        {
            goto back3;
        }
        else
        {
            goto men;
        }

    case 4:
        cleardevice();
        gotoxy(1, 1);
        cout << "\n\n***********************************************************************";
        cout << "\n\n\n\n\t\t\tThis console platform was developed by PINE TEAM.";
        cout << "\n\t\t\tIt provides entertainment for people of all ages.";
        cout << "\n\t\t\tIt enhances the logical thinking of the user,";
        cout << "\n\t\t\tdeveloping thinking skills and speed from all angles";
        cout << "\n\t\t\tIt coordinates our hands and our mind.";
        cout << "\n\n\n\n\t\t\t*** PINE TEAM : *** ";
        cout << "\n\t\t\t### ATHITHYA KUMAR N B ";
        cout << "\n\t\t\t### BHARATH KUMAR R ";
        cout << "\n\t\t\t### MAHADHARSAN R ";
        cout << "\n\t\t\t### NAVEEN PRASHANNA G ";
        cout << "\n\n\n\n\n*****************************************************************";
        delay(1500);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress any key to go to menu...";
        cin >> cr;
        goto men;

    case 5:
        cleardevice();
        gotoxy(1, 1);
        cout << "\n\n\n\n\n\n\t\t\tWe hope to see you again";
        delay(1500);
        logout();

    default:
        cleardevice();
        gotoxy(1, 1);
        cout << "\n\n\n\n\t\t Sorry, You have entered a Wrong Choice!";
        cout << "\n\n\t\t\t Please try again";
        delay(2000);
        goto men;
    }
}
void totalscore(int score)
{
    fstream f4("datb.dat", ios::binary | ios::out | ios::in);
    int a;
    get_info u;
    while (!f4.eof())
    {
        a = f4.tellg();
        f4.read((char *)&u, sizeof(u));
        if (strcmp(u.eid, I.eid) == 0)
        {
            I.tscore += score;
            f4.seekp(a);
            f4.write((char *)&I, sizeof(I));
        }
    }
    f4.close();
}

void coan()
{
    clearviewport();
    int x1 = 150, y1 = 200;
    int x2 = 150, y2 = 250;
    int x3 = 200, y3 = 200;
    int x4 = 200, y4 = 250;
    int i = 0, j = 0;
    char ch;
    int time = 0, score = 0;
    int p = 0, q = 0;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "..//bgi");
    char ch1;

    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(50, 50, " Welcome to");
    outtextxy(150, 100, " coordination analyser");
    delay(500);
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "$ BRIEF INTRODUCTION:";
    cout << "\n     This is not just a game actually...!!";
    cout << "\n     This will check your coordination power between your hand, ";
    cout << "\n     eye and your brain...";
    delay(500);
    cout << "\n\n\n$ HOW TO PLAY   :";
    cout << "\n     * This game will end within few seconds after the start";
    cout << "\n     * you must be able to keep your tile within the boundary";
    cout << "\n     * In every 1 second speed is increased twice, If you hit the  ";
    cout << "\n        boundary \"you are out...!!\" ";
    cout << "\n\n\n\n\n                         PRESS y(or)Y TO CONTINUE......";
    cin >> ch1;
    if (ch1 == 'y' || ch1 == 'Y')
    {
        for (long int a = 0; a >= 0; a++)
        {
            setcolor(CYAN);
            line(10, 10, 10, 470);
            line(10, 10, 630, 10);
            line(630, 10, 630, 470);
            line(10, 470, 630, 470);
            setcolor(RED);
            setcolor(BLUE);
            line(x1, y1, x2, y2);
            line(x1, y1, x3, y3);
            line(x3, y3, x4, y4);
            line(x2, y2, x4, y4);

            setcolor(RED);
            circle(((x1 + x2) / 2), ((y1 + y2) / 2), 10);
            circle(((x1 + x2) / 2), ((y1 + y2) / 2), 5);
            circle(((x3 + x4) / 2), ((y3 + y4) / 2), 5);
            circle(((x1 + x3) / 2), ((y1 + y3) / 2), 5);
            circle(((x2 + x4) / 2), ((y4 + y2) / 2), 5);
            circle(((x3 + x4) / 2), ((y3 + y4) / 2), 10);
            circle(((x1 + x3) / 2), ((y1 + y3) / 2), 10);
            circle(((x2 + x4) / 2), ((y4 + y2) / 2), 10);

            if (kbhit())
            {
                ch = getch();
                if (ch == 'w' || ch == 72 || ch == 'W')
                {
                    i = 0;
                    j = -5;
                }

                else if (ch == 's' || ch == 80 || ch == 'S')
                {
                    i = 0;
                    j = 5;
                }

                else if (ch == 'a' || ch == 75 || ch == 'A')
                {
                    i = -5;
                    j = 0;
                }

                else if (ch == 'd' || ch == 77 || ch == 'D')
                {
                    i = 5;
                    j = 0;
                }
                if (ch == 27)
                {
                    exit(0);
                }
            }
            x1 = x1 + i;
            x2 = x2 + i;
            x3 = x3 + i;
            x4 = x4 + i;
            y1 = y1 + j;
            y2 = y2 + j;
            y3 = y3 + j;
            y4 = y4 + j;

            if (a % 100 == 0)
            {
                time = time + 1;
            }

            if (a % 10000 == 0)
            {
                score = score + 5;
            }

            if (x1 == 15 || x4 == 625 || y1 == 15 || y4 == 465)
            {
                cleardevice();
                delay(100);

                setcolor(YELLOW);
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                outtextxy(120, 200, " YOU ARE OUT !! ");
                textcolor(10);
                textbackground(0);
                cout << endl
                     << "total time played is :";
                cout << "   " << time << ":00";
                cout << endl
                     << "Your score is :";
                cout << "   " << score;
                delay(1500);
                totalscore(score);
                break;
            }
            if (a % 25 == 0 && q >= 5)
            {
                p = p + 2;
            }
            q = 50 - p;
            delay(q);
            cleardevice();
        }
    }
    closegraph();
}
void guess()
{
    char unknown[MAXLENGTH];
    char letter;
    int score3 = 0;
    int num_of_wrong_guesses = 0;
    char word[MAXLENGTH];
    char words[][MAXLENGTH] =
        {
            "india",
            "pakistan",
            "nepal",
            "malaysia",
            "philippines",
            "australia",
            "iran",
            "ethiopia",
            "oman",
            "indonesia"};
    randomize();
    int n = random(10);
    strcpy(word, words[n]);
    initUnknown(word, unknown);

    char ch;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "..//bgi");

    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(50, 50, " Welcome to");
    outtextxy(150, 100, " \"GUESS A COUNTRY NAME\" ");
    setcolor(BLACK);
    cout << "\n\n\n\n\n\n\n\n\n$ RULES :   ";
    cout << "\n\n    * Each letter is represented by a star.";
    cout << "\n\n     * You have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\n\n\n\n                       PRESS y (or) Y TO CONTINUE.....";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        cleardevice();
        gotoxy(1, 1);
        while (num_of_wrong_guesses < MAX_TRIES)
        {
            cout << "\n\n"
                 << unknown;
            cout << "\n\nGuess a letter: ";
            cin >> letter;

            if (letterFill(letter, word, unknown) == 0)
            {
                cout << endl
                     << "Whoops! That letter isn't in there!" << endl;
                num_of_wrong_guesses++;
            }
            else
            {
                cout << endl
                     << "You found a letter! Isn't that exciting!" << endl;
            }
            cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
            cout << " guesses left." << endl;
            if (strcmp(word, unknown) == 0)
            {
                cout << word << endl;
                cout << "                         Yeah! You got it!";
                score3 = MAX_TRIES - num_of_wrong_guesses;
                totalscore(score3);
                break;
            }
        }
        if (num_of_wrong_guesses == MAX_TRIES)
        {
            cout << "\nSorry, you lose...you've been hanged." << endl;
            cout << "The word was : " << word << endl;
        }
    }
    getch();
}
int letterFill(char guess, char secretword[], char guessword[])
{
    int i;
    int matches = 0;
    for (i = 0; secretword[i] != '\0'; i++)
    {
        if (guess == guessword[i])
            return 0;
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}
void initUnknown(char word[], char unknown[])
{
    int i;
    int length = strlen(word);
    for (i = 0; i < length; i++)
        unknown[i] = '*';
    unknown[i] = '\0';
}
void disp()
{
    for (i = 0; i < 2; i++)
    {
        gotoxy(34, 5 + (i * 3));
        for (j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                gotoxy(42, 5 + (i * 3));
                cout << p[i][j];
            }
            else
                cout << p[i][j];
        }
        cout << '\n';
    }
    setcolor(6);
    settextstyle(1, HORIZ_DIR, 2);
    outtextxy(10, 72, "Score:");
    gotoxy(10, 6);
    cout << score1;

    setcolor(2);
    rectangle(260, 56, 290, 86);
    rectangle(324, 103, 354, 133);
    rectangle(260, 103, 290, 133);
    rectangle(324, 56, 354, 86);

    rectangle(259, 55, 291, 87);
    rectangle(323, 102, 355, 134);
    rectangle(259, 102, 291, 134);
    rectangle(323, 55, 355, 87);

    rectangle(0, 0, 630, 460);
    rectangle(1, 1, 629, 459);
    rectangle(2, 2, 628, 458);

    setcolor(15);
    line(253, 192, 283, 192);
    line(293, 192, 323, 192);
    line(333, 192, 363, 192);

    setcolor(4);
    switch (o)
    {
    case 1:
        settextstyle(0, HORIZ_DIR, 1);
        outtextxy(286, 181, "+");
        outtextxy(326, 181, "=");
        settextstyle(0, HORIZ_DIR, 2);
        outtextxy(302, 87, "+");
        break;
    case 2:
        settextstyle(0, HORIZ_DIR, 1);
        outtextxy(286, 181, "-");
        outtextxy(326, 181, "=");
        settextstyle(0, HORIZ_DIR, 2);
        outtextxy(302, 87, "-");
        break;
    case 3:
        settextstyle(0, HORIZ_DIR, 1);
        outtextxy(286, 181, "*");
        outtextxy(326, 181, "=");
        settextstyle(0, HORIZ_DIR, 1);
        outtextxy(304, 92, "*");
        break;
    case 4:
        settextstyle(0, HORIZ_DIR, 1);
        outtextxy(286, 181, "/");
        outtextxy(326, 181, "=");
        settextstyle(0, HORIZ_DIR, 2);
        outtextxy(302, 87, "-");
        outtextxy(302, 86, ":");
        break;
    }
}
void norush()
{
    char ch3;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "..//bgi");
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(50, 50, " Welcome to");
    outtextxy(150, 100, " NUMBER RUSH ");
    cout << "\n\n\n\n\n\n\n\n         $INSTRUCTION:     ";
    cout << "\n   * You have four numbers before you    ";
    cout << "\n   * You also have an operator     ";
    cout << "\n   * You only have 60 seconds to form the right equation..";
    cout << "\n   * Each correct equation formed will add 2 seconds ...";
    cout << "\n\n\n\n\n                  PRESS y (or) Y TO CONTINUE.....";
    cin >> ch3;
    if (ch3 == 'y' || ch3 == 'Y')
    {
        class sum
        {
        public:
            int n, a, b, c, d, o;
        } s;
        clrscr();
        randomize();
        score1 = 0;
        int r;
        int bonus = 0;
        int x = -100, y = -100, z = -100, z1;
        long t1;
        time_t t = time(0);
        t1 = t;

        int gd = DETECT, gm;
        initgraph(&gd, &gm, "C:\\TC\\BGI");
        ifstream f("rush.txt", ios::in);
        while ((t - t1) < 30 + bonus)
        {
            r = random(1) + 1;
            while (!f.eof())
            {
                f.read((char *)&s, sizeof(s));
                if (r == s.n)
                {
                    p[0][0] = s.a;
                    p[0][1] = s.b;
                    p[1][0] = s.c;
                    p[1][1] = s.d;
                    o = s.o;
                    f.seekg(0);
                    break;
                }
            }
            while ((t - t1) < 30 + bonus) //2nd while
            {
                if (x == -100)
                {
                    disp();
                    gotoxy(34, 12);
                    cin >> x;
                    if (x != p[0][0] && x != p[0][1] && x != p[1][0] && x != p[1][1])
                    {
                        x = -100;
                        cleardevice();
                        gotoxy(3, 14);
                        cout << "Enter the nos. from the above set...";
                    }
                }
                else
                {
                    if (y == -100)
                    {
                        cleardevice();
                    h:
                        disp();
                        gotoxy(34, 12);
                        cout << x;
                        gotoxy(39, 12);
                        cin >> y;
                        if (y != p[0][0] && y != p[0][1] && y != p[1][0] && y != p[1][1])
                        {
                            y = -100;
                            cleardevice();
                            gotoxy(3, 14);
                            cout << "Enter the nos. from the above set...";
                            goto h;
                        }
                    }
                    else
                    {
                        cleardevice();
                    k:
                        disp();
                        gotoxy(34, 12);
                        cout << x;
                        gotoxy(39, 12);
                        cout << y;
                        gotoxy(44, 12);
                        cin >> z;
                        if (z != p[0][0] && z != p[0][1] && z != p[1][0] && z != p[1][1])
                        {
                            z = -100;
                            cleardevice();
                            gotoxy(3, 14);
                            cout << "Enter the nos. from the above set...";
                            goto k;
                        }
                    }
                }
                if (x != -100 && y != -100 && z != -100)
                {
                    switch (o)
                    {
                    case 1:
                        z1 = x + y;
                        break;
                    case 2:
                        z1 = x - y;
                        break;
                    case 3:
                        z1 = x * y;
                        break;
                    case 4:
                        z1 = x / y;
                        break;
                    }
                    if (z1 == z)
                    {
                        score1++;
                        bonus += 2;
                        t = time(0);
                        break;
                    }
                    else
                    {
                        cleardevice();
                        disp();
                        gotoxy(34, 12);
                        cout << x;
                        gotoxy(39, 12);
                        cout << y;
                        gotoxy(44, 12);
                        cout << z;
                        gotoxy(3, 14);
                        cout << "Sorry, Wrong. Please try again!";
                        x = -100;
                        y = -100;
                        z = -100;
                        delay(1000);
                        cleardevice();
                    }
                }
                t = time(0);
            }
            cleardevice();
            x = -100;
            y = -100;
            z = -100;
        }
        setcolor(2);
        rectangle(0, 0, 630, 460);
        rectangle(1, 1, 629, 459);
        rectangle(2, 2, 628, 458);

        setcolor(6);
        settextstyle(2, HORIZ_DIR, 7);
        outtextxy(265, 151, "TIME OUT");
        outtextxy(215, 169, "Your score is :");
        gotoxy(50, 12);
        cout << score1;
        delay(2000);
        totalscore(score1);
        f.close();
    }
}

void d_lay()
{
    cleardevice();
    gotoxy(1, 1);
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\tLoading ";
    for (int x = 0; x < 20; x++)
    {
        delay(100);
        cout << '\4';
    }
    cleardevice();
    gotoxy(1, 1);
}

//..................................................................................

void logout()

{
    int a = DETECT, b;
    initgraph(&a, &b, "..\\bgi");

    for (int i = 160; i < 450; i++)
    {
        settextstyle(BOLD_FONT, HORIZ_DIR, 2);
        outtextxy(150, 110, "LOGGING OUT.....");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(120, 300, "Thank you .... Visit us soon.....");

        setcolor(2);
        rectangle(160, 210, 450, 225);
        rectangle(160, 210, i, 225);
        delay(3);
    }
    delay(1000);
    closegraph();
    exit(0);
}

//.................................................................................

void main()
{
    clrscr();

    int l;
    char c;

    begin();
    char id[64], passwd[32];
    fstream f5("datb.dat", ios::binary | ios::out | ios::in | ios::app);

    int a = DETECT, b;
    initgraph(&a, &b, "..\\bgi");

start:
    cout << "\n\n\n\n\n\t             https://www.ThePine.com/login.php  ";
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(200, 50, "$ PINE $");

    cout << "\n\n\n\n\n\n\n\t\t  1. Create an account - Signup ";
    cout << "\n\n\t\t  2. Already have an account - Login ";
    cout << "\n\n\n\n\n\t\t  Enter your choice:  ";
    cin >> l;
    switch (l)
    {
    case 1:
    signup:
        create();
        cleardevice();
        gotoxy(1, 1);
        cout << "\n\n\n\n\t\t\tWelcome " << I.name << "!";
        delay(1500);
        f5.close();
        menu();
        break;
    case 2:
    login:
        cleardevice();
        gotoxy(1, 1);
        cout << "\nhttps://www.ThePine.com/login.php";
        cout << "\n\n\n\n\t\tEnter Your E-Mail ID:  ";
        cin >> id;

        while (!f5.eof())
        {
            f5.read((char *)&I, sizeof(I));
            if (strcmp(id, I.eid) == 0)
            {
                cout << "\n\n\t\tEnter Your Password:  ";
                cin >> passwd;

                if (strcmp(passwd, I.pass) == 0)
                {
                    d_lay();
                    cleardevice();
                    gotoxy(1, 1);
                    cout << "\n\n\n\n\t\t\tWelcome " << I.name << "!";
                    delay(2000);
                    f5.close();
                    menu();
                }
                else
                {
                    d_lay();
                    cleardevice();
                    gotoxy(1, 1);
                    cout << "\n\n\n\n\t\t\tIncorrect PASSWORD";
                    goto login;
                }
            }
        }
        cout << "\n\n\n\n\t\t\tEmail ID doesn't exist...";
        cout << "\n\n\n\n\t\t\tDo you want to create an account? (y/n) :";
        cin >> c;
        if (c == 'y' || c == 'Y')
            goto signup;
        else
        {
            cleardevice();
            f5.close();
            exit(0);
        }
        break;
    default:
        cout << "\n\n\n\t\t\tSorry, wrong choice!! ";
        delay(1000);
        cout << "\n\n\t\t\tTry again! ";
        delay(600);
        goto start;
    }
}