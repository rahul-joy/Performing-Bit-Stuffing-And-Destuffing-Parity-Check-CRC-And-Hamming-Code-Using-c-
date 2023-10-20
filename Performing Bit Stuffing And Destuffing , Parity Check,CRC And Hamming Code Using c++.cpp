
#include<bits/stdc++.h>
using namespace std;
char exor(char a,char b)
{
    if(a==b)
        return '0';
    else
        return '1';
}

int reever(char data[], char key[])
{
    int datalen = strlen(data);
    int keylen = strlen(key);

    for(int i=0; i<keylen-1; i++)
        data[datalen+i]='0';
    data[datalen+keylen-1]='\0';

    int codelen = datalen+keylen-1;

    char temp[20],rem[20];

    for(int i=0; i<keylen; i++)
        rem[i]=data[i];

    for(int j=keylen; j<=codelen; j++)
    {
        for(int i=0; i<keylen; i++)
            temp[i]=rem[i];

        if(rem[0]=='0')
        {
            for(int i=0; i<keylen-1; i++)
                rem[i]=temp[i+1];
        }
        else
        {
            for(int i=0; i<keylen-1; i++)
                rem[i]=exor(temp[i+1],key[i+1]);

        }

        if(j!=codelen)
            rem[keylen-1]=data[j];
        else
            rem[keylen-1]='\0';
    }

    for(int i=0; i<keylen-1; i++)
        data[datalen+i]=rem[i];
    data[codelen]='\0';
    bool flag = 0;
    for(int i=0; i<strlen(rem); i++)
    {


        if(rem[i]=='1')
        {

            flag=1;
            break;
        }

    }
    if (flag==0)
    {
        cout<<"\t\tCRC= "<<rem<<"\nDataword : ="<<data;
        cout<<"\n\n\t\treceived data without errors\n\n";


        return 1;

    }

    else
    {
        cout<<"\n\n\t\treceived code word contains errors \n\n";
        return 2;
    }
}

void crc(char data[], char key[])
{
    int datalen = strlen(data);
    int keylen = strlen(key);

    for(int i=0; i<keylen-1; i++)
        data[datalen+i]='0';
    data[datalen+keylen-1]='\0';

    int codelen = datalen+keylen-1;
    char temp[20],rem[20];

    for(int i=0; i<keylen; i++)
        rem[i]=data[i];

    for(int j=keylen; j<=codelen; j++)
    {
        for(int i=0; i<keylen; i++)
            temp[i]=rem[i];

        if(rem[0]=='0')
        {
            for(int i=0; i<keylen-1; i++)
                rem[i]=temp[i+1];
        }
        else
        {
            for(int i=0; i<keylen-1; i++)
                rem[i]=exor(temp[i+1],key[i+1]);

        }
        if(j!=codelen)
            rem[keylen-1]=data[j];
        else
            rem[keylen-1]='\0';
    }

    for(int i=0; i<keylen-1; i++)
        data[datalen+i]=rem[i];
    data[codelen]='\0';
    cout<<"CRC="<<rem<<"\nDataword="<<data;

    char tp[20];
    cout<<"\nIf you want get orginal data press 1 or to exit press any number : ";
    int h;

    cin>>h;

    if(h==1)
    {



        int h=reever(data,key);
    }
    else
    {
        exit(0);;
    }


    for(int i=0; i<strlen(data)-2*(strlen(key)-1); i++)
    {
        tp[i]=data[i];
    }
    tp[strlen(data)-2*(strlen(key)-1)]='\0';

    cout<<"\n Ogrinal data ="<<tp;


}

void bitDestuffing(int N, char arr[])
{

    char brr[20];

    int i, j, k;
    i = 0;
    j = 0;


    int count = 1;


    while (i < N)
    {

        if (arr[i] == '1')
        {

            brr[j] = arr[i];

            for (k = i + 1; arr[k] == '1' && k < N && count < 5; k++)
            {
                j++;
                brr[j] = arr[k];
                count++;

                if (count == 5)
                {
                    k++;
                }
                i = k;
            }
        }

        else
        {
            brr[j] = arr[i];
        }
        i++;
        j++;
    }
    brr[i]='\0';


    cout<< "\n Atfter de-stuffing : "<<brr<<"\n";
}

int main()
{
    char choice, another;



    cout<<"\n1. Bit Stuffing and De-Stuffing";
    cout<<"\n2. Parity Check";
    cout<<"\n3. Cyclic Redundancy Check";
    cout<<"\n4. Hamming Code";
    cout<<"\n5. Exit";
    cout<<"\n Enter which you want to perform : ";

    cin>>choice;
    switch(choice)
    {
    case '1':
    {
        char in[20],out[20];
        cout<<"Enter The data you want to send : ";
        cin>>in;
        int k, l,ct=0,nl;
        for (k=0; k<strlen(in); k++)
        {
            ct=0;
            for (l=k; l<=(k+5); l++)
            {
                if(in[l]=='1')
                {
                    ct++;
                }
            }

            if(ct==6)
            {
                nl=strlen(in)+2;
                for (; nl>=(k+5); nl--)
                {
                    in[nl]=in[nl-1];
                }
                in[k+5]='0';
                k=k+7;
            }
        }
        //puts(in);
        cout<<"\nAtfter Bit Stuffing : "<<in;
        cout<<"\nIf you want destuffing press 1 or to exit press any number : ";
        int h;

        cin>>h;
        int n=strlen(in);

        if(h==1)
        {



            bitDestuffing (n, in);
        }
        else
        {
            exit(0);
        }
    }
    break;

    case '2':
    {
        char in[20],out[20];
        cout<<"Enter The data you want to send : ";
        cin>>in;
        int p,i,j, count =0;
        for(int p =0; p<strlen(in); p++)
        {

            if (in[p]=='1')
                count++;
        }
        int c=strlen(in)+1;
        if(count%2)
        {
            for ( int i=c, j=c-1; i >0; i--, j--)
            {
                in[ i ] = in[ j ] ;
            }

            in[0] = '1' ;
            cout<<"After the Parity Check : ";
            puts(in);

        }
        else
        {
            for ( int i=c, j=c-1; i >0; i--, j--)
            {
                in[ i ] = in[ j ] ;
            }

            in[0] = '0' ;
            cout<<"After the Parity Check : ";
            puts(in);
        }
    }

    break;

    case '3':
    {
        char in[20],data[20],key[20];
        cout<<"Enter The data you want to send : ";
        cin>>in;

        cout<<"\nEnter the key:";
        cin>>key;

        crc(in,key);
    }

    break;

    case '4':
    {
        int data_bits[20],m,r = 0,parity;
        cout<<"Enter the size of data bits: ";
        cin>>m;


        while(pow (2,r) < m+r+1)
        {
            r++;
        }

        cout<<"Enter the data bit: ";
        for(int i = 1; i <= m; i++)
            cin>>data_bits[i];

        int hamming[m + r],j = 0,k = 1;

        for(int i = 1; i <= m + r; i++)
        {

            if( i == pow( 2, j ))
            {
                hamming[i] = -1;
                j++;
            }
            else
            {
                hamming[i] = data_bits[k];
                k++;
            }
        }

        k = 0;
        int x, mi, ma = 0;
        for (int i = 1; i <= m + r; i = pow (2, k))
        {
            k++;
            parity = 0;
            j= i;
            x = i;
            mi= 1;
            ma = i;
            while ( j <= m + r)
            {
                cout<<"\n"<<i<<" possition : "<<hamming[i]<<" : ";

                for (x = j; ma>= mi && x <= m + r; mi++, x++)
                {
                    cout<<hamming[x]<<" ";
                    if (hamming[x] == 1)
                        parity = parity + 1;
                }
                j = x + i;
                //cout<<j<<"\n";
                mi = 1;
            }

            if (parity % 2 == 0)
            {
                hamming[i] = 0;
            }
            else
            {
                hamming[i] = 1;
            }
        }

        cout<<"\nHamming code is: ";
        for(int i = 1; i <= m + r; i++)
            cout<<hamming[i]<<" ";
    }

    break;


    case '5':
        exit(0);


    }

    return 0;
}
