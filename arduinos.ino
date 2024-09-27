//Problema 1
void setup() {
        Serial.begin(9600); // Iniciar la comunicación serie
    }

    void loop() {
        problema1();
        delay(10000); // Retardo de 10 segundos entre ejecuciones para evitar que se ejecute constantemente
    }

    void problema1() {
        int valores[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
        int cantidad;

        Serial.println("Ingresa la cantidad de dinero: ");

        // Esperar hasta que haya datos disponibles en el monitor serie
        while (Serial.available() == 0) {
            // Esperar...
        }

        // Leer la cantidad ingresada desde el monitor serie
        cantidad = Serial.parseInt();
        Serial.println("\n");

        int faltante = cantidad;

        for (int i = 0; i < 10; i++) {
            int nbilletes = faltante / valores[i];
            Serial.print(valores[i]);
            Serial.print(": ");
            Serial.println(nbilletes);

            faltante = faltante % valores[i];
        }

        if (faltante > 0) {
            Serial.println("\n");
            Serial.print("Faltante: ");
            Serial.println(faltante);
            Serial.println("\n");
        }
    }

//Problema 6:


// Función para convertir minúsculas a mayúsculas
void convertirMayusculas(char cadena[]) {
  // Mostramos la cadena original
  Serial.print("Original: ");
  Serial.println(cadena);

  // Proceso para convertir minúsculas a mayúsculas
  for (int i = 0; cadena[i] != '\0'; i++) {
    if (cadena[i] >= 'a' && cadena[i] <= 'z') {
      cadena[i] = cadena[i] - 32;
    }
  }

  // Mostramos la cadena convertida
  Serial.print("En mayúscula: ");
  Serial.println(cadena);
}

void setup() {
  // Inicializamos la comunicación serie
  Serial.begin(9600);
  
  // Esperamos a que el monitor serie se conecte (útil para algunas placas)
  while (!Serial) {
    ; // Espera a que se establezca la conexión serie
  }

  // Solicitamos al usuario que introduzca una cadena
  Serial.println("Introduce una cadena de caracteres:");
}

void loop() {
  // Verificamos si hay datos disponibles en el puerto serie
  if (Serial.available() > 0) {
    // Leemos la cadena del puerto serie
    char cadena[100];
    Serial.readBytesUntil('\n', cadena, 100);

    // Invocamos la función para convertir a mayúsculas
    convertirMayusculas(cadena);

    // Reiniciamos el proceso, pidiendo otra entrada
    Serial.println("\nIntroduce otra cadena de caracteres:");
  }
}

//PROBLEMA 10

char numeroRomano[100];  // Asumimos un tamaño máximo de 100 caracteres
int longitud = 0;
int total = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese un numero en el sistema romano(Debes usar Mayusculas):");

  // Esperar hasta que el usuario introduzca algo
  while (Serial.available() == 0) {}

  // Leer la entrada del usuario
  int i = 0;
  while (Serial.available() > 0 && i < 100 - 1) {
    numeroRomano[i] = Serial.read();
    i++;
    delay(10);  // Añadimos un pequeño retardo para asegurar que toda la entrada se ha leído
  }
  numeroRomano[i] = '\0';  // Añadimos el terminador de cadena
  longitud = i;

  Serial.print("El numero ingresado fue: ");
  Serial.println(numeroRomano);

  // Recorrer el número romano y convertirlo
  for (int i = 0; i < longitud; i++) {
    int valorActual;
    int valorSiguiente = 0;

    // Asignar el valor correspondiente al carácter actual
    switch (numeroRomano[i]) {
      case 'M': valorActual = 1000; break;
      case 'D': valorActual = 500; break;
      case 'C': valorActual = 100; break;
      case 'L': valorActual = 50; break;
      case 'X': valorActual = 10; break;
      case 'V': valorActual = 5; break;
      case 'I': valorActual = 1; break;
      default: valorActual = 0;  // Por si hubiera un carácter inválido
    }

    // Asignar el valor correspondiente al siguiente carácter (si existe)
    if (i + 1 < longitud) {
      switch (numeroRomano[i + 1]) {
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

    // Sumar o restar según la regla
    if (valorActual < valorSiguiente) {
      total -= valorActual;
    } else {
      total += valorActual;
    }
  }

  Serial.print("Que corresponde a: ");
  Serial.println(total);
}

void loop() {
  // No se necesita hacer nada en loop
}

//Problema 17

int numero;

// Función para calcular la suma de los divisores propios de un número
int sumaDivisores(int num) {
  int suma = 0;
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0) {
      suma += i;
    }
  }
  return suma;
}

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);
  while (!Serial) {
    ; // Esperar a que se abra la comunicación serial
  }
  
  Serial.println("Ingresa un numero: ");
  
  // Esperar a que el usuario ingrese un número a través del monitor serial
  while (Serial.available() == 0) {
    // Esperar hasta que haya datos disponibles
  }
  
  numero = Serial.parseInt();  // Leer el número ingresado
  
  int sumaTotal = 0;

  // Calcular la suma de los números amigables menores al número ingresado
  for (int a = 1; a < numero; a++) {
    int b = sumaDivisores(a);
    if (b != a && b < numero && sumaDivisores(b) == a) {
      sumaTotal += a;  // Agregamos 'a' a la suma si son amigables
    }
  }

  // Mostrar el resultado
  Serial.print("El resultado de la suma es: ");
  Serial.println(sumaTotal);
  Serial.println();
}

void loop() {
  // No hacemos nada en el loop
}
