#ifndef OPERACIONESMATBASICAS_H
#define OPERACIONESMATBASICAS_H


float suma,resta,multiplicacion,division;

/** \brief Metodo sumador de numeros
 *
 * \param pide primer numero
 * \param pide segundo numero
 * \return retorna la suma
 *
 */

float sumador(float num1,float num2)
{
    suma= num1+num2;
    return suma;

}
/** \brief Metodo restador de numeros
 *
 * \param pide primer numero
 * \param pide segundo numero
 * \return retorna la resta
 *
 */
float restador(float num1,float num2)
{
    resta= num1-num2;
    return resta;
}
/** \brief Metodo multiplicador de numeros
 *
 * \param pide primer numero
 * \param pide segundo numero
 * \return retorna la multiplicacion
 *
 */
float multiplicador(float num1,float num2)
{
    multiplicacion=num1*num2;
    return multiplicacion;
}
/** \brief Metodo divisor de numeros
 *
 * \param pide primer numero
 * \param pide segundo numero
 * \return retorna la division
 *
 */
float divisor(float num1,float num2)
{
    division=num1/num2;
    return division;
}
/** \brief Metodo factorizador de numeros
 *
 * \param pide primer numero
 * \param pide segundo numero

 *
 */
float factorializadorNumero(float numUsuario)
{
    float factorialNum=1;

    for (int i=1; i<=numUsuario; i++)
    {
        factorialNum*=i;

    }
    return factorialNum;
}


#endif // OPERACIONESMATBASICAS_H
