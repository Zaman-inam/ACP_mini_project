#include<stdio.h>
void delete_shape(int n,int x,int y,char PAGE[40][80]);
void put_shape(int n,int x,int y,char PAGE[40][80]);
void modify_shape(int n,int ox,int oy,int nx,int ny,char PAGE[40][80]);
void display_page(char PAGE[40][80]);
int main(){
  char PAGE[40][80];
  int i,j;
  int c,n;
  int x,y;
  
  for(i=0;i<40;i++){
    for(j=0;j<80;j++){
      PAGE[i][j]='_';
    }
  }
  printf("This is the empty page\n");
  display_page(PAGE);
  while(1){
    printf("These operations can be performed:\n"
            "1. Add shape\n"
            "2. Modify shape\n"
            "3. Delete shape\n"
            "4. Exit\n");
    printf("Enter the number of operation to perform:");
    scanf("%d",&c);
    switch(c){
      case 1:
        printf("These shapes are available to be drawn:\n"
            "1. LINE\n"
            "2. RECTANGLE\n"
            "3. CIRCLE\n"
            "4. TRIANGLE\n");
        printf("Enter the number of shape you want to put\n");
        scanf("%d",&n);
        printf("Enter the x and y coordinate of the shape\n");
        printf("Enter x coordinate:");
        scanf("%d",&x);
        printf("Enter y coordinate:");
        scanf("%d",&y);

        if(x < 0 || x >= 80 || y < 0 || y >= 40){
          printf("Invalid coordinates\n");
            break;
        }
        if(n==1){

          int z;

        printf("1. Horizontal\n");
        printf("2. Vertical\n");

        scanf("%d",&z);

          if(z==1 && x+10 >= 80){
            printf("Horizontal line exceeds boundary\n");
            return 0;
          }

          if(z==2 && y+10 >= 40){
            printf("Vertical line exceeds boundary\n");
            return 0;
          }
        }

        if(n==2 && (x+12 >= 80 || y+6 >= 40)){
          printf("Rectangle exceeds page boundary\n");
          break;
        }

        if(n==3 && (x+4 >= 80 || x-4 < 0 || y+4 >= 40 || y-4 < 0)){
            printf("Circle exceeds page boundary\n");
            break;
        }

        if(n==4 && (x+5 >= 80 || x-5 < 0 || y+6 >= 40)){
            printf("Triangle exceeds page boundary\n");
            break;
        }
        put_shape(n,x,y,PAGE);
        display_page(PAGE);
        break;
      case 2:{
        int ox,oy,nx,ny;
        printf("Which shape do you want to modify?\n");
        printf("1.LINE\n");
        printf("2.RECTANGLE\n");
        printf("3.CIRCLE\n");
        printf("4.TRIANGLE\n");

        scanf("%d",&n);

        printf("Enter old x coordinate:");
        scanf("%d",&ox);

        printf("Enter old y coordinate:");
        scanf("%d",&oy);

        printf("Enter new x coordinate:");
        scanf("%d",&nx);

        printf("Enter new y coordinate:");
        scanf("%d",&ny);

        modify_shape(n,ox,oy,nx,ny,PAGE);

        display_page(PAGE);
        break;
      }
      case 3:
        printf("Which shape do you want to delete?\n");
        printf("1. LINE\n");
        printf("2. RECTANGLE\n");
        printf("3. CIRCLE\n");
        printf("4. TRIANGLE\n");

        scanf("%d",&n);

        printf("Enter x coordinate:");
        scanf("%d",&x);

        printf("Enter y coordinate:");
        scanf("%d",&y);

        delete_shape(n,x,y,PAGE);

        display_page(PAGE);

        break;
      case 4:
          return 0;
      default:printf("Invalid choice");
    }
  }
  return 0;
}
void put_shape(int n,int x,int y,char PAGE[40][80]){
  int z,i,j;
  switch(n){
    case 1:
      printf("1.horizontal\n"
              "2.Vertical\n");
      scanf("%d",&z);
      if(z==1){
        if(x+10 >= 80){ 
          printf("Horizontal line exceeds boundary\n"); 
          return; 
        }
        for(i=0;i<10;i++){
          PAGE[y][x+i]='*';
        }
      }
      else if(z==2){
        if(y+10 >= 40){ 
          printf("Vertical line exceeds boundary\n"); 
          return; 
        }
        for(j=0;j<10;j++){
          PAGE[y+j][x]='*';
        }
      }
      break;
    case 2:
      for(i=0;i<6;i++){
        for(j=0;j<12;j++){
          if(i==0 || i==5 || j==0 || j==11){
            PAGE[y+i][x+j]='*';
          }
        }
      }
      break;
    case 3:
      for(i=-4;i<=4;i++){
        for(j=-4;j<=4;j++){
          if(i*i + j*j <= 16){
            PAGE[y+i][x+j]='*';
          }
        }
      }
      break;
    case 4:
      for(i=0;i<6;i++){
        for(j=-i;j<=i;j++){
          PAGE[y+i][x+j]='*';
        }
      }
      break;
    default:printf("Invalid choice");
  }
}
void display_page(char PAGE[40][80]){
  int i,j;
  printf("\n");
  for(i=0;i<40;i++){
    for(j=0;j<80;j++){
      printf("%c",PAGE[i][j]);
    }
    printf("\n");
  }
}
void delete_shape(int n,int x,int y,char PAGE[40][80]){
  if(x < 0 || x >= 80 || y < 0 || y >= 40){
    printf("Invalid coordinates\n");
    return;
  }
  int i,j,z;
    switch(n){
      case 1:
        printf("1. Horizontal\n"); 
        printf("2. Vertical\n"); 
        scanf("%d",&z);
        if(z==1){
          for(i=0;i<10;i++){
            PAGE[y][x+i]='_';
          }
        }
        else if(z==2){
          for(i=0;i<10;i++){
            PAGE[y+i][x]='_';
          }
        }
        break;
      case 2:
        for(i=0;i<6;i++){
          for(j=0;j<12;j++){
            if(i==0 || i==5 || j==0 || j==11){
              PAGE[y+i][x+j]='_';
            }
          }
        }
        break;
      case 3:
        for(i=-4;i<=4;i++){
          for(j=-4;j<=4;j++){
            if(i*i + j*j <= 16){
              PAGE[y+i][x+j]='_';
            }
          }
        }
        break;
      case 4:
        for(i=0;i<6;i++){
          for(j=-i;j<=i;j++){
            PAGE[y+i][x+j]='_';
          }
        }
        break;
      default:
        printf("Invalid choice");
    }
}
void modify_shape(int n,int ox,int oy,int nx,int ny,char PAGE[40][80]){
  if(nx < 0 || nx >= 80 || ny < 0 || ny >= 40){
    printf("New position is outside page bounds\n");
    return;
  }
  if(n==1 && nx+10 >= 80){
    printf("Line exceeds page boundary\n");
    return;
  }
  if(n==2 && (nx+12 >= 80 || ny+6 >= 40)){
    printf("Rectangle exceeds page boundary\n");
    return;
  }
  if(n==3 && (nx+4 >= 80 || nx-4 < 0 || ny+4 >= 40 || ny-4 < 0)){
    printf("Circle exceeds page boundary\n");
    return;
  }
  if(n==4 && (nx+5 >= 80 || nx-5 < 0 || ny+6 >= 40)){
    printf("Triangle exceeds page boundary\n");
    return;
  }
  delete_shape(n,ox,oy,PAGE);
  put_shape(n,nx,ny,PAGE);
  printf("Position of the shape has been changed\n");
}



