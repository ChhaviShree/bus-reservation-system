#include<conio.h>

#include<cstdio>

#include<iostream>

#include<string.h>

#include<cstdlib>
using namespace std;
static int p=0;
class a
{
    char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
    public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
}
bus[10];
void vline(char ch)
{
    for(int i=80;i>0;i--)
    cout<<ch;
}
void a::install()
{
    cout<<"Enter bus no:";
    cin>>bus[p].busn;
    cout<<"\nEnter driver's name:";
    cin>>bus[p].driver;
    cout<<"\nArrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nDeparture: ";
    cin>>bus[p].depart;
    cout<<"\n from :\t\t\t";
    cin>>bus[p].from;
    cout<<"\nto:\t\t\t";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
}
void a::allotment()
{
    int seat;
    char number[5];
    top:
    cout<<"Bus no: ";
    cin>>number;
     int n;
     for(n=0;n<=p;n++)
     {
         if(strcmp(bus[n].busn,number)==0)
         break;
     }
     while(n<=p)
     {
         cout<<"\nSeat number:";
         cin>>seat;
         if(seat>32)
         {
             cout<<"\n there are only 32 seats available in this bus";
         }
         else
         {
             if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"empty")==0)
             {
                 cout<<"Enter passsenger's name";
                 cin>>bus[n].seat[seat/4][(seat%4)-1];
                 break;
             }
             else
             {
                 cout<<"The seat no is already reserved.\n";
             }
         }
     }
     if(n>p)
     {
         cout<<"Enter correct bus no\n";
         goto top;
     }

     }
     void a::empty()
     {
         for(int i=0;i<8;i++)
         {
             for(int j=0;j<4;j++)
             {
                 strcpy(bus[p].seat[i][j],"empty");
             }
         }
     }
     void a:: show()
     {
         int n;
         char number[5];
        cout<<"enter bus no:";
        cin>>number;
        for(n=0;n<=p;n++)
        {
            if(strcpy(bus[n].busn,number)==0)
            break;
        }
        while(n<=p)
        {
            vline('*');
            cout<<"bus no:\t"<<bus[n].busn<<"\nDriver:\t"<<bus[n].driver
            <<"\t\tArrival time:\t"<<bus[n].arrival<<"\tDeparture time:"
            <<bus[n].depart<<"\nfrom:\t\t"<<bus[n].from<<"\t\tto\t\t"<<
            bus[n].to<<"\n";
            vline('*');
            bus[0].position(n);
            int a=1;
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<4;j++)
                {
                    a++;
                    if(strcmp(bus[n].seat[i][j],"empty")!=0)
                    cout<<"\nthe seat no"<<(a-1)<<"is reserved for"<<bus[n].seat[i][j]<<".";
                }
            }
            break;

        }
        if(n>p)
        cout<<"Enter correct bus no:";
     }
     void a::position(int i)
     {
         int s=0;p=0;
         for(int i=0;i<8;i++)
         {
             for(int j=0;j<4;j++)
             {
                 s++;
                 if(strcmp(bus[1].seat[i][j],"empty")==0)
                 {
                     cout.width(5);
                     cout.fill(' ');
                     cout<<s<<".";
                     cout.width(10);
                     cout.fill(' ');
                     cout<<bus[1].seat[i][j];
                 }
             }
         }
         cout<<"\n\nthere are"<<p<<"seats empty in bus no:"<<bus[1].busn;
     }
void a::avail()
{
    for(int n=0;n<p;n++)
    {
        vline('*');
            cout<<"bus no:\t"<<bus[n].busn<<"\nDriver:\t"<<bus[n].driver
            <<"\t\tArrival time:\t"<<bus[n].arrival<<"\tDeparture time:"
            <<bus[n].depart<<"\nfrom:\t\t"<<bus[n].from<<"\t\tto\t\t"<<
            bus[n].to<<"\n";
            vline('*');
            vline('_');
    }
}
int main()
{
    system("cls");
    int w;
    while(1)
    {
        cout<<"\n\n\n\n";
        cout<<"\t\t\t1.Install\n\t\t\t"
        <<"2.Reservation\n\t\t\t"
        <<"3.show\n\t\t\t"
        <<"4.buses available\n\t\t\t"
        <<"5.exit";
        cout<<"\n\t\tenter your choice:-> ";
        cin>>w;
        switch(w)
        {
            case 1:bus[p].install();
            break;
            case 2:bus[p].allotment();
            break;
            case 3:bus[0].show();
            break;
            case 4:bus[0].avail();
            break;
            case 5:exit(0);
        }
    }
    return 0;
}

