#ifndef OPERACIONESBASICAS_H
#define OPERACIONESBASICAS_H


class operacionesBasicas
{

    float suma,resta,multiplicacion,division,factorialNum1=1,factorialNum2=1;
float sumador(float num1,float num2)
{
    suma= num1+num2;
    return suma;

}
float restador(float num1,float num2)
{
    resta= num1-num2;
    return resta;
}
float multiplicador(float num1,float num2)
{
    multiplicacion=num1*num2;
    return multiplicacion;
}
float divisor(float num1,float num2)
{
    division=num1/num2;
    return division;
}
float factorializadorNum1(float num1)
{

    for (int i=1; i<=num1; i++)
    {
        factorialNum1*=i;
    }
    return factorialNum1;

}
float factorializadorNum2(float num2)
{

    for (int i=1; i<=num2; i++)
    {
        factorialNum2*=i;
    }
    return factorialNum2;

}

    public:
        operacionesBasicas();
        virtual ~operacionesBasicas();

    protected:

    private:
};

#endif // OPERACIONESBASICAS_H
