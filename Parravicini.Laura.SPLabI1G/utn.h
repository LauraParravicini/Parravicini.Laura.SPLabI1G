#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** \brief Recibe un puntero a un entero, pide la carga un numero y se valida el mismo, si esta dentro del rango y el caracter
 *
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief Recibe un puntero a caracter, pide un caracter lo carga y lo valida
 *
 * \param pResultado char*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo char
 * \param maximo char
 * \param reintentos int
 * \return int
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/** \brief Recibe puntero a int para cada parte de la fecha donde se cargaran los valores ingresados y validados
 *
 * \param dia int*
 * \param mes int*
 * \param anio int*
 * \param mensaje char*
 * \param msjeError char*
 * \param reintentos int
 * \return int
 *
 */
int utn_getFecha(int* dia,int* mes, int* anio, char* mensaje, char* msjeError,int reintentos);

/** \brief Recibe un string que es validado para float
 *
 * \param cadena char*
 * \return int
 *
 */
int utn_getFloat(char * cadena);


/** \brief Recibe un numero de punto flotante ingresado y se valida el mismo
 *
 * \param numeroIngresado float*
 * \param mensaje char*
 * \return mensajeError char*
 *
 */
int getFloat (float *numeroIngresado, char* mensaje, char* mensajeError);

/** \brief Recibe una catena ingresado y se valida el mismo si corresponde a un nombre valido
 *
 * \param stringRecibido char*
 * \return int
 *
 */
int isValidName(char* stringRecibido) ;

/** \brief Pide un nombre que se guarda en un string ya validado, en rango y tipo.
 *
 * \param msg char*
 * \param msgError char*
 * \param min int
 * \param max int
 * \param reintentos int
 * \param resultado char*
 * \return int
 *
 */
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);

/** \brief Valida una cadena de caracteres
 *
 * \param msg char*
 * \param msgError char*
 * \param min int
 * \param max int
 * \param reintentos int*
 * \param resultado char*
 * \return int
 *
 */
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

/** \brief Pide el ingreso de un numero de telefono y lo valida en rango y tipo.
 *
 * \param msg char*
 * \param msgError char*
 * \param minSize int
 * \param maxSize int
 * \param min int
 * \param max int
 * \param reintentos int
 * \param input char*
 * \return int
 *
 */
int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input);


/** \brief Valida la cadena de un numero de telefono
 *
 * \param stringRecibido char*
 * \return int
 *
 */
int isValidTelephone(char* stringRecibido);
#endif // UTN_H_INCLUDED
