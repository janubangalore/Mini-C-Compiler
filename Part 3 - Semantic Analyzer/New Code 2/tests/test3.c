int main()
{
    int x;
    float y;
    char z;

    x = 1; //Valid
    /*y = 'c'; //Invalid*/
    z ='2'; //valid

    int c = 2;
    int d;
    d = x + c; //valid
    /*d = z + c; // Invalid*/

    char a;
    if(x < c){
        /*a = c; //Invalid*/
    }
    return 0;
}
