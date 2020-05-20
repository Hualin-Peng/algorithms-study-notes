# include <stdio.h>

int steps = 0; //count steps moved

void move(char a, char c){
    printf("Step is %d: move 1 plate %c --> %c\n", ++steps, a, c); //not step++
}

void Hanoi(int n, char a, char b, char c){
    if (n==1)
        move(a, c);
    else{
        Hanoi(n-1,a, c, b);
        move(a, c);
        Hanoi(n-1, b, a, c);
    }

}

int main(){
    int plate_num;
    printf("Please input an pisitive integer:");
    scanf("%d", &plate_num);
    if(plate_num <= 0){
        printf("Error input type!\n");
        return 0;
    }
    Hanoi(plate_num, 'A', 'B', 'C');

    return 0;
}
