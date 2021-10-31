#include <stdio.h>
#include <cs50.h>

string cardtype();
int luhnchk();

int main (void){
    long cardnum;
    int result;
    string cardtyp;

    cardnum = get_long("card number:");
    cardtyp = cardtype(cardnum);
    result = luhnchk(cardnum);
    printf("return from fuction %i\n",result);
    if(result == 0){
        printf("INVALID\n");
        return 0;
    }else{
        printf("%s",cardtype(cardnum));
    }
}
string cardtype(long num){

    int amexchk;
    int mastchk;
    int visachkone;
    int visachktwo;

    amexchk = num/10000000000000;
    mastchk = num/100000000000000;
    visachkone = num/1000000000000;
    visachktwo = num/1000000000000000;
    printf("amex:%i  mast:%i visa1:%i visa2:%i\n",amexchk,mastchk,visachkone,visachktwo);



    if(amexchk == 34|amexchk ==37){
        printf("this is a amex");
        return "AMEX";
    }

    else if(mastchk>=51 && mastchk<=55){
        printf("this is mast");
        return "MASTERCARD";
    }
    else if(visachkone == 4){
        printf("this visa1");
        return "VISA";
    }
    else if(visachktwo == 4){
        printf("this visa2");
        return "VISA";
    }else{
        printf("if retunt inval");
        return "INVALID";
    }

    return "INVALID";
}

int luhnchk(long num){
    long holdersecondnum;
    long holderfirstnum;
    int cardlength;
    int cardsum = 0;

    cardlength = 16;
    holderfirstnum = num;
    holdersecondnum = num/10;

    int secondnum[cardlength];
// printf("\n%i\n\n",cardlength);


    for(int i=0;i< cardlength;i++){

            //puting every secondnumber in an array and multiplying by 2
            secondnum[i] = (holdersecondnum%10)*2;
            printf("secondnum times 2: %i\n",secondnum[i]);

                //separting any double ditigets into single taking the singe digit number adding into array and just adding one to card sum
                if (secondnum[i]>=10){
                secondnum[i]=secondnum[i]%10;
                cardsum+=1;
                printf("if case double digits: credsum added 1:%i last diget added to secondnum %i\n",cardsum,secondnum[i]);
                }


                //creating a sum of all the second numbers after they have been seprated and multiplyed by 2

        cardsum += secondnum[i];
        printf("cardsum added %i   ",cardsum);
        cardsum += holderfirstnum%10;
        printf("digit to be added %ld cardsum first digits added: %i\n",holderfirstnum%10,cardsum);

                //loop to take numbers of the end of the card numbers
        for(int j=0;j<2;j++){
            holdersecondnum = holdersecondnum/10;
            holderfirstnum = holderfirstnum/10;
        }
        printf("holder check first#:%ld  second#:%ld\n",holderfirstnum,holdersecondnum);
        }
    printf("cardsum: %i\n",cardsum);
    if(cardsum%10 == 0){
        return 1;
    }else{
    return 0;
}}
