## Tipos de Kernel y sus Diferencias

### 1. **Monolítico**

Un **kernel monolítico** integra todos los servicios del sistema operativo en un solo espacio de memoria. Esto incluye la gestión de procesos, la gestión de memoria, la gestión de dispositivos, entre otros.

- **Ventajas:**
  - Rendimiento alto debido a la comunicación directa entre módulos.
  - Sin sobrecarga de llamadas al sistema.
- **Desventajas:**
  - Menos modularidad y más difícil de mantener.
  - Un fallo en el kernel puede afectar a todo el sistema.

**Ejemplo:** Linux (aunque también tiene características modulares).

### 2. **Microkernel**

Un **microkernel** se centra en minimizar el núcleo del sistema operativo, delegando la mayoría de los servicios a procesos en el espacio de usuario. Solo las funciones esenciales (gestión de procesos y comunicación inter-procesos) residen en el kernel.

- **Ventajas:**
  - Mayor estabilidad y seguridad, ya que los servicios no críticos se ejecutan en el espacio de usuario.
  - Mejor modularidad y facilidad de mantenimiento.
- **Desventajas:**
  - Mayor sobrecarga debido a la comunicación entre el kernel y los servicios en el espacio de usuario.
  - Posiblemente menor rendimiento en comparación con los kernels monolíticos.

**Ejemplo:** Minix, QNX.

### 3. **Híbrido**

El **kernel híbrido** combina elementos de los kernels monolíticos y microkernels. Intenta mantener la eficiencia de los kernels monolíticos mientras mantiene la modularidad y estabilidad de los microkernels.

- **Ventajas:**
  - Equilibrio entre rendimiento y modularidad.
  - Permite la inclusión de drivers y servicios en el espacio del kernel si es necesario.
- **Desventajas:**
  - Puede ser complejo y tener una estructura más pesada que un microkernel puro.

**Ejemplo:** Windows NT, macOS.

### 4. **Exokernel**

Un **exokernel** proporciona una interfaz mínima para el hardware, permitiendo a las aplicaciones gestionar el hardware de manera más directa. Los exokernels ofrecen menos servicios directamente y delegan la mayor parte de la gestión a bibliotecas de usuario.

- **Ventajas:**
  - Flexibilidad máxima para aplicaciones específicas.
  - Potencialmente mayor eficiencia en aplicaciones especializadas.
- **Desventajas:**
  - Mayor complejidad en la gestión de recursos por parte de las aplicaciones.
  - Menos soporte y herramientas en comparación con kernels más tradicionales.

**Ejemplo:** MIT Exokernel.

## User Mode vs Kernel Mode

### **User Mode**

- **Definición:** El **modo usuario** es el modo en el que las aplicaciones y procesos de usuario se ejecutan. En este modo, el código no tiene acceso directo al hardware y a los recursos críticos del sistema.
- **Características:**
  - Menos privilegios en comparación con el kernel mode.
  - Las aplicaciones que fallan en este modo no pueden afectar directamente al sistema operativo.
  - La comunicación con el hardware se realiza a través de llamadas al sistema y servicios proporcionados por el kernel.

### **Kernel Mode**

- **Definición:** El **modo kernel** es el modo en el que el núcleo del sistema operativo y sus módulos críticos se ejecutan. Este modo tiene acceso completo al hardware y a todos los recursos del sistema.
- **Características:**
  - Máximos privilegios y acceso directo al hardware.
  - Los fallos en este modo pueden afectar a todo el sistema operativo.
  - Utilizado para operaciones críticas como la gestión de memoria, el control de dispositivos y la comunicación entre procesos.

## Interruptions vs Traps

### **Interruptions (Interrupciones)**

- **Definición:** Las **interrupciones** son señales generadas por el hardware que requieren la atención inmediata del sistema operativo. Pueden ser generadas por dispositivos de entrada/salida, temporizadores, etc.
- **Características:**
  - Permiten la respuesta inmediata a eventos externos.
  - El sistema operativo detiene temporalmente el proceso actual para manejar la interrupción.
  - Después de manejar la interrupción, el sistema operativo reanuda el proceso interrumpido.

**Ejemplo:** Una interrupción de teclado cuando el usuario presiona una tecla.

### **Traps (Trampas)**

- **Definición:** Las **trampas** son señales generadas por el software, a menudo como resultado de errores o excepciones durante la ejecución de un programa, como divisiones por cero o violaciones de memoria.
- **Características:**
  - Se utilizan para manejar excepciones y errores dentro del espacio de usuario.
  - Permiten al sistema operativo tomar el control cuando ocurre un error en el programa.
  - No son causadas por eventos externos, sino por el propio código en ejecución.

**Ejemplo:** Una trampa generada cuando un programa intenta acceder a una dirección de memoria no permitida.
