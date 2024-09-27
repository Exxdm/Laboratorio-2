#include <iostream>
#include <random>

using namespace std;
void problema1(), problema2(), problema3(), problema4(), problema5(int, char*), problema6(char[]), problema7();
void problema8(), problema9(), problema10(), problema11(), problema12(), problema13(), problema14(), problema15();
void problema16(), problema17(), problema18();

int main() {
    int opcion = 1;
    while (opcion != 0) {
        cout << "BIENVENID@ LAB N2\n \nMENU DE OPCIONES:\n\n1. Problema 1\n2. Problema 2\n3. Problema 3\n4. Problema 4\n5. Problema 5\n"
             << "6. Problema 6\n7. Problema 7\n8. Problema 8\n9. Problema 9\n10. Problema 10\n11. Problema 11\n12. Problema 12\n"
             << "13. Problema 13\n14. Problema 14\n15. Problema 15\n16. Problema 16\n17. Problema 17\n18. Problema 18\n0. Salir\n\nSeleccione una opcion: ";
        cin >> opcion;
        cout << "\n";

        switch (opcion) {
        case 1: problema1(); break;
        case 2: problema2(); break;
        case 3: problema3(); break;
        case 4: problema4(); break;
        case 5:
        {
            int number = 123;  // Numero de prueba
            char result[12];

            problema5(number, result);

            cout << "El numero convertido a cadena es: " << result << endl;
            cout<< "\n";
            break;
        }
        case 6:
        {
            cout<< "EL SIGUIENTE CODIGO ES LA VERSION EN C++, EL CODIGO DE ARDUINO ESTA EN EL OTRO ARCHIVO" <<endl;
            cout<< "\n";

            char cadena[100];

            // Limpiar el bufer de entrada antes de usar getline
            cin.ignore();  // Soluciona problemas de lectura

            // Lectura de la cadena de entrada
            cout << "Introduce una cadena de caracteres: ";
            cin.getline(cadena, 100);

            // Invocación
            problema6(cadena);
            break;
        }
        case 7: problema7(); break;
        case 8: problema8(); break;
        case 9: problema9(); break;
        case 10: problema10(); break;
        case 11: problema11(); break;
        case 12: problema12(); break;
        case 13: problema13(); break;
        case 14: problema14(); break;
        case 15: problema15(); break;
        case 16: problema16(); break;
        case 17: problema17(); break;
        case 18: problema18(); break;
        default:

            if (opcion!=0){

                cout<<"Saludos!!"<<endl; cout<<"\n";
                break;
            }
        }
    }

    return 0;
}


void problema1 ()
{
    cout<< "EL SIGUIENTE CODIGO ES LA VERSION EN C++, EL CODIGO DE ARDUINO ESTA EN EL OTRO ARCHIVO" <<endl;
    cout<< "\n";

    int valores[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cantidad;

    cout << "Ingresa la cantidad de dinero: ";
    cin >> cantidad;
    cout<<"\n";

    int faltante = cantidad;

    for (int i = 0; i < 10; i++) {

        int nbilletes = faltante / valores[i];

        cout << valores[i] << ": " << nbilletes << endl;
        cout<<"\n";

        faltante = faltante % valores[i];
    }

    if (faltante > 0) {
        cout<<"\n";
        cout << "Faltante: " << faltante << endl;
        cout<<"\n";

    }

}

void problema2()
{

    const int TAMANIO = 200;
    char arreglo[TAMANIO];
    int contador[26] = {0};

    random_device rd;  // Generador de números aleatorios
    mt19937 gen(rd()); // Semilla para el generador
    uniform_int_distribution<> dis(65, 90); // Distribución para generar letras A-Z (ASCII 65-90)


    for (int i = 0; i < TAMANIO; ++i) {
        arreglo[i] = static_cast<char>(dis(gen)); // Generar letra aleatoria
        contador[arreglo[i] - 'A']++;
    }

    cout << "Arreglo generado: ";
    for (int i = 0; i < TAMANIO; ++i) {
        cout << arreglo[i];
    }
    cout << endl;


    for (int i = 0; i < 26; ++i) {
        if (contador[i] > 0) {
            cout << static_cast<char>('A' + i) << ": " << contador[i] << endl;
        }
    }
}


void problema3()
{
    char cadena1[100];
    char cadena2[100];

    cout << "Por favor, introduce la primera cadena: ";
    cin.ignore(); //Limpia el bufer
    cin.getline(cadena1, 100);

    cout << "Ahora introduce la segunda cadena: ";
    cin.getline(cadena2, 100);
    cout<< "\n";

    // Comparar ambas cadenas
    int i = 0;
    bool iguales = true;

    // Comparar caracter por caracter hasta que se acaben ambas cadenas
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            iguales = false; // Si algun caracter es diferente, se marca como no iguales
            break;
        }
        i++;
    }

    // Si una cadena es más larga que la otra, también son diferentes
    if (cadena1[i] != '\0' || cadena2[i] != '\0') {
        iguales = false;
    }

    if (iguales) {
        cout << "Las cadenas son iguales." << endl;
        cout<< "\n";
    } else {
        cout << "Las cadenas son diferentes." << endl;
        cout<< "\n";
    }

}

void problema4() {
    const char* cadena = "123";  // Cadena de prueba
    int numero = 0;
    int i = 0;

    // Convertir cada caracter numerico en su valor entero correspondiente
    while (cadena[i] != '\0') {
        numero = numero * 10 + (cadena[i] - '0');
        i++;
    }

    cout << "El numero convertido es: " << numero << endl;
    cout<< "\n";
}

void problema5(int num, char* result) {

    int index = 0;

    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    // Extrae los digitos en orden inverso
    do {
        result[index++] = (num % 10) + '0';  // Convertir el digito en carácter
        num /= 10;
    } while (num > 0);

    // Si el número era negativo, añadir el signo menos
    if (isNegative) {
        result[index++] = '-';
    }

    // Añadir el caracter de fin de cadena
    result[index] = '\0';

    // Invertir la cadena ya que los digitos se agregaron en orden inverso
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
}

void problema6 (char cadena[]) {

    cout << "Original: " << cadena << endl;

    // Proceso para convertir minúsculas a mayúsculas
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - 32;
        }
    }

    cout << "En mayuscula: " << cadena << endl;
    cout << "\n";
}

void problema7 (){

    char cadena[100];
    cout << "Ingresa una cadena de caracteres: ";
    cin >> cadena;
    cout <<"\n";

    char sin_repetidos[100];
    int indice = 0;

    // Proceso para eliminar caracteres repetidos
    for (int i = 0; cadena[i] != '\0'; i++) {
        bool repetido = false;

        // Revisa si el carácter actual ya está en sin_repetidos
        for (int j = 0; j < indice; j++) {
            if (cadena[i] == sin_repetidos[j]) {
                repetido = true;
                break;
            }
        }

        // Si no es repetido, lo agrega a sin_repetidos
        if (!repetido) {
            sin_repetidos[indice] = cadena[i];
            indice++;
        }
    }

    // Termina la cadena sin repetidos
    sin_repetidos[indice] = '\0';

    cout << "Original: " << cadena << endl;
    cout << "Sin repetidos: " << sin_repetidos << endl;
    cout << "\n";
}

void problema8()
{
    const int MAX = 100;
    char original[MAX];
    char texto[MAX] = {};
    char numero[MAX] = {};

    cout << "Introduce una cadena de caracteres: ";
    cin >> original;
    cout << "\n";

    int indiceTexto = 0, indiceNumero = 0;

    // Recorrer el arreglo original hasta encontrar el fin de la cadena ('\0')
    for (int i = 0; original[i] != '\0'; i++) {
        if (original[i] >= '0' && original[i] <= '9') {
            numero[indiceNumero++] = original[i];  // Agrega el número al arreglo
        } else {
            texto[indiceTexto++] = original[i];  // Agrega el carácter al arreglo de texto
        }
    }

    cout << "Original: " << original << "." << endl;
    cout << "Texto: " << texto << "." << endl;
    cout << "Numero: " << numero << "." << endl;
    cout << "\n";
}

void problema9()
{
    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    cout << "Introduce la cadena de numeros: ";
    char cadena[100];
    cin >> cadena;
    cout<< "\n";

    // Calcula la longitud de la cadena
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }

    // Calcula si es necesario añadir ceros al inicio
    int sobrante = longitud % n;
    int totalCeros = sobrante == 0 ? 0 : n - sobrante;

    // Mostrar la cadena original con ceros añadidos si es necesario
    cout << "Original: ";
    for (int i = 0; i < totalCeros; i++) {
        cout << '0';  // Añadir ceros al principio
    }
    cout << cadena << endl;

    // Suma los numeros separados en grupos de n cifras
    int suma = 0;
    int numeroTemporal = 0;
    int contador = 0;

    // Procesa, si es necesario
    for (int i = 0; i < totalCeros; i++) {
        numeroTemporal = numeroTemporal * 10;  // Añade ceros al principio
        contador++;
        if (contador == n) {
            suma += numeroTemporal;
            numeroTemporal = 0;
            contador = 0;
        }
    }

    // Recorre la cadena original
    for (int i = 0; i < longitud; i++) {
        numeroTemporal = numeroTemporal * 10 + (cadena[i] - '0');
        contador++;
        if (contador == n) {  // Cada n cifras, sumamos
            suma += numeroTemporal;
            numeroTemporal = 0;
            contador = 0;
        }
    }

    cout << "Suma: " << suma << endl;
    cout<< "\n";
}

void problema10()
{
    cout<< "EL SIGUIENTE CODIGO ES LA VERSION EN C++, EL CODIGO DE ARDUINO ESTA EN EL OTRO ARCHIVO" <<endl;
    cout<< "\n";

    char numeroRomano[100];
    int longitud = 0;
    int total = 0;

    cout << "Ingrese un numero en el sistema romano (Debes usar Mayusculas): ";
    cin >> numeroRomano;
    cout<< "\n";

    // Calcula la longitud del numero romano
    while (numeroRomano[longitud] != '\0') {
        longitud++;
    }

    // Recorre el numero romano y convertirlo
    for (int i = 0; i < longitud; i++) {
        int valorActual;
        int valorSiguiente = 0;

        // Asignar el valor correspondiente al caracter actual
        switch(numeroRomano[i]) {
        case 'M': valorActual = 1000; break;
        case 'D': valorActual = 500; break;
        case 'C': valorActual = 100; break;
        case 'L': valorActual = 50; break;
        case 'X': valorActual = 10; break;
        case 'V': valorActual = 5; break;
        case 'I': valorActual = 1; break;
        default: valorActual = 0; // Por si hubiera un caracter invalido
        }

        // Asigna el valor correspondiente al siguiente caracter (si existe)
        if (i + 1 < longitud) {
            switch(numeroRomano[i + 1]) {
            case 'M': valorSiguiente = 1000; break;
            case 'D': valorSiguiente = 500; break;
            case 'C': valorSiguiente = 100; break;
            case 'L': valorSiguiente = 50; break;
            case 'X': valorSiguiente = 10; break;
            case 'V': valorSiguiente = 5; break;
            case 'I': valorSiguiente = 1; break;
            default: valorSiguiente = 0;
            }
        }

        // Sumar o restar segun la regla
        if (valorActual < valorSiguiente) {
            total -= valorActual;
        } else {
            total += valorActual;
        }
    }

    cout << "El numero ingresado fue: " << numeroRomano;
    cout << "\nQue corresponde a: " << total << endl;
    cout << "\n";
}

void problema11()
{
    const int FILAS = 15;
    const int ASIENTOS = 20;
    char sala[FILAS][ASIENTOS];
    char fila;
    int asiento, opcion;

    // Inicializa la sala con todos los asientos disponibles
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS; j++) {
            sala[i][j] = '-'; // Todos los asientos disponibles
        }
    }

    do {
        cout <<"BIENVENID@ A CINEEST"<<endl;
        cout << "\n1. Mostrar sala" << endl;
        cout << "2. Reservar asiento" << endl;
        cout << "3. Cancelar reserva" << endl;
        cout << "4. Salir" << endl;
        cout<< "\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            // Mostrar sala
            cout << "   ";
            for (int j = 1; j <= ASIENTOS; j++) {
                if (j < 10) cout << " " << j << " "; // Formato para numeros de 1 digito
                else cout << j << " "; // Formato para números de 2 digitos
            }
            cout << endl;

            for (int i = 0; i < FILAS; i++) {
                cout << (char)('A' + i) << "  "; // Muestra las letras de las filas
                for (int j = 0; j < ASIENTOS; j++) {
                    cout << sala[i][j] << "  "; // Muestra el estado de cada asiento
                }
                cout << endl;
            }
        } else if (opcion == 2) {

            // Reservar asiento
            cout << "Ingrese la fila, letras (En mayuscula, por favor) (A-O): ";
            cin >> fila;
            cout << "Ingrese el numero de asiento (1-20): ";
            cin >> asiento;

            int indiceFila = fila - 'A';
            int indiceAsiento = asiento - 1;

            if (sala[indiceFila][indiceAsiento] == '-') {
                sala[indiceFila][indiceAsiento] = '+';
                cout << "Reserva realizada correctamente." << endl;
                cout<< "\n";
            } else {
                cout << "El asiento ya esta reservado." << endl;
                cout<< "\n";
            }
        } else if (opcion == 3) {
            // Cancelar reserva
            cout << "Ingrese la fila, letras (En mayuscula, por favor) (A-O): ";
            cin >> fila;
            cout << "Ingrese el numero de asiento (1-20): ";
            cin >> asiento;

            int indiceFila = fila - 'A';
            int indiceAsiento = asiento - 1;

            if (sala[indiceFila][indiceAsiento] == '+') {
                sala[indiceFila][indiceAsiento] = '-';
                cout << "Reserva cancelada correctamente." << endl;
                cout<< "\n";
            } else {
                cout << "El asiento no esta reservado." << endl;
                cout<< "\n";
            }
        } else if (opcion == 4) {
            cout << "Saliendo del programa." << endl;
            cout<< "\n";
        } else {
            cout << "Opcion no valida." << endl;
            cout<< "\n";
        }

    } while (opcion != 4);
}

void problema12()
{
    int n = 3;
    int matriz[3][3];

    cout << "Ingrese los valores de la matriz 3x3 (con su debido orden):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    cout<< "\n";
    cout << "La matriz ingresada es:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Verificar si es un cuadrado magico
    int sumaDiagonal1 = 0, sumaDiagonal2 = 0;

    // Sumar la diagonal principal y la secundaria
    for (int i = 0; i < n; i++) {
        sumaDiagonal1 += matriz[i][i];
        sumaDiagonal2 += matriz[i][n-i-1];
    }

    // Si las diagonales no suman lo mismo, no es un cuadrado mágico
    if (sumaDiagonal1 != sumaDiagonal2) {
        cout<< "\n";
        cout << "La matriz no es un cuadrado magico." << endl;
        return ;
    }

    // Revisar las sumas de filas y columnas
    for (int i = 0; i < n; i++) {
        int sumaFila = 0, sumaColumna = 0;
        for (int j = 0; j < n; j++) {
            sumaFila += matriz[i][j];
            sumaColumna += matriz[j][i];
        }

        // Si alguna fila o columna no suma lo mismo que la diagonal, no es cuadrado mágico
        if (sumaFila != sumaDiagonal1 || sumaColumna != sumaDiagonal1) {
            cout<< "\n";
            cout << "La matriz no es un cuadrado magico." << endl;
            return ;
        }
    }

    cout<< "\n";
    cout << "La matriz es un cuadrado magico." << endl;
    cout<< "\n";

}

void problema13()
{

    // Matriz de ejemplo (la misma de la imagen)
    int matriz[6][7] = {
        {0, 3, 4, 0, 0, 6, 8},
        {5, 13, 6, 0, 0, 2, 3},
        {2, 6, 2, 7, 3, 0, 10},
        {0, 0, 4, 15, 4, 1, 6},
        {0, 0, 7, 12, 6, 9, 10},
        {5, 0, 6, 10, 6, 4, 8}
    };

    int filas = 6;
    int columnas = 7;
    int estrellas = 0;

    // Recorre la matriz ignorando los bordes
    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {
            // Calcula el promedio de los vecinos
            int sumaVecinos = matriz[i][j] +
                              matriz[i][j - 1] +
                              matriz[i][j + 1] +
                              matriz[i - 1][j] +
                              matriz[i + 1][j];

            float promedio = sumaVecinos / 5.0;

            // Si el promedio es mayor que 6, se considera una estrella
            if (promedio > 6) {
                estrellas++;
            }
        }
    }

    cout << "Numero de estrellas: " << estrellas << endl;
    cout <<"\n";

}

void problema14()
{
    const int N = 5;  // Tamaño de la matriz
    int matriz[N][N];
    int rotada[N][N];  //Almacena las rotaciones

    // Llena la matriz con los números del 1 al 25
    int valor = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = valor++;
        }
    }

    cout << "Matriz original:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Rota 90 grados
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotada[j][N - 1 - i] = matriz[i][j];
        }
    }

    cout << "Matriz rotada 90 grados:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << rotada[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Rota 180 grados
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotada[N - 1 - i][N - 1 - j] = matriz[i][j];
        }
    }

    cout << "Matriz rotada 180 grados:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << rotada[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Rota 270 grados
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotada[N - 1 - j][i] = matriz[i][j];
        }
    }

    cout << "Matriz rotada 270 grados:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << rotada[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

}

void problema15()
{
    int A[4], B[4], C[4]; // Rectángulos

    cout << "Ingresa los datos del rectangulo A (x, y, ancho, alto): ";
    cin >> A[0] >> A[1] >> A[2] >> A[3];

    cout << "Ingresa los datos del rectangulo B (x, y, ancho, alto): ";
    cin >> B[0] >> B[1] >> B[2] >> B[3];
    cout << "\n";

    C[0] = max(A[0], B[0]); // x de intersección
    C[1] = max(A[1], B[1]); // y de intersección

    int x_fin_A = A[0] + A[2]; // x de la esquina inferior derecha de A
    int y_fin_A = A[1] + A[3]; // y de la esquina inferior derecha de A
    int x_fin_B = B[0] + B[2]; // x de la esquina inferior derecha de B
    int y_fin_B = B[1] + B[3]; // y de la esquina inferior derecha de B

    // Calcular el ancho y alto del rectángulo intersección
    C[2] = min(x_fin_A, x_fin_B) - C[0]; // Ancho de intersección
    C[3] = min(y_fin_A, y_fin_B) - C[1]; // Alto de intersección

    // Verificar si hay intersección
    if (C[2] > 0 && C[3] > 0) {
        cout << "Rectangulo interseccion: {" << C[0] << ", " << C[1] << ", " << C[2] << ", " << C[3] << "}" << endl;
        cout << "\n";
    } else {
        cout << "No hay interseccion entre los rectangulos A y B." << endl;
        cout << "\n";
    }
}

void problema16 ()
{
    int n;
    cout << "Introduce la medida de la malla (n): ";
    cin >> n;

    // Función para calcular el factorial
    auto factorial = [](int num) {
        unsigned long long result = 1;
        for (int i = 1; i <= num; i++) {
            result *= i;
        }
        return result;
    };

    // Calcular el número de caminos usando la fórmula combinatoria C(2n, n)
    unsigned long long caminos = factorial(2 * n) / (factorial(n) * factorial(n));

    cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." <<endl;
    cout << "\n";

}

void problema17 ()
{
    cout<< "EL SIGUIENTE CODIGO ES LA VERSION EN C++, EL CODIGO DE ARDUINO ESTA EN EL OTRO ARCHIVO" <<endl;
    cout<< "\n";

    int numero;
    // Función para calcular la suma de los divisores propios de un número
    auto sumaDivisores = [](int num) {
        int suma = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                suma += i;
            }
        }
        return suma;
    };

    cout << "Ingresa un numero: ";
    cin >> numero;

    int sumaTotal = 0;

    // Calcular la suma de los números amigables menores al número ingresado
    for (int a = 1; a < numero; a++) {
        int b = sumaDivisores(a);
        if (b != a && b < numero && sumaDivisores(b) == a) {
            sumaTotal += a;
        }
    }
    cout << "El resultado de la suma es: " << sumaTotal << endl;
    cout<< "\n";

}

void problema18 ()
{
    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int fact = 1;
    int result[10];
    int available = 10;

    // Calcular el factorial de 9, ya que trabajamos con 10 dígitos
    for (int i = 1; i < available; i++) {
        fact *= i;
    }

    n--;

    for (int i = 0; i < 10; i++) {
        int index = n / fact;
        result[i] = digits[index];

        for (int j = index; j < available - 1; j++) {
            digits[j] = digits[j + 1];
        }

        available--; // Disminuimos el número de dígitos disponibles

        if (available > 0) {
            n %= fact;
            fact /= available; // Recalculamos el factorial para el nuevo tamaño
        }
    }

    cout << "La permutacion del numero " << (n + 1) << " es: ";
    for (int i = 0; i < 10; i++) {
        cout << result[i];
    }
    cout << endl;
    cout <<"\n";
}
